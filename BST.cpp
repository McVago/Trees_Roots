#include <iostream>
using namespace std;


class node{
public:
  int value;
  node *left, *right;
  node(int x){
    value = x;
    left = 0;
    right = 0;
  }
  node(int x, node *lef, node *righ){
    value = x;
    left = lef;
    right = righ;
  }
};

typedef node *link;
class BST{
private:
  int N; // N = amount of nodes
public:
  link root;
  BST(){N = 0;root = 0;}
  void insert(int x);
  void insertA(link p, int x);
  int lenght();
};
int BST::lenght(){
  return N;
}
void BST::insert(int x){
  if (N == 0){
    root = new node(x);
    N++;
  }
  else{
    insertA(root, x);
    }
  }

void BST::insertA(link p, int x){
  if (x<p->value){
    if (p->left != 0) insertA(p->left, x);
    else p->left = new node(x);
    N++;
  }
  else{
    if (p->right != 0)insertA(p->right, x);
    else p->right = new node(x);
    N++;
  }
}
class Splay{
private:
  int N;
public:
  link root;
  Splyce(){
    N = 0;
    link = NULL;
  }
  void insert(int x);
};
void Splay::insert(int x){
  if (N == 0){
    root = new node(x);
  }
  else{
    insertSp(root, x);
  }
}
void Splay::insertSp(link p, int x){
  if (x<p->value){
    if (p->left != 0) insertA(p->left, x);
    else p->left = new node(x);
    N++;
  }
  else{
    if (p->right != 0)insertA(p->right, x);
    else p->right = new node(x);
    N++;
  }
}
link Splay::search(int x){
  searchR(root, x, 0);
}
link Splay::searchR(link p,int x, int sw){
  if (x == p->value){
      return p;
  }
  if (x<p-value){
    searchR(p->left, 0);



  }
}

void rotateR(link &p){
  link temp = p->left;
  p->left = temp->right;
  temp->right = p;
}
void rotateL(link &p){
  link temp = p->right;
  p->right = temp->left;
  temp->left = p;

}
void print(link p){
  cout << p->value << " ";
}
int main(){
  BST a;
  int b;
  a.insert(9);
  print(a.root);
  a.insert(10);
  print(a.root->left);
  cin >> b;

}
