#define _CRT_SECURE_NO_WARNINGS

#include "Shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_CHAR 100
#define ERRO -1
#define FULL_COMAND 17


//Fun�a� que retira o enter
void funcRetiraEnter(char s[]){
    if (s[strlen(s) - 1] == '\n')
        s[strlen(s) - 1] = '\0';
}

//func�o checando comando
const char  funcCheckComand(const char* comandoUser) {
    char* comadosShellC[FULL_COMAND] = { "cls", "date", "time", "dir", "type", "cd", "md", "copy", "rd", "del", "vol", "ver", "path", "set", "exit", "notepad", "winver" };
    char* comandoAltenticado = NULL;
    int i;

    for (i = 0; i < FULL_COMAND; i++)
    {
        if (strcmp(comadosShellC[i], comandoUser) == 0)
        {
            comandoAltenticado = comadosShellC[i];
            break; //Interrompe a repeti��o pq achou o valor
        }
    }

    if (comandoAltenticado == NULL) {
        printf("\nEsse comando n�o est� na lista desgra�a!!!");
    }
    return comandoAltenticado;
}

//fun��o que define os comandos, encaminha em casos especiais
void funcDefinicao(char comandoAltenticado) {


}

//fun�a� que vai vai ativar os system magicamente 
void funcMagicSistem(char comandoAltenticado) {
    system(comandoAltenticado);
}

//fun��o para executar o shell
int funcShell(){
    //comandos do shellControlado
    char comandUsuario[TAM_CHAR];
    char *comandoAltenticado;
    char dirAtual[TAM_CHAR] = {NULL};
    
    //Shell em a��o at� digitar "exit"
    do
    {
        setbuf(stdin, NULL);
        printf("Shell:%s>",dirAtual);
        fgets(comandUsuario, TAM_CHAR, stdin);
        funcRetiraEnter(comandUsuario);
        setbuf(stdin, NULL);

        comandoAltenticado = funcCheckComand(comandUsuario);

        //Apos checar o comando encaminha para a fun�a� que define os casos especiais
        funcDefinicao(comandoAltenticado);
       
    } while (strcmp(comandUsuario, "exit") != 0);
    
    return EXIT_SUCCESS;
}
int main(){
    return funcShell();
}