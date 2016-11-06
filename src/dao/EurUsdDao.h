/*
 * EurUsddao.h
 *
 *  Created on: 06.11.2016
 *      Author: hrs
 */

#ifndef EURUSDDAO_H_
#define EURUSDDAO_H_


#include <vector>
using namespace std;

class EurUsdDao {
	public:
	static EurUsdDao& instance(){
			static EurUsdDao _instance;
		    return _instance;
		}

		vector<int> findAll();
		void test();

		//~EurUsdDao();

	private:
		// verhindert, dass ein Objekt von außerhalb von N erzeugt wird.
		EurUsdDao(){};

		 /* verhindert, dass eine weitere Instanz via
		 Kopier-Konstruktor erstellt werden kann */
		EurUsdDao(const EurUsdDao&);

		//Verhindert weitere Instanz durch Kopie
		EurUsdDao & operator = (const EurUsdDao&);
};

#endif /* EURUSDDAO_H_ */
