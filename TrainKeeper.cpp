#include <algorithm>
#include "TrainKeeper.h"

TrainKeeper::TrainKeeper() {
	std::cout << "Object TrainKeeper. Call a simple constructor\n\n";
	this->trainKeeper = new TRAIN[10];
	this->arraySize = 10;
	this->tempKeep = 0;
}

TrainKeeper::~TrainKeeper() {
	std::cout << "Object TrainKeeper. Call destructor\n";
	delete[] this->trainKeeper;
}

int comparator(TRAIN a, TRAIN b) {
	return a.getTimeofdispatch() < b.getTimeofdispatch	();
}

void TrainKeeper::dataProcessing(int value) {
	switch (value) {
	case 1: {
		TRAIN train;
		std::cin.ignore(32767, '\n');
		std::cout << "Print next data separated by commas: destination, train number and Time of dispatch\n";

		std::cin >> train;
		addTrain(train);
		std::sort(trainKeeper, trainKeeper + tempKeep, comparator);
		break;
	}
	case 2: {
		if (!tempKeep) {
			std::cout << "You have no Timeofdispatch\n";
			return;
		}
		std::cin.ignore(32676, '\n');
		std::cout << "Your Destination:\n";
		std::string Timeofdispatch;
		for (int i = 0; i < tempKeep; i++) {
			if (Timeofdispatch.find(trainKeeper[i].getDestination()) == std::string::npos) {
				std::cout << "\t" << trainKeeper[i].getDestination() << "\n";
				Timeofdispatch.append(trainKeeper[i].getDestination());
			}
		}
		int number = 1;
		std::cout << "Enter an destination:\n";
		std::getline(std::cin, Timeofdispatch);
		for (int i = 0; i < tempKeep; i++) {
			if (trainKeeper[i].getDestination() == Timeofdispatch) {
				std::cout << "This Timeofdispatch \"" << trainKeeper[i].getDestination() << "\" serves:\n";
				std::cout << "\t" << number << ": Train number " << trainKeeper[i].getTrainNumber()
					<< ", Timeofdispatch " << trainKeeper[i].getTimeofdispatch() << "\n";
				number++;
			}
		}
		if (number == 1) {
			std::cout << "Train to \"" << Timeofdispatch << "\" not planned\n";
		}
		break;
	}
	default:
		throw std::invalid_argument("Wrong number. Number should be from 1 to 3");
	}
}

void TrainKeeper::addTrain(TRAIN train) {
	if (this->tempKeep == this->arraySize - 1) {
		this->trainKeeper[this->tempKeep] = train;
		TRAIN* newArray = new TRAIN[this->arraySize + 10];
		for (int i = 0; i < this->arraySize; i++)
			newArray[i] = this->trainKeeper[i];
		delete[] this->trainKeeper;
		this->trainKeeper = newArray;
		this->arraySize += 10;
		this->tempKeep++;
	}
	else {
		this->trainKeeper[this->tempKeep] = train;
		this->tempKeep++;
	}
}