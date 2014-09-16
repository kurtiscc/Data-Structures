#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>
#include <list>
#include <set>
#include "Student.h"

using namespace std;

int Student::compareCount;

void print_Selection_Sort(vector<Student>& quarter_size, vector<Student>& half_size, vector<Student>& full_size, int quarter, int half, int full, ofstream& ofile)
{
	ofile << "Selection Sort\n" << "size: " << quarter_size.size() << "    " << "compares: " << quarter << endl;
	ofile << "size: " << half_size.size() << "    " << "compares: " << half << endl;
	ofile << "size: " << full_size.size() << "    " << "compares: " << full << endl;
	quarter_size.clear();
	half_size.clear();
	full_size.clear();
}

void print_Insertion_Sort(vector<Student>& quarter_size, vector<Student>& half_size, vector<Student>& full_size, int quarter, int half, int full, ofstream& ofile)
{
	ofile << "Insertion Sort\n" << "size: " << quarter_size.size() << "    " << "compares: " << quarter << endl;
	ofile << "size: " << half_size.size() << "    " << "compares: " << half << endl;
	ofile << "size: " << full_size.size() << "    " << "compares: " << full << endl;
	quarter_size.clear();
	half_size.clear();
	full_size.clear();
}

void print_std_sort(vector<Student>& quarter_size, vector<Student>& half_size, vector<Student>& full_size, int quarter, int half, int full, ofstream& ofile)
{
	ofile << "std::sort\n" << "size: " << quarter_size.size() << "    " << "compares: " << quarter << endl;
	ofile << "size: " << half_size.size() << "    " << "compares: " << half << endl;
	ofile << "size: " << full_size.size() << "    " << "compares: " << full << endl;
	quarter_size.clear();
	half_size.clear();
	full_size.clear();
}

void print_std_list_sort(list<Student>& quarter_list, list<Student>& half_list, list<Student>& full_list, int quarter, int half, int full, ofstream& ofile)
{
	ofile << "std::list.sort\n" << "size: " << quarter_list.size() << "    " << "compares: " << quarter << endl;
	ofile << "size: " << half_list.size() << "    " << "compares: " << half << endl;
	ofile << "size: " << full_list.size() << "    " << "compares: " << full << endl;
	quarter_list.clear();
	half_list.clear();
	full_list.clear();
}

void print_lin_search(vector<Student> quarter_size, vector<Student> half_size, vector<Student> full_size, int quarter, int half, int full, ofstream& ofile)
{
	ofile << "Linear Search\n" << "size: " << quarter_size.size() << "    " << "compares: " << quarter << endl;
	ofile << "size: " << half_size.size() << "    " << "compares: " << half << endl;
	ofile << "size: " << full_size.size() << "    " << "compares: " << full << endl;
	quarter_size.clear();
	half_size.clear();
	full_size.clear();
}


void print_std_find(list<Student>& quarter_list, list<Student>& half_list, list<Student>& full_list, int quarter, int half, int full, ofstream& ofile)
{
	ofile << "std::find\n" << "size: " << quarter_list.size() << "    " << "compares: " << quarter << endl;
	ofile << "size: " << half_list.size() << "    " << "compares: " << half << endl;
	ofile << "size: " << full_list.size() << "    " << "compares: " << full << endl;
	quarter_list.clear();
	half_list.clear();
	full_list.clear();
}

void print_set_find(set<Student>& quarter_set, set<Student>& half_set, set<Student>& full_set, int quarter, int half, int full, ofstream& ofile)
{
	ofile << "std::set.find\n" << "size: " << quarter_set.size() << "    " << "compares: " << quarter << endl;
	ofile << "size: " << half_set.size() << "    " << "compares: " << half << endl;
	ofile << "size: " << full_set.size() << "    " << "compares: " << full << endl;
	quarter_set.clear();
	half_set.clear();
	full_set.clear();
}


void size_my_vectors(vector<Student> stud_vec, vector<Student>& quarter_size, vector<Student>& half_size, vector<Student>& full_size)
{
	for(int i=0; i < stud_vec.size() / 4; i++) 
	{
		quarter_size.push_back(stud_vec[i]);
	}
	for(int i=0; i < stud_vec.size() / 2; i++)
	{
		half_size.push_back(stud_vec[i]);
	}
	full_size = stud_vec;
}

void size_my_query(vector<string> query, vector<string>& quarter_query, vector<string>& half_query, vector<string>& full_query)
{
	for(int i=0; i < query.size() / 4; i++) 
	{
		quarter_query.push_back(query[i]);
	}
	for(int i=0; i < query.size() / 2; i++)
	{
		half_query.push_back(query[i]);
	}
	//Student query_temp;
	for(int i=0; i < query.size(); i++)
	{
		//query_temp.addID(query[i]);
		full_query.push_back(query[i]);
	}
}

void size_my_lists(vector<Student> stud_vec, list<Student>& quarter_list, list<Student>& half_list, list<Student>& full_list)
{
	for(int i=0; i < stud_vec.size() / 4; i++) 
	{
		quarter_list.push_back(stud_vec[i]);
	}
	for(int i=0; i < stud_vec.size() / 2; i++)
	{
		half_list.push_back(stud_vec[i]);
	}
	copy( stud_vec.begin(), stud_vec.end(), back_inserter( full_list ) );
}

void size_my_lists_sort(vector<Student> stud_vec, list<Student>& quarter_list, list<Student>& half_list, list<Student>& full_list)
{
	for(int i=0; i < stud_vec.size() / 4; i++) 
	{
		quarter_list.push_back(stud_vec[i]);
	}
	for(int i=0; i < stud_vec.size() / 2; i++)
	{
		half_list.push_back(stud_vec[i]);
	}
	copy( stud_vec.begin(), stud_vec.end(), back_inserter( full_list ) );
}

void size_my_sets(vector<Student> stud_vec, set<Student>& quarter_set, set<Student>& half_set, set<Student>& full_set)
{
	for(int i=0; i < stud_vec.size() / 4; i++) 
	{
		quarter_set.insert(stud_vec[i]);
	}
	for(int i=0; i < stud_vec.size() / 2; i++)
	{
		half_set.insert(stud_vec[i]);
	}
	copy( stud_vec.begin(), stud_vec.end(), inserter(full_set, full_set.end() ) );
}
// SELECTION SORT -------------------------------------------------------------------------------------------------
void sel_sort(vector<Student> stud_vec)
{
	Student temp;
	temp.reset_compareCount();
	 int min;

        for( int i = 0; i < stud_vec.size()-1; i++)
		{
                min = i;
                for (int j = i + 1; j < stud_vec.size(); j++)
				{
                        if (stud_vec[j] < stud_vec[min])
                        min = j;
                }
                swap(stud_vec[i], stud_vec[min]);
		}
}
//------------------------------------------------------------------------------------------------------------------

// INSERTION SORT -------------------------------------------------------------------------------------------------
void ins_sort(vector<Student> stud_vec)
{
	Student temp;
	temp.reset_compareCount();
	int i, j;
	Student item;
	for(i = 1; i <= stud_vec.size()-1; i++)
	{
		item = stud_vec[i];
		j = i;
		while(j > 0 && item < stud_vec[j-1])
		{
			stud_vec[j]=stud_vec[j-1];
			j--;
		}
		stud_vec[j] = item;
	}
}
//-----------------------------------------------------------------------------------------------------------------

// STD::SORT-------------------------------------------------------------------------------------------------------
void std_sort(vector<Student> stud_vec)
{
	Student temp;
	temp.reset_compareCount();
	sort(stud_vec.begin(), stud_vec.end());
}
//-----------------------------------------------------------------------------------------------------------------

// STD::LIST.SORT-------------------------------------------------------------------------------------------------------
void std_list_sort(list<Student> stud_list)
{
	Student temp;
	temp.reset_compareCount();
	stud_list.sort();
}
//-----------------------------------------------------------------------------------------------------------------

// LINEAR SEARCH-----------------------------------------------------------------------------------------------------
void lin_search(vector<string>& query, vector<Student>& Studvec)
{
	Student temp;
	temp.reset_compareCount();
	Student temp_stud;
	for(int i=0; i < query.size(); i++)
	{
		temp_stud.addID(query[i]);
		for(int j=0; j < Studvec.size(); j++)
		{
			if(Studvec[j] == temp_stud)
			{
				break;
			}
		}
	}
}

//--------------------------------------------------------------------------------------------------------------------

// STD::FIND -------------------------------------------------------------------------------------------------------
void std_find(list<Student> stud_list, vector<string>& query)
{
	Student temp;
	temp.reset_compareCount();
	list<Student>::iterator list_it_beg = stud_list.begin();
	list<Student>::iterator list_it_end = stud_list.end();
	Student temp_stud1;
	
	for(int i=0; i < query.size(); i++)
	{
		temp_stud1.addID(query[i]);
		find(list_it_beg, list_it_end, temp_stud1);
	}
}
//------------------------------------------------------------------------------------------------------------------

// SET.FIND SECTION--------------------------------------------------------------------------------------------------
void set_find(set<Student> stud_set, vector<string>& query)
{
	Student temp;
	temp.reset_compareCount();
	Student temp_stud2;
	
	for(int i=0; i < query.size(); i++)
	{
		temp_stud2.addID(query[i]);
		stud_set.find(temp_stud2);
	}
}
//----------------------------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])

{
	ifstream inFile;
	ofstream outFile;
	vector<Student> StudentVector;
	vector<Student> quarter_size;
	vector<Student> half_size;
	vector<Student> full_size;
	vector<string> quarter_query;
	vector<string> half_query;
	vector<string> full_query;
	list<Student> StudentList;
	list<Student> quarter_list;
	list<Student> half_list;
	list<Student> full_list;
	set<Student> quarter_set;
	set<Student> half_set;
	set<Student> full_set;

	//--------------------------------------
	// Read in Student File
	//--------------------------------------
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
		Student stud_obj(ID_Number); // keep this in the while loop!
		StudentVector.push_back(stud_obj);
	}
	inFile.close();
	// End Student input

	//---------------------------------------------------------------------------------
	// Read Query File
	//---------------------------------------------------------------------------------------
	vector<string> query;
	inFile.open(argv[2]);
	string ID;
	while(getline(inFile, ID))
	{
		query.push_back(ID);
	}
	inFile.close();
	outFile.open(argv[3]);

//SELECTION SORT SECTION============================================================================================================
	size_my_vectors(StudentVector, quarter_size, half_size, full_size);
	Student temp;
	sel_sort(quarter_size);
	int sel_q_comp = temp.get_compareCount();
	sel_sort(half_size);
	int sel_h_comp = temp.get_compareCount();
	sel_sort(full_size);
	int sel_f_comp = temp.get_compareCount();

	print_Selection_Sort(quarter_size, half_size, full_size, sel_q_comp, sel_h_comp, sel_f_comp, outFile);
//=================================================================================================================================
//INSERTION SORT SECTION============================================================================================================
	size_my_vectors(StudentVector, quarter_size, half_size, full_size);
	Student temp2;
	ins_sort(quarter_size);
	int ins_q_comp = temp2.get_compareCount();
	ins_sort(half_size);
	int ins_h_comp = temp2.get_compareCount();
	ins_sort(full_size);
	int ins_f_comp = temp2.get_compareCount();

	print_Insertion_Sort(quarter_size, half_size, full_size, ins_q_comp, ins_h_comp, ins_f_comp, outFile);
//=================================================================================================================================
//STD::SORT SECTION============================================================================================================
	size_my_vectors(StudentVector, quarter_size, half_size, full_size);
	Student temp3;
	std_sort(quarter_size);
	int std_sort_q_comp = temp3.get_compareCount();
	std_sort(half_size);
	int std_sort_h_comp = temp3.get_compareCount();
	std_sort(full_size);
	int std_sort_f_comp = temp3.get_compareCount();

	print_std_sort(quarter_size, half_size, full_size, std_sort_q_comp, std_sort_h_comp, std_sort_f_comp, outFile);
//=================================================================================================================================
//STD::LIST.SORT SECTION============================================================================================================
	size_my_lists_sort(StudentVector, quarter_list, half_list, full_list);
	Student temp4;
	std_list_sort(quarter_list);
	int std_list_q_comp = temp4.get_compareCount();
	std_list_sort(half_list);
	int std_list_h_comp = temp4.get_compareCount();
	std_list_sort(full_list);
	int std_list_f_comp = temp4.get_compareCount();

	print_std_list_sort(quarter_list, half_list, full_list, std_list_q_comp, std_list_h_comp, std_list_f_comp, outFile);
//=================================================================================================================================

//LINEAR SEARCH SECTION=============================================================================================================
	Student temp6;
	size_my_vectors(StudentVector, quarter_size, half_size, full_size);
	size_my_query(query, quarter_query, half_query, full_query);
	lin_search(quarter_query, quarter_size);
	int lin_q_comp = temp6.get_compareCount() / quarter_query.size();
	lin_search(half_query, half_size);
	int lin_h_comp = temp6.get_compareCount() / half_query.size();
	lin_search(full_query, full_size);
	int lin_f_comp = temp6.get_compareCount() / full_query.size();

	print_lin_search(quarter_size, half_size, full_size, lin_q_comp, lin_h_comp, lin_f_comp, outFile);
//==================================================================================================================================

//STD::FIND SECTION============================================================================================================
	size_my_lists(StudentVector, quarter_list, half_list, full_list);
	size_my_query(query, quarter_query, half_query, full_query);
	Student temp5;
	std_find(quarter_list, quarter_query);
	int std_find_q_comp = temp5.get_compareCount() / quarter_query.size();
	std_find(half_list, half_query);
	int std_find_h_comp = temp5.get_compareCount() / half_query.size();
	std_find(full_list, full_query);
	int std_find_f_comp = temp5.get_compareCount() / full_query.size();

	print_std_find(quarter_list, half_list, full_list, std_find_q_comp, std_find_h_comp, std_find_f_comp, outFile);
//=================================================================================================================================

//SET.FIND SECTION==================================================================================================================
	size_my_sets(StudentVector, quarter_set, half_set, full_set);
	size_my_query(query, quarter_query, half_query, full_query);
	Student temp7;
	set_find(quarter_set, quarter_query);
	int set_find_q_comp = temp7.get_compareCount() / quarter_query.size();
	set_find(half_set, half_query);
	int set_find_h_comp = temp7.get_compareCount() / half_query.size();
	set_find(full_set, full_query);
	int set_find_f_comp = temp7.get_compareCount() / full_query.size();

	print_set_find(quarter_set, half_set, full_set, set_find_q_comp, set_find_h_comp, set_find_f_comp, outFile);
//==================================================================================================================================
	outFile.close();

	return 0;
}
