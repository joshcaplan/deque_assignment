Name: Josh Caplan
WUSTL ID: 457632

The purpose of this program is for the creation and use of a deque (and an iterator). In a deque, elements can be inserted to the front or back of the deque 
in amortized constant time and elements can be removed from the front or back of the deque in amortized constant time. A deque provides random access to its 
elements.

In this program, I added two unrequired member functions to the my_deque class:

	1) void resize()
		This helper function is used to either enlarge the array when the lIndex or rIndex reaches beyond the array or shrink the array. If the number of 		  elements is greater than half of its size (get_used()>size), when the lIndex or rIndex reaches beyond the array, it doubles the array. If the array is 		 greater than its initial size and the number of elements is less than 1/8 of the array's current size, it halves the array.
	
	2) void print()
		This member function is used to print out the entire array that holds the deque. Uninitialized indices will print out "_" while initialized indices 		    will print out their value

----------------------------------------------------
Deque_test Folder:

	In order to test my program, I used the tests in the deque_test folder. I passed all of the tests except the "random_test_large". I am not exactly sure why this one failed

---------------------------------------------------------------------

DEEP COPY VS SHALLOW COPY:

Code:
	std::deque <int> arr = { 1, 2, 3 };
	std::deque <int> copy = arr;
	arr[1] = 5;
	if (copy[1] == 5) {
		cout << "Shallow copy";
	}
	else { cout << "Deep copy"; }
This code will create a deque with 3 values in the order of 1,2 and 3 and then create a deque whic is a copy of the deque. If 
deque makes a shallow copy, then by changing a value at one of the indices of one of the deques (I changed the original array
at index 1), the other deque will change to the new value at that index as well. If this is not the case, then it is a deep copy, 
since we would have proven that both deques point to the same location at each index.

Answer: std::deque makes a deep copy

