PROG=test arraylist
# LIST=$(addprefix $(BIN), $(PROG))

# all: $(LIST)

# $(BIN)%:  $(SOURCE)%.c
# 	$(CC) $(INC) $< $(CFLAGS) -o $@ $(LIBS)

build:
	gcc -Wall -g test.c graph.c arraylist.c -o ./bin/test

clean:
	rm ./bin/*