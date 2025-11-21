#ifndef T100TEXTURE_H
#define T100TEXTURE_H

#include <vector>
#include "T100Common.h"

class T100DX12Texture;

#define     T100TEXTURE_VECTOR          std::vector<T100Texture*>

class T100Texture
{
    public:
        T100Texture();
        virtual ~T100Texture();

        T100WSTRING         Name;

    protected:

    private:
};

#endif // T100TEXTURE_H
