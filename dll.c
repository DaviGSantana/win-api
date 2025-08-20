#include <windows.h>
#include <stdio.h>

int main(){
    // Carrega a biblioteca 'kernel32.dll' dinamicamente
    HMODULE hKernel32 = LoadLibraryA("kernel32.dll");
    if (!hKernel32){
        printf("Falhar ao carregar kernel32.dll. Erro: %lu\n", GetLastError());
        return 1;
    }

    // Obtem o endereco da funcao 'Beep' da kernel32.dll
    FARPROC funcAddr = GetProcAddress(hKernel32, "Beep");

    if (funcAddr){
        // Exibe o endereco da funcao 'Beep'
        printf("Endereco da funcao 'Beep': %p\n", funcAddr);
    } else{
        // Exibe erro caso nao consiga encontrar a funcao
        printf("Falha ao localizar a funcao 'Beep'. Erro: %lu\n", GetLastError());
    }

    // Libera a biblioteca carregada
    FreeLibrary(hKernel32);

    return 0;
}

/* Conceitos: 
        - Resolucao dinamica de API
        - Uso de LoadLibrary e GetProcAddress
        - Essencial para tecnicas como injecao de dll ou mapeamente manual
*/