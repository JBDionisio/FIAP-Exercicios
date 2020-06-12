#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale>

using namespace std;
#define NC 50
#define TAMANHO 10

struct Registro {
    int rm;
    char nome[NC];
    float media;
};

typedef struct Registro tipoAluno;

int buscaSequencialExaustiva_rm(tipoAluno lista[], int num, int chave, tipoAluno achados[])
{
    int i, ne=0;
    for(i=0; i<num; i++) 
    {
        if(lista[i].rm == chave) {
            achados[ne] = lista[i];
            ne++;
        }
    }    
    return(ne);
}

int main()
{
    setlocale(LC_ALL, "");
    int n;
    char rm[11], nome[50], media[5];
    tipoAluno alunos[TAMANHO];

    FILE *arq;
    arq = fopen("../../file/registro.txt", "rt");
    if(arq == NULL)
    {
        cout << "Arquivo não encontrado.\n";
    }
    else 
    {
        n=0;
        fscanf(arq, "%s%s%s", rm, alunos[n].nome, media);
        cout << "RM \t NOME \t MÉDIA \n";

        while(fscanf(arq, "%s%s%s", rm, alunos[n].nome, media) != EOF)
        {
            alunos[n].rm = atoi(rm);
            alunos[n].media = atof(media);
            cout << alunos[n].rm << "\t" << alunos[n].nome << "\t" << alunos[n].media << endl;
            n++;
        }
        fclose(arq);

        // BUSCA SEQUENCIAL EXAUSTIVA
        cout << "\n* BUSCA SEQUENCIAL EXAUSTIVA\n";
        tipoAluno achados[TAMANHO];
        int rmProcurado = 527;
        int qtdAchados = buscaSequencialExaustiva_rm(alunos, n, rmProcurado, achados);
        cout << "Numero de achados: " << qtdAchados << " com RM: " << rmProcurado << endl;
        cout << "RM\tNOME\tMÉDIA \n";
        for(int i=0; i<qtdAchados; i++)
        {
            cout << achados[i].rm << "\t" << achados[i].nome << "\t" << achados[i].media << endl;
        }

    }

    return 0;
}