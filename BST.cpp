#include <iostream>
using namespace std;


struct node{
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
  link root;
public:
  BST():N{0}, root{0};{}
void insert(int x);
void insertL(link p, int x);

void BST::insert(int x){
  if (N = 0){
    root = new node(x);
  }
  else{
    insertA(root, x);
    }
  }
void BST::insertA(link p, int x){
  if (x<p->value){
    if (p->left != 0) insertA(p->left, x);
    else p->left = new node(x);
  }
  else{
    if (p->right != 0)insertA(p->right, x);
    else p->right = new node(x);
  }
}
}
void print(link p){
  cout << p->value << " ";
}
void
