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
#include <time.h>
#include <algorithm>



using namespace std;


//#################### HELPER FUNCTIONS #####################
template <typename Container>
void printSequenceContainer(Container con){
	for (const auto& it : con)
		cout << it << endl;
	cout << endl << endl;
}

LineSegment l1 = LineSegment(0, 0, 2, 2);
LineSegment l2 = LineSegment(1, 1, 3, 3);
LineSegment l3 = LineSegment(1, 2, 4, 5);

//Prints the distance between all points
void printDistance(vector<LineSegment> ls){

	printSequenceContainer(ls);

	cout << "Distance between points:" << endl;
	for (auto it = ls.begin(); it != ls.end(); ++it)
		cout << it->distance() << endl;
}

// Generates a vector with a given size of line segments which have random coordinates between 1-10
void randomSequenceOfLineSegments(vector<LineSegment>& ls, long double size){
	srand(time_t(NULL));
	for (int i = 0; i < size; i++)
	{
		ls.push_back(LineSegment(rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1));
	}
}

// #######################################################


// ############ BASIC ITERATOR USAGE ######################

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


//Showing some of the iterator operations, in particular how the sunscripting operator is not moving the iterator and that it is possible to increment and decrement 
void iteratorOperations(){
	vector<LineSegment> ls;
	randomSequenceOfLineSegments(ls, 3);

	printSequenceContainer(ls);

	auto it = ls.begin();


	cout << "Last element by pre-incrementing the iterator two times: " << *++++it << endl;
	cout << "First element using the SAME iterator by post-decrementing two times: " << *----it << endl;
	cout << "Using subcripting(it[n]) the iterator will NOT move: " << "Iterators pos: " << *it << " The last element: " << it[ls.size() - 1] << endl;
}
// ##################################################################


// ################## ITERATORS AS THE GLUE #######################
//Showing how the iterator is the glue between containers and algorithm, specificly using a vector of line segments
// and sort them by having overloaded '<' on the line segment class
void sortt(){
	vector<LineSegment> ls;
	randomSequenceOfLineSegments(ls, 10);

	cout << "unsorted: " << endl;
	printSequenceContainer(ls);

	sort(ls.begin(), ls.end());

	cout << "sorted: " << endl;
	printSequenceContainer(ls);
}

//########################################################

// ################### PERFORMANCE TEST OF POST- and PRE-INCREMENT ##############################
//A method that tests the performance of the post- and pre-increment operations for iterators
void testOfIncrementOperation(){
	vector<LineSegment> ls;
	randomSequenceOfLineSegments(ls, 9999999);

	vector<double> distances1;
	vector<double> distances2;

	auto startFirst = time(0);
	cout << "Copy start time: " << startFirst << endl;

	// Using post-increment operation
	for (auto it = ls.begin(); it != ls.end(); it++){
		distances1.push_back(it->distance());
	}

	auto startSecond = time(0);
	cout << "Ref start time: " << startSecond << endl;

	// Using pre-increment operation
	for (auto it = ls.begin(); it != ls.end(); ++it){
		distances2.push_back(it->distance());
	}

	auto end = time(0);
	cout << end << endl;

	cout << "Running time when returning copy: " << startSecond - startFirst << endl;
	cout << "Running time when returning ref: " << end - startSecond << endl;
}

// ######################################################################################



// ########################### MAIN ##############################################
int _tmain(int argc, _TCHAR* argv[])
{
	vectorIteration();
	mapIteration();

	cout << endl << endl;

	sortt();

	iteratorOperations();

	cout << endl << endl;

	//######################################
	// For loop that runs the test method of post- and pre-increment
	//#####################################
	cout << "Starting performance test of post- and pre-increment of iterators(this can take several minutes)" << endl;
	for (int i = 0; i < 5; ++i)
		testOfIncrementOperation();
	

	return 0;
}



