#include "cmn_merge_sort.hpp"
#include <iostream>
#include <cmath>
#include <time.h>
#include <cstdlib>
#include <algorithm>
static const int k = 512; // Множитель для генератора float

static auto rand_f = []() -> float
{ return static_cast<float>(rand()*1.0f / (RAND_MAX/k))*pow(-1, rand()); };

static void merge(std::vector<float> &v, int l, int mid, int r){
    
    std::vector<float> t;
    int i = l, j = mid;
    while (i < mid && j < r)
    {
        if(v[i] <= v[j]){
            t.push_back(v[i++]);
        }
        else{
            t.push_back(v[j++]);
        }
    }
    while (i < mid)
    {
        t.push_back(v[i++]);
    }
    while (j < r)
    {
        t.push_back(v[j++]);
    }
    
    for(i=l;i<r;++i)
        v[i]=t[i-l];
    
}


void cmnMergeSort(std::vector<float> &v, int l, int r)
{
    if (l + 1 >= r)
    {
        return;
    }
    if(r - l > 64){
        int mid = (l + r) / 2; // l/2+r/2=(r-l)/2+l;
        cmnMergeSort(v, l, mid);
        cmnMergeSort(v, mid, r);
        merge(v, l, mid, r);
    }
    else{
        std::sort(v.begin()+l, v.begin()+r);
    }

}


void VectorGen(std::vector<float> &v){
    for(auto& x: v){
        x = rand_f();
       // std::cout << x << std::endl;
    }
}