#ifndef SPLAYCLASS_HPP_INCLUDED
#define SPLAYCLASS_HPP_INCLUDED
#include "Nodeclass.hpp"
class Splaytree{

    node* radacina;

public:
    Splaytree();
    Splaytree(int x);
    void push(int x);
    void inorder(int x, int y);
    void preorder();
    void postorder();
    void splay(node* nod);
    node* getradacina();
    void right(node* nod);
    void left(node* nod);
    node* search(int x);
    bool remove(int x);
    node* predecessor(int x);
    node* successor(int x);
    void interval(int x, int y);
};

#endif
