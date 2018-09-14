#include<iostream>
#include "BinaryTree.h"
#include "BinaryTreeNode.h"
using namespace std;
int main() {
	BinaryTree<char> myBinTree('A');
	myBinTree.PreOrderTraverse(myBinTree.GetRoot());
	cout << endl;

	//1.��ӽڵ�
	myBinTree.InsertLeftChild(myBinTree.GetRoot(), 'B');//�ڸ��ڵ��������ڵ�'B'
	myBinTree.InsertRightChild(myBinTree.GetRoot(), 'C');//�ڸ��ڵ�������ҽڵ�'B'

	myBinTree.InsertLeftChild(myBinTree.GetRoot()->GetLeftChild(), 'D');//��B�������ڵ�'D'
	myBinTree.InsertRightChild(myBinTree.GetRoot()->GetLeftChild(), 'E');//��B������ҽڵ�'E'

	myBinTree.InsertLeftChild(myBinTree.GetRoot()->GetRightChild(), 'F');//��C�������ڵ�'F'
	myBinTree.InsertRightChild(myBinTree.GetRoot()->GetRightChild(), 'G');//��C������ҽڵ�'G'

	myBinTree.PreOrderTraverse(myBinTree.GetRoot());
	cout << endl;
	
	//2.��ȡF�ĸ��ڵ�
	BinaryTreeNode<char>* F = myBinTree.GetRoot()->GetRightChild()->GetLeftChild();
	//��ӡF���ڵ������
	cout << F->GetData() << endl;
	//��ӡF�ڵ�ĸ��ڵ������
	cout << myBinTree.GetParent(myBinTree.GetRoot(), F)->GetData() << endl;

	//3.��ȡF�����ֵܽڵ�
	BinaryTreeNode<char>* rightSiblingF = myBinTree.RightSibling(F);
	//��ӡF�����ֵܽڵ�
	if (rightSiblingF != nullptr)
		cout << rightSiblingF->GetData() << endl;

	//4.��ȡF�����ֵܽڵ�
	BinaryTreeNode<char>* leftSiblingF = myBinTree.LeftSibling(F);
	//��ӡF�����ֵܽڵ�
	if(leftSiblingF != nullptr)
		cout << leftSiblingF->GetData() << endl;
	
	//5.�ж�F�ڵ��Ƿ�Ϊ���ӽڵ�
	cout << myBinTree.IsLeftChild(F) << endl;

	//ɾ���ڵ�
	myBinTree.DeleteLeftChild(myBinTree.GetRoot());//�ڸ��ڵ���ɾ����ڵ�'B'
	myBinTree.DeleteRightChild(myBinTree.GetRoot());//�ڸ��ڵ���ɾ���ҽڵ�'C'
	myBinTree.PreOrderTraverse(myBinTree.GetRoot());
	cout << endl;
}