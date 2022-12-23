#Current make system
BIN=./bin/
SOURCE=./
CFLAGS=-lncurses

PROG=ADD1 ADD2 ADD3
LIST=$(addprefix $(BIN), $(PROG))

all: $(LIST)

$(BIN)%:  $(SOURCE)%.c
	$(CC) $(INC) $< $(CFLAGS) -o $@ $(LIBS)

clean:
	rm ./bin/*