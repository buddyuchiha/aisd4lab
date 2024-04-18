#include <iostream>
#include <fstream>
#include "..\algorithm\algorithm.h"
using namespace std;
using namespace algorithm;
template<typename T>
Set<T> intersection( Set<T>& set1,  Set<T>& set2) {
	Set<T> result;
	Node<T>* current1 = set1.get_root();

	while (current1) {
		if (set2.contains(current1->_data)) {
			result.insert(current1->_data);
		}
		current1 = current1->_right;
	}

	return result;
}

template<typename T>
Set<T> difference( Set<T>& set1, Set<T>& set2) {
	Set<T> result;
	Node<T>* current1 = set1.get_root();
	Node<T>* current2 = set2.get_root();

	while (current1) {
		if (!set2.contains(current1->_data)){
			result.insert(current1->_data);
		}
		current1 = current1->_right;
	}
	while (current2) {
		if (!set1.contains(current2 -> _data)) {
			result.insert(current2 -> _data);
		}
		current2 = current2 -> _right;
	}
	return result;
}


int main() {
	cout << "Set Tests:" << endl;
	Set<int> mySet1;
	Set<int> mySet2;
	Set<int> mySet3;

	mySet1.insert(7);
	mySet1.insert(2);
	mySet1.insert(3);
	mySet1.insert(10);
	mySet1.insert(20);
	mySet1.insert(300);
	mySet1.print();
	mySet2.insert(7);
	mySet2.insert(2);
	mySet2.insert(3);
	mySet3 = mySet2;
	cout << "------------------------------" << endl;
	mySet3.print();
	if (mySet3.contains(7)) {
		cout << "All good!" << endl;
	}
	else {
		cout << "All bad!" << endl;
	}
	mySet3.erase(7);
	mySet3.print();
	if (mySet3.contains(7)) {
		cout << "All good!" << endl;
	}
	else {
		cout << "All bad!" << endl;
	}

	cout << endl;
	cout << "Class Set: " << endl;
	Set<int> mySet4;
	mySet4.set_insert_info(100);
	mySet4.set_insert_info(1000);
	mySet4.set_insert_info(10000);
	Set<int> mySet5;
	mySet5.set_contains_info(100);
	mySet5.set_contains_info(1000);
	mySet5.set_contains_info(10000);
	Set<int> mySet6;
	mySet6.set_erase_info(100);
	mySet6.set_erase_info(1000);
	mySet6.set_erase_info(10000);
	cout << endl;
	cout << "Class Vector: " << endl;
	Set<int> mySet7;
	mySet7.vector_insert_info(100);
	mySet7.vector_insert_info(1000);
	mySet7.vector_insert_info(10000);
	Set<int> mySet8;
	mySet8.vector_contains_info(100);
	mySet8.vector_contains_info(1000);
	mySet8.vector_contains_info(10000);
	Set<int> mySet9;
	mySet9.vector_erase_info(100);
	mySet9.vector_erase_info(1000);
	mySet9.vector_erase_info(10000);
	cout << endl;
	cout << "Variant 1 task: " << endl;
	Set<int> VarSet1;
	Set<int> VarSet2;
	VarSet1.insert(1);
	VarSet1.insert(2);
	VarSet1.insert(3);
	VarSet1.insert(4);
	VarSet1.insert(5);
	VarSet1.insert(6);
	VarSet2.insert(1);
	VarSet2.insert(3);
	VarSet2.insert(6);
	VarSet2.insert(7);
	VarSet2.insert(10);
	Set<int> intersectionSet = intersection<int>(VarSet1, VarSet2);
	Set<int> differenceSet = difference<int>(VarSet1, VarSet2);

	cout << "Intersection: ";
	intersectionSet.print();

	cout << "Difference: ";
	differenceSet.print();
}