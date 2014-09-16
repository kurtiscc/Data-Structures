#include <iostream>
#include <string>
#include <fstream>
#include "HashSet.h"

HashSet<string> set;

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
		set.clear();
		outFile << "clear" << endl;
	}
	else if (cmd == "add" )
	{
		string item;
		inFile >> item;
		set.add(item);
		outFile << "add " << item << endl;
	}
	else if (cmd == "remove" )
	{
		string item;
		inFile >> item;
		set.remove(item);
		outFile << "remove " << item << endl;
	}
	else if (cmd == "print" )
	{
		set.print(outFile);
	}
	else if (cmd == "find" )
	{
		string name;
		inFile >> name;
		
		outFile << "find " << name << " ";
		if(set.find(name) == true)
		{
		   outFile << "true";
		} 
		else{
		   outFile << "false";}
		outFile << endl;
	}
	inFile.close();
	outFile.close();
	set.clear();
	return 0;
}

