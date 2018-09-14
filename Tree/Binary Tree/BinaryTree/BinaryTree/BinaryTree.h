#ifndef  BINARYTREE_H
#define BINARYTREE_H
#include <iostream> //遍历树时需要打印节点数据
#include "BinaryTreeNode.h"

template<class T>
class BinaryTree {
private:
	BinaryTreeNode<T>* m_root;

public:
	BinaryTree() : m_root(nullptr) {}
	BinaryTree(const T &data) : m_root(new BinaryTreeNode<T>(data)) {}
	~BinaryTree() {} //默认析构函数
	//判断是否为空树
	bool IsEmpty() const;

	//判断一个节点是否是左孩子
	bool IsLeftChild(BinaryTreeNode<T>* p);

	//判断一个节点是否是右孩子
	bool IsRightChild(BinaryTreeNode<T>* p);

	//取得整棵树的树根
	BinaryTreeNode<T>* GetRoot();

	//取得一个节点的父亲节点指针
	BinaryTreeNode<T>* GetParent(BinaryTreeNode<T>* root, BinaryTreeNode<T>* p);

	//取得一个节点的左子树根指针
	BinaryTreeNode<T>* LeftChild(BinaryTreeNode<T>* p) const;
	
	//取得一个节点的右子树根指针
	BinaryTreeNode<T>* RightChild(BinaryTreeNode<T>* p) const;

	//取得一个节点的左兄弟指针
	BinaryTreeNode<T>* LeftSibling(BinaryTreeNode<T>* p);

	//取得一个节点的右兄弟指针
	BinaryTreeNode<T>* RightSibling(BinaryTreeNode<T>* p);

	//返回一个节点的数据
	T GetNodeData(BinaryTreeNode<T>* p);

	//设置一个节点的数据
	void SetNodeData(BinaryTreeNode<T>* p, const T &data);

	//插入右孩子到当前节点下
	void InsertRightChild(BinaryTreeNode<T>* p, const T &data);

	//插入左孩子到当前节点下
	void InsertLeftChild(BinaryTreeNode<T>* p, const T &data);

	//删除当前节点的右孩子
	void DeleteRightChild(BinaryTreeNode<T>* p);

	//删除当前节点的左孩子
	void DeleteLeftChild(BinaryTreeNode<T>* p);

	//先序遍历整棵树
	void PreOrderTraverse(BinaryTreeNode<T>* root) const;

	//中序遍历整棵树
	void InOrderTraverse(BinaryTreeNode<T>* root) const;

	//后序遍历整棵树
	void PostOrderTraverse(BinaryTreeNode<T>* root) const;

	//按层遍历整棵树
	void LevelOrderTraverse(BinaryTreeNode<T> *root) const;
};


template<class T>
inline bool BinaryTree<T>::IsEmpty() const {
	return m_root == nullptr ? true : false;
}

template<class T>
inline bool BinaryTree<T>::IsLeftChild(BinaryTreeNode<T>* p) {
	return p == GetParent(m_root, p)->GetLeftChild() ? true : false;
}

template<class T>
inline bool BinaryTree<T>::IsRightChild(BinaryTreeNode<T>* p) {
	return p == GetParent(m_root, p)->GetRightChild() ? true : false;
}

template<class T>
inline BinaryTreeNode<T>* BinaryTree<T>::GetRoot() {
	return m_root;
}

template<class T>
inline BinaryTreeNode<T>* BinaryTree<T>::GetParent(BinaryTreeNode<T>* root, BinaryTreeNode<T>* p) {

	//BinaryTreeNode<T> *q;
	if (NULL == root)
		return NULL;

	if ((p == root->GetLeftChild()) || (p == root->GetRightChild()))
		return root;
	//在root的左子节点进行查找
	if (NULL != (GetParent(root->GetLeftChild(), p)))
		return GetParent(root->GetLeftChild(),p);
	//在root的右子节点进行查找
	else
		return GetParent(root->GetRightChild(), p);
}

template<class T>
inline BinaryTreeNode<T>* BinaryTree<T>::LeftChild(BinaryTreeNode<T>* p) const {
	return p->GetLeftChild();
}

template<class T>
inline BinaryTreeNode<T>* BinaryTree<T>::RightChild(BinaryTreeNode<T>* p) const {
	return p->GetRightChild();
}

template<class T>
inline BinaryTreeNode<T>* BinaryTree<T>::LeftSibling(BinaryTreeNode<T>* p){
	BinaryTreeNode<T>* q;
	//查找到p的父节点
	q = GetParent(m_root, p);
	//如果p的父节点为空或p的父节点的左子节点等于p，返回空
	if (q == nullptr || q->GetLeftChild() == p)
		return nullptr;
	else
		return q->GetLeftChild();
}

template<class T>
inline BinaryTreeNode<T>* BinaryTree<T>::RightSibling(BinaryTreeNode<T>* p){
	BinaryTreeNode<T>* q;
	//查找到p的父节点
	q = GetParent(m_root, p);
	//如果p的父节点为空或p的父节点的右子节点等于p，返回空
	if (q == nullptr || q->GetRightChild() == p)
		return nullptr;
	else
		return q->GetRightChild();
}

template<class T>
inline T BinaryTree<T>::GetNodeData(BinaryTreeNode<T>* p) {
	return p->GetData();
}

template<class T>
inline void BinaryTree<T>::SetNodeData(BinaryTreeNode<T>* p, const T & data) {
	p->SetData(data);
}

template<class T>
inline void BinaryTree<T>::InsertRightChild(BinaryTreeNode<T>* p, const T & data) {
	BinaryTreeNode<T>* rightChild = new BinaryTreeNode<T>(data);
	p->SetRightChild(rightChild);
}

template<class T>
inline void BinaryTree<T>::InsertLeftChild(BinaryTreeNode<T>* p, const T & data) {
	BinaryTreeNode<T>* leftChild = new BinaryTreeNode<T>(data);
	p->SetLeftChild(leftChild);
}

template<class T>
inline void BinaryTree<T>::DeleteRightChild(BinaryTreeNode<T>* p) {
	BinaryTreeNode<T>* delNode = p->GetRightChild();
	p->SetRightChild(nullptr);
	delete delNode;
}

template<class T>
inline void BinaryTree<T>::DeleteLeftChild(BinaryTreeNode<T>* p) {
	BinaryTreeNode<T>* delNode = p->GetLeftChild();
	p->SetLeftChild(nullptr);
	delete delNode;
}

template<class T>
inline void BinaryTree<T>::PreOrderTraverse(BinaryTreeNode<T>* root) const {
	if (root != nullptr) {
		std::cout << root->GetData() << " ";
		PreOrderTraverse(root->GetLeftChild());
		PreOrderTraverse(root->GetRightChild());
	}
}

template<class T>
inline void BinaryTree<T>::InOrderTraverse(BinaryTreeNode<T>* root) const {
	if (root != nullptr) {
		InOrderTraverse(root->GetLeftChild());
		std::cout << root->GetData() << " ";
		InOrderTraverse(root->GetRightChild());
	}
}

template<class T>
inline void BinaryTree<T>::PostOrderTraverse(BinaryTreeNode<T>* root) const {
	if (root != nullptr) {
		PostOrderTraverse(root->GetLeftChild());
		PostOrderTraverse(root->GetRightChild());
		std::cout << root->GetData() << " ";
	}
}

template<class T>
void BinaryTree<T>::LevelOrderTraverse(BinaryTreeNode<T> *root) const {
	queue<binarytreenode<t> *> q;
	if (NULL != root)
		q.push(root);

	while (!q.empty()) {
		root = q.front(), q.pop();
		cout << root->GetData();
		if (root->GetLeftChild())
			q.push(root->GetLeftChild());
		if (root->GetRightChild())
			q.push(root->GetRightChild());
	}
}
#endif // ! BINARYTREE_H


