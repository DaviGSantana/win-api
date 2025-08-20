#include <stdio.h>
#include <windows.h>

int main(){
    MessageBox(
        NULL,       
        "Hello From WinAPI!",
        "MessageBox Example",
        MB_OK | MB_ICONINFORMATION
    );

    return 0;
}