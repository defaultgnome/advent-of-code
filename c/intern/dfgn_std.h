/*
 * === DefaultGnome's Standard Library ===
 */
#ifndef INCLUDE_DFGN_STD_H
#define INCLUDE_DFGN_STD_H

#include <signal.h>
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

//---Debug
#if defined(_MSC_VER)
#define TRAP() __debugbreak()
#elif defined(__GNUC__) || defined(__clang__)
#define TRAP() __builtin_trap()
#else
#define TRAP() raise(SIGTRAP) // Fallback
#endif

//---Arena

// Rather than creating it by hand, it's easier to use
// dfgn_CreateArenaWithCapacityAndMemory()
typedef struct dfgn_Arena {
  usize nextAllocation;
  usize capacity;
  u8 *memory;
} dfgn_Arena;

dfgn_Arena dfgn_CreateArenaWithCapacityAndMemory(usize capacity,
                                                 anyopaque memory);

//---Arrays

#define DFGN_ARRAY_DEFINE(typeName, arrayName)                                 \
  typedef struct arrayName {                                                   \
    typeName *items;                                                           \
    usize length;                                                              \
    usize capacity;                                                            \
  } arrayName;                                                                 \
                                                                               \
  typeName arrayName##_Get(arrayName array, usize index);

#define DFGN_ARRAY_IMPL(typeName, arrayName)                                   \
  typeName arrayName##_Get(arrayName array, usize index) {                     \
    if (index >= 0 && index < array.length) {                                  \
      return array.items[index];                                               \
    }                                                                          \
    TRAP();                                                                    \
    return 0;                                                                  \
  }

DFGN_ARRAY_DEFINE(i32, ArrayI32);

//---Strings
typedef struct dfgn_String {
  char *chars;
  usize length;
} dfgn_String;

#define DFGN__STRING_LENGTH(s) ((sizeof(s) / sizeof((s)[0])) - sizeof((s)[0]))
#define DFGN_STRING(str) {.chars = str, .length = DFGN__STRING_LENGTH(str)}

#endif // INCLUDE_DFGN_STD_H
