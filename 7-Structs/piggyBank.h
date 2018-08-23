#pragma once

struct piggyBank {

	int oneDollarBills;
	int twoDollarBills;
	int fiveDollarBills;

	int quarters;
	int dimes;
	int nickels;
	int pennies;

};

// returns total value of all bills
float calcPiggybankNotes(piggyBank piggy);

// returns total value of all coins
float calcPiggybankCoins(piggyBank piggy);

// returns total value of piggybank
float calcPiggybankTotal(piggyBank piggy);
