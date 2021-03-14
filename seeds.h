#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N (1250)
#define P (25)
#define S (10)
#define L (100000)
#define SIZE(n) ((n+1)*P)


/*
N = quantas sequencias de tamanho diferente
n varia de 0 a N-1
P = quanto a sequencia aumenta a cada n
S quantas sequencias de mesmo tamanho pra cada tamanho
s varia de 0 a S-1
L = limite superior para rng
*/

void createSeeds(char fname[], int NSequences, int seqPerN);

/*
dado um n entre 0 e N-1 e um s entre 0 e s-1,
retorna uma seed
*/
int getSeed(char fname[], int n, int s);

/*
cria uma sequencia em *v 
a partir da seed correspondente a seed(n, s)
*/
void generateSequence(char fname[] ,int *v, int n, int s);

/*cria sequencia com valores abaixo de l*/
void generateSequenceLim(char fname[] ,int *v, int n, int s, int l);