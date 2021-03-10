#include <stdio.h>
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
	int v[N*P];
	int n, s;
	double s_CPU_inicial, s_total_inicial, s_CPU_final, s_total_final;
	double tempoMedioBubble, tempoMedioHeap, tempoMedioCaixa;
	FILE *arqBubble = fopen("bubble.txt", "w");
	FILE *arqHeap = fopen("heap.txt", "w");
	FILE *arqCaixa = fopen("caixa.txt", "w");
	for(n=0;n<N;n++){
		tempoMedioBubble = 0;
		tempoMedioHeap = 0;
		tempoMedioCaixa = 0;
		for(s=0;s<S;s++){
			/*bubble com a sequencia seed(n, s)*/
			generateSequence("seeds.txt", v, n, s);
			Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);
		    metodoBolha(v, SIZE(n));
		    Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
			tempoMedioBubble+=s_CPU_final - s_CPU_inicial;

			/*heap com a sequencia seed(n, s)*/
			generateSequence("seeds.txt", v, n, s);
			Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);
		    heapsort(v, SIZE(n));
		    Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
			tempoMedioHeap+=s_CPU_final - s_CPU_inicial;

			/*Caixa com a sequencia seed(n, s)*/
			generateSequence("seeds.txt", v, n, s);
			Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);
		    metodoCaixas(v, SIZE(n));
		    Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
			tempoMedioCaixa+=s_CPU_final - s_CPU_inicial;
		}
        /*salva o tempo medio entre as "s" execuções*/
	tempoMedioBubble/=(double)S;
	fprintf(arqBubble, "%lf %lf\n", (double)(n+1.0)*P, tempoMedioBubble);
        tempoMedioHeap/=(double)S;
        fprintf(arqHeap, "%lf %lf\n", (double)(n+1.0)*P, tempoMedioHeap);
        tempoMedioCaixa/=(double)S;
        fprintf(arqCaixa, "%lf %lf\n", (double)(n+1.0)*P, tempoMedioCaixa);
	}
	fclose(arqBubble);
	fclose(arqHeap);
	fclose(arqCaixa);
	return 0;
}
