#ifndef T100FILEH3DDECODER_H
#define T100FILEH3DDECODER_H

#include "T100FileH3D.h"

class T100FileH3DDecoder
{
    public:
        T100FileH3DDecoder();
        virtual ~T100FileH3DDecoder();

        T100VOID            Decode(T100FileH3D*);

    protected:

    private:
};

#endif // T100FILEH3DDECODER_H
