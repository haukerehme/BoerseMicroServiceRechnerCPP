/*
 * AnalyseMehrereVergleichsstrecken.h
 *
 *  Created on: 07.11.2016
 *      Author: hrs
 */

#ifndef ANALYSEMEHREREVERGLEICHSSTRECKEN_H_
#define ANALYSEMEHREREVERGLEICHSSTRECKEN_H_

#include <vector>
#include <string>
#include <iostream>

#include "../model/Tradevorhersage.h"

using namespace std;

class AnalyseMehrereVergleichsstrecken {
public:
	AnalyseMehrereVergleichsstrecken(vector<int> intArray, vector<int> _listVergleichslaenge, int _auswertungslaenge, int _spread);
	virtual ~AnalyseMehrereVergleichsstrecken();
	Tradevorhersage makeTradevorhersage();
private:
	vector<int> diffClosewerte;
	vector<int> listVergleichslaenge;
	int auswertungslaenge;
	int spread;
};

#endif /* ANALYSEMEHREREVERGLEICHSSTRECKEN_H_ */
