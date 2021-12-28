#include "TRAIN.h"

TRAIN::TRAIN() {
	this->trainNumber = 0;
	std::cout << "Object TRAIN. Call simple constructor\n";
}

TRAIN::TRAIN(std::string _destination, int _trainNumber, std::string _timeofdispatch) : destination(_destination),trainNumber(_trainNumber),timeofdispatch(_timeofdispatch) {
	std::cout << "Object TRAIN. Call constructor with parameters\n";
}

TRAIN::TRAIN(const TRAIN &train) : destination(train.destination),
trainNumber(train.trainNumber),
timeofdispatch(train.timeofdispatch) {
	std::cout << "Object TRAIN. Call copy constructor\n";
}

TRAIN::~TRAIN() {
	std::cout << "Object TRAIN. Call destructor\n";
}

std::string TRAIN::getDestination() {
	return this->destination;
}

void TRAIN::setDestination(std::string value) {
	this->destination = value;
}

int TRAIN::getTrainNumber() {
	return this->trainNumber;
}

void TRAIN::setTrainNumber(int value) {
	this->trainNumber = value;
}

std::string TRAIN::getTimeofdispatch() {
	return this->timeofdispatch;
}

void TRAIN::setTimeofdispatch(std::string value) {
	this->timeofdispatch = value;
}

std::ostream& operator<<(std::ostream& ostream, const TRAIN& aeroflot) {	ostream << "Destination: " << aeroflot.destination << "\Train number: " << aeroflot.trainNumber
		<< "\nTimeofdispatch: " << aeroflot.timeofdispatch << "\n";

	return ostream;
}

std::istream& operator>>(std::istream& istream, TRAIN& train) {
	std::string input;
	std::getline(istream, input);

	int wordCount = 0;
	std::string tempValue;

	for (char i : input) {
		if (i == ' ') {
			continue;
		}
		if (i == ',') {
			if (wordCount == 0) {
				train.destination = tempValue;
				wordCount++;
				tempValue.clear();
			}
			else if (wordCount == 1) {
				train.trainNumber = std::stoi(tempValue);
				wordCount++;
				tempValue.clear();
			}
		}
		else {
			tempValue.push_back(i);
		}
	}
	if (wordCount == 2)
		train.timeofdispatch = tempValue;
	else
		throw std::invalid_argument("Wrong train data. Data should have the following form: \"destination, train number, train type\"\n");

	return istream;
}