#pragma once
#include <iostream>
#include <random>
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
	Set& operator=(const Set& other) {
		if (this != &other) {
			clear(_root);
			copy(_root, other._root);
		}
		return *this;
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
bool Set<T>::insert(T _data){
	Node<T>** current = &_root;
	while (*current) {
		if (_data < (*current)->_data) {
			current = &(*current)->_left;
		}
		else if ((*current)->_data < _data) {
			current = &(*current)->_right;
		}
		else {
			return false; 
		}
	}
	*current = new Node(_data);
	return true;
}

template<typename T>
bool Set<T>::contains(T _data)
{
	Node<T>* current = _root;
	while (current) {
		if (_data < current->_data) {
			current = current->_left;
		}
		else if (current->_data < _data) {
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
}

int main() {
	Set<int> mySet;
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
}