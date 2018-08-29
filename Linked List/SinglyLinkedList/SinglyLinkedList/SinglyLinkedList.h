#ifndef SINGLYLINKEDLIST_H

#define SINGLYLINKEDLIST_H
#include<iostream>
/*
*��������ڵ���
*/

template<class T>
class ListNode {
	T data;
	ListNode<T>* link;
public:	
	ListNode() : link(nullptr) {}
	ListNode(T value) : data(value), link(nullptr) {}
	~ListNode() {};
	//setter and getter
	void SetLink(ListNode<T>* next);
	void SetData(const T &value);
	ListNode<T>* GetLink();
	T GetData();
};


template<class T>
inline void ListNode<T>::SetLink(ListNode<T>* next) {
	link = next;
}

template<class T>
inline void ListNode<T>::SetData(const T &value) {
	data = value;
}

template<class T>
inline ListNode<T>* ListNode<T>::GetLink() {
	return link;
}

template<class T>
inline T ListNode<T>::GetData() {
	return data;
}

/*
*����������
*/
template<class T>
class List {
	ListNode<T>* head = new ListNode<T>();//���ڳ�ʼ�������ﲻ�ܳ�ʼ��Ϊnullptr�����봴��һ��ListNode<T>�Ľڵ�
	ListNode<T>* tail = head;//���ڳ�ʼ��
public:
	List() = default;
	List(ListNode<T>* _head, ListNode<T>* _tail) : head(_head), tail(_tail) {}
	~List() {};
	//����
	bool AddTail(const T &value);//�������β��ӽڵ�
	bool InsertAt(int index, const T &value);//��ָ����index���������ֵvalue
	//ɾ��
	bool RemoveTail();//ɾ�������β�ڵ�
	bool RemoveAll();//ɾ�����нڵ�
	bool RemoveAt(int index);//ɾ��ָ��index�������Ľڵ�
	void RemoveValue(const T &value);//ɾ�����������еĸ���value��ֵ������������
	//��ȡ
	T GetAt(int index);//��ȡָ��index������ֵ
	int GetCount();//��ȡ������
	ListNode<T>* GetHead();//���������ͷָ��
	ListNode<T>* GetTail();//���������βָ��
	ListNode<T>* GetNodeAt(int index);//����ָ��index����������
	ListNode<T>* GetCur();//���ص�ǰ����ָ��
	ListNode<T>* TowardCur();//ʹ��ǰ�ڵ�cur����ƶ�һ���ڵ㣬�������ƶ����cur
	//�ж��Ƿ�Ϊ��
	bool IsEmpty();
	//��ӡ
	void print();//��ӡ�����е�ֵ

};

//template<class T>
//inline List<T>::List() {
//	head = new ListNode<T>();
//	tail = head;
//	tail->SetLink(nullptr);
//}


template<class T>
inline bool List<T>::AddTail(const T &value) {
	ListNode<T>* add = new ListNode<T>(value);//����һ���µĽڵ�
	tail->SetLink(add);//��tail�ڵ�ָ���´����Ľڵ�
					   //tail�ڵ������ƶ�һ��,����tail�ڵ�ָ��nullptr
	tail = tail->GetLink();
	tail->SetLink(nullptr);
	
   //���һ���ڵ��tail�ڵ㲻Ϊ��
	if (tail != nullptr)
		return true;
	else
		return false;
}

template<class T>
inline bool List<T>::InsertAt(int index, const T &value) {
	//�ж�����ֵ�Ƿ���ȷ
	if (index > this->GetCount() - 1 || index < 0) {
		std::cout << "A wrong position!\n";
		return false;
	}
	//����cur��Ҫ���������index��
	ListNode<T>* cur = head;
	while (index) {
		cur = cur->GetLink();
		index--;
	}
	ListNode<T>* add = new ListNode<T>(value);
	add->SetLink(cur->GetLink());//��add�ڵ�ָ��ǰ�ڵ�cur����һ���ڵ�
	cur->SetLink(add);//����ǰ�ڵ�ָ��add�ڵ�
					  //���ڵ�ǰ�ڵ����һ�ڵ������add�ڵ㣬���Ե�ǰ�ڵ㲻�Ǳ�β�ڵ�
	if (cur->GetLink() != nullptr)
		return true;
	else
		return false;
}

template<class T>
inline bool List<T>::RemoveTail() {
	return RemoveAt(this->GetCount()-1);
}

template<class T>
inline bool List<T>::RemoveAll() {
	ListNode<T>* cur;
	while (head->GetLink() != nullptr) {
		cur = head->GetLink();//��ǰ�ڵ�ָ���ͷ�ڵ�
		head->SetLink(cur->GetLink());//��ͷ�ڵ����ǰ��һ��
		delete cur;//ɾ����ǰ�ڵ�
	}
	tail = head;//�ñ�β�ڵ㵽��ͷ��
	if (head->GetLink() == nullptr)
		return true;
	else
		return false;
}

template<class T>
inline bool List<T>::RemoveAt(int index) {
	//�ж�����ֵ�Ƿ���ȷ
	if (index > this->GetCount() - 1 || index < 0) {
		std::cout << "A wrong position!\n";
		return false;
	}
	//�������ڵ㣬curָ��Ҫɾ���ڵ��ǰһ���ڵ㣬delNodeָ��Ҫɾ���Ľڵ�
	ListNode<T>* cur = head;
	ListNode<T>* delNode = cur->GetLink();
	//������Ҫɾ���Ľڵ�
	while (index) {
		cur = cur->GetLink();
		delNode = delNode->GetLink();
		index--;
	}
	//���Ҫɾ���Ľڵ�Ϊβ�ڵ㣬���tail��Ϊcur
	if (tail == delNode) {
		tail = cur;
	}
	cur->SetLink(delNode->GetLink());//��ǰ�ڵ�ָ��ɾ���ڵ����һ���ڵ�
	delete delNode;
	if (delNode != nullptr)
		return true;
	else
		return false;
}

template<class T>
inline void List<T>::RemoveValue(const T &value) {
	ListNode<T>* cur = head;//��ǰ�ڵ��dummyHead�ڵ㿪ʼ����
	 //�����ǰ�ڵ㲻Ϊβ�ڵ�
	while (cur->GetLink() != nullptr) {
		//�����ǰ�ڵ����һ���ڵ��ڵ�ֵ���ڸ�����Ҫɾ����ֵ��
		//��ɾ����ǰ�ڵ����һ���ڵ�
		//���򣬼���ǰ��һ��
		if (cur->GetLink()->GetData() == value) {
			ListNode<T>* delNode = cur->GetLink();
			cur->SetLink(delNode->GetLink());
			delete delNode;
		}
		else
			cur = cur->GetLink();
	}
}


template<class T>
inline T List<T>::GetAt(int index) {
	//�ж�����ֵ�Ƿ���ȷ
	if (index > this->GetCount() - 1 || index < 0) {
		std::cout << "A wrong position!\n";
	}
	ListNode<T>* cur = head->GetLink();
	while (index) {
		cur = cur->GetLink();
		index--;
	}
	//��Tת��ΪT&lei
	T res = cur->GetData();
	T &result = res;
	return cur->GetData();
	// TODO: �ڴ˴����� return ���
}

template<class T>
inline int List<T>::GetCount() {
	int count = 0;
	ListNode<T>* cur = head->GetLink();//�ӱ�ͷ�ڵ����һ�ڵ㿪ʼ��
	while (cur != nullptr) {
		count++;
		cur = cur->GetLink();
	}
	return count;
}

template<class T>
inline ListNode<T>* List<T>::GetHead() {
	ListNode<T>* cur = head->GetLink();
	return cur;
}

template<class T>
inline ListNode<T>* List<T>::GetTail() {
	return tail;
}

template<class T>
inline ListNode<T>* List<T>::GetNodeAt(int index) {
	//�ж�����ֵ�Ƿ���ȷ
	if (index > this->GetCount() - 1 || index < 0) {
		std::cout << "A wrong position!\n";
	}
	ListNode<T>* cur = head->GetLink();
	while (index) {
		cur = cur->GetLink();
		index--;
	}
	return cur;
}

template<class T>
inline bool List<T>::IsEmpty() {
	return head->GetLink() == nullptr;
}

template<class T>
inline void List<T>::print() {
	ListNode<T>* cur = head->GetLink();//�ӱ�ͷ�ڵ����һ�ڵ㿪ʼ��ӡ
	while (cur != nullptr) {
		std::cout << cur->GetData() << " ";
		cur = cur->GetLink();
	}
	std::cout << std::endl;
}

#endif // !SINGLYLINKEDLIST_H


//#include<iostream>
//#include<assert.h>
///*
//*��������ڵ� Singly Linked List Node
//*/
//template<typename T>
//struct SLListNode {
//	T data;
//	SLListNode *next;
//	SLListNode() {}
//	SLListNode(const T& datainfo) : data(datainfo) {}
//	SLListNode(const T& datainfo, SLListNode *p = nullptr) : data(datainfo), next(p) {}
//	~SLListNode() {}
//};
//
//
//
///*
//*�������� Singly Linked List
//*/
//
//template<typename T>
//class SLList {
//private:
//	SLListNode<T> *head, *tail;
//public:
//	//���캯��
//	SLList(SLListNode<T> *phead = nullptr, SLListNode<T> *ptail = nullptr) : head(phead), tail(ptail) {}
//	//��������
//	~SLList() {}
//	//�ж�Ϊ��
//	bool isempty();
//	//����������
//	size_t size(const SLListNode<T> &list);
//	//������ͷ�������
//	void addToHead(const T &x);
//	//������β�������
//	void addToTail(const T &x);
//	//������ͷɾ�����ݣ������ظ�����
//	T deleteFromHead();
//	//������βɾ�����ݣ������ظ�����
//	T deleteFromTail();
//	//ɾ��ĳ�����ݵĽڵ㣬�����Ƿ�ɾ���ɹ�
//	bool deleteNode(const T &x);
//	//�ж�ĳ�������Ƿ���������
//	bool isInList(const T &x);
//	//��ӡ�����е�����
//	void print();
//};
//
//
////�ж��Ƿ�Ϊ������
//template<typename T>
//inline bool SLList<T>::isempty() {
//	return head == nullptr;
//}
//
//template<typename T>
//inline size_t SLList<T>::size(const SLListNode<T>& list) {
//	return size_t();
//}
//
////������ͷ�������
//template<typename T>
//inline void SLList<T>::addToHead(const T &x) {
//	head = new SLListNode<T>(x, head);
//	//��Ϊ������ʱ��tail��head��ָ��ող���Ľڵ�
//	if (tail == nullptr)
//		tail = head;
//
//}
//
////������β�������
//template<typename T>
//inline void SLList<T>::addToTail(const T &x) {
//	if (tail != nullptr) {
//		tail->next = new SLListNode<T>(x, nullptr);
//		tail = tail->next;
//	}
//	//��Ϊ������ʱ��tail��head��ָ��ող���Ľڵ�
//	else
//		tail = head = new SLListNode<T>(x, nullptr);
//}
//
////������ͷɾ�����ݣ������ظ�����
//template<typename T>
//inline T SLList<T>::deleteFromHead() {
//	assert(!isempty());
//	/******************BUG,headһֱΪnullptr***********************/
//
//	//�ж��Ƿ�ֻ��һ���ڵ�
//	if (head == tail) {
//		T x = head->data;
//		SLListNode<T> *tmp = head;
//		head = tail = nullptr;//ɾ��Ψһ�Ľڵ������Ϊ��
//		delete tmp;
//		return x;
//	}
//	else {
//		T x = head->data;
//		SLListNode<T> *tmp = head;
//		head = head->next;
//		delete tmp;
//		return x;
//	}
//
//}
//
////������βɾ�����ݣ������ظ�����
//template<typename T>
//inline T SLList<T>::deleteFromTail() {
//	assert(!isempty());
//	/******************BUG,headһֱΪnullptr***********************/
//
//	//�ж��Ƿ�ֻ��һ���ڵ�
//	if (head == tail) {
//		T x = tail->data;
//		SLListNode<T> *tmp = tail;
//		head = tail = nullptr;//ɾ��Ψһ�Ľڵ������Ϊ��
//		delete tmp;
//		return x;
//	}
//	else {
//		T x = tail->data;
//		SLListNode<T> *tmp = tail;
//		head = head->next;
//		delete tmp;
//		return x;
//	}
//}
//
//template<typename T>
//inline bool SLList<T>::deleteNode(const T &x) {
//	return false;
//}
//
//template<typename T>
//inline bool SLList<T>::isInList(const T &x) {
//	return false;
//}
//
//template<typename T>
//inline void SLList<T>::print() {
//	if (head == nullptr) {
//		std::cout << "����Ϊ�գ�\n";
//	}
//	else {
//		std::cout << "�����������£�\n";
//		for (; head != nullptr; head = head->next) {
//			std::cout << head->data << " ";
//		}
//		std::cout << std::endl;
//	}
//}
//
//

