/*
 * singleton.cpp
 *
 *  Created on: 29-Aug-2018
 *      Author: subrahmanyam
 */
#include "../headers/singleton.h"

cSingleton* cSingleton::singleton_object=nullptr;
std::mutex cSingleton::m_mutex;

cSingleton* cSingleton::getInstance(){

	if (singleton_object == nullptr){

		std::unique_lock<std::mutex> ul{m_mutex};

		if (singleton_object == nullptr){
			singleton_object = new cSingleton();
		}
	}

	return singleton_object;
}



