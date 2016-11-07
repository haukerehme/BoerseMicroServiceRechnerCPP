/*
 * RechnerZusammenfasser.h
 *
 *  Created on: 07.11.2016
 *      Author: hrs
 */

#ifndef RECHNERZUSAMMENFASSER_H_
#define RECHNERZUSAMMENFASSER_H_

#include "../model/Tradevorhersage.h"
#include <vector>

using namespace std;

class RechnerZusammenfasser {
public:
	RechnerZusammenfasser();
	Tradevorhersage analyse(vector<int> closewerte, int vergleichslaenge, int auswertungslaenge, int zusammenfasserInterval, int spread);
	int addierer(vector<int> liste, int startIndex, int endIndex);
	Tradevorhersage addiereTradevorhersage(vector<Tradevorhersage> vectorTradevorhersage);
	virtual ~RechnerZusammenfasser();
};

#endif /* RECHNERZUSAMMENFASSER_H_ */
