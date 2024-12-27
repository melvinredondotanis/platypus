CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -I./include
LDFLAGS = 
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build
TEST_BUILD_DIR = build/tests

# Source files
SRC = $(wildcard $(SRC_DIR)/**/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Test files
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ = $(TEST_SRC:$(TEST_DIR)/%.c=$(TEST_BUILD_DIR)/%.o)
TEST_BINS = $(TEST_SRC:$(TEST_DIR)/%.c=$(TEST_BUILD_DIR)/%)

# Main targets
all: $(BUILD_DIR) $(TEST_BUILD_DIR) tests

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)/types

$(TEST_BUILD_DIR):
	mkdir -p $(TEST_BUILD_DIR)

# Object compilation
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_BUILD_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# $(BUILD_DIR)/types/types.o: $(SRC_DIR)/types/types.c
#	mkdir -p $(BUILD_DIR)/types
#	$(CC) $(CFLAGS) -c $< -o $@

# Test binaries
$(TEST_BUILD_DIR)/%: $(TEST_BUILD_DIR)/%.o $(OBJ)
	$(CC) $^ $(LDFLAGS) -o $@

# Targets
.PHONY: tests clean run-tests

tests: $(TEST_BINS)

run-tests: tests
	@for test in $(TEST_BINS); do \
	    echo "Running $$test..."; \
	    $$test; \
	done

clean:
	rm -rf $(BUILD_DIR)

# Dependencies
-include $(OBJ:.o=.d)
-include $(TEST_OBJ:.o=.d)
