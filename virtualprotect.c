#include <windows.h>
#include <stdio.h>
#include <string.h>

int main(){
    // Aloca 1024 bytes de memoria com permissoes de leitura e escrita
    LPVOID mem = VirtualAlloc(NULL, 1024, MEM_COMMIT, PAGE_READWRITE);
    if (!mem) {
        printf("Falha ao alocar memoria. Erro: %lu\n", GetLastError());
        return 1;
    }

    // Escreve uma string na memoria alocada
    strcpy_s((char*)mem, 1024, "Testando protecao de memoria.");

    // Altera a protecao de memoria para somente leitura
    DWORD oldProtect;
    if (VirtualAlloc(mem, 1024, PAGE_READONLY, &oldProtect)){
        printf("Protecao de memoria alterada para somente leitura.\n");
    } else{
        printf("Falha ao alterar a protecao de memoria. Erro: %lu\n", GetLastError());
    }

    // Libera a memoria alocada
    VirtualFree(mem, 0, MEM_RELASE);

    return 0;
}

/* Conceitos:
        - Protecao da regiao de memoria
        - PAGE_READWRITE para PAGE_READONLY
        - Util para impor politicas de execucao ou seguranca da memoria
*/