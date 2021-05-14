#include <bits/stdc++.h>
#include "radixsort.hpp"
using namespace std;

void count1(vector<long long>& a, long long d, long long baza){
    long long c;
    vector<long long> frecv;
    frecv.assign(baza, 0);
    vector<long long> ccout;
    ccout.assign(a.size(), 0);
    for(long long i:a){
        frecv[(llabs(i)/d)%baza]++;
    }
    for(long long i=1;i<baza;i++){
        frecv[i]+=frecv[i-1];
    }
    for(long long i=a.size()-1;i>=0;i--){
        c=a[i];
        ccout[frecv[(llabs(c)/d)%baza]-1]=c;
        frecv[(llabs(c)/d)%baza]--;
    }
    a=ccout;
}

void countneg(vector<long long>& a){
    long long c;
    vector<long long> frecv;
    frecv.assign(2, 0);
    vector<long long> ccout;
    ccout.assign(a.size(), 0);
    for(long long i:a){
        if(i>0){
            frecv[1]++;
        }
        else{
            frecv[0]++;
        }
    }
    frecv[1]+=frecv[0];
    long long cfrec=frecv[0];
    for(long long i=a.size()-1;i>=0;i--){
        c=a[i];
        if(c>0){
            ccout[frecv[1]-1]=c;
            frecv[1]--;
        }
        else{
            ccout[cfrec-(frecv[0]-1)-1]=c;
            frecv[0]--;
        }
    }
    a=ccout;
}

void radixsort(vector<long long>& a, long long baza){
    long long mx=a[0];
    long long ng=0;
    for(long long i:a){
        if(i>mx){
            mx=i;
        }
        if(i<0){
            ng=1;
        }
    }
    long long d=1;
    while(d<mx){
        count1(a, d, baza);
        d*=baza;
    }
    if(ng==1){
        countneg(a);
    }
}
