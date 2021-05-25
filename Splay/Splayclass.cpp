#include "Splayclass.hpp"
#include <iostream>
using namespace std;

Splaytree::Splaytree(){
    this->radacina=nullptr;
}

Splaytree::Splaytree(int x){
    node * nod = new node(x);
    this->radacina=nod;
}

void Splaytree::push(int x){
    node* nod = new node(x);
    if(this->radacina==nullptr){
        this->radacina=nod;
    }
    else{
        node* act = this->radacina;
        while(act!=nullptr){
            nod->settata(act);
            if(act->getval() > x){
                act = act->getfiu1();
            }
            else{
                act = act->getfiu2();
            }
        }
        if(x > nod->gettata()->getval()){
            nod->gettata()->setfiu2(nod);
        }
        else{
            nod->gettata()->setfiu1(nod);
        }
    }
    splay(nod);
}

node* Splaytree::search(int x){
    node* nod = this->radacina;
    if(nod == nullptr || (nod->getfiu1()==nullptr && nod->getfiu2()==nullptr)){
        return nullptr;
    }
    while(nod){
        if(nod->getval() == x){
            splay(nod);
            return nod;
        }
        if(x < nod->getval()){
            if(nod->getfiu1() == nullptr){
                splay(nod);
                return nullptr;
            }
            nod = nod->getfiu1();
        }
        else{
            if(nod->getfiu2() == nullptr){
                splay(nod);
                return nullptr;
            }
            nod = nod->getfiu2();
        }
    }
    return nullptr;
}

bool Splaytree::remove(int x){
    node* nod = this->search(x);
    if(nod == nullptr){
        return 0;
    }
    if(nod->getfiu1() == nullptr && nod->getfiu2() == nullptr){
        this->radacina = nullptr;
        delete nod;
        return 1;
    }
    if(nod->getfiu1() == nullptr){
        nod->getfiu2()->settata(nullptr);
        this->radacina = nod->getfiu2();
        delete nod;
        return 1;
    }
    node* act = nod->getfiu1();
    while(act->getfiu2() != nullptr){
        act = act->getfiu2();
    }
    this->radacina = nod->getfiu1();
    this->radacina->settata(nullptr);
    node* exfiu;
    if(nod->getfiu2()!=nullptr){
        exfiu = nod->getfiu2();
        exfiu->settata(act);
    }
    else{
        exfiu = nullptr;
    }
    delete nod;
    splay(act);
    act->settata(nullptr);
    act->setfiu2(exfiu);
    this->radacina = act;
    return 1;
}

void Splaytree::right(node* nod){
    node* tata = nod->gettata();
    node* bunic = tata->gettata();
    if(tata == radacina){
        nod->settata(nullptr);
        radacina=nod;
    }
    else{
        if(bunic->getval() > tata->getval()){
            bunic->setfiu1(nod);
        }
        else{
            bunic->setfiu2(nod);
        }
        nod->settata(bunic);
    }
    if(nod->getfiu2() != nullptr){
        tata->setfiu1(nod->getfiu2());
        nod->getfiu2()->settata(tata);
    }
    else{
        tata->setfiu1(nullptr);
    }
    tata->settata(nod);
    nod->setfiu2(tata);
}

void Splaytree::left(node* nod){
    node* tata = nod->gettata();
    node* bunic = tata->gettata();
    if(tata == radacina){
        nod->settata(nullptr);
        radacina=nod;
    }
    else{
        if(bunic->getval() > tata->getval()){
            bunic->setfiu1(nod);
        }
        else{
            bunic->setfiu2(nod);
        }
        nod->settata(bunic);
    }
    if(nod->getfiu1() != nullptr){
        tata->setfiu2(nod->getfiu1());
        nod->getfiu1()->settata(tata);
    }
    else{
        tata->setfiu2(nullptr);
    }
    tata->settata(nod);
    nod->setfiu1(tata);
}

void Splaytree::splay(node* nod){
    //while(nod != this->radacina){
        if(nod->gettata() == this->radacina){
            if(nod->getval() < this->radacina->getval()){
                right(nod);
            }
            else{
                left(nod);
            }
        }
        else if(nod != this->radacina){
            if(nod->gettata()->getval() > nod->getval()){
                if(nod->gettata()->gettata()->getval() > nod->getval()){
                    right(nod->gettata());
                    right(nod);
                }
                else{
                    right(nod);
                    left(nod);
                }
            }
            else{
                if(nod->gettata()->gettata()->getval() < nod->getval()){
                    left(nod->gettata());
                    left(nod);
                }
                else{
                    left(nod);
                    right(nod);
                }
            }
            splay(nod);
        }
    //}
}

node* Splaytree::predecessor(int x){
    if(this->search(x)==nullptr){
        this->push(x);
    }
    if(this->radacina->getfiu1() == nullptr){
        this->remove(x);
        return nullptr;
    }
    else{
        node* act = this->radacina->getfiu1();
        while(act->getfiu2() != nullptr){
            act = act->getfiu2();
        }
        this->remove(x);
        return act;
    }
    this->remove(x);
    return nullptr;
}

node* Splaytree::successor(int x){
    if(this->search(x)==nullptr){
        this->push(x);
    }
    if(this->radacina->getfiu2() == nullptr){
        this->remove(x);
        return nullptr;
    }
    else{
        node* act = this->radacina->getfiu2();
        while(act->getfiu1() != nullptr){
            act = act->getfiu1();
        }
        this->remove(x);
        return act;
    }
    this->remove(x);
    return nullptr;
}

void Splaytree::interval(int x, int y){
    this->inorder(x, y);
    return;
}

void inordine(node* nod, int x, int y){
    if(nod==nullptr){
        return;
    }
    inordine(nod->getfiu1(), x, y);
    int z = nod->getval();
    if(z>=x && z<=y){
        cout<<z<<" ";
    }
    inordine(nod->getfiu2(), x, y);
}

void Splaytree::inorder(int x, int y){
    inordine(this->radacina, x, y);
    cout<<"\n";
}

void preordine(node* nod){
    if(nod==nullptr){
        return;
    }
    cout<<nod->getval()<<" ";
    preordine(nod->getfiu1());
    preordine(nod->getfiu2());
}

void Splaytree::preorder(){
    preordine(this->radacina);
    cout<<"\n";
}

void postordine(node* nod){
    if(nod==nullptr){
        return;
    }
    postordine(nod->getfiu1());
    postordine(nod->getfiu2());
    cout<<nod->getval()<<" ";
}

void Splaytree::postorder(){
    postordine(this->radacina);
    cout<<"\n";
}

node* Splaytree:: getradacina(){
    return this->radacina;
}
