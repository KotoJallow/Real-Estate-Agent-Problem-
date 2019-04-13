#include <iostream>
#include "util.h"

Util::Util(int s,int o ,int m,bool i){
	self = s;onTheLine = o;matchedWith=m;isEngaged=i;
}
void Util::setOnTheLine(){
	onTheLine++;
}
int Util::getOnTheLine(){
	return onTheLine;
}
void Util::setMatchedWith(int m){
	matchedWith = m;
}
int Util::getMatchedWith(){
	return matchedWith;
}
void Util::setEngagementStatus(bool status){
	isEngaged = status;
}
bool Util::getEngagementStatus(){
	return isEngaged;
}

void Util::displayMatches(){
	std::cout << self << ":" << getMatchedWith() << std::endl;
}