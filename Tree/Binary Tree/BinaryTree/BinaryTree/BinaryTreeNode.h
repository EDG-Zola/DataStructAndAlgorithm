#ifndef  BINARYTREENODE_H
#define BINARYTREENODE_H

template  <class T>
class BinaryTreeNode {
private:
	T m_data;
	BinaryTreeNode<T>* m_leftChid;
	BinaryTreeNode<T>* m_rightChid;
public:
	BinaryTreeNode() : m_leftChid(nullptr), m_rightChid(nullptr) { }
	BinaryTreeNode(const T& data) : m_data(data), m_leftChid(nullptr), m_rightChid(nullptr) { }
	~BinaryTreeNode() {}//默认析构函数
	//getter and setter
	T& GetData();
	BinaryTreeNode<T>* GetLeftChild();
	BinaryTreeNode<T>* GetRightChild();
	void SetData(const T &data);
	void SetLeftChild(BinaryTreeNode<T>* leftChild);
	void SetRightChild(BinaryTreeNode<T>* rightChild);
};


template<class T>
inline T & BinaryTreeNode<T>::GetData() {
	// TODO: 在此处插入 return 语句
	return m_data;
}

template<class T>
inline BinaryTreeNode<T>* BinaryTreeNode<T>::GetLeftChild() {
	return m_leftChid;
}

template<class T>
inline BinaryTreeNode<T>* BinaryTreeNode<T>::GetRightChild() {
	return m_rightChid;
}

template<class T>
inline void BinaryTreeNode<T>::SetData(const T & data) {
	m_data = data;
}

template<class T>
inline void BinaryTreeNode<T>::SetLeftChild(BinaryTreeNode<T>* leftChild) {
	m_leftChid = leftChild;
}

template<class T>
inline void BinaryTreeNode<T>::SetRightChild(BinaryTreeNode<T>* rightChild) {
	m_rightChid = rightChild;
}


#endif // ! BINARYTREENODE_H

