#ifndef SINGLYLINKEDLIST_H

#define SINGLYLINKEDLIST_H
#include<iostream>
/*
*单向链表节点类
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
*单向链表类
*/
template<class T>
class List {
	ListNode<T>* head = new ListNode<T>();//类内初始化，这里不能初始化为nullptr，必须创建一个ListNode<T>的节点
	ListNode<T>* tail = head;//类内初始化
public:
	List() = default;
	List(ListNode<T>* _head, ListNode<T>* _tail) : head(_head), tail(_tail) {}
	~List() {};
	//插入
	bool AddTail(const T &value);//从链表表尾添加节点
	bool InsertAt(int index, const T &value);//从指定的index索引处添加值value
	//删除
	bool RemoveTail();//删除链表表尾节点
	bool RemoveAll();//删除所有节点
	bool RemoveAt(int index);//删除指定index索引处的节点
	void RemoveValue(const T &value);//删除链表中所有的给定value的值，并返回链表
	//获取
	T GetAt(int index);//获取指定index索引的值
	int GetCount();//获取链表长度
	ListNode<T>* GetHead();//返回链表表头指针
	ListNode<T>* GetTail();//返回链表表尾指针
	ListNode<T>* GetNodeAt(int index);//返回指定index索引的链表
	ListNode<T>* GetCur();//返回当前链表指针
	ListNode<T>* TowardCur();//使当前节点cur向后移动一个节点，并返回移动后的cur
	//判断是否为空
	bool IsEmpty();
	//打印
	void print();//打印链表中的值

};

//template<class T>
//inline List<T>::List() {
//	head = new ListNode<T>();
//	tail = head;
//	tail->SetLink(nullptr);
//}


template<class T>
inline bool List<T>::AddTail(const T &value) {
	ListNode<T>* add = new ListNode<T>(value);//创建一个新的节点
	tail->SetLink(add);//将tail节点指向新创建的节点
					   //tail节点向下移动一步,并把tail节点指向nullptr
	tail = tail->GetLink();
	tail->SetLink(nullptr);
	
   //添加一个节点后，tail节点不为空
	if (tail != nullptr)
		return true;
	else
		return false;
}

template<class T>
inline bool List<T>::InsertAt(int index, const T &value) {
	//判断索引值是否正确
	if (index > this->GetCount() - 1 || index < 0) {
		std::cout << "A wrong position!\n";
		return false;
	}
	//遍历cur到要插入的索引index处
	ListNode<T>* cur = head;
	while (index) {
		cur = cur->GetLink();
		index--;
	}
	ListNode<T>* add = new ListNode<T>(value);
	add->SetLink(cur->GetLink());//将add节点指向当前节点cur的下一个节点
	cur->SetLink(add);//将当前节点指向add节点
					  //由于当前节点的下一节点插入了add节点，所以当前节点不是表尾节点
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
		cur = head->GetLink();//当前节点指向表头节点
		head->SetLink(cur->GetLink());//表头节点继续前进一步
		delete cur;//删除当前节点
	}
	tail = head;//置表尾节点到表头处
	if (head->GetLink() == nullptr)
		return true;
	else
		return false;
}

template<class T>
inline bool List<T>::RemoveAt(int index) {
	//判断索引值是否正确
	if (index > this->GetCount() - 1 || index < 0) {
		std::cout << "A wrong position!\n";
		return false;
	}
	//用两个节点，cur指向要删除节点的前一个节点，delNode指向要删除的节点
	ListNode<T>* cur = head;
	ListNode<T>* delNode = cur->GetLink();
	//遍历到要删除的节点
	while (index) {
		cur = cur->GetLink();
		delNode = delNode->GetLink();
		index--;
	}
	//如果要删除的节点为尾节点，则把tail置为cur
	if (tail == delNode) {
		tail = cur;
	}
	cur->SetLink(delNode->GetLink());//当前节点指向删除节点的下一个节点
	delete delNode;
	if (delNode != nullptr)
		return true;
	else
		return false;
}

template<class T>
inline void List<T>::RemoveValue(const T &value) {
	ListNode<T>* cur = head;//当前节点从dummyHead节点开始遍历
	 //如果当前节点不为尾节点
	while (cur->GetLink() != nullptr) {
		//如果当前节点的下一个节点内的值等于给定的要删除的值，
		//则删除当前节点的下一个节点
		//否则，继续前进一步
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
	//判断索引值是否正确
	if (index > this->GetCount() - 1 || index < 0) {
		std::cout << "A wrong position!\n";
	}
	ListNode<T>* cur = head->GetLink();
	while (index) {
		cur = cur->GetLink();
		index--;
	}
	//将T转换为T&lei
	T res = cur->GetData();
	T &result = res;
	return cur->GetData();
	// TODO: 在此处插入 return 语句
}

template<class T>
inline int List<T>::GetCount() {
	int count = 0;
	ListNode<T>* cur = head->GetLink();//从表头节点的下一节点开始数
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
	//判断索引值是否正确
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
	ListNode<T>* cur = head->GetLink();//从表头节点的下一节点开始打印
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
//*单向链表节点 Singly Linked List Node
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
//*单向链表 Singly Linked List
//*/
//
//template<typename T>
//class SLList {
//private:
//	SLListNode<T> *head, *tail;
//public:
//	//构造函数
//	SLList(SLListNode<T> *phead = nullptr, SLListNode<T> *ptail = nullptr) : head(phead), tail(ptail) {}
//	//析构函数
//	~SLList() {}
//	//判断为空
//	bool isempty();
//	//返回链表长度
//	size_t size(const SLListNode<T> &list);
//	//从链表头添加数据
//	void addToHead(const T &x);
//	//从链表尾添加数据
//	void addToTail(const T &x);
//	//从链表头删除数据，并返回该数据
//	T deleteFromHead();
//	//从链表尾删除数据，并返回该数据
//	T deleteFromTail();
//	//删除某个数据的节点，返回是否删除成功
//	bool deleteNode(const T &x);
//	//判断某个数据是否在链表中
//	bool isInList(const T &x);
//	//打印链表中的数据
//	void print();
//};
//
//
////判断是否为空链表
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
////从链表头添加数据
//template<typename T>
//inline void SLList<T>::addToHead(const T &x) {
//	head = new SLListNode<T>(x, head);
//	//当为空链表时，tail与head都指向刚刚插入的节点
//	if (tail == nullptr)
//		tail = head;
//
//}
//
////从链表尾添加数据
//template<typename T>
//inline void SLList<T>::addToTail(const T &x) {
//	if (tail != nullptr) {
//		tail->next = new SLListNode<T>(x, nullptr);
//		tail = tail->next;
//	}
//	//当为空链表时，tail与head都指向刚刚插入的节点
//	else
//		tail = head = new SLListNode<T>(x, nullptr);
//}
//
////从链表头删除数据，并返回该数据
//template<typename T>
//inline T SLList<T>::deleteFromHead() {
//	assert(!isempty());
//	/******************BUG,head一直为nullptr***********************/
//
//	//判断是否只有一个节点
//	if (head == tail) {
//		T x = head->data;
//		SLListNode<T> *tmp = head;
//		head = tail = nullptr;//删除唯一的节点后，链表为空
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
////从链表尾删除数据，并返回该数据
//template<typename T>
//inline T SLList<T>::deleteFromTail() {
//	assert(!isempty());
//	/******************BUG,head一直为nullptr***********************/
//
//	//判断是否只有一个节点
//	if (head == tail) {
//		T x = tail->data;
//		SLListNode<T> *tmp = tail;
//		head = tail = nullptr;//删除唯一的节点后，链表为空
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
//		std::cout << "链表为空！\n";
//	}
//	else {
//		std::cout << "链表数据如下：\n";
//		for (; head != nullptr; head = head->next) {
//			std::cout << head->data << " ";
//		}
//		std::cout << std::endl;
//	}
//}
//
//

