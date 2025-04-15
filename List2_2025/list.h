#pragma once
struct list_elem
{
	double value;
	list_elem* next = nullptr;
	list_elem* prev = nullptr;
};

struct list {
	list_elem* first = nullptr;
	list_elem* last  = nullptr;
};

void add(list& lst, double value);
bool remove(list& lst, double rem_value);
int remove_all(list& lst, double rem_value);
bool is_in_list(list lst, double value);
void clear(list& lst);