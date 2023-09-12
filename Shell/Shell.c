#define _CRT_SECURE_NO_WARNINGS

#include "Shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define TAM_CHAR 100
#define ERRO -1
#define FULL_COMAND 17


//Fun�a� que retira o enter
void funcRetiraEnter(char s[]){
    if (s[strlen(s) - 1] == '\n')
        s[strlen(s) - 1] = '\0';
}

//func�o checando comando
int  funcCheckComand(char *comandUsuario) {
    char comadosShellC[][FULL_COMAND] = { "cls", "date", "time", "dir", "type", "cd", "md", "copy", "rd", "del", "vol", "ver", "path", "set", "exit", "notepad", "winver" };
    int i;

    for (i = 0; i < FULL_COMAND; i++)
    {
        if (strcmp(comadosShellC[i], comandUsuario) == 0)
        {
            return i;
        }
    }
    return ERRO;
}


//fun�a� que vai ativar os system magicamente 
void funcMagicSistem(char *comandoAltenticado) {
    system(comandoAltenticado);
}


//fun��o que define os comandos, encaminha em casos especiais
void funcDefinicao(char *comandoUser, char *dirAtual) {
    int check; 
    
    //Avalia se o comando � valido
    check = funcCheckComand(comandoUser);
    if (check == ERRO)
    {
        printf("\nO comando %s n�o � valido para o SHELL DESGRA�A!!!!!!\n", comandoUser);
    }
    else //Comando especificos
    {
        //outros casos
        funcMagicSistem(comandoUser);
    }
}


// Fun��o para lidar com o comando "cd"
int changeDirectory(char* dirAtual, const char* newDir) {
    char novoCaminho[TAM_CHAR];
    char* ultBarra;

    if (strcmp(newDir, "..") == 0) {
        ultBarra = strrchr(dirAtual, '/');
        if (ultBarra != NULL) {
            *ultBarra = '\0';
        }
    }
    else {
        snprintf(novoCaminho, TAM_CHAR, "%s/%s", dirAtual, newDir);

        if (chdir(novoCaminho) == 0) {
            strcpy(dirAtual, novoCaminho);
            printf("Mudan�a bem-sucedida. Novo diret�rio atual: %s\n", dirAtual);
        }
        else {
            perror("Erro ao mudar de diret�rio");
            return ERRO;
        }
    }

    return EXIT_SUCCESS;
}

// Fun��o principal do shell
int funcShell() {
    char comandUsuario[TAM_CHAR];
    char dirAtual[TAM_CHAR];

    // Shell em a��o at� digitar "exit"
    do {
        printf("Shell:%s>", dirAtual);
        fgets(comandUsuario, TAM_CHAR, stdin);
        funcRetiraEnter(comandUsuario);

        if (strncmp(comandUsuario, "cd", 2) == 0) {
            char newDir[TAM_CHAR];

            strncpy(newDir, comandUsuario + 3, TAM_CHAR);
            funcRetiraEnter(newDir);

            if (changeDirectory(dirAtual, newDir) == ERRO) {
                // Lida com o erro na fun��o de mudan�a de diret�rio
            }
        }
        else if (strcmp(comandUsuario, "exit") != 0) {
            funcMagicSistem(comandUsuario);
        }
    } while (strcmp(comandUsuario, "exit") != 0);

    return EXIT_SUCCESS;
}

int main() {
    return funcShell();
}