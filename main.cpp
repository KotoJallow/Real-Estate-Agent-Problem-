#include <iostream>
#include "matcher.h"

int main(){
	Matcher evsahibi("..\\ornek2\\evsahibitercihi.txt");
	Matcher kiraci("..\\ornek2\\kiracitercihi.txt");

	kiraci.stableMatch(evsahibi);

	kiraci.displayStableMatch();
	cout << "*********" << endl;
	evsahibi.displayStableMatch();

	
}
