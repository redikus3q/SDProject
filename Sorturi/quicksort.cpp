#include <bits/stdc++.h>
#include "quicksort.hpp"

using namespace std;

long long medianof3(vector<long long>& a, long long s, long long d){

    long long m=(s+d)/2;
    if(a[s]>a[m]){
        swap(a[s],a[m]);
    }
    if(a[s]>a[d]){
        swap(a[s], a[d]);
    }
    if(a[m]>a[d]){
        swap(a[m], a[d]);
    }
    swap(a[m],a[d]);
    return a[d];

}

long long pivot(vector<long long>& a, long long s, long long d, long long piv){
    long long p;
    if(piv==0){
        if(a.size()>1e4){
            throw runtime_error("Vector prea mare.");
        }
        p=a[d];
    }
    if(piv==1){
        p=medianof3(a,s,d);
    }
    else{
        if(a.size()>1e4){
            throw runtime_error("Vector prea mare.");
        }
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<long long> dist(s, d);
        swap(a[dist(gen)],a[d]);
        p=a[d];
    }
    long long i=s;
    for(long long j=s; j<d; j++){
        if(a[j]<p){
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[d]);
    return i;
}

void qsort(vector<long long>& a, long long s, long long d, long long piv){

    if(s>=d){
        return;
    }
    long long p=pivot(a,s,d, piv);
    qsort(a,s,p-1, piv);
    qsort(a,p+1,d, piv);

}

void quicksort(vector<long long>& a, long long piv){

    qsort(a, 0, a.size()-1, piv);

}
