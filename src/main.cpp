#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T _data;
	Node* _right;
	Node* _left;
	Node(T data, Node* left = nullptr, Node* right = nullptr): _data(data), _right(right), _left(left);
};

template <typename T>
class Set {
public:
	Set();
	~Set();
	void print();
	bool insert(T _data);
	bool contains(T _data);
	bool erase(T _data);
private:
	Node<T>* _root;
	void clear(){}
};

template<typename T>
Set<T>::Set()
{
}

template<typename T>
Set<T>::~Set()
{
}

template<typename T>
void Set<T>::print()
{
}

template<typename T>
bool Set<T>::insert(T _data)
{
	return false;
}

template<typename T>
bool Set<T>::contains(T _data)
{
	return false;
}

template<typename T>
bool Set<T>::erase(T _data)
{
	return false;
}
