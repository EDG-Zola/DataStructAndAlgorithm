#ifndef LINKSTACK_H
#define LINKSTACK_H

#include<iostream>
#include<assert.h>
template<class T>
class LinkStackNode {
public:
	T data;
	LinkStackNode<T>* link;
	LinkStackNode(const T& x) : data(x), link(nullptr) {}
};




/************��LinkStack************/
template<class T>
class LinkStack {
private:
	LinkStackNode<T>* tos;//ջ������
public:
	LinkStack() : tos(nullptr) {}
	void Push(const T &element);
	T& Pop();
	T& GetTop();
	void MakeEmpty();
	bool IsEmpty();
	void print();
};

template<class T>
inline void LinkStack<T>::Push(const T &element) {
	//����ջ
	if(IsEmpty())
		tos = new LinkStackNode<T>(element);

	else {
		LinkStackNode<T>* add = new LinkStackNode<T>(element);
		add->link = tos;
		tos = add;
	}
	
}

template<class T>
inline T & LinkStack<T>::Pop() {
	assert(tos != nullptr);
	LinkStackNode<T>* old = tos;
	T value = old->data;
	tos = tos->link;
	delete old;
	return value;
}

template<class T>
inline T & LinkStack<T>::GetTop() {
	if (tos == nullptr)
		std::cout << "ջΪ��" << std::endl;
	assert(tos != nullptr);
	return tos->data;

}

template<class T>
inline void LinkStack<T>::MakeEmpty() {
	while (!IsEmpty()) {
		this->Pop();
	}
}

template<class T>
inline bool LinkStack<T>::IsEmpty() {
	return tos == nullptr;
}

template<class T>
inline void LinkStack<T>::print() {
	//����ջ��ջΪ��
	if (IsEmpty())
		std::cout << "ջΪ��" << std::endl;
	while (!IsEmpty()) {
		std::cout << Pop() << " ";
	}
	std::cout <<  std::endl;
}

#endif // !LINKSTACK_H

