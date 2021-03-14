#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <chrono>
#include <bits/stdc++.h>
#include "bubblesort.hpp"
#include "countsort.hpp"
#include "radixsort.hpp"
#include "mergesort.hpp"
#include "quicksort.hpp"
using namespace std;

ofstream out("date_medie_teste/test5.out");

bool validate(vector<long long> a){
    vector<long long> b=a;
    sort(a.begin(), a.begin()+a.size());
    for(long long i=0;i<a.size();i++){
        if(a[i]!=b[i]){
            return 0;
        }
    }
    return 1;
}

void showtime(auto duration, vector<long long> a){

    if(validate(a)==1){
        double time_to_sort = (std::chrono::duration_cast<std::chrono::microseconds>(duration).count())/1e6;
        cout<<time_to_sort<<'s'<<endl;
        out<<time_to_sort<<endl;
        return;
    }
    cout<<"Nu";

}

void functions(vector<long long> a){
        vector<long long> ca=a;
        cout<<"Bubblesort: ";
        auto before = std::chrono::steady_clock::now();
        auto after = std::chrono::steady_clock::now(); ///sa fim siguri ca initializat chiar daca bubble nu merge
        try{
            before = std::chrono::steady_clock::now(); ///incep de aici before ca nu cumva sa duca in eroare la timp operatiile facute de dupa anteriorul before
            bubblesort(a);
            after = std::chrono::steady_clock::now();
            showtime(after-before, a);
        }
        catch(...){
            out<<0<<endl;
            cout<<"Vector prea mare pentru bubblesort. Pentru 1e5 numere ia peste un minut (~73s)."<<endl;
        }

        a=ca;
        cout<<"Mergesort: ";
        before = std::chrono::steady_clock::now();
        mergesort(a);
        after = std::chrono::steady_clock::now();
        showtime(after-before, a);

        a=ca;
        cout<<"Radixsort baza 10: ";
        before = std::chrono::steady_clock::now();
        radixsort(a, 2);
        after = std::chrono::steady_clock::now();
        showtime(after-before, a);

        a=ca;
        cout<<"Radixsort baza 2: ";
        before = std::chrono::steady_clock::now();
        radixsort(a, 2);
        after = std::chrono::steady_clock::now();
        showtime(after-before, a);

        a=ca;
        cout<<"Radixsort baza 256: ";
        before = std::chrono::steady_clock::now();
        radixsort(a, 256);
        after = std::chrono::steady_clock::now();
        showtime(after-before, a);

        a=ca;
        cout<<"Countsort: ";
        try{
            before = std::chrono::steady_clock::now();
            countsort(a);
            after = std::chrono::steady_clock::now();
            showtime(after-before, a);
        }
        catch(...){
            out<<0<<endl;
            cout<<"Interval prea mare pentru countsort."<<endl;
        }

        a=ca;
        cout<<"Quicksort pivot ultimul element: ";
        try{
            before = std::chrono::steady_clock::now();
            quicksort(a, 0);
            after = std::chrono::steady_clock::now();
            showtime(after-before, a);
        }
        catch(...){
            out<<0<<endl;
            cout<<"Vector prea mare pentru acest pivot. ~8s pentru 1e6 numere."<<endl;
        }

        a=ca;
        cout<<"Quicksort pivot mediana de 3: ";
        before = std::chrono::steady_clock::now();
        quicksort(a, 1);
        after = std::chrono::steady_clock::now();
        showtime(after-before, a);

        a=ca;
        cout<<"Quicksort pivot random: ";
        try{
            before = std::chrono::steady_clock::now();
            quicksort(a, 2);
            after = std::chrono::steady_clock::now();
            showtime(after-before, a);
        }
        catch(...){
            out<<0<<endl;
            cout<<"Vector prea mare pentru acest pivot. ~8s pentru 1e6 numere."<<endl;
        }

        a=ca;
        cout<<"STL Sort: ";
        before = std::chrono::steady_clock::now();
        sort(a.begin(), a.end());
        after = std::chrono::steady_clock::now();
        showtime(after-before, a);

}

void printa(vector<long long> a){
    for(auto i:a){
        cout<<i<<" ";
    }
}

void generator(vector<long long>& a, long long mi, long long mx, int n){

    if(n>1e8){
        return;
    }
    if(mi<-1e16 || mx>1e16){
        return;
    }
    a.clear();
    a.shrink_to_fit();
    random_device rd;
    mt19937 rnd(rd());
    uniform_int_distribution<long long> dist(mi, mx);
    a.push_back(mi+1);
    a.push_back(mx-1); ///pentru a face countsortul sa nu mearga pe unele cazuri, pentru a elimina din randomness
    for(int i=0; i<n-2;i++){
        a.push_back(dist(rnd));
    }

}

int main(){
    //Vector crescator test.
    cout<<"Teste pentru un vector strict crescator de 1e4 elemente:"<<endl;
    vector<long long> a(1e4);
    iota(a.begin(), a.end(), 0);
    functions(a);

    //Vector descrescator test.
    cout<<endl<<"Teste pentru un vector strict descrescator de 1e4 elemente:"<<endl;
    int i=9999;
    generate(a.begin(), a.end(), [&i]() {int n=i;i--;return n;});
    functions(a);

    //Vector constant test.
    cout<<endl<<"Teste pentru un vector constant de 1e4 elemente:"<<endl;
    generate(a.begin(), a.end(), [](){return 5;});
    functions(a);

    //RND1
    cout<<endl<<"Teste pentru un vector de 1e4 elemente intre -1e4 si 1e4:"<<endl;
    generator(a, -1e4, 1e4, 1e4);
    functions(a);

    //RND1EXTRA
    ///Pt a observa daca semnul are de-aface cu timpul.
    cout<<endl<<"Teste pentru un vector de 1e4 elemente pozitive intre 0 si 1e8:"<<endl;
    generator(a, 0, 1e8, 1e4);
    functions(a);

    //RND2
    cout<<endl<<"Teste pentru un vector de 1e4 elemente intre -1e8 si 1e8:"<<endl;
    generator(a, -1e8, 1e8, 1e4);
    functions(a);

    //RND3
    cout<<endl<<"Teste pentru un vector de 1e4 elemente intre -1e16 si 1e16:"<<endl;
    generator(a, -1e16, 1e16, 1e4);
    functions(a);

    //RND4
    cout<<endl<<"Teste pentru un vector de 1e6 elemente intre -1e4 si 1e4:"<<endl;
    generator(a, -1e4, 1e4, 1e6);
    functions(a);

    //RND5
    cout<<endl<<"Teste pentru un vector de 1e6 elemente intre -1e8 si 1e8:"<<endl;
    generator(a, -1e8, 1e8, 1e6);
    functions(a);

    //RND6
    cout<<endl<<"Teste pentru un vector de 1e6 elemente intre -1e16 si 1e16:"<<endl;
    generator(a, -1e16, 1e16, 1e6);
    functions(a);

    //RND7
    cout<<endl<<"Teste pentru un vector de 1e7 elemente intre -1e16 si 1e16:"<<endl;
    generator(a, -1e16, 1e16, 1e7);
    functions(a);

    //RND8
    cout<<endl<<"Teste pentru un vector de 1e7 elemente pozitive intre 0 si 1e16:"<<endl;
    generator(a, 0, 1e16, 1e7);
    functions(a);

    //RND9
    cout<<endl<<"Teste pentru un vector de 1e5 elemente pozitive intre 0 si 1e3:"<<endl;
    generator(a, 0, 1e3, 1e5);
    functions(a);

    out.close();

}
