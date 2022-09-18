**This project is purely for demonstration purpose. Do not use in production!**

## Introduction
This is a quick example of how to create multiple executables and DLL files in the same project solution with C++ and CMake.
You can fork this project, build it and play around with it to see how DLLs and multiple executables can be used in the same project.

Particularly interesting is the CMake file, where you can explore how the compiler will first build the DLL
and then link it to the executable.

Additionally, it will create a second executable, other.exe. This is just to demonstrate how that's possible.

In this example ``src/math.cpp`` is the file we can to compile as DLL, while ``main.cpp`` is our primary executable,
which utilizes the compiled DLL.

## Good to know
The project was written in CLion targeting C++14.

You may need to fully build the project for the additional executables to show up.

## Why use DLLs
* Faster initialization of the program, because DLLs can be loaded when needed
* Less memory required, because it's not one huge executable loaded into the memory
* Promotes modularity in big projects
* Patchable (only the DLL needs updating)
* Can be shared outside the project scope
* Reusable
