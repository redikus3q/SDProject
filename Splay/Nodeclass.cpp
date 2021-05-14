#include "Nodeclass.hpp"

using namespace std;

node::node(){
    this->val=0;
    tata=nullptr;
    fiu1=nullptr;
    fiu2=nullptr;
}

node::node(int a){
    this->val=a;
    tata=nullptr;
    fiu1=nullptr;
    fiu2=nullptr;
}

node* node::getfiu1(){
    return this->fiu1;
}

node* node::getfiu2(){
    return this->fiu2;
}

node* node::gettata(){
    return this->tata;
}

int node::getval(){
    return this->val;
}

void node::setfiu1(node* nod){
    this->fiu1=nod;
}
void node::setfiu2(node* nod){
    this->fiu2=nod;
}

void node::settata(node* nod){
    this->tata=nod;
}

void node::setval(int a){
    this->val=a;
}

node::~node(){
    this->val=0;
    this->fiu1=nullptr;
    this->fiu2=nullptr;
    this->tata=nullptr;
}
