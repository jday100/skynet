#ifndef MAIN_H
#define MAIN_H

#include "plugin\T100Plugin.h"

extern "C" {
    __declspec(dllexport)T100Plugin*  __stdcall   Launch();
}

#endif // MAIN_H
