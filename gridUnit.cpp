#define WORLD_SIZE 32

class microbe;

class gridUnit{
public:
	double foodA;	// ENERGY
	double foodB;	// PROTEINS
	double conditions;
	
	// This can be fun
	bool isPoison = false;
	bool causeStirility = false;
	bool causeConstriction = false;
	bool hasMeteor = false;
	
	microbe* microbePtr;
	microbe* lastMicrobePtr;
	
	gridUnit(){
		foodA = 1000000;
		foodB = 1000000;
		conditions = 29;
		microbePtr = NULL;
		lastMicrobePtr = NULL;
		
		if(bellRandom(0) < 0.01)
			isPoison = true;
		if(bellRandom(0) < 0.1)
			causeConstriction = true;
		if(bellRandom(0) < 0.1)
			causeStirility = true;
	}
	
	gridUnit(double qtyA, double qtyB = 100){
		gridUnit::foodA = qtyA;
		gridUnit::foodB = qtyB;
		microbePtr = NULL;
		lastMicrobePtr = NULL;
	}
};

gridUnit world[WORLD_SIZE][WORLD_SIZE];

void initGridSystem(){
	for(int i = 0; i < WORLD_SIZE; i++)
		for(int j = 0; j < WORLD_SIZE; j++){
			if(i < 20)
				world[i][j].conditions = 65;
			if(i >= 20){
				world[i][j].foodB = 100000;
				world[i][j].foodA = 100000;
			}
		}
	return;
}
