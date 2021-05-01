#include<iostream>
using namespace std;

struct Node {
	int data;
	int height;
	Node* left;
	Node* right;
};

typedef Node* Tree;
void init(Tree& t);
Node* create_Node(int x);
int height(Tree t);
int getBalance(Tree t);
void rotateLeft(Tree& t);
void rotateRight(Tree& t);

void insert(Tree& t, int x);
void timNodeTheMang(Tree& x, Tree& y);
void deleteNode(Tree& t, int x);
void setValue(Tree& t);
void NLR(Tree t);

void meNu(Tree& t);