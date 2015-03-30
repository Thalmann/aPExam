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
#include "time.h"
#include <algorithm>



using namespace std;


template <typename Container>
void printSequenceContainer(Container con){
	for (const auto& it : con)
		cout << it << endl;
}


LineSegment l1 = LineSegment(0, 0, 2, 2);
LineSegment l2 = LineSegment(1, 1, 3, 3);
LineSegment l3 = LineSegment(1, 2, 4, 5);

//Showing how concise and readable the use of iterators are
void vectorIteration(){
	vector<LineSegment> v{ l1, l2, l3 };

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
	for (const auto &it : v) //using the address of the iterator(&it) to avoid a potential copy - like Post-increment(it++)
		cout << it << endl;
}

//Showing the member syntax
void mapIteration(){
	map<int, LineSegment> m{};
	m[1] = l1;
	m[2] = l2;
	m[3] = l3;

	//Using the '->' for member access
	typedef map<int, LineSegment>::iterator it_type;
	for (it_type it = m.begin(); it != m.end(); ++it)
		cout << it->second << endl;

	//Using the range-based for-loop from C++ 11 we can do it even easier using the '.' for member access because this is the actuak object
	for (const auto &it : m)
		cout << it.second << endl;
}


void printDistance(){
	srand(time_t(NULL));
	vector<LineSegment> ls;
	for (int i = 0; i < 10; i++)
	{
		ls.push_back(LineSegment(rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1));
	}

	printSequenceContainer(ls);

	cout << "Distance between points:" << endl;
	for (auto it = ls.begin(); it != ls.end(); ++it)
		cout << it->distance() << endl;
}


void sortt(){
	srand(time_t(NULL));
	vector<LineSegment> ls;
	for (int i = 0; i < 10; i++)
	{
		ls.push_back(LineSegment(rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1));
	}

	cout << "unsorted: " << endl;
	printSequenceContainer(ls);

	sort(ls.begin(), ls.end());

	cout << "sorted: " << endl;
	printSequenceContainer(ls);
}



int _tmain(int argc, _TCHAR* argv[])
{
	vectorIteration();
	mapIteration();

	cout << endl << endl;

	printDistance();

	cout << endl << endl;

	sortt();

	return 0;
}



