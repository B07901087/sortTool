
CC = g++
CFLAGS = -c


OPTFLAGS = -O2

all	: bin/NTU_sort
	@echo -n ""

# optimized version
bin/NTU_sort	: sort.o main.o 
			$(CC) $(OPTFLAGS) sort.o main.o -o $@
main.o 	: src/main.cpp 
			$(CC) $(CFLAGS) $< -o $@
sort.o	: src/sort_tool.cpp src/sort_tool.h
			$(CC) $(CFLAGS)  $< -o $@ 
			 


clean:
		rm -rf *.o  bin/*

