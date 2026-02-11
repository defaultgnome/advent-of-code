#include "../../intern/dfgn_std.c"
#include <stdio.h>
#include <stdlib.h>

typedef struct User {
  f64 score;
  i32 id;
} User;

void User_Init(User *user) {
  user->id = 0;
  user->score = 0.0;
}

DFGN_ARENA_ALLOCATE_IMPL(User, User)

int main() {
  dfgn_Arena arena = dfgn_Arena_Create(sizeof(User) * 100);

  User *user = dfgn_Arena_AllocateUser(&arena);
  User_Init(user);
  user->score = 3.56;

  dfgn_ArrayI32 array = {
      .items = (i32 *)malloc(sizeof(i32) * 10), .length = 0, .capacity = 10};

  for (usize i = 0; i < array.capacity; i++) {
    array.items[i] = i;
    array.length += 1;
  }

  i32 result = dfgn_ArrayI32_Get(array, 4);
  printf("this is the result %d\n", result);

  dfgn_String myStr = DFGN_STRING("hello world");
  printf("this is the string '%s'\n", myStr.chars);

  dfgn_Arena_Free(&arena);

  return 0;
}
