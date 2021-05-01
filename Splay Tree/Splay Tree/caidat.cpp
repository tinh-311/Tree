#include"Header.h"

void init(Tree& t) {
	t = NULL;
}

Node* create_Node(int x) {
	Node* p = new Node;
	p->data = x;
	p->left = p->right = NULL;

	return p;
}

void rotateLeft(Tree& t) {
	Node* t1 = t->right;
	t->right = t1->left;
	t1->left = t;
	t = t1;
}

void rotateRight(Tree& t) {
	Node* t1 = t->left;
	t->left = t1->right;
	t1->right = t;
	t = t1;
}


Node* findParent(Tree t, Tree x) {
	if (t == NULL || t == x) {
		return NULL;
	}
	
	if (t->left == x || t->right == x) {
		return t;
	}
	else if (x->data > t->data)
		findParent(t->right, x);
	else if (x->data < t->data)
		findParent(t->left, x);
}

void splay(Tree& t, Tree x) {
	if (t == NULL || t == x) {
		return;
	}
	else {
		if (t->left == x) {
			rotateRight(t);
		}
		else if (t->right == x) {
			rotateLeft(t);
		}
		else {
			Node* p = findParent(t, x);
			Node* g = findParent(t, p);

			if (g == t) {
				if (t->left != NULL && t->left->left == x) {
					rotateRight(t);
					rotateRight(t);
				}
				else if (t->left != NULL && t->left->right == x) {
					rotateLeft(t->left);
					rotateRight(t);
				}
				else if (t->right != NULL && t->right->right == x) {
					rotateLeft(t);
					rotateLeft(t);
				}
				else if (t->right != NULL && t->right->left == x) {
					rotateRight(t->right);
					rotateLeft(t);
				}
			}
			else {
				p = findParent(t, g);
				if (g->left != NULL && g->left->left == x) {
					rotateRight(g);
					rotateRight(g);
				}
				else if (g->left != NULL && g->left->right == x) {
					rotateLeft(g->left);
					rotateRight(g);
				}
				else if (g->right != NULL && g->right->right == x) {
					rotateLeft(g);
					rotateLeft(g);
				}
				else if (g->right != NULL && g->right->left == x) {
					rotateRight(g->right);
					rotateLeft(g);
				}

				if (p->data > g->data) {
					p->left = g;
				}
				else
					p->right = g;

				splay(t, g);

			}
		}
	}
}

Node* insert(Tree& t, int x) {
	if (t == NULL) {
		t = create_Node(x);
		return t;
	}
	else {
		if (x < t->data) {
			return insert(t->left, x);
		}
		else if (x > t->data) {
			return insert(t->right, x);
		}
		else {
			return t;
		}
	}
}

void insertAndSplay(Tree& t, int x) {
	splay(t, insert(t, x));
}

Node* search(Tree& t, int x) {
	if (t == NULL) {
		return NULL;
	}
	
	if (x < t->data) {
		return search(t->left, x);
	}
	else if (x > t->data) {
		return search(t->right, x);
	}
	else {
		return t;
	}
}

void searchAndSplay(Tree& t, int x) {
	splay(t, search(t, x));
}

void timNodeTheMang(Tree& x, Tree& y) {
	if (y->left != NULL) {
		timNodeTheMang(x, y->left);
	}
	else {
		x->data = y->data;
		x = y;
		y = y->right;
	}
}

void deleteNode(Tree& t, int x) {
	if (t == NULL) {
		return;
	}

	searchAndSplay(t, x);

	Node* k = t;
	if (t->left == NULL) {
		Node* p = t;
		t = t->right;
		delete p;
	}
	else if (t->right == NULL) {
		Node* p = t;
		t = t->left;
		delete p;
	}
	else {
		timNodeTheMang(k, t->right);
		delete k;
	}
}

void setValue(Tree& t) {
	int x;
	do {
		cout << "Nhap x (-99 thoat): ";
		cin >> x;
		if (x == -99)
			break;

		insertAndSplay(t, x);
	} while (true);
}
void NLR(Tree t) {
	if (t != NULL) {
		cout << t->data << " ";
		NLR(t->left);
		NLR(t->right);
	}
}

void meNu(Tree& t) {
	bool kt = true;
	while (kt) {
		system("cls");
		cout << "\n\t\t\t====== MENU ======\n" << endl;
		cout << "0. Exit." << endl;
		cout << "1. Set Value." << endl;
		cout << "2. Insert." << endl;
		cout << "3. NLR." << endl;
		cout << "4. Delete Node." << endl;
		cout << "\n\t\t\t====== END ======\n" << endl;

		int luaChon;
		cout << "Nhap lua chon: ";
		cin >> luaChon;

		switch (luaChon) {
		case 0: {
			kt = false;
			break;
		}
		case 1: {
			init(t);
			setValue(t);
			break;
		}
		case 2: {
			int x;
			cout << "Nhap node can chen: ";
			cin >> x;
			insertAndSplay(t, x);
			break;
		}
		case 3: {
			cout << "NLR: " << endl;
			NLR(t);
			break;
		}
		case 4: {
			int x;
			cout << "Nhap node can xoa: ";
			cin >> x;
			deleteNode(t, x);
			break;
		}
		default: {
			cout << "Lua chon khong hop le !" << endl;
		}
		}
		system("pause");
	}
}
