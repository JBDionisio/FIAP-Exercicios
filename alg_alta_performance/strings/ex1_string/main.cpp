#include <iostream>
#include <locale>
#include <cstring>
using namespace std;

//uso de strcat para concatenação de strings
int main()
{
    setlocale(LC_ALL, "");
    char str1[15] = "linguagem";
    char str2[3] = " C";
    
    strcat(str1, str2);
    int size = strlen(str1);

    cout << "Conteudo str1: " << str1 << "\n";
    cout << "Tamanho str1: " << size << "\n";

    return 0;
}
