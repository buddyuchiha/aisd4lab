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
	void print();
	bool insert(T _data);
	bool contains(T _data);
	bool erase(T _data);
private:
	Node<T>* _root;
	void clear(Node* _Node){
		if (_Node != nullptr) {
			clear(_Node->left);
			clear(_Node->right);
			delete _Node;
		}
		_root = nullptr;
	}
	void copy(Node*& to, Node* from){
		if (from) {
			to = new Node(from->data);
			copy(to->left, from->left);
			copy(to->right, from->right);
		}
	}
	Set& operator=(const Set& other) {
		if (this != &other) {
			clear(_root);
			copy(_root, other._root);
		}
		return *this;
	}
};

template<typename T>
Set<T>::Set(): _root(nullptr){}

template<typename T>
Set<T>::Set(const Set& other): _root(nullptr){
	copy(_root, other._root)
}

template<typename T>
Set<T>::~Set()
{
	clear(_root)
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

int main() {

}