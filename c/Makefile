# --- Configuration ---
CFLAGS = -std=c99 -Wall -Wextra -Werror -O2 -g
# Detecting OS to handle file deletion/slashes
ifeq ($(OS),Windows_NT)
		CC = clang
		AR = llvm-ar
		RM = del /Q /F
		FIXPATH = $(subst /,\,$1)
		MKDIR = if not exist "$(subst /,\,$1)" mkdir "$(subst /,\,$1)"
		EXT = .exe
else
		CC = cc
		AR = ar
		RM = rm -f
		FIXPATH = $1
		MKDIR = mkdir -p $1
		EXT =
		CFLAGS += -fsanitize=address
endif

# Usage: make run YEAR=2024 DAY=01
run: build
	@echo --- Running Day $(YEAR)/$(DAY) ---
	$(call FIXPATH,./$(YEAR)/$(DAY)/build/main$(EXT))

build:
	@echo --- Building Day $(YEAR)/$(DAY) ---
	@$(call MKDIR,$(YEAR)/$(DAY)/build)
	$(CC) $(CFLAGS) $(YEAR)/$(DAY)/main.c -o $(YEAR)/$(DAY)/build/main$(EXT)

# Cleanup
clean:
	$(RM) */*/build/main$(EXT)
	@echo Cleaned files.
