class Point {

private:
	int row;
	int col;

public:

	int getRow() const {
		return this->row;
	}

	int getCol() const {
		return this->col;
	}

	Point() {
		this->row = 0;
		this->col = 0;
	}

	Point(const int& row, const int& col) {
		this->row = row;
		this->col = col;
	}

	Point(Point const & other) {
		this->row = other.row;
		this->col = other.col;
	}

	Point& operator=(Point const & other) {
		if (this != &other) {
			this->row = other.row;
			this->col = other.col;
		}
		return *this;
	}

	void Point::print() const {
		std::cout << "(" << row << ", " << col << ")" << " ";
	};
};