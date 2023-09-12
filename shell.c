/*
O Windows possui um prompt de comandos que pode ser usado para a execução de comandos
desse sistema operacional. O shell2 de comandos do Windows utiliza o interpretador de comandos
cmd.exe. Um subconjunto desses comandos possui a sintaxe listada na primeira coluna da Tabela 1.

Os colchetes na Tabela 1 indicam usam opcional. Para obter informações sobre esses comandos
do Windows use a sintaxe <comando> /?, por exemplo, o texto de ajuda do dir será exibido quando o
comando abaixo for executado.

de comandos do Windows utiliza o interpretador de comandos
cmd.exe.

Desenvolva um programa usando a Linguagem C, chamado shell, que:
1. Mostra um prompt ao usuário para que ele possa digitar os comandos da Tabela 1 ou os
programas notepad e winver, ambos localizados no diretório C:\windows\system32. Use o
prompt abaixo.

shell:\>

2. Lê, analisa e executa o comando ou o programa fornecido pelo usuário.
3. Finaliza o programa shell quando o usuário digitar a palavra exit no seu prompt.

Importante: 1. Para executar os comandos da Tabela 1, os programas notepad e winver use a

função system.
2. O prompt deve sempre mostrar o nome do diretório atual do disco. Considere
somente um disco no sistema. Os comandos devem ser executados
considerando o diretório corrente. Observe os exemplos abaixo:

shell:\> cd windows
shell:\windows> dir

Como o diretório corrente foi alterado do raiz (\) para windows, esse deve ser
exibido no prompt (shell\windows>), e é o conteúdo do diretório windows que
deve ser listado quando o comando dir for executado.

shell:\programas> md java

Como o diretório atual agora é programas, o diretório java deve ser criado
como subdiretório de programas quando o comando md for executado.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_COMAND 100
#define TAM_CAMINHO 200
#define NUM_COMAND_VALID 17


int Entrada(){
    char comando;
    int check;
    
    do
    {
        printf("shell:%s",diretorioAtual);
        fgets(comando,100,stdin);
        setbuf(stdin,NULL);
        check=check(comando);


    } while (strcmp(comando,"exit")!=0);
}

//funçaõ para checar se o comando é valido
int check(char comando){
    int i;
    char comandosValidos[NUM_COMAND_VALID] = {{"exit"}, {"date"}, {"time"}, {"dir"}, {"type"},{"cd"}, {"md"}, {"copy"}, {"rd"}, {"del"},{"vol"}, {"ver"}, {"path"}, {"set"}, {"cls"}, {"notepad"}, {"winver"}};
    for (i = 0; i < NUM_COMAND_VALID; i++)
    {
        if(comando,comandosValidos[i])
            

    }
    

    return
}



int main(){
    char diretorioAtual[TAM_COMAND];
    char comando[TAM_COMAND];


    int Entrada();
    
    return EXIT_SUCCESS;
}


