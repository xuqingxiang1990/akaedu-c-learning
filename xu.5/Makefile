main:main.o add.o sub.o mul.o div.o
	gcc main.o add.o sub.o mul.o div.o -o main
main.o:main.c head.h
	gcc -c main.c

add.o:add.c head.h
	gcc -c add.c
sub.o:sub.c head.h
	gcc -c sub.c

mul.o:mul.c head.h
	gcc -c mul.c
div.o:div.c head.h
	gcc -c div.c
clean:
	@echo "cleanning project"
	-rm main *.o
	@echo "clean completed"
