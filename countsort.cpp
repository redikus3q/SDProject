#include <bits/stdc++.h>
#include "countsort.hpp"
using namespace std;

void countsort(vector<long long>& a){
    long long mx=a[0]; //max
    long long mi=a[0]; //min
    vector<long long> frecv;
    for(long long i:a){
        if(i>mx){
            mx=i;
        }
        if(i<mi){
            mi=i;
        }
    }
    long long range=llabs(mx-mi);
    frecv.assign(range+1, 0);
    if(range>(long long)1e8){
        throw runtime_error("Range prea mare pentru countsort.");
    }
    for(long long i:a){
        frecv[i-mi]++;
    }
    a.clear();
    for(long long i=0;i<=range;i++){
        while(frecv[i]){
            a.push_back(i+mi);
            frecv[i]--;
        }
    }
    frecv.clear();
    frecv.shrink_to_fit();
}
