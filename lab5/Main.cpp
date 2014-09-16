#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "LinkedList.h"

LinkedList<string> list;

using namespace std;

int main(int argc, char *argv[])
{
	// INPUT 
	ifstream inFile;
	ofstream outFile;
	
	inFile.open(argv[1]);
	outFile.open(argv[2]);
	string cmd;
	while(inFile >> cmd)

	if(cmd == "clear" )
	{
		list.clear();
		outFile << "clear" << endl;
	}
	else if (cmd == "insert" )
	{
		int index;
		string item;
		inFile >> index;
		inFile >> item;
		list.insert(index, item);
		outFile << "insert " << index << " " << item << endl;
	}
	else if (cmd == "remove" )
	{
		int index;
		inFile >> index;
		outFile << "remove " << index << " " << list.remove(index) << endl;
	}
	else if (cmd == "print" )
	{
		list.print(outFile);
	}
	else if (cmd == "find" )
	{
		string name;
		inFile >> name;
		outFile << "find " << name << " " << list.find(outFile, name) << endl;
	}
	inFile.close();
	outFile.close();
	list.clear();
	return 0;
	
}

