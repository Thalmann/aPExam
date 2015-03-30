

class Point {
private:
	double x;
	double y;

public:
	Point(double, double);

	bool visited = false;

	double getX() const;
	double getY() const;
};
