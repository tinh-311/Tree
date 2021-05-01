#include"Header.h"

void init(Tree& t) {
	t = NULL;
}

Node* create_Node(int x) {
	Node* p = new Node;
	p->data = x;
	p->left = p->right = NULL;
	p->height = 1;

	return p;
}

int height(Tree t) {
	if (t == NULL)
		return 0;

	int a = height(t->left);
	int b = height(t->right);

	if (a > b)
		return a + 1;

	return b + 1;
}

int getBalance(Tree t) {
	if (t == NULL)
		return 0;

	return height(t->left) - height(t->right);
}

void rotateLeft(Tree& t) {
	Node* t1 = t->right;
	t->right = t1->left;
	t1->left = t;

	t->height = height(t);
	t1->height = height(t1);

	t = t1;
}

void rotateRight(Tree& t) {
	Node* t1 = t->left;
	t->left = t1->right;
	t1->right = t;

	t->height = height(t);
	t1->height = height(t1);

	t = t1;
}

void insert(Tree& t, int x) {
	if (t == NULL) {
		t = create_Node(x);
		return;
	}
	
	if (t->data == x) {
		cout << "Da co " << x << " trong cay !" << endl;
		return;
	}
	else if (x < t->data) {
		insert(t->left, x);
	}
	else {
		insert(t->right, x);
	}

	t->height = height(t);

	if (getBalance(t) == 2) {
		if (getBalance(t->left) == -1) {
			rotateLeft(t->left);
			rotateRight(t);
		}
		else {
			rotateRight(t);
		}
	}
	else if (getBalance(t) == -2) {
		if (getBalance(t->right) == 1) {
			rotateRight(t->right);
			rotateLeft(t);
		}
		else {
			rotateLeft(t);
		}
	}
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
	
	if (x < t->data) {
		deleteNode(t->left, x);
	}
	else if (x > t->data) {
		deleteNode(t->right, x);
	}
	else {
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
			deleteNode(t->right, t->data);
			delete k;
		}
	}

	if (getBalance(t) == 2) {
		if (getBalance(t->left) == -1) {
			rotateLeft(t->left);
			rotateRight(t);
		}
		else {
			rotateRight(t);
		}
	}
	else if (getBalance(t) == -2) {
		if (getBalance(t->right) == 1) {
			rotateRight(t->right);
			rotateLeft(t);
		}
		else {
			rotateLeft(t);
		}
	}
}

void setValue(Tree& t) {
	int x;
	do {
		cout << "Nhap x (-99 de thoat): ";
		cin >> x;
		if (x == -99)
			break;

		insert(t, x);
	} while (true);
}
void NLR(Tree t) {
	if (t != NULL) {
		cout << t->data << " - " << "Height: " << t->height << endl;
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
			insert(t, x);
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