#include <iostream>
#include "global.h"
#include "dllloader.h"
#include "ge.h"

using namespace std;


typedef Ge::Matrix4x4* (*Ge_CreateMatrix4x4)();

int main(int argc, char* argv[]){
    #ifdef _MSC_VER
        cout << STR(------MSVC:) << _MSC_VER << endl<< STR(------);
    #elif defined(__GNUC__)
        cout << STR(------GCC:) << __GNUC__ << endl << STR(------);
    #endif


    auto handle = LOAD_DLL(ge.dll);

    Ge_CreateMatrix4x4 func_createMatrix4x4 = (Ge_CreateMatrix4x4)GET_MEMBER(handle, createMatrix4x4);

    Ge::Matrix4x4* pMatrix = func_createMatrix4x4();
    cout << pMatrix->entry[1][1];
    UNLOAD_DLL(handle);
    return 0;
}

