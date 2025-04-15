#include <iostream>
#include "list.h"
using namespace std;

void show_list(list lst) {
	auto curr = lst.first;
	while (curr) {
		cout << curr->value << (curr->next ? " " : "");
		curr = curr->next;
	}
	cout << endl;
}

void main() {
	setlocale(LC_ALL, "");
	const int N = 10;
	double vals[] = {0.3, 1.2, -9.3, -1.0, 0.3, 0.2+0.1, 0.85, 0.85, 11.2, -11.2};
	list lst;
	for (int i = 0; i < N; i++) {
		add(lst, vals[i]);
		show_list(lst);
	}
	cout << endl;
	cout << "������� " << remove_all(lst, 0.3) << " ��������=" << 0.3 << endl;
	show_list(lst);
	cout << endl;
	remove(lst, 0.8499999999999999);
	show_list(lst);
	cout << "������� �������� " << -11.2 << " � ������: " << (is_in_list(lst, -11.2) ? "��" : "���") << endl;
	cout << "������� �������� " << -7.2 << " � ������: " << (is_in_list(lst, -7.2) ? "��" : "���") << endl;
	clear(lst);
	show_list(lst);
}