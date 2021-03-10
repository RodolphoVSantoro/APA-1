#include "sort.h"

/*Print array*/
void printArray(int arr[], int tamanhoArr) { 
    int i; 
    for (i=0; i < tamanhoArr; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

/*Swap*/
void swap(int *xp, int *yp){ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

/*Bubble Sort*/
void metodoBolha(int arr[], int tamanhoArr){
    int chave = 1;
    while( chave == 1){
        chave = 0;
        int i;
        for(i = 0; i < tamanhoArr-1; i++){
            if(arr[i+1] < arr[i]){
                swap(&arr[i], &arr[i+1]);
                chave = 1;
            }
        }
    }
}

/*Heap Sort*/
void heapify(int arr[], int tamanhoArr, int i){
    int maiorAtual = i;
    int indiceEsquerda = 2*i+1;
    int indiceDireita = 2*i+2;

    /*se a folha da esquerda for maior que a raiz, troca*/
    if(indiceEsquerda < tamanhoArr && arr[indiceEsquerda] > arr[maiorAtual]) maiorAtual = indiceEsquerda;

    /*se a folha da direira for maior que a raiz, troca*/
    if(indiceDireita < tamanhoArr && arr[indiceDireita] > arr[maiorAtual]) maiorAtual = indiceDireita;

    /*se a raiz troca com um dos seus filhos*/
    if(maiorAtual != i){
        swap(&arr[i], &arr[maiorAtual]);
        /* aplicando o heapify na subarvore*/
        heapify(arr, tamanhoArr, maiorAtual);
    }
}

void heapsort(int arr[], int tamanhoArr){
    /*construindo a heap - usando maxheap*/
    for(int i = tamanhoArr/2-1; i>=0; i--) heapify(arr, tamanhoArr, i);

    /*dando swap na raiz e na ultima folha e rearrumando a arvore*/
    for(int i= tamanhoArr-1; i>0; i--){
        /*trocando a raiz pela folha*/
        swap(&arr[0], &arr[i]);

        /*arrumando a arvore*/
        heapify(arr, i, 0);

    }
}

/*Método das Caixas*/
void metodoCaixas(int arr[], int tamanhoArr){
    int min = arr[0];
    int max = arr[0];

    /*procurando min e max*/
    for(int i=1; i<tamanhoArr; i++){
        if(arr[i] < min) min = arr[i];
        if(arr[i] > max) max = arr[i];  
    }
    int tamanho = max-min;

    /*iniciando as caixas vazias*/
    int caixas[tamanho];
    for(int i=0; i<tamanho; i++) caixas[i] = 0;

    /*colocando os numeros em suas caixas*/
    for(int i=0; i<tamanhoArr; i++) caixas[arr[i]-min] = caixas[arr[i]-min]+1;

    /*colocando as caixas em ordem*/
    int posicaoCaixa = 0;
    for(int i=0; i< tamanho; i++){
        while(caixas[i] != 0){
            caixas[i] = caixas[i]-1;
            arr[posicaoCaixa] = i+min;
            posicaoCaixa = posicaoCaixa+1;
        }
    }

}
