#include "stdafx.h"
#include "Framework.h"

int main()
{
    FRAMEWORK.Init(1920, 1080, "TIMBER_FRAMEWORK");
    FRAMEWORK.Do();
    FRAMEWORK.Release();

    return 0;
}