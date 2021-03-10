#include <stdlib.h>
#include <time.h>
#include "seeds.h"

int main(){
	srand(time(NULL));
	createSeeds("seeds.txt", N, S);
	return 0;
}
