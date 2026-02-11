#include "../../intern/dfgn_std.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
  ArrayI32 array = {
      .items = (i32 *)malloc(sizeof(i32) * 10), .length = 10, .capacity = 10};

  for (usize i = 0; i < array.length; i++) {
    array.items[i] = i;
  }

  i32 result = ArrayI32_Get(array, 4);
  printf("this is the result %d\n", result);

  dfgn_String myStr = DFGN_STRING("hello world");
  printf("this is the string '%s'\n", myStr.chars);

  return 0;
}
