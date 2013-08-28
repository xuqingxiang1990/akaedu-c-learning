src = $(wildcard *.c)
obj = $(patsubst %.c, %.o, $(src))
target = main
CC = gcc

$(target): $(obj)
	$(CC) -o $@ $^ 
%.o:%.c
	$(CC) -o $@ -c $< 

clean:
	-rm -f $(target)
	-rm -f $(obj)
	-rm -f *~

.PHONY: clean
