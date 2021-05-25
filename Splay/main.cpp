#include <iostream>
#include <vector>
#include "Splayclass.hpp"

using namespace std;

int main()
{
    Splaytree x;
    vector<int> v{1,5,7,8,10};
    for(int i : v){
        x.push(i);
    }
    x.interval(4, 9);


    return 0;
}
