#include "LinkStack.h"
#include <iostream>
using namespace std;
int main() {
	LinkStack<int> mlinkStack;

	mlinkStack.Push(0);
	mlinkStack.Push(1);
	mlinkStack.Push(2);
	mlinkStack.Push(3);
	mlinkStack.Push(4);

	mlinkStack.Pop();//3 2 1 0
	//mlinkStack.print();//3 2 1 0
	cout << mlinkStack.IsEmpty() << endl;// 0

	mlinkStack.MakeEmpty();


	mlinkStack.print();//Õ»Îª¿Õ


}