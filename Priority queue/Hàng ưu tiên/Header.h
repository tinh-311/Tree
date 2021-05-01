#pragma once
#include<iostream>
using namespace std;

const int MAX = 100;

struct PriQueue {
	int list[MAX];
	int count;
};

void init(PriQueue& q);
bool isEmpty(PriQueue q);
bool isFull(PriQueue q);

int getParent(int i);
int getLeft(int i);
int getRight(int i);

void swap(int *x, int *y);
void shiftUp(PriQueue& q, int i);
void shiftDown(PriQueue& q, int i);

void insert(PriQueue& q, int x);
void deleteKey(PriQueue& q, int key);

void setValue(PriQueue& q);
void print(PriQueue q);
void meNu(PriQueue& q);