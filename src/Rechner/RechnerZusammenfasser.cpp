/*
 * RechnerZusammenfasser.cpp
 *
 *  Created on: 07.11.2016
 *      Author: hrs
 */

#include "RechnerZusammenfasser.h"
#include "tbb/parallel_for.h"
#include "tbb/blocked_range.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


RechnerZusammenfasser::RechnerZusammenfasser() {
	// TODO Auto-generated constructor stub

}

Tradevorhersage RechnerZusammenfasser::analyse(vector<int> closewerte, int vergleichslaenge, int auswertungslaenge, int zusammenfasserInterval, int spread){
	Tradevorhersage result;
	vector<Tradevorhersage> vectorTradevorhersage;


	//Der Abschnitt der gesucht wird
	vector<int> akt(closewerte.begin() + (closewerte.size()-vergleichslaenge), closewerte.end());

	auto lambdaFunction = [&](tbb::blocked_range<int> range){
			for(int i = range.begin(); i < range.end(); i++){

				bool formFound = true;
				Tradevorhersage tmpTradevorhersage = Tradevorhersage();

				if(RechnerZusammenfasser::addierer(akt,0,zusammenfasserInterval-1) - RechnerZusammenfasser::addierer(closewerte,i, i+zusammenfasserInterval-1) < 4 &&
				   addierer(akt,0,zusammenfasserInterval-1) - addierer(closewerte,i, i+zusammenfasserInterval-1) > -4
				){
					for(unsigned int z = zusammenfasserInterval; z < akt.size();z=z+zusammenfasserInterval){
				    	if(addierer(akt,z,z+zusammenfasserInterval-1) - addierer(closewerte,i+z, i+z+zusammenfasserInterval-1) >= 4 ||
				           addierer(akt,z,z+zusammenfasserInterval-1) - addierer(closewerte,i+z, i+z+zusammenfasserInterval-1) <= -4){

				    		formFound = false;
				            break;
				        }
				    }
				    if(formFound){
				    	if((addierer(akt,0,akt.size()-1) - addierer(closewerte,i, akt.size()-1) >= (vergleichslaenge / 10)) ||
				           (addierer(akt,0,akt.size()-1) - addierer(closewerte,i, akt.size()-1) <= -(vergleichslaenge /10 ))){

				    		formFound = false;
				        }
				    }
				    if(formFound){
				    	tmpTradevorhersage.anzFormFound++;
				        int entwicklung = 0;
				        for(int z =i+vergleichslaenge;z < i+vergleichslaenge+auswertungslaenge;z++){
				        	entwicklung += closewerte[z];
				        }
				        if(entwicklung > 0){
				        	tmpTradevorhersage.GenerellPlus++;
				            if(entwicklung > 10){
				            	tmpTradevorhersage.hohesPlus++;
				            }
				        }
				        if(entwicklung < 0){
				        	tmpTradevorhersage.GenerellMinus++;
				        	if(entwicklung < -10){
				        		tmpTradevorhersage.hohesMinus++;
				        	}
				        }

				        if(entwicklung > spread){
				        	tmpTradevorhersage.GewinnzaehlerLong++;
				            if(entwicklung > spread){
				            	tmpTradevorhersage.geringerLongGewinn++;
				            }
				            if(entwicklung > spread+3){
				            	tmpTradevorhersage.mittlererLongGewinn++;
				            }
				            if(entwicklung > spread+9){
				            	tmpTradevorhersage.hoherLongGewinn++;
				            }
				            if(entwicklung > spread+15){
				            	tmpTradevorhersage.sehrHoherLongGewinn++;
				            }

				            if(entwicklung > spread+6){
				            	tmpTradevorhersage.hoherShortVerlust++;
				            }
				        }

				        if(entwicklung < spread){
				        	tmpTradevorhersage.VerlustzaehlerLong++;
				        }

				        if(entwicklung < -spread){
				        	tmpTradevorhersage.GewinnzaehlerShort++;

				            if(entwicklung < -spread){
				            	tmpTradevorhersage.geringerShortGewinn++;
				            }
				            if(entwicklung < -spread-3){
				            	tmpTradevorhersage.mittlererShortGewinn++;
				            }
				            if(entwicklung < -spread-10){
				            	tmpTradevorhersage.hoherShortGewinn++;
				            }
				            if(entwicklung < -spread-15){
				            	tmpTradevorhersage.sehrHoherShortGewinn++;
				            }
				            if(entwicklung > -spread-6){
				            	tmpTradevorhersage.hoherLongVerlust++;
				            }
		                }

				        if(entwicklung > -spread){
				        	tmpTradevorhersage.VerlustzaehlerShort++;
				        }
				        vectorTradevorhersage.push_back(tmpTradevorhersage);
				    }
				}
			}
		};

	tbb::parallel_for(tbb::blocked_range<int>(0,closewerte.size() - (vergleichslaenge + auswertungslaenge)), lambdaFunction);

	return addiereTradevorhersage(vectorTradevorhersage);
}

int RechnerZusammenfasser::addierer(vector<int> liste, int startIndex, int endIndex){
	int result = 0;
    for(int i = startIndex; i <= endIndex;i++){
    	result += liste[i];
    }
    return result;
}

Tradevorhersage RechnerZusammenfasser::addiereTradevorhersage(vector<Tradevorhersage> vectorTradevorhersage){
	Tradevorhersage ergebnis = Tradevorhersage();
	for(Tradevorhersage summand : vectorTradevorhersage){
		ergebnis.GewinnzaehlerLong += summand.GewinnzaehlerLong;
		ergebnis.GewinnzaehlerShort += summand.GewinnzaehlerShort;
		ergebnis.VerlustzaehlerLong += summand.VerlustzaehlerLong;
		ergebnis.VerlustzaehlerShort += summand.VerlustzaehlerShort;

		ergebnis.GenerellPlus += summand.GenerellPlus;
		ergebnis.GenerellMinus += summand.GenerellMinus;
		ergebnis.hohesPlus += summand.hohesPlus;
		ergebnis.hohesMinus += summand.hohesMinus;

		ergebnis.hoherLongVerlust += summand.hoherLongVerlust;
		ergebnis.geringerLongGewinn += summand.geringerLongGewinn;
		ergebnis.mittlererLongGewinn += summand.mittlererLongGewinn;
		ergebnis.hoherLongGewinn += summand.hoherLongGewinn;
		ergebnis.sehrHoherLongGewinn += summand.sehrHoherLongGewinn;

		ergebnis.geringerShortGewinn += summand.geringerShortGewinn;
		ergebnis.mittlererShortGewinn += summand.mittlererShortGewinn;
		ergebnis.hoherShortGewinn += summand.hoherShortGewinn;
		ergebnis.sehrHoherShortGewinn += summand.sehrHoherShortGewinn;
		ergebnis.hoherShortVerlust += summand.hoherShortVerlust;

		ergebnis.anzFormFound += summand.anzFormFound;
	}
	return ergebnis;
}

RechnerZusammenfasser::~RechnerZusammenfasser() {
	// TODO Auto-generated destructor stub
}
