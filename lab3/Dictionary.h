#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include "Board.h"

using namespace std;

class Dictionary
{
	private:
		string dic_words;
		set<string> dic_set;
		set<string>::iterator dic_it;
		string misspelled_word;
		
	public:

	Dictionary(string dic_words_in)
	{
		dic_words = dic_words_in;
	}

	//-----------------------------------------------------------------------------------------------------------------------------
	void print_dic_set()
	{
		for(dic_it=dic_set.begin(); dic_it!=dic_set.end(); dic_it++)
		{
			cout << *dic_it << endl;
		}
	}
	void LOAD(string line)
	{
		dic_set.insert(line);
	}	
	set<string> get_dic_set()
	{
		return dic_set;
	}
};