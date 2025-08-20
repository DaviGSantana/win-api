#include <stdio.h>
#include <windows.h>

int main() {

    HANDLE hFile = CreateFileA(
        "example.txt",
        GENERIC_WRITE,
        0,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        printf("Failed to create file. Error: ", GetLastError);
        return 1;
    }

    const char* data = "Hello, WinAPI file IO!";
    DWORD bytesWritten;

    BOOL success = WriteFile(
        hFile,
        data,
        strlen(data),
        &bytesWritten,
        NULL
    );

    if (!success) {
        printf("Write failed. Error: ", GetLastError);
    } else {
        printf("Successfully wrote ", bytesWritten , "bytes.");
    }

    CloseHandle(hFile);

    return 0;
}