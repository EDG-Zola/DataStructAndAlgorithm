#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include<memory>
#include<assert.h>
template<class T>
class ArrayStack {
private:
	unsigned int size;
	int tos;//栈顶索引
	std::unique_ptr<T[]> contain;//智能指针管理的栈空间
	//T* contain;//栈空间
public:
	ArrayStack() :size(0), tos(-1), contain(nullptr) {}
	ArrayStack(unsigned int n) : size(n), tos(-1), contain(new T[size]) {}//分配n个T类型元素的栈空间
	void Push(const T &element);//入栈
	T& GetTop();//获取栈顶元素
	T& Pop();//出栈
	void MakeEmpty();//置空
	bool IsEmpty();//判空
	void print(); //遍历栈，遍历完栈后，栈为空

};

//template<class T>
//inline ArrayStack<T>::ArrayStack(unsigned int n) {
//	size = n;
//	tos = -1;
//	contain(new T[size]);
//}

template<class T>
inline void ArrayStack<T>::Push(const T & element) {
	//入栈时判断栈是否已满
	if (tos == size)
		std::cout << "栈已满" << std::endl;
	assert(tos != size - 1);
	contain[++tos] = element;//先见栈顶索引加1，再添加元素
}

template<class T>
inline T& ArrayStack<T>::GetTop() {
	//判断栈不为空
	if (tos == -1)
		std::cout << "栈为空" << std::endl;
	assert(tos != -1);
	return contain[tos];
}

template<class T>
inline T& ArrayStack<T>::Pop() {
	//判断栈不为空
	if (tos == -1)
		std::cout << "栈为空" << std::endl;
	assert(tos != -1);
	//先返回栈顶元素，再见栈顶索引-1
	return contain[tos--];
}

template<class T>
inline void ArrayStack<T>::MakeEmpty() {
	contain.release();
	tos = -1;
}

template<class T>
inline bool ArrayStack<T>::IsEmpty() {
	return tos == -1;
}

template<class T>
inline void ArrayStack<T>::print() {
	if (tos == -1)
		std::cout << "栈为空" << std::endl;
	assert(tos != -1);
	while (tos != -1) {
		std::cout << Pop() << " ";
	}
	std::cout << std::endl;
}

#endif // !ARRAYSTACK_H

