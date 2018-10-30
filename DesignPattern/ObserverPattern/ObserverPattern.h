/*
 * ObserverPattern.h
 *
 *  Created on: 24-Oct-2018
 *      Author: subrahmanyam
 */

#ifndef HEADERS_OBSERVERPATTERN_H_
#define HEADERS_OBSERVERPATTERN_H_


#include <mutex>
#include<iostream>
#include<string>
#include<memory>
#include<thread>
#include<vector>
#include<string>

class Observer;

class Subject{
private:
	std::vector<Observer*> listeners;

public:
	void notify();
	void register_me(Observer* subscriber);
	void unregister(int index);
};

class Observer{
public:
	Observer(Subject* ptr, int index);
	~Observer();
	virtual void update(std::string &msg)=0;

	void register_me();
	void unregister();

	int getID() const;
private:
	Subject* sender;
	int myid;


};

class subscribers: public Observer{
public:
	subscribers(Subject* ptr,int myid);
	~subscribers();

	void update(std::string &msg);


};

#endif /* HEADERS_OBRVERPATTERN_H_ */
