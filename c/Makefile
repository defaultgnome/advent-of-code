# --- Environment Setup ---
# Detecting OS to handle file deletion/slashes
ifeq ($(OS),Windows_NT)
    RM = del /Q /F
    FIXPATH = $(subst /,\,$1)
    MKDIR = if not exist $(subst /,\,$1) mkdir $(subst /,\,$1)
    LIB_NAME = utils.lib
else
    RM = rm -f
    FIXPATH = $1
    MKDIR = mkdir -p $1
    LIB_NAME = libutils.a
endif

# --- Configuration ---
CC = clang
AR = llvm-ar
CFLAGS = -Wall -Wextra -O2 -I./libutils/include
LDFLAGS = -L./libutils -lutils

# Paths
LIB_DIR = libutils
LIB_SRC = $(wildcard $(LIB_DIR)/src/*.c)
LIB_OBJ = $(LIB_SRC:.c=.o)
STATIC_LIB = $(LIB_DIR)/$(LIB_NAME)

# Usage: make run YEAR=2024 DAY=01
run: build
	@echo --- Running Day $(DAY) ($(YEAR)) ---
	$(call FIXPATH,./$(YEAR)/$(DAY)/solution.exe)

build: $(STATIC_LIB)
	@echo --- Building Day $(DAY) ---
	$(CC) $(CFLAGS) $(YEAR)/$(DAY)/main.c -o $(YEAR)/$(DAY)/solution.exe $(LDFLAGS)

# Build the utility library
$(STATIC_LIB): $(LIB_OBJ)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleanup
clean:
	$(RM) $(call FIXPATH,$(LIB_OBJ))
	$(RM) $(call FIXPATH,$(STATIC_LIB))
	@echo Cleaned library files.
