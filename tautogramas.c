#include <stdio.h>
#include <string.h>
#include <ctype.h>

char tautologia(char texto[]){
    char letra, resposta;
    letra = texto[0];

    for(int i = 1; i < strlen(texto);){
        if(texto[i] != ' ') i++;
        else if(texto[i+1] == toupper(letra) || texto[i+1] == tolower(letra)) {
            resposta = 'Y';
            i++;
        } else {
            resposta = 'N';
            return resposta;
        }
    }

    return resposta;
}

int main(){
    char texto[1000];   
    int espaco;

    inicio:
        gets(texto);
        if(texto[0] == '*') return 0;
        espaco = 0;

        for(int i = 0; i < strlen(texto); i++){
            if(texto[i] == ' ') espaco++;
        }

        if (espaco != 0){
            printf("%c\n", tautologia(texto));
        } else printf("Y\n");
        
        goto inicio;
}