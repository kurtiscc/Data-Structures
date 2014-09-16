#include "Student.h"
#include <map>
#include <iomanip>
using namespace std;

Student::Student(string ID_Number_in, string name_in)
{
	ID_Number = ID_Number_in;
	name = name_in;
	double gpa = 0;
}
Student::Student()
{
	double gpa = 0;
}

Student::~Student(){}

string Student::getID_Number()
{
	return ID_Number;
}
string Student::getname()
{
	return name;
}
string Student::getAddress()
{
	return address;
}
string Student::getPhone()
{
	return phone;
}
string Student::getgrade()
{
	return grade;
}
void Student::setgpa(double num)
{
	gpa = num;
}
string Student::toString()
{
	stringstream ss;
	ss << ID_Number << "    " << fixed << setprecision(2) << setfill('0')  << gpa << "    " << name << endl;
	return ss.str();
}
vector<string> Student::get_just_grades()
{
	return just_grades;
}
void Student::print_Student_Vector()
{
	cout << "Student" << endl;
	cout << ID_Number << endl;
	cout << name << endl;
}
int Student::print_size()
{
	return just_grades.size();
}
void Student::add_grade(string grade)
{
	just_grades.push_back(grade);
}
