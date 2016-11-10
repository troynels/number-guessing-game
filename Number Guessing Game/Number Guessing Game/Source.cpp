#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
#include <random>
#include <cstdio>
using namespace std;

/*
Asks the user for a minimum and a maximum number, then asks for guesses for a random
number between the minimum and maximum. Tells the user if their guess was too high or too low
*/

// Asks the user for input, then returns the input
int getUserInput(int step) {
	string input = "";
	int num = 0;
	while (true) {
		if (step == 1) {
			cout << "\nPlease enter the smallest that the random number can be: ";
		}
		else if (step == 2) {
			cout << "Please enter the largest that the random number can be: ";
		}
		else if (step == 3) {
			cout << "\nEnter your guess between the minimum number and the maximum number: ";
		}
		getline(cin, input);
		string processInput = input;
		if (processInput[0] == '-' || isdigit(processInput[0])) {
			int i = 0;
			for (char c : processInput) {
				if (isdigit(c)) {

				}
				else {
					if (i == 0) { continue; }
					input = "";
				}
				i += 1;
			}
		}
		// This code converts from string to number safely.
		stringstream myStream(input);			
		if (myStream >> num) {
			break;
		}
		cout << endl << "ERROR: Your input was invalid. Please try again." << endl;
	}
	return num;
}

// Generates a random int between a and b
int randomNumber(int a, int b) {
	auto c = b - a;
	mt19937 rng;
	rng.seed(random_device()());
	uniform_int_distribution<mt19937::result_type> dist6(0, c);
	int rand = dist6(rng);
	rand += a;
	return rand;
}

// A template for informing the user of the accuracy of their guess. Changes the message depending on the input
void prgmFeedback(string a, int g) {
	cout << endl << "Your guess of " << g << " was " << a << "\n";
}

// Main function, displays introduction message and initiates other functions
int main() {
	cout << "Hello and welcome to a number guessing game!\n";
	cout << "In this game, you try to guess a random number, and I will tell you if you guessed too high or too low.\n";
retryInput:
	int minNum = getUserInput(1);
	int maxNum = getUserInput(2);
	if (minNum > maxNum || maxNum == NULL) {
		cout << endl << "ERROR: Your input was invalid. Please try again." << endl;
		goto retryInput;
	}
	int randNum = randomNumber(minNum, maxNum);
	int guess;
	do {
		guess = getUserInput(3);
		if (guess < minNum || guess > maxNum) { cout << endl << "ERROR: Your guess of " << guess << " was out of bounds." << endl; }
		else if (guess > randNum) { prgmFeedback("too high.", guess); }
		else if (guess < randNum) { prgmFeedback("too low.", guess); }
	} while (guess != randNum);
	prgmFeedback("correct!", guess);
	cout << "\nYou win!\n" << endl;
	cout << "Press enter to continue...\n";
	cin.ignore();
	cin.get();
}