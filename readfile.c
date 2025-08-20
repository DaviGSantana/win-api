#include <windows.h>
#include <stdio.h>

int main() {
    // Abre o arquivo "example.txt" com permissão de leitura
    HANDLE hFile = CreateFileA(
        "example.txt",           // Arquivo a ser aberto
        GENERIC_READ,            // Acesso desejado (apenas leitura)
        FILE_SHARE_READ,         // Modo de compartilhamento (leitura permitida por outros processos)
        NULL,                    // Atributos de segurança (NULL para padrão)
        OPEN_EXISTING,           // Abre o arquivo apenas se ele existir
        FILE_ATTRIBUTE_NORMAL,   // Atributos normais (sem atributos especiais)
        NULL                     // Arquivo modelo (NULL se não for necessário)
    );

    // Verifica se o arquivo foi aberto com sucesso
    if (hFile == INVALID_HANDLE_VALUE) {
        printf("Não foi possível abrir o arquivo. Erro: %lu\n", GetLastError());
        return 1;  // Retorna 1 em caso de erro
    }

    char buffer[128] = {0};  // Buffer para armazenar os dados lidos
    DWORD bytesRead;         // Variável para armazenar a quantidade de bytes lidos

    // Lê os dados do arquivo
    BOOL success = ReadFile(
        hFile,
        buffer,
        sizeof(buffer) - 1,    // Lê até 127 bytes
        &bytesRead,            // Armazena o número de bytes lidos
        NULL                   // Ponteiro de sobreposição (NULL para operação síncrona)
    );

    // Verifica se a leitura foi bem-sucedida
    if (!success) {
        printf("Falha na leitura. Erro: %lu\n", GetLastError());
    } else {
        // Exibe os dados lidos do arquivo
        printf("Foram lidos %lu bytes: %s\n", bytesRead, buffer);
    }

    // Fecha o arquivo após a operação
    CloseHandle(hFile);

    return 0;  // Retorna 0 indicando sucesso
}

/* Conceitos:
    - Leitura de arquivos com controle de baixo nivel
    - Gerenciamento de buffer e saida segura 
    */