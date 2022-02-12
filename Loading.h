#pragma once
#include<vector>
#include<string>
#include <fstream>
#include <iostream>
using namespace std;

class Loading
{
public:
	////This class is For Loading old written ids in text id's files to keep id's unique////

	static vector<int> loadTheIdsOfAllpersons(string fileName);

	static int loadLastId(string fileName,int startIds);

	static void writeNewId(string filename,int newId);


};

