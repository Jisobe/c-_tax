#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Calculate AGI and repair any negative values
int CalcAGI(int wages, int interest, int unemployment) {

   return fabs(wages) + fabs(interest) + fabs(unemployment);

}

// Calculate deduction depending on single, dependent or married
int GetDeduction(int status) {
   
   if (status == 1){
      return 12000;
   }else if (status == 2){
      return 24000;
   }

   return 6000;
}

// Calculate taxable but not allow negative results
int CalcTaxable(int agi, int deduction) {
   
   return agi - deduction >= 0 ? agi - deduction : 0;
}

// Calculate tax for single or dependent
int CalcTax(int status, int taxable) {

   double due;
   
   if (status == 2){
      if (taxable < 20001){
         due = taxable * 0.10;
      }
      else if (taxable < 80001){
         due = 2000 + ((taxable - 20000) * 0.12);
      }
      else{
         due = 9200 + ((taxable - 80000) * 0.22);
      }
   }
   else{
      if (taxable < 10001){
         due = taxable * 0.10;
      }
      else if (taxable < 40001){
         due = 1000 + ((taxable - 10000) * 0.12);
      }
      else if (taxable < 85000){
         due = 4600 + ((taxable - 40000) * 0.22);
      }
      else{
         due = 14500 + ((taxable - 85000) * 0.24);
      }
   }

   return int(round(due));
}

// Calculate tax due and check for negative withheld
int CalcTaxDue(int tax, int withheld) {
   
   withheld = withheld < 0 ? 0 : withheld;

   return tax - withheld;
}

int main() {
   int wages, interest, unemployment,status, withheld;
   int tax, agi, due, deduction, taxable;

   cout << "Please enter your wage income: ";
   cin >> wages;
   cout << "Please enter your interest income: ";
   cin >> interest;
   cout << "Please enter your unemployment compensation income: ";
   cin >> unemployment;
   cout << "Please enter your filing status (0: Dependent 1: Single 2: Married): ";
   cin >> status;
   cout << "Please enter your total federal tax withholding: ";
   cin >> withheld;


   // Step #2: Calculate AGI
   agi = CalcAGI(wages, interest, unemployment);
   deduction = GetDeduction(status);
   taxable = CalcTaxable(agi, deduction);
   tax = CalcTax(status, taxable);
   due = CalcTaxDue(tax, withheld);
   cout << "AGI: $" << agi << endl;
   cout << "Deduction: $" << deduction << endl;
   cout << "Taxable income: $" << taxable << endl;
   cout << "Federal tax: $" << tax << endl;
   cout << "Tax due: $" << due << endl;
   
   return 0;
}