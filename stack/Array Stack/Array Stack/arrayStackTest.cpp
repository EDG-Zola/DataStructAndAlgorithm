#include"arrayStack.h"
#include<iostream>
using namespace std;

int main() {
	
	ArrayStack<int> stacka(5);//定义一个5个int元素的栈
	stacka.Push(0);
	stacka.Push(1);
	stacka.Push(2);
	stacka.Push(3);
	stacka.Push(4);//4 3 2 1 0
	stacka.Pop();//3 2 1 0
	int a = stacka.GetTop(); //3
	std::cout << a << std::endl;

	std::cout << stacka.IsEmpty() << std::endl; //0
	
	stacka.print();//

	stacka.MakeEmpty();
	
	

}