export CC=	g++
export CFLAGS=	-W -Wall -ansi -pedantic
export LFLAGS=	-lsfml-network -lsfml-system
BIN_DIR=	./bin/
SRC_DIR=	./src/
INCLUDE_DIR=	./include/

all: server

debug: CFLAGS += -g3
debug: all

server:
	@(cd $(SRC_DIR) && $(MAKE))
	@(rm -rf bin/)
	@(mkdir bin/)
	@(mv $(SRC_DIR)server $(BIN_DIR))

.PHONY: clean mrproper $(EXEC)

clean:
	@(cd $(SRC_DIR) && $(MAKE) $@)

mrproper: clean
	@(cd $(BIN_DIR) && rm server)
