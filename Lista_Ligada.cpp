#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std;

class Linked_List{

    protected:

    struct Node{
        int val;
        Node* proximo;
        Node* anterior;
    };

    Node* sentinela;
    size_t sz;

    public:

    Linked_List();
    int at(int pos);
    void print();
    void append(int val);
    void insert(int val, size_t pos);
    void remove(size_t pos);
    size_t size(){
        return sz;
    }
};

    Linked_List::Linked_List(){
        sentinela = new Node;
        sentinela->proximo = sentinela;
        sentinela->anterior = sentinela;
        sz = 0;
    }

    Linked_List::~Linked_List(){
    Node* cursor = sentinela->proximo;
    while(cursor != sentinela){
        Node* next = cursor->proximo;
        delete cursor;
        cursor = next;
    }
    delete sentinela;
    }

    int Linked_List::at(int pos){
        assert(pos < sz);    
        Node* cursor = sentinela->proximo;
        for(int i = 0; i < pos; i++){
            cursor = cursor->proximo;
        }
        return cursor->val;
    }

    void Linked_List::print(){
        Node* cursor = sentinela->proximo;
        while(cursor != sentinela){
            cout << cursor->val << endl;
            cursor = cursor->proximo;
        }
    }

    void Linked_List::append(int val){
        Node* cursor = sentinela;
        Node* new_node = new Node;
        new_node->anterior = sentinela->anterior; //Fazendo o anterior de new_node apontar para o ultimo elemento
        new_node->proximo = sentinela; // Fazendo o new_node apontar para o sentinela
        sentinela->anterior->proximo = new_node; //Fazendo ajuste de ponteiros para o ponteiro próximo do ultimo elemento referenciar o new_node
        sentinela->anterior = new_node; // Fazendo ajuste de ponteiros para o ponteiro anterior de sentinela apontar para o new_node (ultimo da lsita)
        new_node->val = val;
        sz++;
    }

    void Linked_List::insert(int val, size_t pos){
        assert(pos < sz);
        Node* cursor = sentinela->proximo;
        Node* new_node = new Node;
        for(int i = 0; i < pos; i++){
            cursor = cursor->proximo;
        }
        new_node->anterior = cursor->anterior;
        new_node->proximo = cursor;
        cursor->anterior->proximo = new_node;
        cursor->anterior = new_node;
        new_node->val = val;
        sz++;
    }

    void Linked_List::remove(size_t pos){
        Node* cursor = sentinela->proximo;
        Node* to_die;
        for(int i = 0; i < pos; i++){
            cursor = cursor->proximo;
        }
        to_die = cursor;
        to_die->anterior->proximo = to_die->proximo;
        to_die->proximo->anterior = to_die->anterior;
        delete to_die;
        sz--;
    }
