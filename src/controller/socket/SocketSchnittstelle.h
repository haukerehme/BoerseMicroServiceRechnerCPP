/*
 * SocketSchnittstelle.h
 *
 *  Created on: 06.11.2016
 *      Author: hrs
 */

#ifndef SOCKETSCHNITTSTELLE_H_
#define SOCKETSCHNITTSTELLE_H_

class SocketSchnittstelle {


public:

	static SocketSchnittstelle& sharedSocketSchnittstelle(){
		static SocketSchnittstelle _sharedSocketSchnittstelle;
	    return _sharedSocketSchnittstelle;
	}



	~SocketSchnittstelle();

	void run();

private:
	// verhindert, dass ein Objekt von außerhalb von N erzeugt wird.
	SocketSchnittstelle(){};

	 /* verhindert, dass eine weitere Instanz via
	 Kopier-Konstruktor erstellt werden kann */
	SocketSchnittstelle(const SocketSchnittstelle&);

	//Verhindert weitere Instanz durch Kopie
	SocketSchnittstelle & operator = (const SocketSchnittstelle&);


};

#endif /* SOCKETSCHNITTSTELLE_H_ */
