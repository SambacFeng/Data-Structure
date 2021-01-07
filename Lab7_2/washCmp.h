#ifndef WASH_H
#define WASH_H

#include <queue>
#include "car.h"

class WashCmp
{
private:
	std::queue<Car> carQueue;
	const static int CAPACITY;

	int numServedCars;//�����ѷ���ĳ�����
	double totalWaitingTime;
	double arrivalTime;
	int numServedCars_MAX;//�����ܹ�����ĳ���
	int Car_MAX;//��¼����г���




	int getNextArrival(); //accept user input to get the next arrival time
	void processArrivalNonEmptyQ(double currTime); //a car arrives and the waiting queue is not empty
	void processArrivalEmptyQ(double currTime); //a car arrives and the waiting queue is empty
	void processDeparture();
	void processRemain(); //no more arriving cars, process the remaining cars in the waiting queue

public:
	WashCmp();
	WashCmp(int n);
	void simulation();
	void printCmpStatistic();
};


#endif