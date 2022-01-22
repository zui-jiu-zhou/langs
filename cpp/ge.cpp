#include "ge.h"

using namespace Ge;

Matrix4x4::Matrix4x4(){
    entry[0][0]=1;
    entry[1][1]=1;
    entry[2][2]=1;
    entry[3][3]=1;
}

Matrix4x4* createMatrix4x4(){
    return new Matrix4x4();
}