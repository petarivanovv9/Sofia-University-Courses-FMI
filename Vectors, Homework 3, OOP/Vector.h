#pragma once

class Vector {
public:
	Vector();
	Vector(const Vector& other);
	~Vector();
public:
	void addValuesToVector();
	void printVector() const;
public:
	const double& operator[](int) const;
	Vector& operator=(const Vector&);

	Vector& operator+=(const Vector&);
	Vector operator+(Vector&) const;

	Vector& operator-=(Vector&);
	Vector operator-(Vector&) const;

	Vector& operator*=(double);
	Vector operator*(double);

	Vector& operator/=(double);
	Vector operator/(double) const;

	double operator%(Vector&);
private:
	double* arr;
	int sizeArr;
	double zero = 0;
private:
	void clearVector();
	void copyVector(const double*, int);
	void makeNewArray(int);
};