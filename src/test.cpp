#include "cmn_merge_sort.hpp"
#include "par_merge_sort.hpp"
#include <chrono>
#include <iostream>
#ifndef OMP_NUM_THREADS
    #define OMP_NUM_THREADS 4

    #endif
//const int size = 100; 
void cmn_test(int size){
    std::vector<float> v(size), x;
   
    srand((unsigned) time(0));
    VectorGen(v);
    x = v;
    auto begin = std::chrono::high_resolution_clock::now();
    //omp_set_dynamic(0);
   // omp_set_nested(1);
    //omp_set_num_threads(4);
   
    std::cout << omp_get_num_threads() << std::endl;
    parMergeSort(x, 0, size, 0, 4);
    //func(v, 0, size);
    auto end = std::chrono::high_resolution_clock::now();
    auto measured_time= std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    
    std::cout << "Measured time: " << measured_time.count()/(1000.0f) << " s\n";

    x=v;
    begin = std::chrono::high_resolution_clock::now();
    
    cmnMergeSort(x, 0, size);
    //func(v, 0, size);
    end = std::chrono::high_resolution_clock::now();
    measured_time= std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    // for(auto& xa: x){
    //     std::cout << xa << ' ';
    // }
    std::cout << std::endl;
    std::cout << "Measured time: " << measured_time.count()/(1000.0f) << " s\n";
}
