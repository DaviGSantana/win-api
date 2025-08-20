#include <windows.h>
#include <stdio.h>
#include <string.h>

int main(){
    DWORD pid;

    printf("Digite o PID do processo alvo: ");
    scanf("%lu", &pid);

    // Abre o processo com permissao de operacao, leitura e escrita na memoria
    HANDLE hProcess = OpenProcess(
        PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ,  // Permissao para operar, ler e escrever
        FALSE,      // Nao herda o handle
        pid     // PID do processo
    );

    // Verifica se o OpenProcess falhou
    if (!hProcess) {
        printf("Falha ao abrir o processo. Erro: %lu\n", GetLastError());
        return 1;
    }

    // Aloca memoria no processo remoto (256 bytes)
    LPVOID remoteAddr = VirtualAllocEx(
        hProcess,       // Handle do processo remoto
        NULL,       // Endereco onde aloca a memoria (NULL PARA ALOCACAO AUTOMATICA)
        256,        // Tamanho da memoria a ser alocada (256 bytes)
        MEM_COMMIT,     // Flags para alocar memoria
        PAGE_READWRITE      // Permissoes de acessoa a memoria (leitura e escrita)
    );

    // Mensagem a ser escrita na memoria
    const char* message = "Hello from C to your memory!";

    SIZE_T bytesWritten;
    //Tenta escrever a mensagem na memoria alocada no processo remoto
    if (WriteProcessMemory(
        hProcess,       // Handle do processo remoto
        remoteAddr,     // Endereco de memoria remoto
        message,        // Dados a serem escritos (mensagem)
        strlen(message) + 1,    // Tamanho dos dados (incluindo o caractere nulo de termino)
        &bytesWritten       // Numero de bytes realmente escritos
    )){
        printf("Escreveu com sucesso %lu bytes no processo remoto.\n", bytesWritten);
    }else{
        printf("Falha ao escrever na memória do processo. Erro: %lu\n", GetLastError());
    }

    CloseHandle(hProcess);

    return 0;
}

/* Conceitos:
        - Escrite de memoria remota
        - WriteProcessMemory
        - Deve garantir permissoes corretas a regiao de memoria valida
*/