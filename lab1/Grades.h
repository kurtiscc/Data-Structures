#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Grades
{
	private:
		string Class;
		string ID_Number;
		string grade;


public:

	Grades(string grade_ID_Number, string grade);
	virtual ~Grades();

	string getClass();
	string get_grade_ID_Number();
	string getgrade();
	void print_grade_vector();
};