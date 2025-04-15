#include "list.h"
#include <math.h>
#define EPS 1e-15

void add(list_elem*& first, list_elem*& last, double value) {
	auto new_el = new list_elem;
	new_el->value = value;
	if (!first) {
		first = last = new_el;
		return;
	}
	if (new_el->value < first->value) {
		new_el->next = first;
		first->prev = new_el;
		first = new_el;
		return;
	}
	if (new_el->value > last->value) {
		new_el->prev = last;
		last->next = new_el;
		last = new_el;
		return;
	}
	auto curr = first;
	while (curr && curr->next && new_el->value > curr->value) {
		curr = curr->next;
	}
	new_el->next = curr;
	new_el->prev = curr->prev;
	if (curr->prev) curr->prev->next = new_el;
	curr->prev = new_el;
}

void add(list& lst, double value)
{
	add(lst.first, lst.last, value);
}

bool remove(list_elem*& first, list_elem*& last, double rem_value) {
	if (!first || rem_value < first->value || rem_value > last->value)
		return false;
	if (fabs(first->value - rem_value) < EPS) {
		if (first->next) first->next->prev = nullptr;
		auto rem = first;
		first = first->next;
		if (!first) last = first;
		delete rem;
		return true;
	}
	if (fabs(last->value - rem_value) < EPS) {
		last->prev->next = nullptr;
		auto rem = last;
		last = last->prev;
		delete rem;
		return true;
	}
	auto curr = first->next;
	while (curr && fabs(curr->value - rem_value) > EPS) {
		curr = curr->next;
	}
	if (curr) {
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		delete curr;
	}
}

bool remove(list& lst, double rem_value)
{
	return remove(lst.first, lst.last, rem_value);
}

int remove_all(list_elem*& first, list_elem*& last, double rem_value) {
	int i = 0;
	if (!first || rem_value < first->value || rem_value > last->value)
		return i;
	while (fabs(first->value - rem_value) < EPS) {
		if (first->next) first->next->prev = nullptr;
		auto rem = first;
		first = first->next;
		if (!first) last = first;
		delete rem;
		i++;
	}
	if (i > 0) return i;
	while (fabs(last->value - rem_value) < EPS) {
		last->prev->next = nullptr;
		auto rem = last;
		last = last->prev;
		delete rem;
		i++;
	}
	if (i > 0) return i;
	auto curr = first->next;
	while (curr && fabs(curr->value - rem_value) > EPS) {
		curr = curr->next;
	}
	while (curr && fabs(curr->value - rem_value) < EPS) {
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		auto rem = curr;
		curr = curr->next;
		delete rem;
		i++;
	}
	return i;
}

int remove_all(list& lst, double rem_value)
{
	return remove_all(lst.first, lst.last, rem_value);
}

bool is_in_list(list_elem* first, list_elem* last, double value) {
	auto curr1 = first;
	auto curr2 = last;
	while (curr1 
		&& curr2 
		&& (curr1->value - value) < EPS 
		&& (value - curr2->value) < EPS
		) {
		if (fabs(curr1->value - value) < EPS
			|| fabs(curr2->value - value) < EPS)
			return true;
		curr1 = curr1->next;
		curr2 = curr2->prev;
	}
	return false;
}

bool is_in_list(list lst, double value)
{
	return is_in_list(lst.first, lst.last, value);
}

void clear(list& lst)
{
	auto curr = lst.first;
	while (curr) {
		auto rem = curr;
		curr = curr->next;
		delete rem;
	}
	lst.first = nullptr;
	lst.last = nullptr;
}
