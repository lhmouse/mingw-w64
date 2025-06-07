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
#include <windows.h>

wint_t btowc (int c)
{
  if (c == EOF)
    return (WEOF);

  unsigned cp = ___lc_codepage_func();

  /* "C" locale */
  if (cp == 0)
    return (unsigned char) c;

  /* Flags to pass to MultiByteToWideChar */
  unsigned flags = 0;

  switch (cp)
  {
    case 50220: /* ISO-2022-JP */
    case 50221: /* ISO-2022-JP */
    case 50222: /* ISO-2022-JP */
    case 50225: /* ISO-2022-KR */
    case 50227: /* ISO-2022-CN */
    case 50229: /* ISO-2022-CN */
    case 57002: /* x-iscii-de  */
    case 57003: /* x-iscii-be  */
    case 57004: /* x-iscii-ta  */
    case 57005: /* x-iscii-te  */
    case 57006: /* x-iscii-as  */
    case 57007: /* x-iscii-or  */
    case 57008: /* x-iscii-ka  */
    case 57009: /* x-iscii-ma  */
    case 57010: /* x-iscii-gu  */
    case 57011: /* x-iscii-pa  */
    case 65000: /* UTF-7       */
      /* no flags allowed */
      break;
    default:
      flags |= MB_ERR_INVALID_CHARS;
  }

  unsigned char ch = c;
  wchar_t wc = WEOF;

  if (!MultiByteToWideChar (cp, flags, (char*)&ch, 1, &wc, 1))
    return WEOF;

  return wc;
}
