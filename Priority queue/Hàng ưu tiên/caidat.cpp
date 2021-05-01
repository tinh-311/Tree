#include"Header.h"

void init(PriQueue& q) {
	q.count = 0;
}

bool isEmpty(PriQueue q) {
	return q.count == 0 ? true : false;
}

bool isFull(PriQueue q) {
	return q.count == MAX ? true : false;
}

int getParent(int i) {
	return (i - 1) / 2;
}

int getLeft(int i) {
	return (2 * i + 1);
}

int getRight(int i) {
	return (2 * i + 2);
}
void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void shiftUp(PriQueue& q, int i) {
	if (q.list[getParent(i)] > q.list[i]) {
		swap(q.list[i], q.list[getParent(i)]);
		shiftUp(q, getParent(i));
	}
}

void shiftDown(PriQueue& q, int i) {
	if (getLeft(i) >= q.count)
		return;

	if (getRight(i) >= q.count) {
		if (q.list[getLeft(i)] < q.list[i]) {
			swap(q.list[getLeft(i)], q.list[i]);
			shiftDown(q, getLeft(i));
		}
	}
	else {
		int min = (q.list[getLeft(i)] < q.list[getRight(i)]) ? getLeft(i) : getRight(i);
		if (q.list[i] > q.list[min]) {
			swap(q.list[i], q.list[min]);
			shiftDown(q, min);
		}
	}

}

void insert(PriQueue& q, int x) {
	if (q.count == MAX) {
		cout << "Hang uu tien da day, khong the chen !" << endl;
		return;
	}

	q.list[q.count++] = x;
	shiftUp(q, q.count - 1);
}
void deleteKey(PriQueue& q, int key) {
	if (q.count == 0)
		return;
	else {
		if (key == q.list[q.count - 1]) {
			q.count--;
		}
		else {
			for (int i = 0; i < q.count; i++) {
				if (key == q.list[i]) {
					q.list[i] = q.list[q.count - 1];
					q.count--;
					shiftDown(q, i);
					break;
				}
			}
		}
	}
}


void setValue(PriQueue& q) {
	int x;
	do {
		cout << "Nhap x (-99 thoat): ";
		cin >> x;
		if (x == -99)
			break;
		insert(q, x);
	} while (true);
}

void print(PriQueue q) {
	for (int i = 0; i < q.count; i++) {
		cout << q.list[i] << " ";
	}
}

void meNu(PriQueue& q) {
	bool kt = true;
	while (kt) {
		system("cls");
		cout << "\n\t\t\t====== MENU ======\n" << endl;
		cout << "0. Exit." << endl;
		cout << "1. Set value." << endl;
		cout << "2. Insert." << endl;
		cout << "3. Print." << endl;
		cout << "4. Delete." << endl;
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
			setValue(q);
			break;
		}
		case 2: {
			int x;
			cout << "Nhap phan tu can chen: ";
			cin >> x;
			insert(q, x);
			break;
		}
		case 3: {
			cout << "Priority queue: ";
			print(q);
			cout << endl;
			break;
		}
		case 4: {
			int x;
			cout << "Nhap phan tu can xoa: ";
			cin >> x;
			deleteKey(q, x);
			break;
		}
		default: {
			cout << "Lua chon khong hop le !!!" << endl;
		}
		}
		system("pause");
	}
}