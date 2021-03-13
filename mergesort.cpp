#include <bits/stdc++.h>
#include "mergesort.hpp"

using namespace std;

void merg1(vector<long long>& a, long long s, long long d, long long m){

    vector<long long> st(a.begin()+s, a.begin()+m+1);
    vector<long long> dr(a.begin()+m+1, a.begin()+d+1);
    long long i=0; long long j=0; long long k=s;
    while(i<st.size() && j<dr.size()){
        if(st[i]<=dr[j]){
            a[k]=st[i];
            i++;
        }
        else{
            a[k]=dr[j];
            j++;
        }
        k++;
    }
    while(i<st.size()){
        a[k]=st[i];
        i++;k++;
    }
    while(j<dr.size()){
        a[k]=dr[j];
        j++;k++;
    }
    st.clear();
    dr.clear();
}

void msort(vector<long long>& a, long long s, long long d){

    if(d<=s){
        return;
    }
    long long m=s+(d-s)/2;
    msort(a, s, m);
    msort(a, m+1, d);
    merg1(a, s, d, m);

}

void mergesort(vector<long long>& a){
    msort(a,0,a.size()-1);

}
