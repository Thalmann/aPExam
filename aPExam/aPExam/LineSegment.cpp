#include "stdafx.h"
#include "LineSegment.h"
#include <iostream>

LineSegment::LineSegment(){}

LineSegment::LineSegment(int ax, int ay, int bx, int by) : ax{ ax }, ay{ ay }, bx{ bx }, by{ by }{
}

LineSegment::LineSegment(const LineSegment& l) : ax{ l.getAX() }, ay{ l.getAY() }, bx{ l.getBX() }, by{ l.getBY() } {
}

int LineSegment::getAX() const{
	return ax;
}

int LineSegment::getAY() const{
	return ay;
}

int LineSegment::getBX() const{
	return bx;
}

int LineSegment::getBY() const{
	return by;
}

std::ostream& operator<<(std::ostream& o, const LineSegment& l){
	return o << "Point a : (" << l.getAX() << "," << l.getAY() << ") " << "Point b : (" << l.getBX() << "," << l.getBY() << ").";
}

LineSegment::~LineSegment()
{
}
