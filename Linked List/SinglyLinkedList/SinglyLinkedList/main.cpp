#include<iostream>
#include "SinglyLinkedList.h"
using namespace std;
int main() {
	List<int> listA;
	listA.AddTail(1);
	listA.AddTail(2);
	listA.AddTail(3);
	listA.InsertAt(0, 1);
	listA.InsertAt(0, 2);
	//����ListNode<T>* GetHead();//���������ͷָ��
	ListNode<int> *pHead = listA.GetHead();
	std::cout << pHead->GetData() << std::endl;

	//����ListNode<T>* GetTail();//���������βָ��
	ListNode<int> *pTail = listA.GetTail();
	std::cout << pTail->GetData() << std::endl;

	//����ListNode<T>* GetNodeAt(int index);//����ָ��index����������
	ListNode<int> *pNode = listA.GetNodeAt(2);
	std::cout << pNode->GetData() << std::endl;

	//���Գ���
	std::cout << listA.GetCount() << std::endl;

	//�����Ƿ�Ϊ��
	bool flag = listA.IsEmpty();
	std::cout << flag << std::endl;
	
	//��ӡ
	listA.print();

	//����ɾ��һ��ָ��ֵ�Ľڵ�
	listA.RemoveValue(4);
	listA.print();
	
	//����ɾ��һ�������Ľڵ�
	flag = listA.RemoveAt(2);
	listA.print();
	std::cout << flag << std::endl;

	//���Է���һ�����������ڵ��ֵ
	int value = listA.GetAt(2);
	std::cout << value << std::endl;

	//����ɾ�����нڵ�
	listA.RemoveAll();
	listA.print();

	system("pause");
}