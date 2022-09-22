#include <fs.h>

typedef size_t (*ReadFn)(void *buf, size_t offset, size_t len);
typedef size_t (*WriteFn)(const void *buf, size_t offset, size_t len);

extern uint8_t ramdisk_start;
typedef struct {
  char *name;
  size_t size;
  size_t disk_offset;
  ReadFn read;
  WriteFn write;
  size_t open_offset;
} Finfo;

enum { FD_STDIN,
       FD_STDOUT,
       FD_STDERR,
       FD_FB };

size_t invalid_read(void *buf, size_t offset, size_t len) {
  panic("should not reach here");
  return 0;
}

size_t invalid_write(const void *buf, size_t offset, size_t len) {
  panic("should not reach here");
  return 0;
}

/* This is the information about all files in disk. */
static Finfo file_table[] __attribute__((used)) = {
    [FD_STDIN] = {"stdin", 0, 0, invalid_read, invalid_write},
    [FD_STDOUT] = {"stdout", 0, 0, invalid_read, invalid_write},
    [FD_STDERR] = {"stderr", 0, 0, invalid_read, invalid_write},
#include "files.h"
};

void init_fs() {
  // TODO: initialize the size of /dev/fb
}

int fs_open(const char *pathname, int flags, int mode) {
  int filenum = sizeof(file_table) / sizeof(Finfo);
  int i = 0;
  while (strcmp(file_table[i].name, pathname)) {
    if (i == filenum) {
      panic("invalid file!\n");
    }
    i++;
  }
  printf("%d",i);
  file_table[i].open_offset = 0;
  return i;
}

size_t
fs_lseek(int fd, size_t offset, int whence) {
  switch (whence) {
  case SEEK_SET:
    if (offset > file_table[fd].size) {
      panic("lseek file size overflow!\n");
    }
    file_table[fd].open_offset = offset;
    break;
  case SEEK_CUR:
    if (offset + file_table[fd].open_offset > file_table[fd].size) {
      panic("lseek file size overflow!\n");
    }
    file_table[fd].open_offset += offset;
    break;
  case SEEK_END:
    if (file_table[fd].size + file_table[fd].open_offset > file_table[fd].size) {
      panic("lseek file size overflow!\n");
    }
    file_table[fd].open_offset = file_table[fd].size + offset;
    break;
  default:
    panic("invalid whence!\n");
  }

  return file_table[fd].open_offset;
}

size_t fs_read(int fd, void *buf, size_t len) {
  if (len + file_table[fd].open_offset > file_table[fd].size) {
    panic("read file size overflow!\n");
  }
  strncpy(buf, (void *)(&ramdisk_start + file_table[fd].disk_offset + file_table[fd].open_offset), len);
  fs_lseek(fd, len, SEEK_CUR);
  return len;
}

int fs_close(int fd) {
  file_table[fd].open_offset = 0;
  return 0;
}

size_t fs_write(int fd, const void *buf, size_t len) {
  if (len + file_table[fd].open_offset > file_table[fd].size) {
    panic("write file size overflow!\n");
  }
  strncpy((void *)(&ramdisk_start + file_table[fd].disk_offset + file_table[fd].open_offset), buf, len);
  fs_lseek(fd, len, SEEK_CUR);
  return len;
}
