CC = gcc 
MYDATE=`date`
MYPWD=$(notdir $(PWD))
MYC= $(wildcard *.c) 
MYH= $(wildcard *.h)
MYO= $(MYC:.c=.o)
all:$(MYPWD)
	@echo finish!
	@./$(MYPWD)

dep:
	-rm .depend
	for i in $(MYC); do gcc -MM $$i >> .depend; done
	cat .depend
old:
	gcc -MM main.c > .depend
	gcc -MM add.c >> .depend
	gcc -MM sub.c >> .depend
	gcc -MM div.c >> .depend
	cat .depend

$(MYPWD):$(MYO)
	$(CC)  $^ -o $@

%.o:%.c
	$(CC) -g -c $< -o  $@ 

c clean:
	-rm *.o
	-rm .depend
	-rm $(MYPWD)
	@echo OK
test:
	@echo $(MYPWD)
	@echo $(MYC)
	@echo $(MYH)
	@echo $(MYDATE)
