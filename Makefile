CC = gcc
CFLAGS = -Wall -Wno-unused-result -g -Og -I include
SRC_DIR = src
WIP_FLAGS = -fsanitize=address

MAIN_SRC=compiler.c
SRC_PATH= $(SRC_DIR)/$(MAIN_SRC)

BIN_FINAL = compiler-program-final
BIN_WIP = compiler-program-wip

all: $(BIN_FINAL) $(BIN_WIP)

$(BIN_WIP): $(SRC_PATH)
	$(CC) $(CFLAGS) $(WIP_FLAGS) -o $@ $^

$(BIN_FINAL): $(SRC_PATH)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(BIN_WIP) $(BIN_FINAL)
