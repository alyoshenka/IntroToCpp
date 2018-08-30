#include <iostream>
#include "piggyBank.h"

// returns total value of all bills
float calcPiggybankNotes(piggyBank p) {
	float total = 0.0f;
	total += p.oneDollarBills;
	total += p.twoDollarBills * 2;
	total += p.fiveDollarBills * 5;
	return total;
}

// returns total value of all coins
float calcPiggybankCoins(piggyBank p) {
	float total = 0.0f;
	total += p.quarters * 0.25;
	total += p.dimes * 0.1;
	total += p.nickels * 0.05;
	total += p.pennies * 0.01;
	return total;
}

// returns total value of piggybank
float calcPiggybankTotal(piggyBank p) {
	float val = calcPiggybankNotes(p) + calcPiggybankCoins(p);
	return val;
}