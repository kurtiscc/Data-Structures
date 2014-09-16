#include "Grades.h"
#include <map>
#include <vector>
using namespace std;

Grades::Grades(string ID_Number_in, string grade_in)
{
	ID_Number = ID_Number_in;
	grade = grade_in;
}
Grades::~Grades(){}

string Grades::getClass()
{
	return Class;
}

string Grades::get_grade_ID_Number()
{
	return ID_Number;
}
string Grades::getgrade()
{
	return grade;
}
void Grades::print_grade_vector()
{
	cout << "Grades" << endl;
	cout << ID_Number << endl;
	cout << grade << endl;
}



