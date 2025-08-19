CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

SRC = src/delete.c src/chatbot.c src/lowercase.c src/intention.c main.c
OBJ = $(SRC:.c=.o)
EXEC = chatbot

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
