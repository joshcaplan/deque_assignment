#pragma once
// declare your my_deque class here
#include<iostream>
#include<vector>
#include <stdexcept>
using namespace std;
class my_deque_iterator;

enum{success};

class my_deque {
private:
	int size;
	int rIndex;
	int lIndex;
	int* array;
	int const init_size;
public:
	my_deque(int initial_size);
	my_deque(const my_deque& d);
	~my_deque();
	int get_used();
	int get_size();
	int get_lIndex();
	int get_rIndex();
	void center();
	void resize();
	void push_back(int v);
	void push_front(int v);
	int pop_back();
	int pop_front();
	int* get_mem();
	int& operator[](const int i);
	my_deque_iterator begin();
	my_deque_iterator end();
	void print();
};