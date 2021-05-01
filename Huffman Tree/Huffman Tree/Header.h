#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const int MAX = 257;

struct Node {
	unsigned f = 0;
	char ch;
	string s = "";
	Node* left;
	Node* right;
};

struct List {
	int n;
	Node* arr[MAX];
};

struct maBit {
	char ch;
	string ma = "";
};

struct arrMaBit {
	int n = 0;
	maBit arr[MAX];
};

typedef Node* Tree;
Node* create_Node(unsigned f, char ch);
void thongKeTanSuat(List& l,string tenFile);
void swap(Node*& a, Node*& b);
void sapXep(List& l);

void xoa(List& l, int viTri);
Tree build(List& l);

void duyet(Tree t, arrMaBit& m);

string nen(string tenFile, arrMaBit& m);
void ghiFile(string s, string tenFile);


string giaiNen(Tree t, string chuoiMaHoa);

void meNu(List& l,Tree& t, arrMaBit& m);