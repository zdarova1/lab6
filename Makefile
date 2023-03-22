main: main.cpp cmn_merge_sort.o par_merge_sort.o
	g++ main.cpp cmn_merge_sort.o par_merge_sort.o -o main -fopenmp -D OMP_NUM_THREADS=4


cmn_merge_sort.o: src\cmn_merge_sort.cpp
	g++ -c src\cmn_merge_sort.cpp

par_merge_sort.o: src\par_merge_sort.cpp
	g++ -c src\par_merge_sort.cpp

test.o: src\test.cpp
	g++ -c src\test.cpp



clean:
	erase *.o 
	erase *.exe 

	
	