#include <windows.h>
#include <stdio.h>

// Funcao da thread, deve seguir a assinatura correta
DWORD WINAPI MyThreadFunction(LPVOID lpParam) {
    printf("Thread em execucao... ID: %lu\n", GetCurrentThreadId());
    Sleep(1000);
    return 0;
}

int main(){

    HANDLE hThread;
    DWORD threadId;

    //Cria uma nova thread
    hThread = CreateThread(
        NULL,   // Segurança padrao
        0,  // Tamanho de pilha padrao
        MyThreadFunction,   // Funcao da thread
        NULL,   // Parametro para a thread
        0,  // Flags de criacao padrao
        &threadId   // Recebe o ID da thread
    );

    // Verifica se a criacao da thread foi bem-sucedida
    if (hThread == NULL){
        printf("Falha ao criar a thread. Erro: %lu\n", GetLastError());
        return 1;
    }

    // Exibe o ID da thread criada
    printf("Thread criada. ID: %lu\n", threadId);

    // Aguarda a thread terminar
    WaitForSingleObject(hThread, INFINITE);

    // Fecha o handle da thread
    CloseHandle(hThread);

    return 0;
}

/* Conceitos:
        - Criacao de thread
        - Assinatura de funcao para threads WinAPI
        - Utilizacao CreateThread e sincronizacao via WaitForSingleObject

*/