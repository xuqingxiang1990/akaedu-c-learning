CC = gcc
#TEST := $(CC)
#TEST := abc 
CC = cc
#TEST += $(CC)
TEST ?= 123 
TEST := $(TEST)$(CC)

CC = cc
all: main 
	./main
	echo finish	
	echo $(TEST)
main: main.o sub.o div.o 
	$(CC) $^ -g -o $@
%.o:%.c
	$(CC) -g -c  $<  -o $@
	
.PHONY: clean
c clean:
	-rm main *.o
	@echo clean ok	
