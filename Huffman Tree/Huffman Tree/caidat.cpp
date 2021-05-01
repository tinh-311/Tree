#include"Header.h"

Node* create_Node(unsigned f, char ch) {
	Node* p = new Node();
	p->f = f;
	p->ch = ch;
	p->left = p->right = NULL;

	return p;
}

void thongKeTanSuat(List& l, string tenFile) {
	ifstream fileIn;
	fileIn.open(tenFile, ios_base::in);
	int vt = 0;
	while (!fileIn.eof()) {
		bool kt = false;
		char temp;
		fileIn.get(temp);

		for (int i = 0; i < l.n; i++) {
			if (l.arr[i]->ch == temp) {
				l.arr[i]->f++;
				kt = true;
				vt = i;
				break;
			}
		}

		if (kt == false) {
			l.arr[l.n] = create_Node(0, temp);
			l.arr[l.n]->f++;
			l.n++;
		}
	}
	//Xử lý phần tử cuối cùng xét 2 lần
	l.arr[vt]->f--;
	fileIn.close();
}

void swap(Node*& a, Node*& b) {
	Node* temp = a;
	a = b;
	b = temp;
}

void sapXep(List& l) {
	for (int i = 0; i < l.n - 1; i++) {
		for (int j = i + 1; j < l.n; j++) {
			if (l.arr[j]->f > l.arr[i]->f) {
				swap(l.arr[j], l.arr[i]);
			}
		}
	}
}

void xoa(List& l, int viTri) {
	for (int i = viTri + 1; i < l.n; i++) {
		l.arr[i - 1] = l.arr[i];
	}
	l.n--;
}

Tree build(List& l) {
	int k = l.n;
	while (l.n != 1) {
		Tree t;
		int i = k - 2;
		int j = k - 1;

		if (l.arr[i]->ch > l.arr[j]->ch) {
			t = create_Node(0, l.arr[i]->ch);
		}
		else
			t = create_Node(0, l.arr[j]->ch);

		t->f = l.arr[i]->f + l.arr[j]->f;

		t->left = l.arr[i];
		t->right = l.arr[j];

		xoa(l, j);

		l.arr[i] = t;
		k = k - 2;

		if (k == 0 || k == 1)
			k = l.n;
	}

	return l.arr[0];
}


void duyet(Tree t, arrMaBit& m) {
	if (t == NULL)
		return;

	t->s = m.arr[m.n].ma; 

	if (t->left == NULL && t->right == NULL) {
		m.arr[m.n].ch = t->ch;
		m.n++;
	}
	else {
		m.arr[m.n].ma += + '0';
		duyet(t->left, m);
		m.arr[m.n].ma = t->s + '1';
		duyet(t->right, m);
	}
}

string nen(string tenFile, arrMaBit& m) {
	ifstream fileIn;
	fileIn.open("data.txt", ios_base::in);
	string kq;
	string s;
	while (!fileIn.eof()) {
		getline(fileIn, s);
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < m.n; j++) {
				if (s[i] == m.arr[j].ch) {
					kq += m.arr[j].ma;
				}
			}
		}
	}
	fileIn.close();
	return kq;
}

void ghiFile(string s, string tenFile) {
	ofstream fileOut;
	fileOut.open(tenFile, ios_base::out);
	fileOut << s;
	fileOut.close();
}

string giaiNen(Tree t, string chuoiMaHoa) {
	string kq;
	if (t == NULL)
		return "";
	Tree p = t;
	for (int i = 0; i <= chuoiMaHoa.length(); i++) {
		if (p->left == NULL && p->right == NULL) {
			kq += p->ch;
			p = t;
		}

		if (chuoiMaHoa[i] == '0')
			p = p->left;
		else
			p = p->right;
	}

	return kq;
}

void meNu(List& l,Tree& t, arrMaBit& m) {
	bool kt = true;
	while (kt) {
		system("cls");
		cout << "\n\t\t\t====== MENU ======\n" << endl;
		cout << "0. Exit." << endl;
		cout << "1. Nen." << endl;
		cout << "2. Giai nen." << endl;
		cout << "\n\t\t\t====== END ======\n" << endl;

		int luaChon;
		cout << "Nhap lua chon: ";
		cin >> luaChon;

		switch (luaChon){
			case 0: {
				kt = false;
				break;
			}
			case 1: {
				l.n = 0;
				ifstream fileIn;
				thongKeTanSuat(l, "data.txt");
				sapXep(l);
				t = build(l);
				duyet(t, m);

				string kq;
				kq = nen("data.txt", m);
				fileIn.close();

				cout << "Nen thanh cong !" << endl;
				cout << "Chuoi ma hoa: " << kq << endl;
				ghiFile(kq, "File_Nen.txt");
				break;
			}
			case 2: {
				string s;
				ifstream fileIn;
				fileIn.open("File_Nen.txt", ios_base::in);
				fileIn >> s;
				fileIn.close();

				string kq = giaiNen(t, s);

				cout << "Giai nen thanh cong ! " << endl;
				cout << "Chuoi ket qua: " << kq << endl;
				ghiFile(kq, "File_Giai_Nen.txt");
				break;
			}
		}
		system("pause");
	}
}