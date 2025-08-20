#include <windows.h>
#include <stdio.h>

int main(){
    DWORD pid;

    printf("Digite o PID do processo a ser aberto: ");
    scanf("%lu", &pid);

    // Abre o processo com permissao de consulta e leitura de memoria.
    HANDLE hProcess = OpenProcess(
        PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, // Permissoes para consulta e leitura de memoria
        FALSE, // Nao herda o handle
        pid // PID do processo
    );

    // Verifica se o processo foi aberto com sucesso
    if (hProcess == NULL){
        printf("Falha ao abrir o processo. Error: %lu\n", GetLastError()); 
        return 1; // Retorna 1 em caso de erro
    }

    // Exibe o handle do processo aberto com sucesso
    printf("Processo aberto com sucesso (handle: %p).\n", hProcess);

    // Fecha o handle do processo
    CloseHandle(hProcess);

    return 0; 

}

/* Conceitos: 
        - Acessando processos externos
        - Permissoes necessarias
        - Gerenciamento de alças

*/