#include <iostream>

using namespace std;

#include "Queue.h"

int main() {

	Queue<int> q;
	for (int i = 0; i < 105; i++)
		q.enqueue(i);
	
	cout << q.head() << endl;

	Queue<int> q2 = q;
	q2.enqueue(-1);

	while (!q2.isEmpty()) {
		cout << q2.head() << ' ';
		q2.dequeue();
	}
	cout << endl;

	cout << q2.head() << endl;
	cout << q2.head() << endl;

	cout << q.head() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.head() << endl;
	cout << q.head() << endl;


	return 0;
}