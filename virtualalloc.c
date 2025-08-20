#include <windows.h>
#include <stdio.h>
#include <string.h>

int main() {
    // Aloca 1 KB de memória com permissões de leitura e escrita
    LPVOID mem = VirtualAlloc(
        NULL,                      // Deixa o SO escolher o endereço
        1024,                      // Tamanho em bytes
        MEM_COMMIT | MEM_RESERVE, // Tipo de alocação
        PAGE_READWRITE             // Proteção
    );

    if (mem == NULL) {
        DWORD error = GetLastError();
        printf("Falha na alocação de memória. Erro: %lu\n", error);
        return 1;
    }

    // Escreve dados na memória alocada
    strncpy((char*)mem, "This is dynamic memory via WinAPI.", 1024);

    // Garante que está terminado em nulo (boa prática com strncpy)
    ((char*)mem)[1023] = '\0';

    // Exibe o conteúdo da memória
    printf("Conteúdo da memória: %s\n", (char*)mem);

    // Libera a memória
    VirtualFree(mem, 0, MEM_RELEASE);

    return 0;
}
