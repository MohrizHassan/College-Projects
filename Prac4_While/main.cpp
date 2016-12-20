//Program to determine how many months it takes to pay off a loan.//
#include <iostream>
#include <iomanip> //for I/O manipulation ops fixed, setprecision and setw
using namespace std;

int main() {

   double annual_rate = 12, loan_amount = 1500, monthly_payment = 50;
   double monthly_rate, balance, interest, total_interest;
   int num_months;

   //If you prefer to ask the user to supply loan terms -
   //cout << "How much are you borrowing in euro? ";
   //cin >> loan_amount;
   //cout << "\nWhat is the annual percentage interest rate (e.g. 12)? ";
   //cin >> annual_rate;
   //cout << "\nHow much will you pay each month? ";
   //cin >> monthly_payment;

   monthly_rate = (annual_rate/12.0)/100;//to give a monthly multiplier
   num_months = 0;
   balance = loan_amount;
   total_interest = 0;

   cout << "Month Interest  Capital  Balance\n";
   cout << fixed << setprecision (2);

   while (balance > 0)
     {
       num_months = num_months + 1;
       //compute interest, reduction in balance for this month
       interest = balance * monthly_rate;
       total_interest = total_interest + interest;
       balance = balance + interest - monthly_payment;//new amount of debt
       //Output details for checking purposes
       cout << setw(4) << num_months << setw(10) <<  interest;
       cout << setw(9) << monthly_payment-interest << setw(9) << balance << endl;
     }

   cout << "\n\nFor a loan of " << loan_amount << " euro, at ";
   cout << annual_rate << "% per annum, \nby paying " << monthly_payment;
   cout << " euro per month, \nthe loan will be paid in full after ";
   cout << num_months << " months.\n";
   cout << "The total cost of the credit will be " << total_interest << " euro.\n";

   //This next bit not required for the Practical:
   //The final payment may need to be less than the usual monthly payment.
   //The balance now is 0 or negative by the amount of overpayment, so ...
   double final_payment = monthly_payment + balance;
   cout << "The final monthly payment should be " << final_payment;
   cout << endl << endl;

   return 0;
   }
