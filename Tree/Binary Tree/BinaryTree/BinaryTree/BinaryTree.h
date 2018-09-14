#ifndef  BINARYTREE_H
#define BINARYTREE_H
#include <iostream> //������ʱ��Ҫ��ӡ�ڵ�����
#include "BinaryTreeNode.h"

template<class T>
class BinaryTree {
private:
	BinaryTreeNode<T>* m_root;

public:
	BinaryTree() : m_root(nullptr) {}
	BinaryTree(const T &data) : m_root(new BinaryTreeNode<T>(data)) {}
	~BinaryTree() {} //Ĭ����������
	//�ж��Ƿ�Ϊ����
	bool IsEmpty() const;

	//�ж�һ���ڵ��Ƿ�������
	bool IsLeftChild(BinaryTreeNode<T>* p);

	//�ж�һ���ڵ��Ƿ����Һ���
	bool IsRightChild(BinaryTreeNode<T>* p);

	//ȡ��������������
	BinaryTreeNode<T>* GetRoot();

	//ȡ��һ���ڵ�ĸ��׽ڵ�ָ��
	BinaryTreeNode<T>* GetParent(BinaryTreeNode<T>* root, BinaryTreeNode<T>* p);

	//ȡ��һ���ڵ����������ָ��
	BinaryTreeNode<T>* LeftChild(BinaryTreeNode<T>* p) const;
	
	//ȡ��һ���ڵ����������ָ��
	BinaryTreeNode<T>* RightChild(BinaryTreeNode<T>* p) const;

	//ȡ��һ���ڵ�����ֵ�ָ��
	BinaryTreeNode<T>* LeftSibling(BinaryTreeNode<T>* p);

	//ȡ��һ���ڵ�����ֵ�ָ��
	BinaryTreeNode<T>* RightSibling(BinaryTreeNode<T>* p);

	//����һ���ڵ������
	T GetNodeData(BinaryTreeNode<T>* p);

	//����һ���ڵ������
	void SetNodeData(BinaryTreeNode<T>* p, const T &data);

	//�����Һ��ӵ���ǰ�ڵ���
	void InsertRightChild(BinaryTreeNode<T>* p, const T &data);

	//�������ӵ���ǰ�ڵ���
	void InsertLeftChild(BinaryTreeNode<T>* p, const T &data);

	//ɾ����ǰ�ڵ���Һ���
	void DeleteRightChild(BinaryTreeNode<T>* p);

	//ɾ����ǰ�ڵ������
	void DeleteLeftChild(BinaryTreeNode<T>* p);

	//�������������
	void PreOrderTraverse(BinaryTreeNode<T>* root) const;

	//�������������
	void InOrderTraverse(BinaryTreeNode<T>* root) const;

	//�������������
	void PostOrderTraverse(BinaryTreeNode<T>* root) const;

	//�������������
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
	//��root�����ӽڵ���в���
	if (NULL != (GetParent(root->GetLeftChild(), p)))
		return GetParent(root->GetLeftChild(),p);
	//��root�����ӽڵ���в���
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
	//���ҵ�p�ĸ��ڵ�
	q = GetParent(m_root, p);
	//���p�ĸ��ڵ�Ϊ�ջ�p�ĸ��ڵ�����ӽڵ����p�����ؿ�
	if (q == nullptr || q->GetLeftChild() == p)
		return nullptr;
	else
		return q->GetLeftChild();
}

template<class T>
inline BinaryTreeNode<T>* BinaryTree<T>::RightSibling(BinaryTreeNode<T>* p){
	BinaryTreeNode<T>* q;
	//���ҵ�p�ĸ��ڵ�
	q = GetParent(m_root, p);
	//���p�ĸ��ڵ�Ϊ�ջ�p�ĸ��ڵ�����ӽڵ����p�����ؿ�
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


