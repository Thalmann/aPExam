// aPExam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "point.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <map>
#include <string>

using namespace std;

//Showing how concise and readable the use of iterators is
void containerIteration(){
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


int _tmain(int argc, _TCHAR* argv[])
{
	containerIteration();

	auto p = ::Point{ 1, 2 };
	
	list<int> l{ 3, 2, 1 };
	map<string, int> m{};
	m["one"] = 1;
	m["two"] = 2;
	m["three"] = 3;

	map<int, int> m2{};
	m2[1] = 1;
	m2[2] = 2;
	m2[3] = 3;

	


	return 0;
}



