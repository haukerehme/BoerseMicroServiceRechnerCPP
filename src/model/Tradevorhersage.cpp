/*
 * Tradevorhersage.cpp
 *
 *  Created on: 07.11.2016
 *      Author: hrs
 */

#include "Tradevorhersage.h"

Tradevorhersage::Tradevorhersage() {
	// TODO Auto-generated constructor stub
	GewinnzaehlerLong = 0;
	VerlustzaehlerLong = 0;

	GewinnzaehlerShort = 0;
	VerlustzaehlerShort = 0;

	GenerellPlus = 0;
	GenerellMinus = 0;
	hohesMinus = 0;
	hohesPlus = 0;

	hoherLongVerlust = 0;
	geringerLongGewinn = 0;
	mittlererLongGewinn = 0;
	hoherLongGewinn = 0;
	sehrHoherLongGewinn = 0;

	geringerShortGewinn = 0;
	mittlererShortGewinn = 0;
	hoherShortGewinn = 0;
	sehrHoherShortGewinn = 0;
	hoherShortVerlust = 0;

	anzFormFound = 0;
}

Tradevorhersage::~Tradevorhersage() {
	// TODO Auto-generated destructor stub
}

