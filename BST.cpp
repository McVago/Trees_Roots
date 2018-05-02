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
  Splay(){
    N = 0;
    root = 0;
  }
  void insert(int x);
  void insertA(link &p,int x);
};
void Splay::insert(int x){
  insertA(root, x);
}
void Splay::insertA(link &p, int x){
  if (p == 0){
    p = new node(x);
    return;
  }
  if (x < p->value){
    link & pleft = p->left;
    if (pleft == 0) {
      p = new node(x, 0, p); return;
    }
    if (x < pleft->value){
      insertA(pleft->left, x); rotateR(p);
    }
    else{
      insertA(pleft->right, x); rotateL(pleft);
    }
    rotateR(p);
  }
  else{
    link & pright = p->right;
    if (pright == 0){
      p = new node(x, p, 0); return;
    }
    if (x > pright->value){
      insertA(pright->right, x); rotateL(p);
    }
    else{
      insertA(pright->left, x); rotateR(pright);
    }
    rotateL(p);
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

class TopDownNode{
private:
  int value;
  bool is2, is3, is4;
  TopDownNode *leftleft, *left, *right, *rightright, *father
public:
  TopDownNode(int x){
    value1 = x;
    value2 = 0;
    value3 = 0;
    is2 = true;
    is3 = false;
    is4 = false;
    leftleft = 0;
    left = 0;
    right = 0;
    rightright = 0;
    father = 0;
  }
  TopDownNode(int x, TopDownNode *f){
    value1 = x;
    value2 = 0;
    value3 = 0;
    is2 = true;
    is3 = false;
    is4 = false;
    leftleft = 0;
    left = 0;
    right = 0;
    rightright = 0;
    father = f;
  }
}

class TopDownTree{
private:
  int N;
  link root;
public:
  RBTree(){
    N = 0;
    root = 0;
  }
  void insert();
  void insertA();
}
void TopDownTree::insert(int x){
  if (root == 0){
    root = new TopDownNode(x);
  }
  if (x < root->value1){
    insertA(root->leftleft, x);
  }
}
void TopDownTree::insertA(TopDownNode *&p, int x){

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
