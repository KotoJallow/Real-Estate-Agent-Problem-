#include <iostream>
#include "matcher.h"

Matcher::Matcher(string fn){
	fillList(fn);
	size = dataList.size();
	fillUtil();
}
int Matcher::getSize(){
	return size;
}
int len(int num){
	int size =  1;
	while(num/10){
		num %= 10;
		size++;
	}
	return size;
}

int tabsCount(string data){
	int count = 1;
	for(int i=0;i<data.size();i++){
		if(data[i] == '\t') count++;
	}
	return count;
}

list<int> Matcher::getRow(int index){
	list<list<int> >::iterator it = dataList.begin();
	while(index){
		++it;
		--index;
	}
	return *it;
}

int Matcher::getElement(int row,int col){
	list<int> elemRow = getRow(row);
	list<int>::iterator it = elemRow.begin();
	while(col){
		++it;
		--col;
	}
	return *it;
}
int Matcher::getIndex(int row,int val){
	list<int> elemRow = getRow(row);
	list<int>::iterator it = elemRow.begin();
	for(;it!=elemRow.end();it++){
		if(*it == val){
			return distance(elemRow.begin(),it);
		}
	}
	return NOT_FOUND;
}
void Matcher::display(){
	list<list<int> >::iterator l_it;
	for(l_it = dataList.begin();l_it != dataList.end();l_it++){
	
		list<int>::iterator it;
		for(it = l_it->begin();it != l_it->end();it++){
			cout << *it << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void Matcher::displayStableMatch(){
	if(!isUtilDefault()){
		vector<Util>::iterator it = util.begin();
		for(;it != util.end();it++){
			it->displayMatches();
		}
	}else{
		cout << "Access Denied!!!" << endl;
	}	
}

void Matcher::fillUtil(){
	for(int i=0;i<size;i++){
		util.push_back(Util(i,0,0,false));
	}
}

bool Matcher::isUtilDefault(){
	for(int i=0;i<size;i++){
		if(util[i].getMatchedWith()) return false; 
	}
	return true;
}

void Matcher::fillList(string fileName){
	ifstream fn(fileName.c_str());
	string data;
	while(getline(fn,data) && data.size()){
		const char * dataPtr = data.c_str();
		int count = tabsCount(data);
		list<int> temp;
		for(int i=0;i<count;i++){
			int elem;
			sscanf(dataPtr,"%d",&elem);
			dataPtr += len(elem) + 1;
			temp.push_back(elem);
		} 
		dataList.push_back(temp);
		
		temp.clear();
	}
}

bool Matcher::allEngaged(){
	for(int i=0;i<size;i++){
		if(!util[i].getEngagementStatus()) return false;
	}
	return true;
}
bool  Matcher::isMorePreferable(int row,int yeni){
	int eski = util[row].getMatchedWith();
	return getIndex(row,yeni) < getIndex(row,eski);
}

bool Matcher::isRowValid(int row){
	list<int> currentRow = getRow(row);
	int rowSize = currentRow.size();
	currentRow.sort();
	
	list<int>::iterator it = currentRow.begin();
	list<int>::iterator prev = it;
	it++;
	for(;it != currentRow.end();it++){
		if(*it == *prev) return false;
		prev = it;
	}

	return (rowSize==size);
}

int Matcher::rowSum(int row){
	list<int> currentRow = getRow(row);
	list<int>::iterator it = currentRow.begin();
	int sum = 0;
	for(;it != currentRow.end();it++){
		sum+= (*it);
	}
	return sum;
}

bool Matcher::isDataListValid(){
	int tSum = 0;
	int sRow;
	for(int i=0;i<size;i++){
		if(!isRowValid(i)) return false;
		sRow = rowSum(i);
		tSum += sRow;
	}
	return (tSum==size*sRow);
}

vector<Util>& Matcher::getUtil(){
	return util;
}

void Matcher::stableMatch(Matcher& m){
	bool matchable = (m.getSize() == size);
	if(isDataListValid() && matchable){
		int row = 0;
		while(!allEngaged()){
				if(!this->getUtil()[row].getEngagementStatus()){
					int index = this->getUtil()[row].getOnTheLine();
					int elem = this->getElement(row,index);
					
					if(!m.getUtil()[elem].getEngagementStatus()){
						this->getUtil()[row].setEngagementStatus(true);
						this->getUtil()[row].setMatchedWith(elem);
						this->getUtil()[row].setOnTheLine();
						
						m.getUtil()[elem].setEngagementStatus(true);
						m.getUtil()[elem].setMatchedWith(row);
						
					}else if(m.isMorePreferable(elem,row)){
						int previousEngaged = m.getUtil()[elem].getMatchedWith();
						this->getUtil()[previousEngaged].setEngagementStatus(false);
						
						this->getUtil()[row].setEngagementStatus(true);
						this->getUtil()[row].setMatchedWith(elem);
						this->getUtil()[row].setOnTheLine();
						
						m.getUtil()[elem].setMatchedWith(row);
						
						row = previousEngaged;
						continue;
					}else{
						this->getUtil()[row].setOnTheLine();
						continue;
					}
				}
				row++;
		}
	}else if(!matchable){
		cout << "Datasets cannot be matched "<< endl;
	}else{
		cout << "Invalid data input" << endl;
	}
}
