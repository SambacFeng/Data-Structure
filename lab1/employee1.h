#ifndef EMPLOYEE
#define EMPLOYEE

#include <string> // declares string class

using namespace std;

class Employee
{
	protected:
	//private:
		string name;
		double grossPay;

	public:

		// Postcondition: this employee's name has been set to ""
		//                and gross pay to 0.00.
		Employee();


		// Postcondition: The name and gross pay of this Employee have
		//                been read in.
		void input();


		// Postcondition: this Employee's name and gross pay have been
		//                written out.
		void output() const;


		// Postcondition: this Employee contains a copy of otherEmployee.
		void copy(const Employee& otherEmployee);


		// Postcondition: true has been returned if this Employee's gross
		//                pay is greater than that of otherEmployee.
		//                Otherwise, false has been returned.
		bool compare(const Employee& otherEmployee) const;

		string getName() const;

}; // Employee

#endif