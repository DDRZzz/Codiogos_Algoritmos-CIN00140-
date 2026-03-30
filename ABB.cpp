#include <cstdio>
#include <iostream>

using namespace std;

class Tree{
    public:

    struct Node{
        int Valor;
        Node* Pai;
        Node* FilhoDireita;
        Node* FilhoEsquerda;
    };

    Node* Raiz;

    Tree() : Raiz(nullptr) {};
    Node* Busca(Node* Cursor, int Valor);
    void Insert(int Valor);
    void Remove(int Valor);
    int Sucessor(int valor);
    int Minimo (Node* Cursor);
    void PreOrder (Node* Cursor);
    void PosOrdem(Node*  Cursor);
};

    Tree::Node * Tree::Busca(Node* Cursor, int Valor){
        if(Cursor->Valor == NULL || Cursor->Valor == Valor){
            return Cursor;
        }
        else if(Cursor->Valor > Valor){
            return Busca(Cursor->FilhoEsquerda, Valor);
        }
        else{
            return Busca(Cursor->FilhoDireita, Valor);
        }
    }

    void Tree::Insert(int valor){
        Node* Cursor = Raiz;
        Node* NewNode = new Node;
        Node* Pai_aux;
        bool Esquerda_Direita;
        while(Cursor != nullptr){
            if(Cursor->Valor > valor){
                Pai_aux = Cursor;
                Cursor = Cursor->FilhoEsquerda;
                Esquerda_Direita = false;
            }
            else{
                Pai_aux = Cursor;
                Cursor = Cursor->FilhoDireita;
                Esquerda_Direita = true;
            }
        }
        if(Raiz != nullptr){
            NewNode->Pai = Pai_aux;
            if(Esquerda_Direita){
                Pai_aux->FilhoDireita = NewNode;
            }
            else{
                Pai_aux->FilhoEsquerda = NewNode;
            }
        }
        else{
            Raiz = NewNode;
        }
        NewNode->Valor = valor;
        NewNode->FilhoDireita = nullptr;
        NewNode->FilhoEsquerda = nullptr;
    }

    void Tree::Remove(int Valor){
        Node* Todie = Busca(Raiz, Valor);
        if(Todie->Pai->Valor > Todie->Valor){
            Todie->Pai->FilhoEsquerda = nullptr;
        }
        else{
            Todie->Pai->FilhoDireita = nullptr;
        }
        Todie->Valor = NULL;
        Todie->Pai = nullptr;
        delete Todie;
    }

    int Tree::Sucessor(int Valor){
        Node* Alvo = Busca(Raiz, Valor);
        if(Alvo->FilhoDireita != nullptr){
            return Minimo(Alvo->FilhoDireita);
        }
        else{
            while(Alvo->Pai != Raiz && Alvo->Valor > Alvo->Pai->Valor){
                Alvo = Alvo->Pai;
                if(Alvo->Pai == Raiz && Alvo->Valor > Raiz->Valor){
                    cout << "O número: " << Valor << " não tem antecessor.";
                }
            }
            return Alvo->Pai->Valor;
        }
    }

    int Tree::Minimo(Node* Cursor){
        while(Cursor != nullptr){
            Cursor = Cursor->FilhoEsquerda;
        }
        return Cursor->Valor;
    }

    void Tree::PreOrder(Node* Cursor){
        if(Cursor == nullptr){
            return;
        }
        else{
            cout << Cursor->Valor << endl;
            PreOrder(Cursor->FilhoEsquerda);
            PreOrder(Cursor->FilhoDireita);
        }
    } 

    void Tree::PosOrdem(Node* Cursor){
        if(Cursor == nullptr){
            return;
        }
        else{
            PosOrdem(Cursor->FilhoEsquerda);
            PosOrdem(Cursor->FilhoDireita);
            cout << Cursor->Valor << endl;
        }
    }

int main(){
    Tree Arvore;
    string entrada;
    int nmr;

    while(cin >> entrada){
        nmr = stoi(entrada);
        Arvore.Insert(nmr);
    }  
    Arvore.PosOrdem(Arvore.Raiz);
}
