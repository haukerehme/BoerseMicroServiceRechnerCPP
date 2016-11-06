/*
 * EurUsddao.cpp
 *
 *  Created on: 06.11.2016
 *      Author: hrs
 */

#include "EurUsdDao.h"
#include <vector>
#include <mysql++.h>
#include <mysql.h>

#define dbname "SpringTest"
#define server "62.75.142.111"
#define user "root"
#define pass "43mitmilch"

using namespace std;
using namespace mysqlpp;

vector<int> EurUsdDao::findAll(){
	vector<int> resultVector;

	Connection con(true);
	    try {
	        con.connect(dbname, server, user, pass);
	        cout << "Connected to database\n";
	        string s = "SELECT wert FROM eurusd order by zeit ASC";
	        Query q = con.query(s);
	        StoreQueryResult sq = q.store();
	        StoreQueryResult::iterator it;
	        it = sq.begin();
	        Row row = *it;
	        int diff;
	        double wertAlt = row[0];
	        double wertNeu;
	        it++;
	        while (it != sq.end()) {
	            wertNeu = row[0];
	        	diff = (int) (10000*wertNeu - 10000*wertAlt);
	        	resultVector.push_back(diff);
	            it++;
	        }
	    } catch (Exception &e) {
	        cout << e.what() << endl;
	    }

	    cout << "Vektorgröße: " << resultVector.size() << endl;

	return resultVector;
}

void EurUsdDao::test(){
	vector<int> tmpVector;

	Connection con(true);
	    try {
	        con.connect(dbname, server, user, pass);
	        cout << "Connected to database\n";
	        string s = "SELECT * FROM user";
	        Query q = con.query(s);
	        StoreQueryResult sq = q.store();
	        StoreQueryResult::iterator it;
	        it = sq.begin();
	        while (it != sq.end()) {
	            Row row = *it;
	            cout << row[0] << " " << row[1] << " " << row[2] << endl;
	            it++;
	        }
	    } catch (Exception &e) {
	        cout << e.what() << endl;
	    }
}

