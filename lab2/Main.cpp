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

void output(map<string,list<int> >::iterator& map_it, map<string,list<int> >& MAP, ofstream& outFile)
{
		for (map_it=MAP.begin(); map_it!=MAP.end(); ++map_it)
	{
		outFile << map_it->first << ": ";
	
		for(list<int>::iterator map_it_2 = map_it->second.begin(); map_it_2 != map_it->second.end(); map_it_2++)
		{
			outFile << *map_it_2 << " ";
		}
		outFile << endl;
	}
}

int main(int argc, char *argv[])
{
	// Input Dictionary File 
	ifstream inFile;
	ofstream outFile;
	int lines = 0;

	list<int> LIST;
	list<int>::iterator list_it = LIST.begin();
	map<string,list<int> > MAP;
	map<string,list<int> >::iterator map_it;
	set<string> SET;
	set<string>::iterator set_it;
	
	inFile.open(argv[1]);
	string dic_words;
	Dictionary dic_obj(dic_words);

	while(getline(inFile, dic_words))
	{
		to_lower(dic_words);
		dic_obj.add_dic_file(dic_words);
	}
	inFile.close();

		// Input Document File
	inFile.open(argv[2]);
	
	string doc_words;
	while(getline(inFile, doc_words))
	{
		lines++;
		to_lower(doc_words);
		to_alpha(doc_words);
		string w;
		istringstream ss(doc_words);
		while(ss >> w)
		{
			dic_obj.compare_sets(lines, w, set_it, MAP);
		}
	}
	inFile.close();
	
	//Output Misspelled Words
	outFile.open(argv[3]);
	output(map_it,MAP,outFile);
	outFile.close();
	
	system("pause");
	return 0;
}

