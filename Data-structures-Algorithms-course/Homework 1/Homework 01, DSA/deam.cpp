//#include <iostream>
//#include <stack>
//#include <cstring>
//
//int charToNumber(const char*& c);
//char* decompress(char const* input, char* output);
//
//int main() {
//
//	//char in[20] = "2(K2(G2(A)P)V2(D))";
//	char in[25] = "2(K2(G2(A)P)2(2(C)))";
//	//char in[3] = "AB";
//	char out[500] = "";
//	std::cout << "Result:> " << decompress(in, out) << std::endl;
//
//	return 0;
//}
//
//int charToNumber(const char*& c) {
//	int cval = 0;
//	while (*c >= '0' && *c <= '9') {
//		cval = cval * 10 + *c - '0';
//		++c;
//	}
//	return cval;
//}
//
//char* decompress(char const* input, char* output) {
//		std::stack<int> numbers;
//		std::stack<const char*> buffer;
//		long buffer_size = 0;
//		char const *p = input;
//		char* o = output;
//		while (*p != '\0') {
//	
//			if (*p >= 'A' && *p <= 'Z') {
//				*o++ = *p;
//			} 
//			else if (*p >= '0' && *p <= '9') {
//				numbers.push(charToNumber(p));
//				buffer.push(o);
//			}
//			else if (*p == ')') {
//				int n = numbers.top();
//				numbers.pop();
//				long int k = o - buffer.top();
//				for (int i = 0; i < n - 1; i++) {
//					strncat(output, buffer.top(), k);
//					o += k;
//					buffer_size += k;
//				}
//				buffer.pop();
//			}
//			++p;
//		}
//	
//		return output;
//}