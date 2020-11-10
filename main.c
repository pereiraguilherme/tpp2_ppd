#include <stdio.h>
#include <stdlib.h>

// #define BUBBLE 1
#define QUICK 1   
#define TRESHOLD 25         
#define ARRAY_SIZE 100      
/* recebe um ponteiro para um vetor que contem as mensagens recebidas dos filhos e            */ 
int *interleaving(int vetor[], int tam)
{
	int *vetor_auxiliar;
	int i1, i2, i_aux;

	vetor_auxiliar = (int *)malloc(sizeof(int) * tam);

	i1 = 0;
	i2 = tam / 2;

	for (i_aux = 0; i_aux < tam; i_aux++) {
		if (((vetor[i1] <= vetor[i2]) && (i1 < (tam / 2)))
		    || (i2 == tam))
			vetor_auxiliar[i_aux] = vetor[i1++];
		else
			vetor_auxiliar[i_aux] = vetor[i2++];
	}

	return vetor_auxiliar;
}

int cmpfunc (const void * a, const void * b) {
   return(*(int32_t*)a - *(int32_t*)b);
}

void bs(int n, int * vetor)
{
    int c=0, d, troca, trocou =1;

    while (c < (n-1) & trocou )
        {
        trocou = 0;
        for (d = 0 ; d < n - c - 1; d++)
            if (vetor[d] > vetor[d+1])
                {
                troca      = vetor[d];
                vetor[d]   = vetor[d+1];
                vetor[d+1] = troca;
                trocou = 1;
                }
        c++;
        }
}

int decide( int * array) {

    if( sizeof(array) <= TRESHOLD) {
        #ifdef BUBBLE
            bs(sizeof(array), array);
        #endif
        #ifdef QUICK
            qsort(array, sizeof(array), sizeof(int), cmpfunc);        
        #endif
        return array;
    } else {
        int arraySize = sizeof(array);
        printf("array size: %d \n", arraySize);
        int vector[(arraySize/2)];
        for(int i; i < arraySize/2; i++){    
            vector[i] = array[i];
            printf("vector: %d \n", vector[i]);
        }
        decide(vector);
    }
}

int main()
{
    int vetor[ARRAY_SIZE];
    int i;

    for (i=0 ; i<ARRAY_SIZE; i++)              /* init array with worst case for sorting */
        vetor[i] = ARRAY_SIZE-i;
   


    bs(ARRAY_SIZE, vetor);                     /* sort array */


    #ifdef DEBUG
    printf("\nVetor: ");
    for (i=0 ; i<ARRAY_SIZE; i++)                              /* print sorted array */
        printf("[%03d] ", vetor[i]);
    #endif

    return 0;
}