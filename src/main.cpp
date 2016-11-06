//============================================================================
// Name        : BoerseMicroServiceRechnerCPP.cpp
// Author      : Hauke Rehme-Schlüter
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "dao/EurUsdDao.h"
using namespace std;

int main() {
	cout << "" << endl; // prints 
	EurUsdDao& eurUsdDao = EurUsdDao::instance();
	eurUsdDao.findAll();
	return 0;
}
