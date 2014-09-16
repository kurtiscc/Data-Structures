#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <cmath>
#include <math.h>

using namespace std;

class Board
{
	private:
		string board_words;
		set<string> board_set;
		set<string>::iterator board_it;
		vector< vector<string> > board_vec;
		double board_size;
		double letter_counter;
		string temp;
		string potential_word;
		set<int> used;
		set<string> found_words;
		set<string>::iterator found_words_it;

		
	public:

	Board(string board_words_in)
	{
		board_words = board_words_in;
	}
	Board(vector<vector<string> > board_vec_in)
	{
		board_vec = board_vec_in;
	}

	//-----------------------------------------------------------------------------------------------------------------------------
	void LOAD(double get_letter_counter, vector<string> my_letters)
	{
		vector<string> row;
		board_size = sqrt(get_letter_counter);
		double row_count = 0;
		for(int i = 0; i < board_size; i++)
		{
			for(int j = 0; j < board_size; j++)
			{
				row.push_back(my_letters[row_count]); // Add an element (column) to the row
				row_count++;
			}
			board_vec.push_back(row); // Add the row to the main vector
			row.clear();
		}
	}
	
	void FINDWORDS(set<string>& dic_set, string potential_word)
	{
		found_words_it = dic_set.find(potential_word);
		if(found_words_it != dic_set.end())
		{
			found_words.insert(potential_word);
		}
	}
	
	void Start_Boggle(set<string>& dic_set)
	{
		for (int row = 0; row < board_vec.size(); row++) 
		{
			for (int col = 0; col < board_vec.size(); col++) 
			{
				FINDWORD(row, col, potential_word, dic_set);
			}
		}
	}

	bool USED(set<int>& used, int pair)
	{
		int count;
		count = used.count(pair);
		if(count == 1)
		{
			return true;
		}
	}
	
	bool FINDPREFIX(set<string>& dic_set, string potential_word)
	{
		set<string>::iterator it;
		it = dic_set.lower_bound(potential_word);
		if(it != dic_set.end())
		{
			temp = *it;
			for(int i = 0; i < potential_word.length(); i++)
			{
				if(potential_word[i] != temp[i])
				{
					return false;
				}
			}
			if(potential_word.length() >=4)
				{
					FINDWORDS(dic_set, potential_word);
				}
			return true;
		}
		return false;
	}
	
	void FINDWORD(int row, int col, string potential_word, set<string>& dic_set)
	{
		int pair = (row * board_size) + col;
	
		if(col < 0 || row < 0 || row >= board_vec.size() || col >= board_vec.size())
		{
			return;
		}
		if(USED(used, pair))
		{
			return;
		}

		potential_word.append(board_vec[row][col]);

		if(!FINDPREFIX(dic_set, potential_word))
		{
			return;
		}
		used.insert(pair);

		FINDWORD(row, col+1, potential_word, dic_set);
		FINDWORD(row+1, col+1, potential_word, dic_set);
		FINDWORD(row+1, col, potential_word, dic_set);
		FINDWORD(row+1, col-1, potential_word, dic_set);
		FINDWORD(row, col-1, potential_word, dic_set);
		FINDWORD(row-1, col-1, potential_word, dic_set);
		FINDWORD(row-1, col, potential_word, dic_set);
		FINDWORD(row-1, col+1, potential_word, dic_set);

		used.erase(pair);
		return;
	}

	void PRINT(ofstream& outFile)
	{
		int row = board_vec.size();
			for (int i = 0; i < row; i++) 
			{
				int col = board_vec[i].size();
				for (int j = 0; j < col; j++) 
				{
					outFile << board_vec[i][j] << " ";
				}	
				outFile << endl;
			}
			outFile << endl;
			for(found_words_it=found_words.begin(); found_words_it!=found_words.end(); found_words_it++)
				{
					outFile << *found_words_it << endl;
				}
	}
};