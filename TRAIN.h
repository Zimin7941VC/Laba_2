#ifndef LAB2_1_TRAIN_H
#define LAB2_1_TRAIN_H

#include <iostream>
#include <string>

class TRAIN {
public:
	TRAIN();
	TRAIN(std::string _destination, int _trainNumber, std::string _Timeofdispatch);
	TRAIN(const TRAIN& train);
	~TRAIN();
	std::string getDestination();
	void setDestination(std::string value);
	int getTrainNumber();
	void setTrainNumber(int value);
	std::string getTimeofdispatch();
	void setTimeofdispatch(std::string value);
	friend std::ostream& operator<<(std::ostream& ostream, const TRAIN& train);
	friend std::istream& operator>>(std::istream& istream, TRAIN& train);
private:
	std::string destination;
	int trainNumber;
	std::string timeofdispatch;
};


#endif //LAB2_1_TRAIN_H