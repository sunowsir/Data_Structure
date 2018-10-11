++ = g++
gw = -g -Wall
mainobjs = main.o selection.o sequential_search.o hash_search.o binarytree_search.o

.PHONY: clean

main: $(mainobjs)
	$(++) $(gw) -o main $(mainobjs)

sequential_search.o: sequential_search.cpp main.h
	$(++) $(gw) -c -o sequential_search.o sequential_search.cpp

hash_search.o: hash_search.cpp main.h
	$(++) $(gw) -c -o hash_search.o hash_search.cpp

binarytree_search.o: binarytree_search.cpp main.h
	$(++) $(gw) -c -o binarytree_search.o binarytree_search.cpp

selection.o: selection.cpp main.h
	$(++) $(gw) -c -o selection.o selection.cpp

main.o: main.cpp main.h
	$(++) $(gw) -c -o main.o main.cpp

clean:
	rm -f $(mainobjs) main
