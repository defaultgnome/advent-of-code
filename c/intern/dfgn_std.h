/*
 * === DefaultGnome's Standard Library ===
 * this is made STB-style, you should decalre the implementation
 * `DFGN_STD_IMPLEMENTAION` in ONLY ONE of the file you are including this file
 * in.
 */
#ifndef INCLUDE_DFGN_STD_H
#define INCLUDE_DFGN_STD_H

#include <stddef.h>
#include <stdint.h>

#define internal static
#define local_persist static
#define global_variable static

// Nice Types
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef i32 bool32;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

typedef size_t usize;
typedef ptrdiff_t isize;

typedef void *anyopaque;

// Arena

// Arrays

#define DFGN_ARRAY_DEFINE(typeName, arrayName)                                 \
  typedef struct {                                                             \
    typeName *items;                                                           \
    usize length;                                                              \
    usize capacity;                                                            \
  } arrayName;

// TODO: add DFGN_ prefix everywhere
DFGN_ARRAY_DEFINE(i32, ArrayI32);

// TODO: add this to DEFINE
i32 ArrayI32_Get(ArrayI32 array, usize index);

// Strings
typedef struct {
  char *chars;
  usize length;
} String;

#define DFGN__STRING_LENGTH(s) ((sizeof(s) / sizeof((s)[0])) - sizeof((s)[0]))
#define DFGN_STRING(str) {.chars = str, .length = DFGN__STRING_LENGTH(str)}

#endif // INCLUDE_DFGN_STD_H

// FIXME: remove this #define
// #define DFGN_STD_IMPLEMENTAION

#ifdef DFGN_STD_IMPLEMENTAION

#include <signal.h>
#include <sys/signal.h>

// TODO: create macro for DFGN_ARRAY_FUNCTIONS
i32 ArrayI32_Get(ArrayI32 array, usize index) {
  if (index >= 0 && index < array.length) {
    return array.items[index];
  }
  raise(SIGTRAP);
  return 0;
}

#endif // DFGN_STD_IMPLEMENTAION
