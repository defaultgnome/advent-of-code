#include "../../intern/dfgn_std.c"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

enum PasswordMethod {
  PASSWORD_METHOD_NORMAL,
  PASSWORD_METHOD_0x434C49434B,
};

int main() {
  dfgn_Arena arena = dfgn_Arena_Create(sizeof(u8) * 1024 * 1024 * 1); // 1 MB

  FILE* file;
  char* buffer = (char*)dfgn_Arena_Allocate(&arena, sizeof(char) * MAX_LINE_LENGTH);
  // NOTE: makefile is running from the "c" directory
  dfgn_String filename = DFGN_STRING("../inputs/2025/01_input.txt");
  // dfgn_String filename = DFGN_STRING("../inputs/2025/01_example.txt");

  file = fopen(filename.chars, "r");
  if (file == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  int password_method = PASSWORD_METHOD_0x434C49434B;
  int rotation = 50;
  int zero_count = 0;

  while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
    printf("\n---Rotation: %d\n", rotation);
    char direction = buffer[0];
    int num = atoi(buffer + 1);
    printf("OP: %c %d\n", direction, num);
    int mult = direction == 'L' ? -1 : 1;
    int was_zero = rotation == 0;
    rotation += num * mult;
    printf("New Rotation: %d\n", rotation);
    while (rotation < 0 || rotation > 99) {
      printf("Rotation is out of bounds: %d\n", rotation);
      rotation += 100 * -1 * mult;
      printf("New Rotation: %d\n", rotation);
      if (password_method == PASSWORD_METHOD_0x434C49434B && rotation != 0 && !was_zero) {
        zero_count++;
        printf("Overclock count: %d\n", zero_count);
      }
    }
    if (rotation == 0) {
      zero_count++;
      printf("Rotation is 0: %d\n", rotation);
      printf("Overclock count: %d\n", zero_count);
    }
    // sanity check
    if (rotation < 0 || rotation > 99) {
      printf("rotation is out of bounds: %d\n", rotation);
      return EXIT_FAILURE;
    }
  }

  printf("End Password Method: %s\n", password_method == PASSWORD_METHOD_NORMAL ? "NORMAL" : "0x434C49434B");
  printf("End Rotation: %d\n", rotation);
  printf("End Zero Count: %d\n", zero_count);
  fclose(file);

  dfgn_Arena_Free(&arena);

  return EXIT_SUCCESS;
}
