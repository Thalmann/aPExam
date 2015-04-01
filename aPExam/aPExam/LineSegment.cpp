#include "stdafx.h"
#include "LineSegment.h"
#include <iostream>
#include <time.h>
#include <algorithm>

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

double LineSegment::distance() const{
	return sqrt(pow(ax-bx,2) + pow(ay-by,2));
}

// Overload of '<<' for pretty printing a line segment
std::ostream& operator<<(std::ostream& o, const LineSegment& l){
	return o << "Point a: (" << l.getAX() << "," << l.getAY() << ") " << "Point b: (" << l.getBX() << "," << l.getBY() << ").";
}

// Overload for comparision - used for sort in aPExam.cpp - sorting after the x-value
bool operator < (const LineSegment& _this, const LineSegment& other){
	return std::min(_this.getAX(), _this.getBX()) < std::min(other.getAX(), other.getBX());
}

LineSegment::~LineSegment()
{
}
