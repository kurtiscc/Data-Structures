#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <set>

using namespace std;

class Student
{
	private:
		string ID_Number;
		//vector<string> StudentVector;
		//list<string> StudentList;
		//list<string>::iterator list_it;
		//set<string> StudentSet;
		//set<string>::iterator set_it;
		static int compareCount;

	public:

	bool operator < (const Student& s) const {
		compareCount++;
		return ID_Number < s.ID_Number;
	}

	bool operator == (const Student& s) const {
		compareCount++;
		return ID_Number == s.ID_Number;
	}

	bool operator > (const Student& s) const {
		compareCount++;
		return ID_Number > s.ID_Number;
	}

	Student(string ID_Number_in);
	Student();
	virtual ~Student();
	void addID(string query)
	{
		ID_Number = query;
	}
	string getID_Number();

	int get_compareCount();

	void reset_compareCount();

	string print_Selection_Sort(vector<Student>& studvec);

	string print_Insertion_Sort();

	string print_std_sort();

	string print_std_list_sort();

	string print_Linear_Search();

	string print_std_find();

	string print_set_find();

};
