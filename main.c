#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

//Fun��o para prencher o vetor com n�meros aleat�rios
void prencherVetor(int *vetor, int tam){

    int i;

    for(i=0; i < tam; i++)
    {
        vetor[i] = rand()%100;
    }
}
//Fun��o para mostrar o vetor
void mostrarVetor(int*vetor, int tam){

    int i;

    for(i = 0; i < tam; i++)
    {
        printf("%i\t", vetor[i]);
    }
    printf("\n");
}
int menu(){

int opc;

  // Esta � tela de op��o que ser� excutada ap�s a tela de menu
	printf("-----------------\tOPCAO DE ORDENACAO\t-----------------\n\n");
	printf(" Digite qual metodo deseja usar: \n\n");
	printf(" 0 - SAIR\n");
    printf(" 1 - Para usar Bublle Sort \n");
    printf(" 2 - Para usar Selection Sort\n");
    printf(" 3 - Para usar Quick Sort\n");
    scanf("%d", &opc);

  system("cls");

return opc;
}
void gravaArquivo(int tam, int troca, int tempo, int tempo1, FILE *relatorio,char *metodo){

fprintf(relatorio,"\nPara um vetor de %d posicoes e ordenado pelo metodo %s temos:", tam, metodo);
fprintf(relatorio,"\n Tempo de ordenacao em milesegundos: %d milisegundos \n", tempo);
fprintf(relatorio,"\n Tempo de ordenacao em segundos: %d segundos \n", tempo1);
fprintf(relatorio,"\n Numero de trocas sao: %d \n\n", troca);

fclose(relatorio);

}
//Swap ("Troca") � uma fun��o que troca posi��es no vetor
int swap(int *arr, int i, int j){

    int troca = 0;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    troca++;

    return troca;
}
//Fun��o Bublle Sort
int bublle(int *vetor, int tam){

	int troca = 0;

    if (tam == 1)

        return 0;

    for (int i=0; i<tam-1; i++)
        if (vetor[i] > vetor[i+1])
            troca +=  swap(vetor, i, i+1);

    bublle(vetor, tam-1);

    return troca;
}
// Fun��o recursiva para executar o Selection Sort no subarray arr[i...n-1]
int selection(int *vetor, int i, int tam, int troca){

   for (int i = 0; i < tam - 1; i++)
    {	// Encontra o elemento m�nimo no subarray n�o classificada [i..n-1]
        int min = i; //Swap ("Troca") com o arr[i]

    for (int j = i + 1; j < tam; j++)
    {

        if (vetor[j] < vetor[min]) //Se arr[j] � menor elemento, ent�o � o novo m�nimo
            min = j;    // Atualiza o menor elemento do index
    }
	// Swap ("troca") o minimo de elementos em uma subarray [i...n-1]
      troca += swap(vetor, min, i);
}
    if (i + 1 < tam)
    {
        troca = selection(vetor, i + 1, tam, troca);
    }

    return troca;
}
//Fun��o Quick Sort
int quick(int *vetor, int inicio, int fim, int troca){

	int i, j, pivo, aux;

	i = inicio;
	j = fim;
	troca = 0;

	pivo = vetor[(inicio+fim)/2];

	do{
		while(vetor[i]<pivo)  // Enquanto o valor do vetor na posi��o 'i' for menor que o piv� o 'i' avan�a para direita
		i++;
		while(vetor[j]>pivo)  // Enquanto o valor do vetor na posi��o 'j' for maior que o piv�  o 'i' retrocede para esquerda
		j--;
		if(i<=j) // Se a posi��o de 'i' for menor ou igual a 'j' ('i' a esquerda e 'j' a direita ou encontro de 'i' e 'j')
		{
			aux = vetor[i];  // Trocas
			vetor[i]=vetor[j];
			vetor[j] = aux;

			i++;
			j--;
			troca ++;
	    }
	}while (i<=j); // La�o roda at� o encontro dos indices 'i' e 'j'

	if(inicio <j) // Se o incio for menor que o 'j' chamar a fun��o quick para a sub lista a esquerda
	troca += quick(vetor, inicio,j,troca);

	if(i<fim) // Se o 'i' for menor que o fim chamar a fun��o quik para a sublista a direita
	troca += quick(vetor, i, fim, troca);

	return troca;
	}

   int main(){

    int* vetor;
    int inicio, fim, tempo, tempo1, troca = 0;
    int opc, tam;
    FILE *relatorio;
    char metodo[20];

    do {
    relatorio = fopen("relatorio.txt", "at");

    if (relatorio == NULL)
    {
        printf("Socorro! O arquivo n�o p�de ser aberto!\n");
    }

    opc = menu();

    if( opc != 0 ){
    // Este � o menu que aparecer� no inicio do programa
    printf("-----------------\t\t **** \t\t-----------------\n\n");
    printf(" Vamos testar qual metedo de ordenacao eh mais rapido!\n");
    printf(" Digite o tamanho do vetor que deseja ordenar: ");
    scanf("%d", &tam);
    vetor = (int *)malloc(tam * sizeof(int));
    prencherVetor(vetor, tam);
    printf("\n Este eh o vetor sem ordenar:\n\n");
	mostrarVetor(vetor, tam);
	  system("pause");


    }


	switch (opc){


	case 0:

                printf("Fim do programa, clique em qualquer tecla para sair");
                break;
	case 1 : //Caso seja selecionado op��o 1 ser� executado o m�todo Bublle Sort
		system("cls");
        inicio = GetTickCount();
        troca = bublle(vetor, tam);
        fim = GetTickCount();
        tempo = fim - inicio;
        tempo1 = tempo/1000;
        printf("-----------------\tBUBLLE SORT\t-----------------\n\n");
        printf("\n Este eh o vetor ordenado:\n\n");
        mostrarVetor(vetor, tam);
        printf("\n Tempo de ordenacao: %d milisegundos \n", tempo);
        printf("\n Tempo de ordenacao: %d segundos \n", tempo1);
        printf("\n Numero de trocas sao: %d \n\n", troca);
        strcpy( metodo,"Buble Sort");
        gravaArquivo(tam,troca,tempo,tempo1,relatorio, metodo);
        system("pause");
        break;
    case 2 : //Caso seja selecionado op��o 2 ser� executado o m�todo Selection Sort
    	system("cls");
        inicio = 0;
        troca = 0;
        inicio = GetTickCount();
        troca = selection(vetor,0, tam, troca);
        fim = GetTickCount();
        tempo = fim - inicio;
        tempo1 = tempo/1000;
        printf("-----------------\tSELECTION SORT\t-----------------\n\n");
        printf("\n Este eh o vetor ordenado:\n\n");
        mostrarVetor(vetor, tam);
        printf("\n Tempo de ordenacao: %d milisegundos \n", tempo);
        printf("\n Tempo de ordenacao: %d segundos \n", tempo1);
        printf("\n Numero de trocas sao: %d \n\n", troca);
        strcpy( metodo,"Selection Sort");
        gravaArquivo(tam,troca,tempo,tempo1,relatorio, metodo);
        system("pause");
        break;
    case 3 : //Caso seja selecionado op��o 3 ser� executado o m�todo Quick Sort
    	system("cls");
        inicio = 0;
        inicio = GetTickCount();
        troca = quick(vetor, 0, tam-1, troca);
        fim = GetTickCount();
        tempo = fim - inicio;
        tempo1 = tempo/1000;
        printf("-----------------\tQUICK SORT\t-----------------\n\n");
        printf("\n Este eh o vetor ordenado:\n\n");
        mostrarVetor(vetor, tam);
        printf("\n Tempo de ordenacao: %d milisegundos \n", tempo);
        printf("\n Tempo de ordenacao: %d segundos \n", tempo1);
        printf("\n Numero de trocas sao: %d \n\n", troca);
        strcpy(metodo,"Quick Sort");
        gravaArquivo(tam,troca,tempo,tempo1,relatorio, metodo);
        system("pause");
        break;
    default :
        printf("Opcao invalida\n");
	}
	system("cls");
	}

	while ( opc != 0);





    return 0;
}
