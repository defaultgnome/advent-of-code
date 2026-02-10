# --- Environment Setup ---
# Detecting OS to handle file deletion/slashes
ifeq ($(OS),Windows_NT)
		CC = clang
		AR = llvm-ar
    RM = del /Q /F
    FIXPATH = $(subst /,\,$1)
    MKDIR = if not exist $(subst /,\,$1) mkdir $(subst /,\,$1)
else
		CC = cc
		AR = ar
    RM = rm -f
    FIXPATH = $1
    MKDIR = mkdir -p $1
endif

# --- Configuration ---
CFLAGS = -std=c99 -Wall -Wextra -Werror -O2 -g -fsanitize=address

# Usage: make run YEAR=2024 DAY=01
run: build
	 @echo --- Running Day $(YEAR)/$(DAY) ---
	$(call FIXPATH,./$(YEAR)/$(DAY)/solution.exe)

build:
	@echo --- Building Day $(YEAR)/$(DAY) ---
	$(CC) $(CFLAGS) $(YEAR)/$(DAY)/main.c -o $(YEAR)/$(DAY)/solution.exe

# Cleanup
clean:
	$(RM) */*/solution.exe
	@echo Cleaned files.
