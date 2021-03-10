#include "seeds.h"

/*cria arquivo com N*S seeds*/
void createSeeds(char fname[], int NSequences, int seqPerN){
	srand(time(NULL));
	FILE *arq = fopen(fname, "wb");
	int r;
	for(int i=0;i<NSequences;i++){
		for(int k=0;k<seqPerN;k++){
			r = rand();
			fwrite(&r, sizeof(int), 1, arq);
		}
	}
	fclose(arq);
}

/*
dado um n entre 0 e N-1 e um s entre 0 e s-1,
retorna uma seed
*/
int getSeed(char fname[], int n, int s){
	FILE *arq = fopen(fname, "rb");
	int r;
	fseek(arq, (n*N + s)*sizeof(int), SEEK_SET);
	fread(&r, sizeof(int), 1, arq);
	fclose(arq);
	return r;
}

/*
cria uma sequencia em *v 
a partir da seed correspondente a seed(n, s)
*/
void generateSequence(char fname[] ,int *v, int n, int s){
	int seed = getSeed(fname, n, s);
	int size = SIZE(n);
	srand(seed);
	for(int i=0; i < size; i++){
		v[i] = rand()%L;
	}
}
