#include <bits/stdc++.h>
#include "bubblesort.hpp"
using namespace std;

void bubblesort(vector<long long>& a){
    if(a.size()>1e4){
        throw runtime_error("Vector prea mare.");
    }
    bool b=0; //sortat?
    while(b==0){
        b=1;
        for(long long i=0;i<a.size()-1;i++){
            if(a[i]>a[i+1]){
                swap(a[i], a[i+1]);
                b=0;
            }
        }
    }

}
