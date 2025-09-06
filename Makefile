CC = gcc
CFLAGS = -Wall -I src
WIP_FLAGS = -fsanitize=address

SRC= main.c

BIN_FINAL = compiler-program-final
BIN_WIP = compiler-program-wip

all: $(BIN_FINAL)

$(BIN_WIP): $(SRC)
	$(CC) $(CFLAGS) $(WIP_FLAGS) -o $(BIN_WIP) $(SRC)

$(BIN_FINAL): $(SRC)
	$(CC) $(CFLAGS) -o $(BIN_FINAL) $(SRC)

clean:
	rm -f $(BIN_WIP) $(BIN_FINAL)
