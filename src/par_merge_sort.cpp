#include "par_merge_sort.hpp"

static void merge(std::vector<float> &v, int l, int mid, int r){
    //vl = v[l;mid], vr = v[mid,r]
    
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
    

    return;

}


void parMergeSort(std::vector<float> &v, int l, int r, int depth, int numTreads){
    if (l + 1 >= r)
    {
        return;
    }
    
    //std::cout << omp_get_thread_ << '\n';
    int mid = (l + r) / 2, leftTreads, rightTreads; // l/2+r/2=(r-l)/2+l;
    leftTreads = numTreads/2;
    rightTreads = numTreads - leftTreads;
    
    omp_set_num_threads(numTreads);
    #pragma omp parallel 
    {
        //std::cout << omp_get_num_threads() << '\n';

   #pragma omp task
    {
            //std::cout << omp_get_thread_num() << '\n';
            parMergeSort(v, l, mid, depth+1, leftTreads);
    }


    #pragma omp task
    {
            //std::cout << omp_get_thread_num() << '\n';
            parMergeSort(v, mid, r, depth+1, rightTreads);
    } 

    
    }
    merge(v, l, mid, r);
}