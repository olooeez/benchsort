CC=gcc

CFLAGS=-Wall -Wextra -Werror -g

SRC=src
OBJ=obj
BIN=bin
HDR=include

SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

NAME=$(BIN)/benchsort

all: $(OBJ) $(BIN) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HDR)

$(OBJ):
	mkdir $@

$(BIN):
	mkdir $@

clean:
	rm -rf $(BIN) $(OBJ)

run: all
	./$(NAME)
