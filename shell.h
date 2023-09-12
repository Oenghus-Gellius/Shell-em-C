#pragma once

/*
O Windows possui um prompt de comandos que pode ser usado para a execução de comandos
desse sistema operacional. O shell2

de comandos do Windows utiliza o interpretador de comandos
cmd.exe.
Os colchetes na Tabela 1 indicam usam opcional. Para obter informações sobre esses comandos
do Windows use a sintaxe <comando> /?, por exemplo, o texto de ajuda do dir será exibido quando o
comando abaixo for executado.
Desenvolva um programa usando a Linguagem C, chamado shell, que:
1. Mostra um prompt ao usuário para que ele possa digitar os comandos da Tabela 1 ou os
programas notepad e winver, ambos localizados no diretório C:\windows\system32. Use o
prompt abaixo.

shell:\>

2. Lê, analisa e executa o comando ou o programa fornecido pelo usuário.
3. Finaliza o programa shell quando o usuário digitar a palavra exit no seu prompt.

Importante: 1. Para executar os comandos da Tabela 1, os programas notepad e winver use a


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

3. Refaça o programa shell do Exercício 2 substituindo a função system pela _execv3 da C Runtime
Library (CRT) para executar apenas os programas notepad e winver. Observe e registre o que
acontecerá com o programa shell ao executar esses programas.
*/


//Funçaõ que retira o enter
void funcRetiraEnter(char s[]);

//funcão checando comando
int  funcCheckComand(char* comandUsuario);

//funçaõ que vai ativar os system magicamente 
void funcMagicSistem(char* comandoAltenticado);

// Função para lidar com o comando "cd"
int changeDirectory(char* dirAtual, const char* newDir);

//função que define os comandos, encaminha em casos especiais
void funcDefinicao(char* comandoUser, char* dirAtual);

//função para executar o shell
int funcShell();