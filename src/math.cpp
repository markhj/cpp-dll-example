// Declare two methods which must exist in our DLL
// The "extern C" part exposes the method to be used by linked executables and libraries

extern "C" int add(int a, int b) {
    return a + b + 10;
}

extern "C" int sub(int a, int b) {
    return a - b;
}