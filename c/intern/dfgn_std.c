/*
 * === DefaultGnome's Standard Library ===
 * this is the implementaion of the lib, import only once
 */
#include "./dfgn_std.h"
#include <stdlib.h>

//---Arrays
DFGN_ARRAY_IMPL(i32, dfgn_ArrayI32);

//---Arena
dfgn_Arena dfgn_Arena_Create(usize capacity) {
  anyopaque memory = malloc(capacity);
  dfgn_Arena arena = {.capacity = capacity, .memory = memory, .ptr = memory};
  return arena;
}

usize dfgn_Arena_GetCapacityLeft(dfgn_Arena arena) {
  return ((arena.memory + arena.capacity) - arena.ptr);
}

void dfgn_Arena_Reset(dfgn_Arena *arena) { arena->ptr = arena->memory; }

void dfgn_Arena_Free(dfgn_Arena *arena) { free(arena->memory); }

DFGN_ARENA_ALLOCATE_IMPL(i32, I32);
