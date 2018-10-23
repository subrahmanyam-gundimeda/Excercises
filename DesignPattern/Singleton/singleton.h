/*
 * singleton.h
 *
 *  Created on: 29-Aug-2018
 *      Author: subrahmanyam
 */

#ifndef HEADERS_SINGLETON_H_
#define HEADERS_SINGLETON_H_


#include <mutex>
#include<iostream>
#include<string>
#include<memory>
#include<thread>

using namespace std;

class cSingleton{

public:
	static cSingleton* getInstance();

private:
	cSingleton(){};
	cSingleton(const cSingleton& lhs) ;
	cSingleton(const cSingleton&& lhs) ;
	~cSingleton(){};
private:
	static cSingleton* singleton_object;
	static std::mutex m_mutex;

	//static std::shared_ptr<cSingleton> singleton_object;

};



#endif /* HEADERS_SINGLETON_H_ */
