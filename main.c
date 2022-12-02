#include <stdio.h>
#define TAM 50

void pedirCadena(char *cad);
int esPalindromo(char *cad);

int main() {
    char cad[TAM];
    printf("Introduzca cadena a comprobar: ");
    pedirCadena(cad);
    do {
        if (esPalindromo(cad)==1)
            printf("La cadena es un palindromo.");
        else
            printf("La cadena NO es un palindromo.");
        printf("\n\nIntroduzca cadena a comprobar (0 para salir): ");
        pedirCadena(cad);
    } while (cad[0]!='0');
    return 0;
}

void pedirCadena(char *cad){
    scanf("%[^\n]", cad);
    fflush(stdin);
}

int esPalindromo(char *cad){
    int caracteres=0,i=0;
    do {
        if (cad[i]!=' ')
            caracteres++;
        i++;
    } while (cad[i]!='\0');
    char c1[caracteres], c2[caracteres];
    int j=0;
    for (i=0; i < caracteres; i++) {
        while ((cad[j]==' ')||(cad[j]=='\0'))
            j++;
        c1[i]=cad[j];
        c2[caracteres-i-1]=cad[j];
        j++;
    }
    int iguales=1;
    for (i=1; i < caracteres && iguales==1; ++i) {
        if (c1[i]!=c2[i])
            iguales=0;
    }
    return iguales;
}