// #include "src/test.cpp"
#include <string>
#include <immintrin.h>
#include <iostream>
#include "src/test.cpp"
#include "src/cmn_merge_sort.hpp"
#include "src/par_merge_sort.hpp"

using namespace std;

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    int result, F_1, F_2;
#pragma omp parallel
    {
        
#pragma omp single
        {
#pragma omp task shared(F_1)
            F_1 = fib(n - 1);
#pragma omp task shared(F_2)
            F_2 = fib(n - 2);
#pragma omp taskwait
            result = F_1 + F_2;
        }
    }
    return result;
}




int main(int argc, char **argv)
{
   //omp_set_dynamic(0);
    
    std::string s(argv[1]);
// print_mm256i(x);
    cmn_test(std::stoi(s));


    return 0;
}