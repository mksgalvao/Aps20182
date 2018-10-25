#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void prencherVetor(int *vetor, int tam)
{

    int i;

    for(i=0; i < tam; i++)
    {
        vetor[i] = rand()%100;
    }
}

void mostrarVetor(int *vetor, int tam)
{

    int i;

    for(i = 0; i < tam; i++)
    {
        printf("%i\t", vetor[i]);
    }
    printf("\n");

}

int trocas(int *arr, int i, int j)
{
    int troca = 0;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    troca++;

    return troca;
}


int bolha(int *vetor, int tam)
{
    int troca = 0;
    // Base case

    if (tam == 1)
        return 0;
    for (int i=0; i<tam-1; i++)
        if (vetor[i] > vetor[i+1])
            troca +=  trocas(vetor, i, i+1);
    bolha(vetor, tam-1);

    return troca;

}


// Recursive function to perform selection sort on subarray arr[i..n-1]
int selecao(int *vetor, int i, int tam, int troca)
{
	int i;int j

   for (int i = 0; i < tam - 1; i++)
    {
        // find the minimum element in the unsorted subarray[i..n-1]
        // and swap it with arr[i]
        int min = i;

    for (int j = i + 1; j < tam; j++)
    {
        // if arr[j] element is less, then it is the new minimum
        if (vetor[j] < vetor[min])
            min = j;    // update index of min element
    }

    // swap the minimum element in subarray[i..n-1] with arr[i]
      troca += trocas(vetor, min, i);
}
    if (i + 1 < tam)
    {
        troca += selecao(vetor, i + 1, tam, troca);
    }

    return troca;
}



int quick(int *vetor, int inicio, int fim, int troca){

	int i, j, pivo, aux;

	i = inicio;
	j = fim;
	troca = 0;

	pivo = vetor[(inicio+fim)/2];
	do{
		while(vetor[i]<pivo)
		i++; // enquanto o valor do vetor na posição i for menor que o pivô  o -i avança para direita
		while(vetor[j]>pivo)
		j--;// enquanto o valor do vetor na posição j for maior que o pivô  o -i retrocede para esquerda
		if(i<=j) // se a posição de i for menor ou igual a j (I a esquerda e j a direita ou encontro de i e j)
		{
			aux = vetor[i];
			vetor[i]=vetor[j];
			vetor[j] = aux; // troca

			i++;
			j--;
			troca ++;
	}
	}while (i<=j); // laço roda até o encontro dos indices i e j

	if(inicio <j)
	troca += quick(vetor, inicio,j,troca); // se o incio for menor que o j chamar a função quick para a sub lista a esquerda

	if(i<fim)
	troca += quick(vetor, i, fim, troca); // se o i for menor que o fim chamar a função quik para a sublista a direita

	return troca;
	}

int main()
{

    int* vetor;
    int inicio, fim, tempo, tempo1, troca;
    troca =0;
    int opc, tam;


    printf("#######\t~\tMENU\t~\t####### \n");
    printf("Vamos testar qual metodo de ordenacao eh mais rapido!\n");
    printf("Para comecar entre com o tamanho do vetor que deseja ordenar:\n");
    scanf("%d", &tam);
    vetor = (int *)malloc(tam * sizeof(int));
    printf("\n Este eh o vetor sem ordenar\n");
    prencherVetor(vetor, tam);
    mostrarVetor(vetor, tam);

    printf("\tdigite 1 para Bublle sort\n");
    printf("\tdigite 2 para Selection sort\n");
    printf("\tdigite 3 para  Quick sort\n");
    scanf("%d", &opc);

    // opc = menu(vetor);

    switch ( opc )
    {
    case 1 :
        inicio = GetTickCount();
        troca = bolha(vetor, tam);
        fim = GetTickCount();
        tempo = fim - inicio;
        tempo1 = tempo/1000;
        printf(" \n Vetor ordenado pelo metodo bublle sort eh: \n");
        mostrarVetor(vetor, tam);
        printf("\n Tempo de ordenacao: %d milisegundos \n", tempo);
        printf("\n Tempo de ordenacao: %d segundos \n", tempo1);
        printf("\n Numero de trocas sao: %d \n", troca);
        system("pause");
        break;
    case 2 :
        inicio = 0;
        troca = 0;
        inicio = GetTickCount();
        troca = selecao(vetor,0, tam, troca);
        fim = GetTickCount();
        tempo = fim - inicio;
        tempo1 = tempo/1000;
        printf(" \n Vetor ordenado pelo metodo selection sort eh: \n");
        mostrarVetor(vetor, tam);
        printf("\n Tempo de ordenacao: %d milisegundos \n", tempo);
        printf("\n Tempo de ordenacao: %d segundos \n", tempo1);
        printf("\n Numero de trocas sao: %d \n", troca);
        system("pause");
        break;
    case 3 :
        inicio = 0;

        inicio = GetTickCount();
        troca = quick(vetor, 0, tam-1, troca);
        fim = GetTickCount();
        tempo = fim - inicio;
        tempo1 = tempo/1000;
        printf(" \n Vetor ordenado pelo metodo quick sort é: \n");
        mostrarVetor(vetor, tam);
        printf("\n Tempo de ordenacao: %d milisegundos \n", tempo);
        printf("\n Tempo de ordenacao: %d segundos \n", tempo1);
        printf("\n Numero de trocas sao: %d \n", troca);
        system("pause");
        break;
    default :
        printf("Valor invalido \n");
    }

    return 0;
}

