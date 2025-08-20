#include <windows.h>
#include <stdio.h>

int main() {
    STARTUPINFOA si = { sizeof(si) };  // Inicializa a estrutura STARTUPINFO
    PROCESS_INFORMATION pi;            // Receberá as informações do processo

    // Caminho para o executável (deve existir)
    LPCSTR appName = "C:\\Windows\\System32\\notepad.exe";

    // Cria um novo processo (nesse caso, o Notepad)
    BOOL sucesso = CreateProcessA(
        appName,       // Nome do aplicativo
        NULL,          // Linha de comando
        NULL,          // Atributos de segurança do processo
        NULL,          // Atributos de segurança da thread
        FALSE,         // Herança de handles
        0,             // Flags de criação
        NULL,          // Ambiente
        NULL,          // Diretório atual
        &si,           // Informações de inicialização
        &pi            // Informações do processo (saída)
    );

    if (!sucesso) {
        printf("Falha ao criar o processo. Erro: %lu\n", GetLastError());
        return 1;
    }

    printf("Processo criado com sucesso! PID: %lu\n", pi.dwProcessId);

    // Espera até o processo finalizar
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Fecha os handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
