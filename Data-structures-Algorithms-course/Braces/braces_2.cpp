#include <stack>
#include <iostream>

char openingBrace(char ch) {
	switch (ch) {
        case ')': return '(';
        case ']': return '[';
        case '}': return '{';
	}
}

int main() {
	std::stack<char> braces;
	char ch;
	bool isOK = true;

	while (std::cin >> ch) {
		switch (ch) {
            case '(': case '[': case '{': case '<':
                braces.push(ch);
                break;
            case ')': case ']': case '}': case '>':
                if (!braces.empty() && braces.top() == OpeningBrace(ch))
                    braces.pop();
                else
                    isOK = false;
		}
	}

	if (isOK && braces.empty()) {
		std::cout << "Okay!\n";
	}
	else {
		std::cout << "Not okay!\n";
	}

	return 0;
}
