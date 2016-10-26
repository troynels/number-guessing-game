#include <iostream>
#include <string>
#include <random>
using namespace std;

/*
Asks the user for a minimum and a maximum number, then asks for guesses for a random
number between the minimum and maximum. Tells the user if their guess was too high or too low
*/

// Asks the user for input, then returns the input
int getUserInput() {
	int input;
	cin >> input;
	return input;
}

// Generates a random int between a and b
int randomNumber(int a, int b) {
	mt19937 rng;
	rng.seed(random_device()());
	uniform_int_distribution<mt19937::result_type> dist6(a, b);
	return dist6(rng);
}

// A template for informing the user of the accuracy of their guess
void prgmFeedback(string a, int g) {
	cout << "Your guess of " << g << " was " << a << "\n";
}

int main() {
	cout << "Hello and welcome to a number guessing game!\n";
	cout << "In this game, you try to guess a random number, and I will tell you if you guessed too high or too low.\n";
invalidRange:
	cout << "\nPlease enter the smallest that the random number can be: ";
	int minNum = getUserInput();						// If a needlessly large negative number (e.g. -999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999) 
														// is entered, the program breaks and infinitely loops.
	if (minNum < 0) {
		cout << "ERROR: Your input was too small. \n";
		goto invalidRange;
	}
	cout << "Please enter the largest that the random number can be: ";
	int maxNum = getUserInput();
	if (minNum > maxNum) {
		cout << "\nERROR: One or more of your inputs were invalid, please try again.\n";
		goto invalidRange;
	}
	int randNum = randomNumber(minNum, maxNum);
	int guess;
	do {
		cout << "Enter your guess between " << minNum << " and " << maxNum << ": ";
		guess = getUserInput();
		if (guess < minNum || guess > maxNum) { cout << "ERROR: Your guess of " << guess << " was out of bounds.\n"; }
		else if (guess > randNum) { prgmFeedback("too high.", guess); }
		else if (guess < randNum) { prgmFeedback("too low.", guess); }
	} while (guess != randNum);
	prgmFeedback("correct!", guess);
	cout << "You win!\n";
	cout << "\nType 'exit' to end the program...\n\n";
	string endProgram = "exit";
	string uInput;
	do {
		getline(cin, uInput);
	} while (uInput != endProgram);
}