#ifndef Util_H
#define Util_H 

class Util{
	private:
		int self ;
		int onTheLine;
		int matchedWith;
		bool isEngaged;
	public:
		Util(){};
		Util(int,int,int,bool);
		void setOnTheLine();
		int getOnTheLine();
		void setMatchedWith(int);
		int getMatchedWith();
		void setEngagementStatus(bool);
		bool getEngagementStatus();
		void displayMatches();	
};
#endif