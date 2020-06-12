#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale>

using namespace std;
#define NC 700
#define TAMANHO 10

int busca_sequencial_exaustiva(int array[], int num, int chave)
{
    int encontrados[NC];
    int i, ne = 0;
    int comparacoes=0;
    for (i = 0; i < num; i++)
    {
        comparacoes++;
        if(array[i] == chave)
            ne++;
    }
    return(comparacoes);
}
int busca_sequencial(int bd[], int num, int chave)
{
    int i, pos=-1;
    int achou = 0;
    int comparacoes = 0;
    for(i=0; i<num && achou == 0; i++)
    {
        comparacoes++;
        if(bd[i] == chave)
        {
            achou = 1;
            pos=i;
        }
    }
    return(comparacoes);
}
int busca_binaria(int bd[],int num, int chave)
{
int i_baixo = 0,i_alto = num-1, i_medio;
int achou = 0;
int	pos = -1;
int comparacoes = 0;
while( achou != 1 && i_baixo <= i_alto) {
	i_medio = (i_baixo + i_alto)/2;
    comparacoes++;
	if (chave == bd[i_medio])  {
		pos = i_medio;
		achou =1;
		}
	else {
        comparacoes++; //contando aqui pois ela faz mais uma comparação
		if (chave < bd[i_medio])
			i_alto = i_medio-1;
		else
			i_baixo = i_medio+1;
        }
	}
	return(comparacoes);
}

int bubble_sort(int vetor[],int n)
{
int aux,i,j;
int troca=true;
int comparacoes = 0;
for (i=0; i<n-1 && troca==true; i++)
{
    troca=false;
    for (j=0; j<n-i-1; j++)
    {
        comparacoes++;
        if (vetor[j]>vetor[j+1])
        {
            aux=vetor[j];
            vetor[j]=vetor[j+1];
            vetor[j+1]=aux;
            troca=true;
            }
        }
    }
    return comparacoes;
}

int insertion_sort(int vetor[],int n)
{
    int eleito, j,i;
    int comparacoes = 0;
    for(i = 1; i <n; i++)
    {
        eleito = vetor[i];
        j = i-1;
        comparacoes++;
        while(j >= 0 && vetor[j] > eleito) 
        {
            vetor[j+1] = vetor[j];
            j = j-1;
        }
        vetor[j+1] =  eleito;
    }
    return comparacoes;
}

int main()
{
    setlocale(LC_ALL, "");
    int n;
    char buffer[10];
    int arrayNumbers[NC];

    FILE *arq;
    arq = fopen("../file_numbers.txt", "rt");
    if(arq == NULL)
    {
        cout << "Arquivo não encontrado.\n";
    }
    else 
    {
        n=0;
        fscanf(arq, "%s", buffer);
        while(fscanf(arq, "%s", buffer) != EOF)
        {
            arrayNumbers[n] = atoi(buffer);
            n++;
        }
        fclose(arq);
    }

    //BUSCAS
    // cout << "BUSCAS: " << endl;
    // int compSequencialExaustiva = busca_sequencial_exaustiva (arrayNumbers, n, 210);
    // int compSequencial = busca_sequencial(arrayNumbers, n, 210);
    // int compBinaria = busca_binaria(arrayNumbers, n, 210);
    // cout << "Sequencial Exaustiva: " << compSequencialExaustiva << endl;
    // cout << "Sequencial: " << compSequencial << endl;
    // cout << "Binaria: " << compBinaria << endl;

    //ORDENACAO
    cout << "\n\nORDENACOES: " << endl;
    int compBubbleSort = bubble_sort(arrayNumbers, n);
    cout << "Bubble sort: " << compBubbleSort << endl;
    // int compInsertionSort = insertion_sort(arrayNumbers, n);
    // cout << "Insertion Sort: " << compInsertionSort << endl;

    return 0;
}