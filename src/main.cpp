//============================================================================
// Name        : BoerseMicroServiceRechnerCPP.cpp
// Author      : Hauke Rehme-Schlüter
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "dao/EurUsdDao.h"
#include "controller/socket/SocketSchnittstelle.h"
#include "Rechner/AnalyseMehrereVergleichsstrecken.h"
#include "dao/EurUsdDao.h"
using namespace std;

int main() {
	cout << "" << endl; // prints 
	//EurUsdDao& eurUsdDao = EurUsdDao::instance();
	//eurUsdDao.findAll();

//	double value = 0;

	vector<int> closewerteEurUsd = EurUsdDao::instance().findAll();
	vector<int> vergleichsstrecken(240,150);
	AnalyseMehrereVergleichsstrecken analyse = AnalyseMehrereVergleichsstrecken(closewerteEurUsd, vergleichsstrecken, 30, 1);
	cout << "Start Analyse" << endl;
	Tradevorhersage tradevorhersage = analyse.makeTradevorhersage();
	cout << "Finish" << endl;


	/*for(;;){
		value = SocketSchnittstelle::sharedSocketSchnittstelle().recvLiveValue();
		if(value!=0){
			closewerteEurUsd.push_back(value);
		}
	}*/

	return 0;
}
