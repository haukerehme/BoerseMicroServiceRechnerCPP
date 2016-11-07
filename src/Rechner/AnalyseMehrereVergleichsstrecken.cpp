/*
 * AnalyseMehrereVergleichsstrecken.cpp
 *
 *  Created on: 07.11.2016
 *      Author: hrs
 */

#include "AnalyseMehrereVergleichsstrecken.h"
#include <vector>
#include <string>
#include <iostream>

#include "RechnerZusammenfasser.h"
#include "../model/Tradevorhersage.h"

using namespace std;


AnalyseMehrereVergleichsstrecken::AnalyseMehrereVergleichsstrecken(vector<int> intArray, vector<int> _listVergleichslaenge, int _auswertungslaenge, int _spread):
		diffClosewerte(intArray),listVergleichslaenge(_listVergleichslaenge),auswertungslaenge(_auswertungslaenge),spread(_spread){}

AnalyseMehrereVergleichsstrecken::~AnalyseMehrereVergleichsstrecken() {
	// TODO Auto-generated destructor stub
}

Tradevorhersage AnalyseMehrereVergleichsstrecken::makeTradevorhersage() {
	Tradevorhersage result;

	RechnerZusammenfasser rechner = RechnerZusammenfasser();

	result = rechner.analyse(this->diffClosewerte, this->listVergleichslaenge[0],this->auswertungslaenge, 30, this->spread);


	return result;
}
