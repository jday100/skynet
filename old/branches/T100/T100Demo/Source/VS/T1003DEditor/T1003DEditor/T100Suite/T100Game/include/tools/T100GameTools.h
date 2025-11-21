#ifndef T100GAMETOOLS_H
#define T100GAMETOOLS_H

#include <windows.h>
#include "T100Common.h"

inline void GetAssetsPath(_Out_writes_(pathSize) WCHAR* path, UINT pathSize)
{
    if (path == nullptr)
    {
        throw std::exception();
    }

    DWORD size = GetModuleFileNameW(nullptr, path, pathSize);
    if (size == 0 || size == pathSize)
    {
        throw std::exception();
    }

    WCHAR* lastSlash = wcsrchr(path, L'\\');
    if (lastSlash)
    {
        *(lastSlash + 1) = L'\0';
    }
}

class T100GameTools
{
    public:
        T100GameTools();
        virtual ~T100GameTools();

    protected:

    private:
};

#endif // T100GAMETOOLS_H
