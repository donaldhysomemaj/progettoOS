CC=gcc
CCOPTS=--std=gnu99 -Wall -lpthread

BINS=cpu main

#disastros_test

.phony: clean all


all:	$(LIBS) $(BINS)

%.o:	%.c $(HEADERS)
	$(CC) $(CCOPTS) -c -o $@  $<

# main:	main.c $(LIBS)
# 	$(CC) $(CCOPTS) -o $@ $^

# cpu:	cpu.c $(LIBS)
# 	$(CC) $(CCOPTS) -o $@ $^

clean:
	rm -rf *.o *~ $(LIBS) $(BINS)