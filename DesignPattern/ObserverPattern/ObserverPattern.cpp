/*
 * ObserverPattern.cpp
 *
 *  Created on: 30-Oct-2018
 *      Author: subrahmanyam
 */
#include "ObserverPattern.h"


//---------------Subject..............................
void Subject::notify(){
	for(auto i:listeners){
		std::string tmp = "New message is broadcasting.....";
		i->update(tmp);
	}
}

void Subject::register_me(Observer* subscriber){
	listeners.push_back(subscriber);
}
void Subject::unregister(int index){
	using tr = std::vector<Observer*>::iterator;
	tr i =  std::end(listeners);
	for( i = std::begin(listeners); i != std::end(listeners); ++i){
		if(index == (*i)->getID())
			std::cout<<"\n Found the instance";
			break;
	}

	listeners.erase(i);

}

//---------------Observer..............................
Observer::Observer(Subject* ptr, int index):sender(ptr),myid(index){}
Observer::~Observer(){};

void Observer::register_me(){
	sender->register_me(this);
}
void Observer::unregister(){
	std::cout<<"\n unregister called for "<<myid;
	sender->unregister(myid);
}

int Observer::getID() const{
	return myid;
}
//---------------subscribers..............................
subscribers::subscribers( Subject* ptr,int myid):Observer(ptr,myid){};
subscribers::~subscribers(){};

void subscribers::update(std::string &msg){
	std::cout<<"\n My object number: "<<getID()<<"\t received a broadcast message from "
			"sender as\""<<msg<<"\"";
}

//-------------------------Usage of Observer pattern----------
Subject *s = new Subject;
subscribers s1(s,1);
s1.register_me();
subscribers s2(s,2);
s2.register_me();
subscribers s3(s,3);
s3.register_me();

s->notify();
cout<<"\n Added all instances";

s1.unregister();

s->notify();
