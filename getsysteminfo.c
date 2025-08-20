#include <windows.h>
#include <stdio.h>

int main() {
    SYSTEM_INFO infoSistema;

    // Preenche a estrutura SYSTEM_INFO
    GetSystemInfo(&infoSistema);

    // Exibe as informações do sistema
    printf("Arquitetura do processador: %u\n", infoSistema.wProcessorArchitecture);
    printf("Tamanho da página: %u bytes\n", infoSistema.dwPageSize);
    printf("Número de processadores: %u\n", infoSistema.dwNumberOfProcessors);

    return 0;
}
