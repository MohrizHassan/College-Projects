/**
* 1E3 - Introduction to Programming
* Practical 3 - Finding Net Pay
*
* Week of 29th January 2015
* Mohriz Hassan
*/

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

//Declare the numeric variables as doubles (decimal numbers)
//inputs
double hours, hourly_rate, credit;
//variables for calculation
double gross_wage, tax,  prsi, union_dues, net_pay;

//Declare the variable to hold the name as type "string"
string name;

//Read in the values, note the getline() function is used for the name
//This version assumes all value entered on one line as in the spec. which is handy for later looping versions
cout << "Enter hours, hourly rate, tax credit, name:";
cin >> hours >> hourly_rate >> credit;
getline(cin, name);
/* Alternative input processing:
cout << "Input Details: "<<endl;
cout << "------------------" <<endl;
cout << "Hours: ";
cin >> hours;
cout << "Hourly Rate: ";
cin >> hourly_rate;
cout << "Tax Credit: "; //for Task#2
cin >> credit;  //for Task#2
cout << "Name: " ;
//the newline character left by the last cin statement needs to be thrown away before getline will work:
cin.ignore(INT_MAX, '\n');
getline(cin, name);
*/

//Calculate the gross wage
//check if any overtime (more than 35 hours was worked)
if(hours>35)
{
	double overtime = (hours-35)*(1.5*hourly_rate); //for Task#2
	gross_wage = (35*hourly_rate) + overtime;
}
else
{
	gross_wage = hours*hourly_rate;
}

//Calculate the deductions

//calculate tax
tax = gross_wage * 0.20;

//apply the tax credit  //for Task#2
tax = tax - credit;

//ensure tax is a postive number  //for Task#2
if(tax < 0)
{
	//otherwise set it to zero
	tax = 0;
}

prsi = gross_wage * 0.025;
union_dues = 3.50;

//calculate net_pay
net_pay = gross_wage - tax - prsi - union_dues;

//Set the number of fraction digits for output to two
cout<<endl;
cout << fixed << setprecision(2) << endl;

//Print out the details

cout << left << setw(5) << "Name" << right << setw(20) << name << endl;
cout << left << setw(15) << "Hours" 		<< right << setw(10) << hours << endl;
cout << left << setw(15) << "Hourly rate" 	<< right << setw(10) << hourly_rate << endl;
cout << left << setw(15) << "Gross wage" 	<< right << setw(10) << gross_wage << endl;
cout << left << setw(15) << "Tax" 			<< right << setw(10) << tax << endl;
cout << left << setw(15) << "PRSI" 			<< right << setw(10) << prsi << endl;
cout << left << setw(15) << "Union Dues" 	<< right << setw(10) << union_dues << endl;
cout << "------------------------------------" << endl;
cout << left << setw(15) << "Net pay" 		<< right << setw(10) << net_pay << endl;

return 0;
}
