exce.o : main.c   threadpool.c threadpool.h
	gcc -Wall main.c  threadpool.c -o exce.o -lpthread

.PHONY : clean
clean :
	rm exce.o 