#include <iostream>
#include <cstring>

#include "Stack.h"

int charToNumber(const char*& c);
char* decompress(char const* input, char* output);

int main() {

	//char in[25] = "1100(K2(G2(A)P)2(2(C)))";
	//char out[50000] = "";

	char in[25] = "2(K2(G2(A)P)2(2(C)))";
	char out[500] = "";

	//char in[25] = "2(23(C)3(AB))";
	//char out[500] = "";

	std::cout << "Result:> " << decompress(in, out) 
							 << std::endl << std::endl;

	return 0;
}

int charToNumber(const char*& c) {
	int cval = 0;
	while (*c >= '0' && *c <= '9') {
		cval = cval * 10 + *c - '0';
		++c;
	}
	return cval;
}

char* decompress(char const* input, char* output) {
	Stack<int> numbers;
	Stack<const char*> buffer;

	char const *pInput = input;
	char* pOutput = output;
	
	while (*pInput != '\0') {

		if (*pInput >= 'A' && *pInput <= 'Z') {
			*pOutput++ = *pInput;
		}
		else if (*pInput >= '0' && *pInput <= '9') {
			numbers.push(charToNumber(pInput));

			// save the pointer's position from where we
			// should start to add new strings
			buffer.push(pOutput);
		}
		else if (*pInput == ')') {
			int n = numbers.peek();
			numbers.pop();
			const char* lastPointer = buffer.peek();

			// in k we holds how many letters we want to add
			// to the output string
			long int k = pOutput - lastPointer;

			for (int i = 0; i < n - 1; i++) {
				strncat(output, lastPointer, k);
				pOutput += k;
			}
			buffer.pop();
		}

		++pInput;
	}

	return output;
}