#include <stdio.h>
#include <stdlib.h>
#include "seeds.h"
#include "sort.h"
#include "tempocpu.h"


/*
N = quantas sequencias de tamanho diferente
n varia de 0 a N-1
P = quanto a sequencia aumenta a cada n
S quantas sequencias de mesmo tamanho pra cada tamanho
s varia de 0 a S-1
L = limite superior para rng
*/


int main(){	
	int *v = (int*)malloc(sizeof(int)*N*P);
	int *v2 = (int*)malloc(sizeof(int)*N*P);
	int n, s;
	double s_CPU_inicial, s_total_inicial, s_CPU_final, s_total_final;
	double tempoMedioBubble, tempoMedioHeap, tempoMedioCaixa;
	FILE *arqBubble = fopen("bubble.txt", "w");
	FILE *arqHeap = fopen("heap.txt", "w");
	FILE *arqCaixa = fopen("caixa.txt", "w");
	for(n=49;n<N;n++){
		tempoMedioBubble = 0;
		tempoMedioHeap = 0;
		tempoMedioCaixa = 0;
		for(s=0;s<S;s++){
			printf("(%d,%d)\n", n, s);
			/*bubble com a sequencia seed(n, s)*/
			generateSequence("seeds.txt", v, n, s);
			Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);
		    metodoBolha(v, SIZE(n));
		    Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
			tempoMedioBubble+=s_CPU_final - s_CPU_inicial;
			
			/*heap com a sequencia seed(n, s)*/
			Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);
			generateSequence("seeds.txt", v, n, s);
			for(int i=0;i<50;i++){
				for(int j=0;j<SIZE(n);j++){
					v2[j]=v[j];
				}
			    heapSort(v2, SIZE(n));
			}
		    Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
			tempoMedioHeap+=(s_CPU_final - s_CPU_inicial)/50.0;
			
			/*Caixa com a sequencia seed(n, s)*/
			generateSequence("seeds.txt", v, n, s);
			Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);
			for(int i=0;i<100;i++){
				for(int j=0;j<SIZE(n);j++){
					v2[j]=v[j];
				}
		    	metodoCaixas(v2, SIZE(n));
		    }
		    Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
			tempoMedioCaixa+=(s_CPU_final - s_CPU_inicial)/100.0;
		}
        /*salva o tempo medio entre as "s" execuções em microSegundos*/
		/*tempoMedioBubble*=1000 * 1000;
		tempoMedioBubble/=(double)S;
		fprintf(arqBubble, "%lf %lf\n", (double)(n+1.0)*P, tempoMedioBubble);
		tempoMedioHeap*=1000 * 1000;
        tempoMedioHeap/=(double)S;
        fprintf(arqHeap, "%lf %lf\n", (double)(n+1.0)*P, tempoMedioHeap);
        */
		tempoMedioCaixa*=1000 * 1000;
        tempoMedioCaixa/=(double)S;
        fprintf(arqCaixa, "%lf %lf\n", (double)(n+1.0)*P, tempoMedioCaixa);
	}
	free(v);
	free(v2);
	fclose(arqBubble);
	fclose(arqHeap);
	fclose(arqCaixa);
	return 0;
}
