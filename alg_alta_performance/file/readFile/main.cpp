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
int main()
{
    setlocale(LC_ALL, "");
    int n;
    char rm[11], nome[50], media[5];
    tipoAluno alunos[TAMANHO];

    FILE *arq;
    arq = fopen("../registro.txt", "rt");
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

    }
    return 0;
}