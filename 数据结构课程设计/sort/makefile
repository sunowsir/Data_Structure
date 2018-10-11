++ = g++
gw = -g -Wall

mainobjs = main.o insert_sort.o merge_sort.o shell_sort.o quick_sort.o swap.o bubble_sort.o selection.o heap_sort.o selection_sort.o output.o

.PHONY: clean

main: $(mainobjs)
	$(++) $(gw) -o main $(mainobjs)

swap.o: swap.cpp main.h
	$(++) $(gw) -c -o swap.o swap.cpp

insert_sort.o: insert_sort.cpp main.h
	$(++) $(gw) -c -o insert_sort.o insert_sort.cpp

merge_sort.o: merge_sort.cpp main.h
	$(++) $(gw) -c -o merge_sort.o merge_sort.cpp

shell_sort.o: shell_sort.cpp main.h
	$(++) $(gw) -c -o shell_sort.o shell_sort.cpp

quick_sort.o: quick_sort.cpp main.h
	$(++) $(gw) -c -o quick_sort.o quick_sort.cpp

bubble_sort.o: bubble_sort.cpp main.h
	$(++) $(gw) -c -o bubble_sort.o bubble_sort.cpp

heap_sort.o: heap_sort.cpp main.h
	$(++) $(gw) -c -o heap_sort.o heap_sort.cpp

selection_sort.o: selection_sort.cpp main.h
	$(++) $(gw) -c -o selection_sort.o selection_sort.cpp

output.o: output.cpp main.h
	$(++) $(gw) -c -o output.o output.cpp

selection.o: selection.cpp main.h
	$(++) $(gw) -c -o selection.o selection.cpp

main.o: main.cpp main.h
	$(++) $(gw) -c -o main.o main.cpp

clean:
	rm -f $(mainobjs) main
