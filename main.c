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

int swap(int arr[], int i, int j)
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
    int troca;
    // Base case
    if (tam == 1)

        return;

    for (int i=0; i<tam-1; i++)
        if (vetor[i] > vetor[i+1])
            troca =  swap(vetor, i, i+1);

    bolha(vetor, tam-1);

    return troca;

}


// Recursive function to perform selection sort on subarray arr[i..n-1]
int selecao(int arr[], int i, int n)
{
    // find the minimum element in the unsorted subarray[i..n-1]
    // and swap it with arr[i]
    int troca = 0;
    int min = i;
    for (int j = i + 1; j < n; j++)
    {
        // if arr[j] element is less, then it is the new minimum
        if (arr[j] < arr[min])
            min = j;    // update index of min element
    }

    // swap the minimum element in subarray[i..n-1] with arr[i]
    troca = swap(arr, min, i);

    if (i + 1 < n)
    {
        selecao(arr, i + 1, n);
    }
    return troca;
}



void quick(int *arr, int low, int high)
{
    int pivot, i, j, temp;
    if(low < high)
    {
        pivot = low; // select a pivot element
        i = low;
        j = high;
        while(i < j)
        {
            // increment i till you get a number greater than the pivot element
            while(arr[i] <= arr[pivot] && i <= high)
                i++;
            // decrement j till you get a number less than the pivot element
            while(arr[j] > arr[pivot] && j >= low)
                j--;
            // if i < j swap the elements in locations i and j
            if(i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        // when i >= j it means the j-th position is the correct position
        // of the pivot element, hence swap the pivot element with the
        // element in the j-th position
        temp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;
        // Repeat quicksort for the two sub-arrays, one to the left of j
        // and one to the right of j
        quick(arr, low, j-1);
        quick(arr, j+1, high);
    }
}

int main()
{

    int* vetor;
    int inicio, fim, tempo, tempo1, troca;
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
        printf("\n Tempo de ordemnacao: %d milisegundos \n", tempo);
        printf("\n Tempo de ordemnacao: %d segundos \n", tempo1);
        printf("\n Numero de trocas sao: %d \n", troca);
        system("pause");
        break;
    case 2 :
        inicio = 0;
        troca = 0;
        inicio = GetTickCount();
        troca = selecao(vetor,0, tam);
        fim = GetTickCount();
        tempo = fim - inicio;
        tempo1 = tempo/1000;
        printf(" \n Vetor ordenado pelo metodo selection sort eh: \n");
        mostrarVetor(vetor, tam);
        printf("\n Tempo de ordemnacao: %d milisegundos \n", tempo);
        printf("\n Tempo de ordemnacao: %d segundos \n", tempo1);
        printf("\n Numero de trocas sao: %d \n", troca);
        system("pause");
        break;
    case 3 :
        inicio = 0;

        inicio = GetTickCount();
        quick(vetor, 0, tam-1);
        fim = GetTickCount();
        tempo = fim - inicio;
        tempo1 = tempo/1000;
        printf(" \n Vetor ordenado pelo metodo quick sort é: \n");
        mostrarVetor(vetor, tam);
        printf("\n Tempo de ordemnacao: %d milisegundos \n", tempo);
        printf("\n Tempo de ordemnacao: %d segundos \n", tempo1);
        system("pause");
        break;
    default :
        printf("Valor invalido \n");
    }

    return 0;
}

