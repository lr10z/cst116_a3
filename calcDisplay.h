//
// CST 116 - Assignment 3
//
// File:  calcDisplay.h
//
// This file contains prototypes for functions that
// calculate loan monthly payments and display a row
// of an amortization table.
//


//
// Returns a monthly payment value calculated from
// values for principal, interest rate (ie. 5.8%),
// and loan duration (in years).
//
double  calcMonthlyPayment( double  principal,
                            double  annualRate,
                            int     numYears );


//
// Displays a row of the amortization schedule given the month
// number, principal amount for the month, interest due for the
// months, and the balance remaining.  The intent is for this
// function to be called for each loan payment made.
//
// The month number is a sequential number that tracks the number
// of payments:
//    1 - designates the first monthly payment
//    2 - designates the second monthly payment
//    3 - designates the third monthly payment
//    ...
//
// If the month number is one, the header for the table is
// displayed.
//
void  displayMonth( unsigned  monthNum,
                    double    amtPrincipal,
                    double    amtInterest,
                    double    balance );
