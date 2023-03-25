CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c99 -pedantic -fprofile-arcs -ftest-coverage

HDR_DIR = include
BIN_DIR = bin
SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = test

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

TEST_SRCS := $(wildcard $(TEST_DIR)/*.c)
TEST_BINS := $(patsubst $(TEST_DIR)/%.c, $(TEST_DIR)/bin/%, $(TEST_SRCS))

NAME = benchsort
VERSION = 1.0.0

.PHONY: all clean check docker coverage

all: $(OBJ_DIR) $(BIN_DIR) $(BIN_DIR)/$(NAME)

$(BIN_DIR)/$(NAME): main.c $(OBJS)
	@echo "> Generating the executable in $@."
	@$(CC) $(CFLAGS) -I $(HDR_DIR) $^ -o $@

$(OBJ_DIR):
	@echo "> Creating $@ directory."
	@mkdir -p $@

$(BIN_DIR):
	@echo "> Creating $@ directory."
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "> Generating $@ from $<."
	@$(CC) $(CFLAGS) -I $(HDR_DIR) -c $< -o $@

$(TEST_DIR)/bin/%: $(TEST_DIR)/%.c $(OBJS)
	@echo "> Generating $@ from $<."
	@$(CC) $(CFLAGS) -I $(HDR_DIR) $< $(OBJS) -o $@ -lcriterion -lgcov

$(TEST_DIR)/bin:
	@echo "> Creating $@ directory."
	@mkdir -p $@

check: $(TEST_DIR)/bin $(TEST_BINS)
	@for test in $(TEST_BINS); do echo "> Running test from $$test."; ./$$test; done

coverage: $(TEST_DIR)/bin $(TEST_BINS)
	@echo "> Generating code coverage report."
	@rm -f *.gcno *.gcda *.gcov
	@for test in $(TEST_BINS); do echo "> Running test with coverage from $$test."; ./$$test; done
	@echo "> Running gcovr to get the coverage."
	@gcovr --xml-pretty --exclude-unreachable-branches --print-summary -o coverage.xml --root .

clean:
	@echo "> Cleaning the project."
	@$(RM) -rf $(OBJ_DIR) $(BIN_DIR) $(TEST_DIR)/bin *.gcno *.gcda *.gcov $(TEST_DIR)/*.gcov

run: all
	@echo "> Running the project in $(BIN)/$(NAME)."
	@./$(BIN_DIR)/$(NAME)

docker:
	@echo "> Building a docker image from version $(VERSION)."
	@docker build -t registry.gitlab.com/olooeez/$(NAME):$(VERSION) .
	@echo "> Pushing new docker image verison $(VERSION) to container registry."
	@docker push registry.gitlab.com/olooeez/$(NAME):$(VERSION)
