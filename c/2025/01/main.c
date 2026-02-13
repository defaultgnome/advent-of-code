#include "../../intern/dfgn_std.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
  dfgn_Arena arena = dfgn_Arena_Create(sizeof(u8) * 1024 * 1024 * 1); // 1 MB

  // TODO: read input file from ../../../inputs/2025/01_input.txt
  // TODO: for each line, print it

  dfgn_Arena_Free(&arena);

  return 0;
}
