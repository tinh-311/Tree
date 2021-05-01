#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

typedef Node* Tree;
void init(Tree& t);
Node* create_Node(int x);

void rotateLeft(Tree& t);
void rotateRight(Tree& t);

Node* findParent(Tree t, Tree x);
void splay(Tree& t, Tree x);

Node* insert(Tree& t, int x);
void insertAndSplay(Tree& t, int x);

Node* search(Tree& t, int x);
void searchAndSplay(Tree& t, int x);

void timNodeTheMang(Tree& x, Tree& y);
void deleteNode(Tree& t, int x);

void setValue(Tree& t);

void NLR(Tree t);
void meNu(Tree& t);