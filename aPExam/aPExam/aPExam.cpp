// aPExam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <map>
#include <string>
#include "LineSegment.h"


using namespace std;

//Showing how concise and readable the use of iterators are
void vectorIteration(){
	vector<int> v{ 1, 2, 3 };

	//Before iterators - the C way:
	for (size_t i = 0; i < v.size(); i++)
		cout << v[i] << endl;

	//Here for the completeness sake
	auto it = v.begin();
	while (it != v.end()){
		cout << *it << endl;
		++it;
	}

	//Using iterators
	for (auto it = v.begin(); it != v.end(); ++it) //Using Pre-increment(++it) because it returns a reference to it
		cout << *it << endl;

	//Using the range-based for-loop introduced in C++ 11
	for (auto &it : v) //using the address of the iterator(&it) to avoid a potential copy - like Post-increment(it++)
		cout << it << endl;
}

//Showing the member syntax
void mapIteration(){
	map<int, LineSegment> m{};
	m[1] = LineSegment(0,0,2,2);
	m[2] = LineSegment(1,1,3,3);
	m[3] = LineSegment(1,2,4,5);

	for (auto &it : m)
		cout << "Point " + it.first << it.second << endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	vectorIteration();


	return 0;
}



