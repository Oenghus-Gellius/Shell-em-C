#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
void retiraEnter(char s[]) {
    if (s[strlen(s) - 1] == '\n')
        s[strlen(s) - 1] = '\0';
}
int validaComandoUsuario(char comandoU[]) {
    char* comandosShell[17] = { "exit", "cd", "cls", "date", "time", "dir", "type", "md", "copy", "rd", "del",
                               "vol", "ver", "path", "set", "notepad", "winver" };
    int i, tamanhoComando;
    for (i = 0; i < 17; i++) {
        tamanhoComando = strlen(comandosShell[i]);
        if (strncmp(comandosShell[i], comandoU, tamanhoComando) == 0)
            return i;
    }
    return -1;
}
void executaComando(char comandoU[]) {
    system(comandoU);
}
int trocaDiretorio(char comandoU[]) {
    int valida;
    valida = chdir(comandoU + 3);
    return valida;
}
int inicializa() {
    char comandoUsuario[100], diretorio[100], * diretorioSemC;
    int opcao;
    do {
        getcwd(diretorio, sizeof(diretorio));
        diretorioSemC = strrchr(diretorio, '\\');
        printf("shell:%s>", diretorioSemC);
        fgets(comandoUsuario, 100, stdin);
        setbuf(stdin, NULL);
        retiraEnter(comandoUsuario);
        opcao = validaComandoUsuario(comandoUsuario);
        if (opcao == -1) {
            printf("\n'%s' nÃ£o Ã© reconhecido como um comando interno\n", comandoUsuario);
            printf("ou externo, um programa operÃ¡vel ou um arquivo em lotes.\n");
        }
        else if (opcao == 1) {
            if (trocaDiretorio(comandoUsuario) != 0)
                printf("\nO sistema nÃ£o pode encontrar o caminho especificado.\n");
        }
        else if (opcao > 0) {
            executaComando(comandoUsuario);
        }
    } while (opcao != 0);
    return EXIT_SUCCESS;
}
int main() {
    return inicializa();
}