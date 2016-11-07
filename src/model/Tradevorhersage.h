/*
 * Tradevorhersage.h
 *
 *  Created on: 07.11.2016
 *      Author: hrs
 */

#ifndef TRADEVORHERSAGE_H_
#define TRADEVORHERSAGE_H_

class Tradevorhersage {
public:
	Tradevorhersage();

	virtual ~Tradevorhersage();

	int GewinnzaehlerLong;
	int VerlustzaehlerLong;

	int GewinnzaehlerShort;
	int VerlustzaehlerShort;

	int GenerellPlus;
	int GenerellMinus;
	int hohesMinus;
	int hohesPlus ;

	int hoherLongVerlust;
	int geringerLongGewinn;
	int mittlererLongGewinn;
	int hoherLongGewinn;
	int sehrHoherLongGewinn;

    int geringerShortGewinn;
    int mittlererShortGewinn;
    int hoherShortGewinn;
    int sehrHoherShortGewinn;
    int hoherShortVerlust;
    int anzFormFound;
};

#endif /* TRADEVORHERSAGE_H_ */
