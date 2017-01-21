#include <iostream>

#include "RLEString.h"
//#include "Box.h"

using namespace std;


int main() {

	//char const* input = "AAABBCCABQQQQTTTTTTTT";
	
	char const* input_1 = "AAABBCBBC";
	RLEString test_1(input_1);
	cout << "------------------------------" << endl;
	cout << "result 1: " << test_1 << endl;
	cout << "------------------------------" << endl;
	cout << "length 1: " << test_1.length() << endl;
	cout << "------------------------------" << endl;


	char const* input_2 = "QQQH";
	RLEString test_2(input_2);
	cout << "------------------------------" << endl;
	cout << "result 2: " << test_2 << endl;
	cout << "------------------------------" << endl;
	cout << "length 2: " << test_2.length() << endl;
	cout << "------------------------------" << endl;


	RLEString test_3 = test_1 + test_2;
	cout << "------------------------------" << endl;
	cout << "result 3: " << test_3 << endl;
	cout << "------------------------------" << endl;
	cout << "length 3: " << test_3.length() << endl;
	cout << "------------------------------" << endl;

	cout << "result 1: " << test_1 << endl;
	cout << "result 2: " << test_2 << endl;

	//test_1.splice(2, 5);
	//cout << "result 1: " << test_1 << endl;

	test_3.splice(2, 5);
	cout << "result 3: " << test_3 << endl;


	char const* input_4 = "AB";
	RLEString test_4(input_4);

	char const* input_5 = "AABCC";
	RLEString test_5(input_5);

	test_5.insert(test_4, 2);
	cout << "------------------------------" << endl;
	cout << "result 5: " << test_5 << endl;
	cout << "------------------------------" << endl;
	cout << "length 5: " << test_5.length() << endl;
	cout << "------------------------------" << endl;
	cout << "result 4: " << test_4 << endl;


	return 0;
}