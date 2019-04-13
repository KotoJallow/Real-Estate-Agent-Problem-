#ifndef Matcher_H
#define Matcher_H 

#include <cstdio>
#include <fstream>
#include <List>
#include <algorithm>
#include <vector>
#include "util.h"
#define NOT_FOUND -1

using namespace std;

class Matcher{
	private:
		int size;
		list<list<int> > dataList;
		vector<Util> util;
		void fillList(string);
		void fillUtil();
		bool allEngaged();
		bool isMorePreferable(int,int);
		bool isUtilDefault();
		bool isRowValid(int);
		bool isDataListValid();
		int rowSum(int);
		int getElement(int,int);
		int getIndex(int,int);
		list<int> getRow(int);
		vector<Util>& getUtil();
	public:
		Matcher(string);
		void stableMatch(Matcher&);
		void displayStableMatch();
		void display();
		int getSize();
		
};


#endif