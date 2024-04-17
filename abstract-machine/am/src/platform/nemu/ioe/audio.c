#include <am.h>
#include <nemu.h>

#define AUDIO_FREQ_ADDR      (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR  (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR   (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR      (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR     (AUDIO_ADDR + 0x14)

static uint32_t bufsize = 0;

void __am_audio_init() { bufsize = inl(AUDIO_SBUF_SIZE_ADDR); }

void __am_audio_config(AM_AUDIO_CONFIG_T *cfg) {
    cfg->present = true;
    cfg->bufsize = bufsize;
}

void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl) {
    outl(AUDIO_FREQ_ADDR, ctrl->freq);
    outl(AUDIO_CHANNELS_ADDR, ctrl->channels);
    outl(AUDIO_SAMPLES_ADDR, ctrl->samples);
    outl(AUDIO_INIT_ADDR, 1);
}

void __am_audio_status(AM_AUDIO_STATUS_T *stat) { stat->count = inl(AUDIO_COUNT_ADDR); }

void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
    uint8_t *load_flag = ctl->buf.start;
    uint8_t *buf_end = ctl->buf.end;

    while (load_flag != buf_end) {
        int count = inl(AUDIO_COUNT_ADDR);
        int load_len = (buf_end - load_flag) > (bufsize - count) ? (bufsize - count) : (buf_end - load_flag);
        uint8_t *sb = (uint8_t *)(uintptr_t)AUDIO_SBUF_ADDR + count;
        for (int i = 0; i < load_len; i++) {
            sb[i] = *load_flag;
            load_flag++;
        }
        if (inl(AUDIO_COUNT_ADDR) != count) {
            load_flag -= load_len;
        } else {
            outl(AUDIO_COUNT_ADDR, count + load_len);
            if (count + load_len >= bufsize) {
                while (inl(AUDIO_COUNT_ADDR) != 0)
                    ;
            }
        }
    }
}
