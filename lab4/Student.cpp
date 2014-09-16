#include "Student.h"
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

Student::Student(string ID_Number_in)
{
	ID_Number = ID_Number_in;
}


Student::Student()
{
	
}


Student::~Student(){}



string Student::getID_Number()
{
	return ID_Number;
}

int Student::get_compareCount()
{
	return compareCount;
}

void Student::reset_compareCount()
{
	compareCount = 0;
}

