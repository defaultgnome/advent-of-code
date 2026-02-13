#include "../../intern/dfgn_std.c"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

int main() {
  dfgn_Arena arena = dfgn_Arena_Create(sizeof(u8) * 1024 * 1024 * 1); // 1 MB

  FILE* file;
  char* buffer = (char*)dfgn_Arena_Allocate(&arena, sizeof(char) * MAX_LINE_LENGTH);
  // NOTE: makefile is running from the "c" directory
  dfgn_String filename = DFGN_STRING("../inputs/2025/01_input.txt");

  file = fopen(filename.chars, "r");
  if (file == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  int rotation = 50;
  int zero_count = 0;

  while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
    char direction = buffer[0];
    int num = atoi(buffer + 1);
    if (direction == 'L') {
      rotation -= num;
      while (rotation < 0) {
        rotation += 100;
      }
    }
    else {
      rotation += num;
      while (rotation > 99) {
        rotation -= 100;
      }
    }
    if (rotation == 0) {
      zero_count++;
    }
    // sanity check
    if (rotation < 0 || rotation > 99) {
      printf("rotation is out of bounds: %d\n", rotation);
      return EXIT_FAILURE;
    }
  }

  printf("final rotation: %d\n", rotation);
  printf("final zero count: %d\n", zero_count);
  fclose(file);

  dfgn_Arena_Free(&arena);

  return EXIT_SUCCESS;
}
