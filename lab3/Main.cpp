#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <list>
#include "Dictionary.h"
#include "Board.h"

using namespace std;

void to_lower(string& a_string) 
{
	for (size_t i = 0; i < a_string.length(); i++)
	a_string[i] = tolower(a_string[i]);
}

void to_alpha(string& a_string) 
{
	for (size_t i = 0; i < a_string.length(); i++)
		if(!isalpha(a_string[i]))
		{
			a_string[i] = ' ';
		}
}

int main(int argc, char *argv[])
{
	vector<string> individual_letters;
	ifstream inFile;
	ofstream outFile;

	/*
	list<int> LIST;
	list<int>::iterator list_it = LIST.begin();
	map<string,list<int> > MAP;
	map<string,list<int> >::iterator map_it;
	set<string> SET;
	set<string>::iterator set_it;
	*/
	//===============================================================================================================================
	// Input Dictionary File ----------------------------------------------------------------------------------------------
	inFile.open(argv[1]);
	string dic_words;
	Dictionary dic_obj(dic_words);

	while(getline(inFile, dic_words))
	{
		to_lower(dic_words);
		dic_obj.LOAD(dic_words);
	}
		//dic_obj.print_dic_set();
	inFile.close();
	// End Input Dictionary File-------------------------------------------------------------------------------------------------
	//================================================================================================================================
	// Input Board File--------------------------------------------------------------------------------------------------------
	inFile.open(argv[2]);
	string board_letters;
	string letter;
	Board board_obj(board_letters);
	double letter_counter = 0;
	while(getline(inFile, board_letters))
	{
		to_lower(board_letters);
		istringstream ss(board_letters);
		while(ss >> letter)
		{
			letter_counter++;
			individual_letters.push_back(letter);
		}
	}
	board_obj.LOAD(letter_counter, individual_letters); // Load my tiles into my board
	inFile.close();
	// End Input Board File------------------------------------------------------------------------------------------------------
	//=================================================================================================================================
	// Output File-------------------------------------------------------------------------------------------------------------
	set<string> temp = dic_obj.get_dic_set();	
	board_obj.Start_Boggle(temp);
	outFile.open(argv[3]);
	board_obj.PRINT(outFile); // Print out my Boggle board
	outFile.close();
	//End Output File-----------------------------------------------------------------------------------------------------------

	return 0;
}
