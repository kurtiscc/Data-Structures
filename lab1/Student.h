#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Student
{
	private:
		string ID_Number;
		string name;
		string address;
		string phone;
		string grade;
		double gpa;
		vector<string> just_grades;
		

public:

	Student(string ID_Number_in, string name);
	Student();
	virtual ~Student();

	string getID_Number();
	string getname();
	string getAddress();
	string getPhone();
	string getgrade();
	string toString();
	void setgpa(double num);
	vector<string> get_just_grades();
	void print_Student_Vector();
	int print_size();
	void add_grade(string grade);
};
