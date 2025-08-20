#include <windows.h>

int main() {
    // Pausa a execução por 2 segundos
    Sleep(2000); // Milissegundos

    // Toca um som (frequência de 750 Hz, duração de 300 ms)
    Beep(750, 300);

    return 0;
}
