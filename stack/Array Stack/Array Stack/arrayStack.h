#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include<memory>
#include<assert.h>
template<class T>
class ArrayStack {
private:
	unsigned int size;
	int tos;//ջ������
	std::unique_ptr<T[]> contain;//����ָ������ջ�ռ�
	//T* contain;//ջ�ռ�
public:
	ArrayStack() :size(0), tos(-1), contain(nullptr) {}
	ArrayStack(unsigned int n) : size(n), tos(-1), contain(new T[size]) {}//����n��T����Ԫ�ص�ջ�ռ�
	void Push(const T &element);//��ջ
	T& GetTop();//��ȡջ��Ԫ��
	T& Pop();//��ջ
	void MakeEmpty();//�ÿ�
	bool IsEmpty();//�п�
	void print(); //����ջ��������ջ��ջΪ��

};

//template<class T>
//inline ArrayStack<T>::ArrayStack(unsigned int n) {
//	size = n;
//	tos = -1;
//	contain(new T[size]);
//}

template<class T>
inline void ArrayStack<T>::Push(const T & element) {
	//��ջʱ�ж�ջ�Ƿ�����
	if (tos == size)
		std::cout << "ջ����" << std::endl;
	assert(tos != size - 1);
	contain[++tos] = element;//�ȼ�ջ��������1�������Ԫ��
}

template<class T>
inline T& ArrayStack<T>::GetTop() {
	//�ж�ջ��Ϊ��
	if (tos == -1)
		std::cout << "ջΪ��" << std::endl;
	assert(tos != -1);
	return contain[tos];
}

template<class T>
inline T& ArrayStack<T>::Pop() {
	//�ж�ջ��Ϊ��
	if (tos == -1)
		std::cout << "ջΪ��" << std::endl;
	assert(tos != -1);
	//�ȷ���ջ��Ԫ�أ��ټ�ջ������-1
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
		std::cout << "ջΪ��" << std::endl;
	assert(tos != -1);
	while (tos != -1) {
		std::cout << Pop() << " ";
	}
	std::cout << std::endl;
}

#endif // !ARRAYSTACK_H

