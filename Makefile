CC = gcc
CFLAGS = -std=gnu99 -Wall -g -Werror
 
EXECS = dining_philosophers

LDFLAGS = -lpthread

all: $(EXECS)
 
%: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
 
.PHONY: clean
clean:
	/bin/rm -rf $(EXECS) *.o
