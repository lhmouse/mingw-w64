/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include "mb_wc_common.h"
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <windows.h>

/* Return just the first byte after translating to multibyte.  */
int wctob (wint_t wc)
{
  unsigned cp = ___lc_codepage_func();

  /* "C" locale */
  if (cp == 0)
    return wc <= 0xFF ? wc : EOF;

  wchar_t w = wc;
  char c;
  /* Will be set to 1 if conversion failed */
  int failed = 0;

  /* Do not use WC_NO_BEST_FIT_CHARS, CRT performs best-fit conversion */
  if (!WideCharToMultiByte (cp, 0, &w, 1, &c, 1, NULL, &failed) || failed)
    return EOF;

  return (unsigned char) c;
}
