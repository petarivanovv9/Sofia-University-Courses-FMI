#include <iostream>

#include "Stack.h"

using namespace std;

int main() {

	Stack<int> peshko;
	peshko.push(5);
	peshko.push(6);
	peshko.push(7);
	peshko.push(9);
	peshko.push(10);

	cout << peshko.peek() << std::endl;

	//int a;
	//peshko.pop(a);
	int a = peshko.peek();
	peshko.pop();
	cout << a << std::endl;

	cout << peshko.peek() << std::endl;

    a = peshko.peek();
	peshko.pop();
	//peshko.pop(a);
	cout << a << std::endl;

	cout << peshko.peek() << std::endl;

	Stack<int> baba;
	baba = peshko;

	cout << baba.peek() << std::endl;



	return 0;
}
