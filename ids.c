#include <windows.h>
#include <stdio.h>

int main() {
    DWORD pid = GetCurrentProcessId();  // Obtém o ID do processo atual
    DWORD tid = GetCurrentThreadId();   // Obtém o ID da thread atual

    // Exibe o ID do processo e da thread
    printf("ID do Processo Atual: %lu\n", pid);
    printf("ID da Thread Atual: %lu\n", tid);

    return 0;
}
