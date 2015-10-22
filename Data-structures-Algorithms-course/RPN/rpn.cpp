#include <stack>
#include <iostream>

using namespace std;

char * rpns[] = {
	"14/2+",
	"54*32++",
	"546+/"
};

int main () {
	/* iterate over all input data */
	for (char*& str : rpns) {
		stack<float> s;

		for (char *c = str; *c; c++) {
			/* as long as it is digit -> push it */
			if (*c >= '0' && *c <= '9') {
				s.push(*c - '0');
			}
			else {
				/* mind that we first pop the second operand then the first */
				float b = s.top(); s.pop();
				float a = s.top(); s.pop();
				switch (*c) {
                    case '+': s.push(a + b); break;
                    case '-': s.push(a - b); break;
                    case '*': s.push(a * b); break;
                    case '/': s.push(a / b); break;
				}
			}
		}

		cout << str << " = " << s.top() << endl;
	}

	return 0;
}
