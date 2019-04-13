#include <iostream>
#include "matcher.h"

int main(){
	Matcher evsahibi("evsahibitercihi.txt");
	Matcher kiraci("kiracitercihi.txt");

	kiraci.stableMatch(evsahibi);

	kiraci.displayStableMatch();
	cout << "*********" << endl;
	evsahibi.displayStableMatch();

	
}
