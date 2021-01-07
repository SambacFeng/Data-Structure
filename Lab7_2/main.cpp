#include "car.h"
#include "washCmp.h"
#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
double l, u;
int main()
{
	int n;
	
	srand((unsigned int)time(0));
	cout << "please input the mean inter_arrival time";
	cin >> l;
	l = 1.0 / l;
	cout << "please input the mean service time";
	cin >> u;
	u = 1.0 / u;

	cout << "please input the total number of carsevices";
	cin >> n;
	WashCmp cmp(n);
	cmp.simulation();
	cmp.printCmpStatistic();
	cout <<"\n" <<l/(u*(u-l));
	return 0;
}