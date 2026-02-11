/*
 * === DefaultGnome's Standard Library ===
 * this is the implementaion of the lib, import only once
 */
#include "./dfgn_std.h"

//---Arrays
DFGN_ARRAY_IMPL(i32, ArrayI32);

//---Arena
dfgn_Arena dfgn_CreateArenaWithCapacityAndMemory(usize capacity,
                                                 anyopaque memory) {
  dfgn_Arena arena = {.capacity = capacity, .memory = (u8 *)memory};
  return arena;
}
