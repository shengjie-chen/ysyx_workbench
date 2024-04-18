#include <SDL2/SDL.h>
#include <common.h>
#include <device/map.h>

enum { reg_freq, reg_channels, reg_samples, reg_sbuf_size, reg_init, reg_count, nr_reg };

static uint8_t *sbuf = NULL;
static uint32_t *audio_base = NULL;
static uint32_t pos = 0;

static void audio_callback(void *udata, uint8_t *stream, int len) {
    SDL_LockAudio();
    SDL_memset(stream, 0, len);
    len = len > audio_base[reg_count] ? audio_base[reg_count] : len;
    if (audio_base[reg_count] == 0)
        return;
    if ((pos + len) < CONFIG_SB_SIZE) {
        memcpy(stream, sbuf + pos, len);
        pos += len;
    } else {
        memcpy(stream, sbuf + pos, (CONFIG_SB_SIZE - pos));
        pos = CONFIG_SB_SIZE - pos;
        memcpy(stream + pos, sbuf, len - pos);
        pos = len - pos;
    }
    SDL_UnlockAudio();
    audio_base[reg_count] -= len;
}

static void audio_io_handler(uint32_t offset, int len, bool is_write) {
    if (offset == 0x10 && is_write) {
        SDL_AudioSpec audio;
        audio.freq = audio_base[reg_freq];
        audio.format = AUDIO_S16SYS;
        audio.channels = audio_base[reg_channels];
        audio.samples = audio_base[reg_samples];
        audio.callback = audio_callback;

        SDL_OpenAudio(&audio, NULL);
        SDL_PauseAudio(0);
    }
}

void init_audio() {
    uint32_t space_size = sizeof(uint32_t) * nr_reg;
    audio_base = (uint32_t *)new_space(space_size);
#ifdef CONFIG_HAS_PORT_IO
    add_pio_map("audio", CONFIG_AUDIO_CTL_PORT, audio_base, space_size, audio_io_handler);
#else
    add_mmio_map("audio", CONFIG_AUDIO_CTL_MMIO, audio_base, space_size, audio_io_handler);
#endif

    sbuf = (uint8_t *)new_space(CONFIG_SB_SIZE);
    add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, NULL);
    audio_base[reg_sbuf_size] = CONFIG_SB_SIZE;
    SDL_Init(SDL_INIT_AUDIO);
}
