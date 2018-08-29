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
	//测试ListNode<T>* GetHead();//返回链表表头指针
	ListNode<int> *pHead = listA.GetHead();
	std::cout << pHead->GetData() << std::endl;

	//测试ListNode<T>* GetTail();//返回链表表尾指针
	ListNode<int> *pTail = listA.GetTail();
	std::cout << pTail->GetData() << std::endl;

	//测试ListNode<T>* GetNodeAt(int index);//返回指定index索引的链表
	ListNode<int> *pNode = listA.GetNodeAt(2);
	std::cout << pNode->GetData() << std::endl;

	//测试长度
	std::cout << listA.GetCount() << std::endl;

	//测试是否为空
	bool flag = listA.IsEmpty();
	std::cout << flag << std::endl;
	
	//打印
	listA.print();

	//测试删除一个指定值的节点
	listA.RemoveValue(4);
	listA.print();
	
	//测试删除一个索引的节点
	flag = listA.RemoveAt(2);
	listA.print();
	std::cout << flag << std::endl;

	//测试返回一个给定索引节点的值
	int value = listA.GetAt(2);
	std::cout << value << std::endl;

	//测试删除所有节点
	listA.RemoveAll();
	listA.print();

	system("pause");
}