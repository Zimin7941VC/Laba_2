#include <iostream>

#include "TrainKeeper.h"

void printFirstInformation() {
	std::cout << "\nWant you want to do?\n";
	std::cout << "1. Add Train\n";
	std::cout << "2. Display Timeofdispatch and train numbers\n";
	std::cout << "3. Exit\n";
}



int main() {
	TrainKeeper trainKeeper;

	int choiser;
	std::cout << "Hello!\n";

	while (true) {
		printFirstInformation();
		std::cout << "Write a number: ";
		std::cin >> choiser;
		std::cout << "\n";
		if (choiser == 3) {
			std::cout << "Bye\n";
			break;
		}
		try {
			trainKeeper.dataProcessing(choiser);
		}
		catch (std::invalid_argument error) {
			std::cerr << error.what();
		}
	}

	return 0;
}