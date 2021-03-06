
#include "listTemp.h"
#include "company.h"
#include <ctime>
#include <iostream>
using namespace std;

int main()
{

	//srand((unsigned int)time(0));
	//cout << rand() % 1000 << endl;
	//cout << RAND_MAX << endl;

	//clock_t start_t, end_t, elapsed_t;

	//start_t = clock();
	//// code segment whose time cost is to be measured
	//for (int i = 0; i < 100000000; i++);
	//end_t = clock();

	//elapsed_t = end_t - start_t; //in milliseconds

	//cout << "time elapsed: " << (double)elapsed_t / CLOCKS_PER_SEC << "seconds" << endl;
	//cout << "clock ticks per second: " << CLOCKS_PER_SEC << endl;


	//---------------------------------------------------------------------------
	Company cmp;
	cmp.inputSalary();

	clock_t start_t, end_t;

	start_t = clock();
	cmp.findBestPaid();
	end_t = clock();
	cmp.printBestPaid();
	cout << "Findbestpaid time cost: " << (double)(end_t - start_t) / CLOCKS_PER_SEC << " seconds" << endl;


	start_t = clock();
	cmp.findBestPaidReverse();
	end_t = clock();
	cmp.printBestPaid();
	cout << "Reverse-findbestpaid time cost: " << (double)(end_t - start_t) / CLOCKS_PER_SEC << " seconds" << endl;


	return 0;
}