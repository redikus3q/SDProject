#ifndef NODECLASS_HPP_INCLUDED
#define NODECLASS_HPP_INCLUDED

class node{

    int val;
    node* tata;
    node* fiu1;
    node* fiu2;

public:
    node();
    node(int a);
    node* getfiu1();
    node* getfiu2();
    node* gettata();
    int getval();
    void setfiu1(node* nod);
    void setfiu2(node* nod);
    void settata(node* nod);
    void setval(int a);
    ~node();

};

#endif
