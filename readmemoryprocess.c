#include <windows.h>
#include <stdio.h>

int main(){
    
    DWORD pid;
    
    printf("Digite o PID do processo alvo: ");
    scanf("%lu", &pid);

    // Abre o processo com permissoes de leitura de memoria e consulta de informacoes 
    HANDLE hProcess = OpenProcess(
        PROCESS_VM_READ | PROCESS_QUERY_INFORMATION,  // Permissoes de leitura e consulta
        FALSE,  // Nao herda o handle
        pid   // PID do processo
    );


    // Verifica se o processo foi aberto com sucesso
    if (!hProcess){
        printf("Falha ao abrir o processo. Erro: %lu\n", GetLastError());
        return 1;
    }

    // Endereco de memoria (deve ser valido no processo alvo)
    LPCVOID address = (LPCVOID)0x7FFDF000;
    char buffer[32] = {0}; // Buffer para armazenar os dados lidos
    SIZE_T bytesRead;

    // Tenta ler a memoria do processo
    BOOL success = ReadProcessMemory(
        hProcess,   // Handle do processo aberto
        address,    // Endereco de memoria da ser lido
        buffer,     // Buffer onde os dados lidos sao armazenados
        sizeof(buffer),     // Tamanho do buffer
        &bytesRead      // Variavel que recebera o numero de bytes lidos
    )
    
    if (sucess) {
        printf("Dados lidos (%lu bytes): %s\n", bytesRead, buffer);
    }else{
        printf("Falha ao ler a memoria do processo. Erro: %lu\n", GetLastError());
    }

    // Fecha o handle do processo
    CloseHandle(hProcess);

    return 0;
}

/* Conceitos:
        - Acesso a memoria entre processos
        - ReadProcessMemory e gerenciamento de ponteiros
        - Requer conhecimento de regioes de memoria validas
*/