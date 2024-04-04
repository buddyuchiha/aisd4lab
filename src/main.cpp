#include <iostream>
#include <fstream>
#include "..\algorithm\algorithm.h"
using namespace std;
using namespace algorithm;

#include <vector>

std::vector<int> removeDuplicates(std::vector<int> vec) {
	std::vector<int> uniqueVec;

	for (int i = 0; i < vec.size(); ++i) {
		bool isDuplicate = false;
		for (int j = 0; j < uniqueVec.size(); ++j) {
			if (vec[i] == uniqueVec[j]) {
				isDuplicate = true;
				break;
			}
		}
		if (!isDuplicate) {
			uniqueVec.push_back(vec[i]);
		}
	}

	return uniqueVec;
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
	cout << "Variant 4 task: " << endl;
	vector<int> originalVec = { 1, 2, 3, 2, 4, 5, 3, 6, 7, 1 };
	vector<int> uniqueVec = removeDuplicates(originalVec);
	for (int i = 0; i < uniqueVec.size(); ++i) {
		std::cout << uniqueVec[i] << " ";
	}
}