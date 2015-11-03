#include <iostream>
#include <stack>
#include <string>

using namespace std;

//int getNumber(char*& c) {
//	int cval = 0;
//	while (*c >= '0' && *c <= '9') {
//		cval = cval * 10 + *c - '0';
//		++c;
//	}
//	cout << "in getNumber -- c: " << *c << endl;
//
//	return cval;
//}

//int main() {
//
//	char* input = "12(A3(AB))";
//	//char* input = "3(AB)";
//	//char* input = "AB";
//
//	for (char* c = input; *c; c++) {
//		cout << "c: " << *c << endl;
//
//		if (*c >= '0' && *c <= '9') {
//			cout << "cval: " << getNumber(c) << endl;
//		}
//
//		cout << "after getNumber -- c: " << *c << endl;
//
//	}
//	
//		cout << endl;
//	
//	return 0;
//}
