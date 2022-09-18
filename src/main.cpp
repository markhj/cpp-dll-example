#include <iostream>
#include <windows.h>

// The signature of the function in the DLL, must be declared with typedef
typedef int (CALLBACK* LPADD)(int,int);
typedef int (CALLBACK* LPSUB)(int,int);

int main() {
    // Load the DLL
    HINSTANCE mathDLL = LoadLibrary(TEXT("./libmath.dll"));

    // Check if the DLL has been loaded
    if (!mathDLL) {
        std::cerr << "Could not load the dynamic Math library" << std::endl << std::flush;
        return EXIT_FAILURE;
    }

    // Assign the function pointers
    // Note the type-casts to the previously specified typedefs
    LPADD addptr = (LPADD) GetProcAddress((HMODULE) mathDLL, "add");
    LPSUB subptr = (LPSUB) GetProcAddress((HMODULE) mathDLL, "sub");

    // Verify that the pointers were loaded
    if (!addptr || !subptr) {
        std::cerr << "Failed to load functions from Math library" << std::endl << std::flush;
        return EXIT_FAILURE;
    }

    // Put the DLL methods to use
    std::cout << "Addition from DLL: " << addptr(2, 3) << std::endl;
    std::cout << "Subtract from DLL: " << subptr(10, 3) << std::endl;

    FreeLibrary(mathDLL);

    return EXIT_SUCCESS;
}
