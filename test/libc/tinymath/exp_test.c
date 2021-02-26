/*-*- mode:c;indent-tabs-mode:nil;c-basic-offset:2;tab-width:8;coding:utf-8 -*-│
│vi: set net ft=c ts=2 sts=2 sw=2 fenc=utf-8                                :vi│
╞══════════════════════════════════════════════════════════════════════════════╡
│ Copyright 2020 Justine Alexandra Roberts Tunney                              │
│                                                                              │
│ Permission to use, copy, modify, and/or distribute this software for         │
│ any purpose with or without fee is hereby granted, provided that the         │
│ above copyright notice and this permission notice appear in all copies.      │
│                                                                              │
│ THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL                │
│ WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED                │
│ WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE             │
│ AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL         │
│ DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR        │
│ PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER               │
│ TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR             │
│ PERFORMANCE OF THIS SOFTWARE.                                                │
╚─────────────────────────────────────────────────────────────────────────────*/
#include "libc/math.h"
#include "libc/runtime/gc.h"
#include "libc/stdio/stdio.h"
#include "libc/testlib/testlib.h"
#include "libc/x/x.h"

#define expl(x) expl(VEIL("t", (long double)(x)))
#define exp(x)  exp(VEIL("x", (double)(x)))
#define expf(x) expf(VEIL("x", (float)(x)))

TEST(expl, test) {
  EXPECT_STREQ("1", gc(xdtoal(expl(0))));
  EXPECT_STREQ("1", gc(xdtoal(expl(-0.))));
  EXPECT_STREQ("INFINITY", gc(xdtoal(expl(INFINITY))));
  EXPECT_STREQ("0", gc(xdtoal(expl(-INFINITY))));
  EXPECT_STREQ("NAN", gc(xdtoal(expl(NAN))));
  EXPECT_STREQ("0", gc(xdtoal(expl(-132098844872390))));
  EXPECT_STREQ("INFINITY", gc(xdtoal(expl(132098844872390))));
}

TEST(exp, test) {
  EXPECT_STREQ("1", gc(xdtoa(exp(0))));
  EXPECT_STREQ("1", gc(xdtoa(exp(-0.))));
  EXPECT_STREQ("INFINITY", gc(xdtoa(exp(INFINITY))));
  EXPECT_STREQ("0", gc(xdtoa(exp(-INFINITY))));
  EXPECT_STREQ("NAN", gc(xdtoa(exp(NAN))));
  EXPECT_STREQ("0", gc(xdtoa(exp(-132098844872390))));
  EXPECT_STREQ("INFINITY", gc(xdtoa(exp(132098844872390))));
}

TEST(expf, test) {
  EXPECT_STREQ("1", gc(xdtoaf(expf(0))));
  EXPECT_STREQ("1", gc(xdtoaf(expf(-0.))));
  EXPECT_STREQ("INFINITY", gc(xdtoaf(expf(INFINITY))));
  EXPECT_STREQ("0", gc(xdtoaf(expf(-INFINITY))));
  EXPECT_STREQ("NAN", gc(xdtoaf(expf(NAN))));
  EXPECT_STREQ("0", gc(xdtoaf(expf(-132098844872390))));
  EXPECT_STREQ("INFINITY", gc(xdtoaf(expf(132098844872390))));
}

TEST(exp, fun) {
  ASSERT_STREQ("7.389056", gc(xasprintf("%f", exp(2.0))));
  ASSERT_STREQ("6.389056", gc(xasprintf("%f", expm1(2.0))));
  ASSERT_STREQ("6.389056", gc(xasprintf("%f", exp(2.0) - 1.0)));
}
