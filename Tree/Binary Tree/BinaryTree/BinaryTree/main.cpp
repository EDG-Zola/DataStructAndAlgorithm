#include<iostream>
#include "BinaryTree.h"
#include "BinaryTreeNode.h"
using namespace std;
int main() {
	BinaryTree<char> myBinTree('A');
	myBinTree.PreOrderTraverse(myBinTree.GetRoot());
	cout << endl;

	//1.添加节点
	myBinTree.InsertLeftChild(myBinTree.GetRoot(), 'B');//在根节点下添加左节点'B'
	myBinTree.InsertRightChild(myBinTree.GetRoot(), 'C');//在根节点下添加右节点'B'

	myBinTree.InsertLeftChild(myBinTree.GetRoot()->GetLeftChild(), 'D');//在B下添加左节点'D'
	myBinTree.InsertRightChild(myBinTree.GetRoot()->GetLeftChild(), 'E');//在B下添加右节点'E'

	myBinTree.InsertLeftChild(myBinTree.GetRoot()->GetRightChild(), 'F');//在C下添加左节点'F'
	myBinTree.InsertRightChild(myBinTree.GetRoot()->GetRightChild(), 'G');//在C下添加右节点'G'

	myBinTree.PreOrderTraverse(myBinTree.GetRoot());
	cout << endl;
	
	//2.获取F的父节点
	BinaryTreeNode<char>* F = myBinTree.GetRoot()->GetRightChild()->GetLeftChild();
	//打印F父节点的数据
	cout << F->GetData() << endl;
	//打印F节点的父节点的数据
	cout << myBinTree.GetParent(myBinTree.GetRoot(), F)->GetData() << endl;

	//3.获取F的右兄弟节点
	BinaryTreeNode<char>* rightSiblingF = myBinTree.RightSibling(F);
	//打印F的左兄弟节点
	if (rightSiblingF != nullptr)
		cout << rightSiblingF->GetData() << endl;

	//4.获取F的左兄弟节点
	BinaryTreeNode<char>* leftSiblingF = myBinTree.LeftSibling(F);
	//打印F的左兄弟节点
	if(leftSiblingF != nullptr)
		cout << leftSiblingF->GetData() << endl;
	
	//5.判断F节点是否为左子节点
	cout << myBinTree.IsLeftChild(F) << endl;

	//删除节点
	myBinTree.DeleteLeftChild(myBinTree.GetRoot());//在根节点下删除左节点'B'
	myBinTree.DeleteRightChild(myBinTree.GetRoot());//在根节点下删除右节点'C'
	myBinTree.PreOrderTraverse(myBinTree.GetRoot());
	cout << endl;
}