#include <iostream>
/*
	This project takes a user's given amount of money and returns
	that amount into the most efficient distribution of change.
*/

class BreakTheMoneyDown
{
private:

	// Not needed, and gets messy

protected:

	// Not needed this exercise
	

public:
	// Using built in constructor / destructor for the purpose of this project
	// Could have used inline, but not the purpose of this exercise, and my fingers get less tired.
	// Just practicing extracting the change and casting without arithmetic overloading.
	// I have seen other coding examples where they have the user enter the dollar amount then enter the change without the decimal. I could not except that.
	// My goal was to take an Integer or floating point number and perform the breakdown, without separating dollars from the cents.
	// There are many other ways to tackle this problem, but this was good practice to refresh my c++.
	

	const double numHundreds(double, int) const;
	const double numFifties(double, int, int) const;
	const double numTwenties(double, int, int, int) const;
	const double numTens(double, int, int, int, int) const;
	const double numFives(double, int, int, int, int,int) const;
	const double numOnes(double, int, int, int, int, int, int) const;

	const double extractFraction(double, double ) const;
	const double numQuarters(double, double) const;
	const double subtQuarters(double, double, double);
	const double numDimes(double, double, double) const;
	const double subtDimes(double, double, double) const;
	const double numNickels(double, double, double) const;
	const double subtNickels(double, double, double) const;
	const double numPennies(double, double, double) const;
};

// Default arguments and no private's keep main function cleaner and less confusing

const double BreakTheMoneyDown::numHundreds(double amount, int hundred = 100) const
{	
	return (int)amount / hundred;
}

const double BreakTheMoneyDown::numFifties(double amount, int hundred = 100, int fifty = 50) const
{	
	return (int)amount % hundred / fifty;
}

const double BreakTheMoneyDown::numTwenties(double amount, int hundred = 100, int fifty = 50, int twenty = 20) const
{
	return (int)amount % hundred % fifty / twenty;
}

const double BreakTheMoneyDown::numTens(double amount, int hundred = 100, int fifty = 50, int twenty = 20, int ten = 10) const
{	
	return (int)amount % hundred % fifty % twenty / ten;
}

const double BreakTheMoneyDown::numFives(double amount, int hundred = 100, int fifty = 50, int twenty = 20, int ten = 10, int five = 5) const
{	
	return (int)amount % hundred % fifty % twenty % ten / five;
}

const double BreakTheMoneyDown::numOnes(double amount, int hundred = 100, int fifty = 50, int twenty = 20, int ten = 10, int five = 5, int one = 1) const
{	
	return (int)amount % hundred % fifty % twenty % ten % five / one;
}

const double BreakTheMoneyDown::extractFraction(double amount, double intAmount) const
{
	return amount - (int)amount;	
}

const double BreakTheMoneyDown::numQuarters(double extractFraction, double oneFourth = 0.25) const
{
	
	return (int)(extractFraction / oneFourth);
}

const double BreakTheMoneyDown::subtQuarters(double extractFraction, double numQuarters, double oneFourth = 0.25)
{
	return (extractFraction - (numQuarters * oneFourth));
}

const double BreakTheMoneyDown::numDimes(double subtQuarters, double tenCents = 0.1, double offset = 0.00001) const
{
	return (int)(subtQuarters / tenCents + offset);
}

const double BreakTheMoneyDown::subtDimes(double subtQuarters, double dimes, double tenCents = 0.1) const
{
	return (subtQuarters - (dimes * tenCents));
}

const double BreakTheMoneyDown::numNickels(double subtDimes, double fiveCents = 0.05, double offset = 0.00001) const
{
	return (int)(subtDimes / fiveCents + offset);
}

const double BreakTheMoneyDown::subtNickels(double subtDimes, double numNickels, double fiveCents = 0.05) const
{
	return (subtDimes - (numNickels * fiveCents));
}

const double BreakTheMoneyDown::numPennies(double subtNickels, double oneCent = 0.01, double offset = 0.00001) const
{
	return (int)(subtNickels / oneCent + offset);
}

int main()
{
	// Object of class
	BreakTheMoneyDown b;

	double amount{};

	// Check that amount is greater than zero
	do {
		// Get user input
		std::cout << "Enter an amount greater than zero: ";		
		std::cin >> amount;			
	} while (amount <= 0);
	
	/*********** Display dollar/s distribution ***************/

	std::cout << b.numHundreds(amount) << ":   Hundred\n";	
	std::cout << b.numFifties(amount) << ":   Fifty\n";
	std::cout << b.numTwenties(amount) << ":   Twenties\n";
	std::cout << b.numTens(amount) << ":   Ten\n";
	std::cout << b.numFives(amount) << ":   Five\n";
	std::cout << b.numOnes(amount) << ":   dollars\n";

	/************** Fractional change functions and variable assignment **********/

	double extractFraction = b.extractFraction(amount, (int)amount);
	double numQuarters = b.numQuarters(extractFraction);	
	double subtQuarters = b.subtQuarters(extractFraction, numQuarters);
	double numDimes = b.numDimes(subtQuarters);	
	double subtDimes = b.subtDimes(subtQuarters, numDimes);
	double numNickels = b.numNickels(subtDimes);	
	double subtNickels = b.subtNickels(subtDimes, numNickels);
	double numPennies = b.numPennies(subtNickels);	
	
	/************ Display change ***********/

	std::cout << numQuarters << ":   quarters\n";
	std::cout << numDimes << ":   dimes\n";
	std::cout << numNickels << ":   nickels\n";
	std::cout << numPennies << ":   pennies\n";


	std::cout << "\n\n";
	system("pause");
	return 0;
}