// define my_deque_iterator here
#include "my_deque_iterator.h"
#include"my_deque.h"

my_deque_iterator::my_deque_iterator(int* r, my_deque*d) {
	curr = r;
	deque = d;
	if (curr == d->get_mem() + d->get_rIndex()) {
		int*curr =  d->get_mem()+d->get_rIndex();
	}
	else if (curr <= d->get_mem() + d->get_lIndex() || curr > d->get_mem() + d->get_rIndex()) {
		curr = nullptr;
	}
	else {
		
	}
}

my_deque_iterator my_deque_iterator::operator+ (int n) {
	my_deque_iterator temp(this->curr, this->deque);
	if (n < 0) {
		temp.curr = nullptr;
		return temp;
	}
	if (temp.curr + n > get_mem() + temp.deque->get_rIndex()) {
		temp.curr = nullptr;
	}
	else { 
		temp.curr = temp.curr + n; 
	}
	return temp;
	}
my_deque_iterator& my_deque_iterator::operator+= (int n)  {
	my_deque_iterator& temp = *this;
	if (n < 0) {
		temp.curr = nullptr;
		return temp;
	}
	if (temp.curr + n > get_mem() + temp.deque->get_rIndex()) {
		temp.curr = nullptr;
	}
	temp.curr = temp.curr + n;
	return temp;
}
int& my_deque_iterator::operator*() {
	if (curr == nullptr || curr == deque->get_mem() + deque->get_rIndex()) {
		throw exception();
	}
	int& temp = *curr;
	return *curr;
}

bool my_deque_iterator::operator< (const my_deque_iterator compare_against) const {
	if (this->curr == nullptr || compare_against.curr == nullptr || this->deque != compare_against.deque) {
		throw exception();
	}
	if ((this->curr) < (compare_against.curr)) {
		return true;
	}
	return false;
}

bool my_deque_iterator::operator== (const my_deque_iterator other) const {
	if (*(this->curr) == *(other.curr) && this->deque == other.deque) {
		return true;
	}
	else { return false; }
}

int* my_deque_iterator::get_mem() {
	return curr;
}