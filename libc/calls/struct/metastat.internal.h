#ifndef COSMOPOLITAN_LIBC_CALLS_STRUCT_METASTAT_H_
#define COSMOPOLITAN_LIBC_CALLS_STRUCT_METASTAT_H_
#ifndef __STRICT_ANSI__
#include "libc/calls/struct/stat.h"
#if !(__ASSEMBLER__ + __LINKER__ + 0)
COSMOPOLITAN_C_START_

#define METASTAT(x, field)                  \
  (IsLinux() || IsMetal() ? x.linux.field   \
   : IsXnu()              ? x.xnu.field     \
   : IsFreebsd()          ? x.freebsd.field \
   : IsOpenbsd()          ? x.openbsd.field \
   : IsNetbsd()           ? x.netbsd.field  \
                          : 0)

struct stat_xnu {
  int32_t st_dev;
  uint16_t st_mode, st_nlink;
  uint64_t st_ino;
  uint32_t st_uid, st_gid;
  int32_t st_rdev;
  struct timespec st_atim, st_mtim, st_ctim, st_birthtim;
  int64_t st_size, st_blocks;
  int32_t st_blksize;
  uint32_t st_flags, st_gen;
  int32_t st_lspare;
  int64_t st_qspare[2];
};

struct stat_freebsd {
  uint64_t st_dev, st_ino, st_nlink;
  uint16_t st_mode;
  int16_t st_padding0;
  uint32_t st_uid, st_gid;
  int32_t st_padding1;
  uint64_t st_rdev;
  struct timespec st_atim, st_mtim, st_ctim, st_birthtim;
  int64_t st_size, st_blocks;
  int32_t st_blksize;
  uint32_t st_flags;
  uint64_t st_gen;
  unsigned long st_spare[10];
};

struct stat_openbsd {
  uint32_t st_mode;
  int32_t st_dev;
  uint64_t st_ino;
  uint32_t st_nlink, st_uid, st_gid;
  int32_t st_rdev;
  struct timespec st_atim, st_mtim, st_ctim;
  int64_t st_size, st_blocks;
  int32_t st_blksize;
  uint32_t st_flags, st_gen;
  struct timespec __st_birthtim;
};

struct stat_netbsd {
  uint64_t st_dev;
  uint32_t st_mode;
  uint64_t st_ino;
  uint32_t st_nlink, st_uid, st_gid;
  uint64_t st_rdev;
  struct timespec st_atim, st_mtim, st_ctim, st_birthtim;
  int64_t st_size, st_blocks;
  int32_t st_blksize;
  uint32_t st_flags, st_gen, st_spare[2];
};

union metastat {
  struct stat linux;
  struct stat_xnu xnu;
  struct stat_freebsd freebsd;
  struct stat_openbsd openbsd;
  struct stat_netbsd netbsd;
};

COSMOPOLITAN_C_END_
#endif /* !(__ASSEMBLER__ + __LINKER__ + 0) */
#endif /* !ANSI */
#endif /* COSMOPOLITAN_LIBC_CALLS_STRUCT_METASTAT_H_ */
