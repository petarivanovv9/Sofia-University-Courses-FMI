#include <iostream>
#include <algorithm>
#include <vector>

int gcd(int a, int b) {
	if (a == 0) 
		return b;
	return gcd(b % a, a);
}

struct Fraction {
	int numerator;
	int denominator;

	void print() {
		std::cout << numerator << "/" << denominator << " ";
	}

	bool operator<(const Fraction & other) const {
		return (this->numerator * other.denominator) < (other.numerator * this->denominator);
	}
};

//bool sortByValue(const Fraction & f1, const Fraction & f2) {
//	std::cout << "HERE" << std::endl;
//	std::cout << "f1: " << f1.numerator / f1.denominator << std::endl;
//	std::cout << "f1: " << f2.numerator / f2.denominator << std::endl;
//	std::cout << "f1 < f2: " << ((f1.numerator / f1.denominator) < (f2.numerator / f2.denominator)) << std::endl;
//	//std::cout << f1 
//	return (f1.numerator / f1.denominator) < (f2.numerator / f2.denominator);
//}

//struct less_than_fraction {
//	inline bool operator() (const Fraction& struct1, const Fraction& struct2) {
//		return (struct1.numerator / struct1.denominator) < (struct2.numerator / struct2.denominator);
//	}
//};

void swapIf(Fraction& f_1, Fraction& f_2) {
	if (f_1 < f_2) {
		std::swap(f_1.numerator, f_2.numerator);
		std::swap(f_1.denominator, f_2.denominator);
	}
}


int main() {

	int n;
	std::cin >> n;

	std::vector<Fraction> result;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (gcd(i,j) == 1 && i < j) {
				Fraction current_fraction;
				current_fraction.numerator = i;
				current_fraction.denominator = j;

				result.push_back(current_fraction);
			}
		}
	}

	//for (int i = 0; i < result.size(); i++) {
	//	std::cout << result.at(i).numerator << "/" << result.at(i).denominator << std::endl;
	//}
	//std::cout << "BOOM" << std::endl;

	//std::sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result.size(); j++) {
			swapIf(result[i], result[j]);
		}
	}
	
	std::cout << 0 << " ";
	for (int i = 0; i < result.size(); i++) {
		result.at(i).print();
	}
	//std::cout << std::endl;

	return 0;
}
