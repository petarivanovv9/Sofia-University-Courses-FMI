#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

	string input;
	cin >> input;
	int inputSize = input.length();

	stack<char> buffer;

	bool isOk = true;

	for (int i = 0; i < inputSize; i++) {
		if (input[i] == '(') {
			buffer.push(input[i]);
		}
		else if (input[i] == ')') {
			if (buffer.empty()) {
				isOk = false;
			}
			else if (buffer.top() == '(') {
				buffer.pop();
			}
		}

		if (input[i] == '[') {
			buffer.push(input[i]);
		}
		else if (input[i] == ']') {
			if (buffer.empty()) {
				isOk = false;
			}
			else if (buffer.top() == '[') {
				buffer.pop();
			}
		}

        if (input[i] == '{') {
			buffer.push(input[i]);
		}
		else if (input[i] == '}') {
			if (buffer.empty()) {
				isOk = false;
			}
			else if (buffer.top() == '{') {
				buffer.pop();
			}
		}
	}
	if (isOk && buffer.empty()) {
		cout << "OK" << endl;
	}
	else {
		cout << "NOT OK" << endl;
	}

	return 0;
}
