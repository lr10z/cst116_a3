//
//  Assignment #3 - Leander Rodriguez
//
//  CST 116 - C++ Programming I
//
//  Due Date:  Sunday, November 4th by 11:59pm
//


#include <iostream>
#include <iomanip>
#include "calcDisplay.h"

using namespace std;

#define CHOICE_PRINCIPLE		1
#define CHOICE_INTEREST_RATE	2
#define CHOICE_NUM_YEARS		3
#define CHOICE_AMORTIZATION		4
#define CHOICE_EXIT				5



//
// The user is shown a MENU and is prompted
// to select which loan detail he would like 
// to input first
//
int displayMenu(	double principle,
					double interest,
					double monthly,
					int years	)
{
	int choice;

	cout  <<  endl  <<  endl
		  <<  "Loan Calculator"  <<  endl
		  <<  "---------------"  <<  endl  <<  endl
		  <<  "\tMonthly payment\t"  <<  "  :  $"  <<  monthly
		  <<  endl  <<  endl
		  <<  "  1. Set principal\t" <<  "  :  $"  <<  principle  
		  <<  endl
		  <<  "  2. Set annual interest  :  "  <<  interest  <<  "%"  
		  <<  endl
		  <<  "  3. Set number of years  :  "  <<  years  
		  <<  endl
		  <<  "  4. Amortization schedule"
		  <<  endl
		  <<  "  5. Exit"  <<  endl
		  <<  endl
		  <<  "Enter Choice : ";  
	cin  >>  choice;

	return choice;

}


//
// The amortization table is displayed to provide user
// with a detailed view of the loan and interest payments 
// over the life of the loan
//
void amortizationSchedule(	double principle, 
							double interest,
							double monthlyAmount,
							int years	)
{

	double	interestASpercentage = interest / 100,
			interestFORmonth = interestASpercentage / 12,
			remainingBalance = principle,
			interestSum = principle;
	int		monthNum = 1,
			count = 0,
			totalMonths = years * 12;

	do
	{
		double	payTOinterest = remainingBalance * interestFORmonth,
				payTOprinciple = monthlyAmount - payTOinterest;
				remainingBalance = remainingBalance - payTOprinciple;
				interestSum = payTOinterest + interestSum;

		displayMonth( monthNum, payTOprinciple, payTOinterest, remainingBalance );
		++count;
		++monthNum;

	}	while ( count < totalMonths );

	//
	// The total amount paid is calculated to include
	// original principle plus the sum of all payments towards
	// interest
	//
	cout  <<  endl
		  <<  "Total paid:  $"
		  <<  interestSum
		  <<  endl;		
}


//
// Monthly payment is calculated
//
double monthlyPayment(	double principle,
						double interest, 
						int years	)
{
	double monthlyPayment = calcMonthlyPayment( principle, 
												interest, 
												years );
	
	return monthlyPayment;
}


//
// User sets length of loan in terms of years
//
int setNUMofyears()
{
	int numOFyears;

	cout  <<  endl  <<  "Enter number of years:  ";
	cin  >>  numOFyears;  

	return numOFyears;
}


//
// User sets the interest rate of the loan
//
double setINTERESTrate()
{
	double interestRate;

	cout  <<  endl  <<  "Enter annual interest rate:  ";
	cin  >>  interestRate;

	return interestRate;
}


//
// User sets the principle amount of the loan
//
double setPrinciple()
{
	double principle;

	cout  <<  endl  <<  "Enter principal: ";  
	cin  >>  principle;

	return principle;
}


//
// Main program
//
int main()
{

	cout  <<  fixed  <<  setprecision(2);

	double	balance = 0, 
			monthlyAmount = 0,
			principle = 0,
			interest = 0;
	int		years = 0;


	bool done = false;

	while ( ! done )
	{
		
		switch ( displayMenu ( principle, interest, monthlyAmount, years ) )
		{
			
			case CHOICE_PRINCIPLE		:	principle = setPrinciple();
											break;

			case CHOICE_INTEREST_RATE	:	interest = setINTERESTrate();
											break;

			case CHOICE_NUM_YEARS		:	years = setNUMofyears(); 
											monthlyAmount = monthlyPayment(	principle, 
																			interest, 
																			years	);
											break;

			case CHOICE_AMORTIZATION	:	amortizationSchedule(	principle,
																	interest,
																	monthlyAmount,
																	years	);
											break;

			case CHOICE_EXIT			:	done = true;
											break;

			default						:	cout  <<  "*** Invalid choice ***"; 
				
		}

	}

  return  0;
}