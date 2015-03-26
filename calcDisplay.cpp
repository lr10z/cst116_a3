//
// CST 116 - Assignment 3
//
// File:  calcDisplay.cpp
//
// This file contains functions that calculate
// loan monthly payments and display a row of an
// amortization table.
//

#include  <cmath>
#include  <iostream>
#include  <iomanip>
#include  "calcDisplay.h"

using namespace  std;


//
// Constants
//
#define  MONTHS_PER_YEAR  12


//
// Returns a monthly payment value calculated from
// values for principal, interest rate (ie. 5.8%),
// and loan duration (in years).
//
double  calcMonthlyPayment( double  principal,
                            double  annualRate,
                            int     numYears )
{
  double  monthlyRate  =  annualRate / (MONTHS_PER_YEAR * 100);
  int     numMonths    =  numYears * MONTHS_PER_YEAR;

  return  (principal * monthlyRate) / (1 - pow(1 + monthlyRate, -numMonths) );
}


//
// Displays a row of the amortization schedule given the month
// number, principal amount for the month, interest due for the
// months, and the balance remaining.
//
// If the month number is one, the header for the table is
// displayed.
//
void  displayMonth( unsigned  monthNum,
                    double    amtPrincipal,
                    double    amtInterest,
                    double    balance )
{
  char  sep7[]   =  "-------";
  char  sep11[]  =  "-----------";

  if  ( monthNum == 1 )
  {
    cout  <<  endl  <<  endl
          <<  setw(7)   <<  "Year"
          <<  setw(7)   <<  "Month"
          <<  setw(11)  <<  "Principal"
          <<  setw(11)  <<  "Interest"
          <<  setw(11)  <<  "Balance"  <<  endl
          <<  setw(7)   <<  sep7
          <<  setw(7)   <<  sep7
          <<  setw(11)  <<  sep11
          <<  setw(11)  <<  sep11
          <<  setw(11)  <<  sep11  <<  endl;
  }

  cout  <<  setw(7)   <<  1 + (monthNum-1) / 12
        <<  setw(7)   <<  1 + (monthNum-1) % 12
        <<  setw(11)  <<  amtPrincipal
        <<  setw(11)  <<  amtInterest
        <<  setw(11)  <<  balance  <<  endl;

  ++monthNum;
}
