#include <iostream>

class LineSegment
{
private:
	int ax, ay, bx, by;
public:
	LineSegment();
	LineSegment(int, int, int, int);
	LineSegment(const LineSegment&);
	int getAX() const;
	int getAY() const;
	int getBX() const;
	int getBY() const;
	~LineSegment();
};

std::ostream& operator<<(std::ostream&, const LineSegment&);

