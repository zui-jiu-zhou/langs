#pragma once
#ifndef _GE_H_
#define _GE_H_

#include "global.h"

namespace Ge
{
    class _DLL_EXPORT_ Matrix4x4
    {
    public:
        double entry[4][4];

        Matrix4x4();
    };
}
    extern "C"{
        _DLL_EXPORT_ Ge::Matrix4x4* createMatrix4x4();
    }
#endif