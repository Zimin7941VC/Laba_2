#ifndef LAB2_1_TRAINKEEPER_H
#define LAB2_1_TRAINKEEPER_H

#include "TRAIN.h"

class TrainKeeper {
public:
	TrainKeeper();
	~TrainKeeper();
	void addTrain(TRAIN train);
	void dataProcessing(int value);
private:
	TRAIN* trainKeeper;
	int tempKeep;
	int arraySize;
};


#endif //LAB2_1_TRAINKEEPER_H