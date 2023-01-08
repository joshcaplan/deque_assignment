#pragma once
// define my_deque here
#include "my_deque.h"
#include "my_deque_iterator.h"

my_deque::my_deque(int initial_size) :
	size(initial_size), rIndex(initial_size / 2 ), lIndex((initial_size / 2-1)), init_size(initial_size) {
	array = new int[size];
	if (initial_size % 2 != 0 && init_size>0) {
		throw exception();
		
	}
}

my_deque::my_deque(const my_deque& d) : size(0), lIndex(-1), rIndex(0), array(nullptr), init_size(d.size){
	if (d.size > 0) {
		size = d.size;
		rIndex = d.rIndex;
		lIndex = d.lIndex;
		array = new int[size];
		for (size_t i = 0; i < size; ++i) {
			array[i] = d.array[i];
		}
	}
}

my_deque:: ~my_deque() {
	delete[] array;
}

int my_deque::get_used() {
	int value = rIndex - lIndex - 1;
	int v2=0;
	for (int i = 0; i < size; ++i) {
		if (array[i] > -10) {
			++v2;
		}
	}
	return value;
}

int my_deque::get_size() {
	return size;
}
int my_deque::get_lIndex() {
	return lIndex;
}
int my_deque::get_rIndex() {
	return rIndex;
}

/*This helper function is used to either enlarge the array when the lIndex or rIndex reaches beyond the array or shrink the array. If the number of elements 
  is greater than half of its size (get_used()>size), when the lIndex or rIndex reaches beyond the array, it doubles the array. If the array is greater than 
  its initial size and the number of elements is less than 1/8 of the array's current size, it halves the array.
*/
void my_deque::resize() {
	int num =get_used();
	int newSize;
	double a = size;
	double b = a-a / 4.0 -2;
	double c = a + a / 4.0;
	int l2 = (int)round(b);
	int r2 = (int)round(c);
	if (num > size / 2) {
		newSize = size * 2;
		int* newArray = new int[newSize];
		for (int i = 1; i <= num; ++i) {
			
			newArray[l2+i] = array[lIndex+i];
		}
		delete[] array;
		array = newArray;
		size = newSize;
		lIndex = l2;
		rIndex = r2;
	}
	if (num < size / 8 && size>init_size) {
		newSize = size / 2;
		l2 = (int)round(size / 4.0 - size / 16.0 - 1);
		r2 = (int)round(size / 4.0 + size / 16.0 - 1);
		int *newArray = new int[newSize];
		for (int i = 1;i <= num; ++i) {
			newArray[l2+i] = array[lIndex+i];
		}
		delete[] array;
		array = newArray;
		size = newSize;
		lIndex = l2;
		rIndex =r2;
	}

}

void my_deque::push_back(int v) {
	if (rIndex < size) {
		array[rIndex] = v;
		rIndex = rIndex + 1;
	}
	else if (rIndex == size) {
		int l2 = (int)round(size / 2.0 - get_used() / 2.0 - 2);
		int r2 = (int)round(size / 2.0 + get_used() / 2.0);
		for (int j = 1; j <= get_used(); ++j) {
			array[l2 + j] = array[lIndex + j];
			array[lIndex + j] = array[0];
		}
		lIndex = l2;
		rIndex = r2;
		array[rIndex - 1] = v;

		if (size / 2 < get_used()) {
			resize();
		}
	}
}

void my_deque::push_front(int v) {
	if (lIndex > -1) {
		array[lIndex] = v;
		lIndex = lIndex - 1;
	}
	else if (lIndex == -1) {
		int l2 = (int)round(size / 2.0 - get_used() / 2.0 - 2);
		int r2 = (int)round(size / 2.0 + get_used() / 2.0);
		for (int j = 1; j <= get_used(); ++j) {
			array[r2 - j] = array[rIndex - j];
			array[rIndex - j] = array[size - 1];
		}
		lIndex = l2;
		rIndex = r2;
		array[lIndex + 1] = v;

		if (size / 2 < get_used()) {
			resize();
		}
	}
}

int my_deque::pop_back() {
	
	if (get_used() == 0) {
		throw exception();
	}
	else {
		int temp = *(array + rIndex - 1);
		array[rIndex - 1] = array[size - 1];
		rIndex -= 1;
		if (size / 8 > get_used()) {
			resize();
		}
		return temp;
	}
}

int my_deque::pop_front() {

	if (get_used() == 0) {
		throw exception();
	}
	int temp = *(array + lIndex + 1);
	array[lIndex + 1] = array[size - 1];
	lIndex = lIndex + 1;
	if (size / 8 > get_used()) {
		resize();
	}
	return temp;
}

int* my_deque::get_mem() {
	return array;
}
int& my_deque::operator[](const int i) {
	if (i<0||i >= get_used()) {
		throw exception();
	}
	int& p = *(array + lIndex +1+i);
	return p;			
}

my_deque_iterator my_deque::begin() {
	int* current = array + lIndex + 1;
	my_deque_iterator temp(array + lIndex+1, this);
	return temp;
}

my_deque_iterator my_deque::end(){
	int* current = array + rIndex;
	my_deque_iterator temp(array + rIndex, this);
	return temp;
}

// This is a function to print out the entire array
void my_deque::print() {
	for (int i = 0; i < size; ++i) {
		if (array[i] <-10) {
			cout << "_ ";
		}
		else {
			cout << array[i] << " ";
		}
	}
	cout<<"\n";
}