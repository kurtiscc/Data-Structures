#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>


using namespace std;

class Dictionary
{
	private:
		string dic_words;
		set<string> dic_set;
		set<string>::iterator it;
		string misspelled_word;
		
	public:

	Dictionary(string dic_words_in)
	{
		dic_words = dic_words_in;
	}
	string get_dic_words()
	{
		return dic_words;
	}
	void print_dic_set()
	{
		for(it=dic_set.begin(); it!=dic_set.end(); it++)
		{
			cout << *it << endl;
		}
	}
	void add_dic_file(string line)
	{
		dic_set.insert(line);
	}
	set<string> get_set()
	{
		return dic_set;
	}
	set<string>::iterator get_it()
	{
		return it;
	}
	string set_misspelled_word(string word)
	{
		misspelled_word = word;
	}
	void compare_sets(int lines, string w, set<string>::iterator& set_it, map<string, list<int> >& MAP)
	{
			set_it = dic_set.find(w);
			if (set_it == dic_set.end())
			{
				MAP[w].push_back(lines);
			}
	}
	
};
