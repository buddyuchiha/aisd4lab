#pragma once
#include <iostream>
#include <random>
#include <chrono>
#include <vector>
using namespace std;

template <typename T>
struct Node {
	T _data;
	Node* _right;
	Node* _left;
	Node(T data) : _data(data), _right(nullptr), _left(nullptr) {};
};

template <typename T>
class Set {
public:
	Set();
	~Set();
	Set(const Set& other);
	void helper(Node<T>* _Node);
	void print();
	bool insert(T _data);
	bool contains(T _data);
	bool erase(T _data);
	void set_insert_info(size_t size);
	void set_contains_info(size_t size);
	void set_erase_info(size_t size);
	void vector_insert_info(size_t size);
	void vector_contains_info(size_t size);
	void vector_erase_info(size_t size);
	Set& operator=(const Set& other) {
		if (this != &other) {
			clear(_root);
			copy(_root, other._root);
		}
		return *this;
	}
	size_t lcg() {
		static size_t x = 0;
		x = (1021 * x + 24631) % 116640;
		return x;
	}
private:
	Node<T>* _root;
	void clear(Node<T>* _Node){
		if (_Node != nullptr) {
			clear(_Node->_left);
			clear(_Node->_right);
			delete _Node;
		}
		_root = nullptr;
	}
	void copy(Node<T>*& to, Node<T>* from){
		if (from) {
			to = new Node(from->_data);
			copy(to->_left, from->_left);
			copy(to->_right, from->_right);
		}
	}
	
};

template<typename T>
Set<T>::Set(): _root(nullptr){}


template<typename T>
Set<T>::Set(const Set& other): _root(nullptr){
	copy(_root, other._root);
}

template<typename T>
Set<T>::~Set()
{
	clear(_root);
}

template<typename T>
void Set<T>::helper(Node<T>* _Node)
{
	if (_Node) {
		helper(_Node->_left);
		cout << _Node->_data << " ";
		helper(_Node->_right);
	}
}

template<typename T>
void Set<T>::print()
{
	helper(_root);
	cout << endl;
}

template<typename T>
bool Set<T>::insert(T data){
	Node<T>** current = &_root;
	while (*current) {
		if (data < (*current)->_data) {
			current = &(*current)->_left;
		}
		else if ((*current)->_data < data) {
			current = &(*current)->_right;
		}
		else {
			return false; 
		}
	}
	*current = new Node(data);
	return true;
}

template<typename T>
bool Set<T>::contains(T data)
{
	Node<T>* current = _root;
	while (current) {
		if (data < current->_data) {
			current = current->_left;
		}
		else if (current->_data < data) {
			current = current->_right;
		}
		else {
			return true; 
		}
	}
	return false; 
}

template<typename T>
bool Set<T>::erase(T _data)
{
	Node<T>** current = &_root;
	while (*current) {
		if (_data < (*current)->_data) {
			current = &(*current)->_left;
		}
		else if ((*current)->_data < _data) {
			current = &(*current)->_right;
		}
		else {
			Node<T>* _Node = *current;
			if (!_Node->_left) {
				*current = _Node->_right;
				delete _Node;
			}
			else if (!_Node->_right) {
				*current = _Node->_left;
				delete _Node;
			}
			else {
				Node<T>** minNode = &(_Node->_right);
				while ((*minNode)->_left) {
					minNode = &((*minNode)->_left);
				}
				_Node->_data = (*minNode)->_data;
				_Node = *minNode;
				*minNode = (*minNode)->_right;
				delete _Node;
			}
			return true; 
		}
	}
	return false; 
}

template<typename T>
void Set<T>::set_insert_info(size_t size){
	Set<int> data;
	double result = 0.0;
	for (size_t i = 0; i < 100; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		for (size_t j = 0; j < size; j++) {
			data.insert(lcg());
		}
		auto end = std::chrono::high_resolution_clock::now();

		double seconds = std::chrono::duration<double>(end - start).count();
		result += seconds / 100;
	}

	cout << "Set insert method with " << size << " numbers take: " << result << endl;
}

template<typename T>
void Set<T>::set_contains_info(size_t size) {
	Set<int> data;
	double result = 0.0;
	for (size_t i = 0; i < size; i++) {
		data.insert(lcg());
	}
	for (size_t i = 0; i < 1000; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		data.contains(lcg());
		auto end = std::chrono::high_resolution_clock::now();
		double seconds = std::chrono::duration<double>(end - start).count();
		result += seconds / 1000;
	}

	cout << "Set find method with " << size << " numbers take: " << result << endl;
}


template<typename T>
void Set<T>::set_erase_info(size_t size) {
	Set<int> data;
	double result = 0.0;
	for (size_t i = 0; i < size; i++) {
		data.insert(lcg());
	}
	auto start = std::chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000; i++) {
		data.insert(lcg());
		data.erase(lcg());
		auto end = std::chrono::high_resolution_clock::now();
		double seconds = std::chrono::duration<double>(end - start).count();
		result += seconds / 1000;
	}

	cout << "Set erase method with " << size << " numbers take: " << result << endl;
}

template<typename T>
void Set<T>::vector_insert_info(size_t size) {
	vector<int> data;
	double result = 0.0;
	for (size_t i = 0; i < 100; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		for (size_t j = 0; j < size; j++) {
			data.push_back(lcg());
		}
		auto end = std::chrono::high_resolution_clock::now();

		double seconds = std::chrono::duration<double>(end - start).count();
		result += seconds / 100;
	}
	cout << "Vector insert method with " << size << " numbers take: " << result << endl;
}

template<typename T>
void Set<T>::vector_contains_info(size_t size)
{
	vector<int> data;
	double result = 0.0;
	for (size_t i = 0; i < size; i++) {
		data.push_back(lcg());
	}
	for (size_t i = 0; i < 1000; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		std::find(data.begin(), data.end(), lcg());
		auto end = std::chrono::high_resolution_clock::now();
		double seconds = std::chrono::duration<double>(end - start).count();
		result += seconds / 1000;
	}
	cout << "Vector contains method with " << size << " numbers take: " << result << endl;
}

template<typename T>
void Set<T>::vector_erase_info(size_t size)
{
	vector<int> data;
	double result = 0.0;
	for (size_t i = 0; i < size; i++) {
		data.push_back(lcg());
	}
	auto start = std::chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000; i++) {
		data.push_back(lcg());
		data.pop_back();
		auto end = std::chrono::high_resolution_clock::now();
		double seconds = std::chrono::duration<double>(end - start).count();
		result += seconds / 1000;
	}

	cout << "Vector erase method with " << size << " numbers take: " << result << endl;
}





int main() {
	/*Set<int> mySet;
	Set<int> mySet2;
	Set<int> mySet3;

	mySet.insert(7);
	mySet.insert(2);
	mySet.insert(3);
	mySet.insert(10);
	mySet.insert(20);
	mySet.insert(300);
	mySet.print();
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
	if (mySet3.contains(70)) {
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
	}*/
	
	cout << "Class Set: " << endl;
	Set<int> mySet;
	mySet.set_insert_info(100);
	mySet.set_insert_info(1000);
	mySet.set_insert_info(10000);
	Set<int> mySet1;
	mySet1.set_contains_info(100);
	mySet1.set_contains_info(1000);
	mySet1.set_contains_info(10000);
	Set<int> mySet2;
	mySet1.set_erase_info(100);
	mySet1.set_erase_info(1000);
	mySet1.set_erase_info(10000);
	cout << endl;
	cout << "Class Vector: " << endl;
	Set<int> mySet3;
	mySet3.vector_insert_info(100);
	mySet3.vector_insert_info(1000);
	mySet3.vector_insert_info(10000);
	Set<int> mySet4;
	mySet4.vector_contains_info(100);
	mySet4.vector_contains_info(1000);
	mySet4.vector_contains_info(10000);
	Set<int> mySet5;
	mySet5.vector_erase_info(100);
	mySet5.vector_erase_info(1000);
	mySet5.vector_erase_info(10000);

}