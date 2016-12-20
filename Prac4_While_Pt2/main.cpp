//Solution to Practical 4 Second and Third (Advanced) Task
//Handles multiple records of temperature values.
//If the program is Practical4b.cpp and the data is in a file called data.txt
//run the program as "./Practical4b < data.txt"

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main ()
{
   int m, count;
   double temp, min, max, total;
   double average;
   string station;
   //output table header
   cout << setw(25) << "Min" << setw(10) << "Max";
   cout << setw(10) << "Ave" << endl;

   cin >> station;//read the first station name
   while (station!="XXX")//process records
   {
       total = 0.0;
	   count = 0;

       cin >> temp;//read the first temperature

       min = temp; //give min a valid value, not 0
	   max = temp; //give max a valid value, not 0

       while (temp != -999)
       {
		//deal with the current value
		count = count + 1;
		total = total + temp;
		if (temp > max)
		{
			max = temp;
		}
		if (temp < min)
		{
			min = temp;
		}
		//read in value of next temperature
		cin >> temp;
       }
       average = total / count;

       //output values for current month
       cout << setw(15) << station;
       cout << fixed << setprecision(2);
       cout << setw(10) << min;
       cout << setw(10) << max;
       cout << setw(10) << average;
       cout << endl;

	//read in value of next station name
	cin >> station;
   }

   return 0;
}
