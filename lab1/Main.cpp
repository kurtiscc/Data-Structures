#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>
#include "Student.h"
#include "Grades.h"


using namespace std;


double get_gpa(Student letter)
	{
	map<string,double> GRADE;
  GRADE["A"] = 4.0;
  GRADE["A-"] = 3.7;
  GRADE["B+"] = 3.4;
  GRADE["B"] = 3.0;
  GRADE["B-"] = 2.7;
  GRADE["C+"] = 2.4;
  GRADE["C"] = 2.0;
  GRADE["C-"] = 1.7;
  GRADE["D+"] = 1.4;
  GRADE["D"] = 1.0;
  GRADE["D-"] = 0.7;
  GRADE["E"] = 0.0;

  double count = 0;

  for(int i = 0; i < letter.get_just_grades().size(); i++)
  {
		count += GRADE[letter.get_just_grades()[i]];
  }
 
  double gpa = 0;
  if(letter.get_just_grades().size() > 0)
  {
	gpa = count / letter.get_just_grades().size();
	cout << gpa;
  }
  return gpa;
	}

void myfunct (vector<string>& query, vector<Student>& StudentVector, ofstream& outFile)
{
	for(int i=0; i < query.size(); i++)
	{
		for(int j=0; j < StudentVector.size(); j++)
		{
			if(query[i] == StudentVector[j].getID_Number())
			{
				double number = get_gpa(StudentVector[j]);
				StudentVector[j].setgpa(number);
				outFile << StudentVector[j].toString();
				break;
			}
		}
	}
}

int main(int argc, char *argv[])

{
	//--------------------------------------
	// Read in Student File
	//--------------------------------------
	ifstream inFile;
	ofstream outFile;
	vector<Student> StudentVector;

	inFile.open(argv[1]);
	string ID_Number;
	while(getline(inFile, ID_Number))
	{
		string name;
		string address;
		string phone;
		getline(inFile, name);
		getline(inFile, address);
		getline(inFile, phone);
		Student load(ID_Number, name);
		StudentVector.push_back(load);
	}
	inFile.close();

	// End Student input

	//---------------------------------------------------------------------------------
	// Read Query File
	//---------------------------------------------------------------------------------------

	vector<string> query;
	inFile.open(argv[3]);
	string ID;

	while(getline(inFile, ID))
	{
		query.push_back(ID);
	}
	
	inFile.close();

	//-----------------------------------------------------------------------------------------------
	// Read Grade File
	//-----------------------------------------------------------------------------------------------


	inFile.open(argv[2]);
	string Class;
	string grade_ID_Number;
	string grade;
	while(getline(inFile, Class))
	{
		getline(inFile, grade_ID_Number);
		getline(inFile, grade);

		for(int i =0; i < StudentVector.size(); i++)
		{
			if(StudentVector[i].getID_Number() == grade_ID_Number)
			{
				StudentVector[i].add_grade(grade);
				break;
			}
		}
	}
	inFile.close();

	vector<string> student_grades;
	string match;
	outFile.open(argv[4]);
	myfunct(query, StudentVector, outFile);
	outFile.close();
	return 0;
}
	
