#ifndef T100DIAGRAMTRANSDUCERTARGET_H
#define T100DIAGRAMTRANSDUCERTARGET_H

#include "T100BufferedFile.h"

class T100DiagramTransducerTarget
{
    public:
        T100DiagramTransducerTarget(T100BufferedFile*);
        virtual ~T100DiagramTransducerTarget();

        T100BOOL                    setINTEGER(T100INT);
        T100BOOL                    getINTEGER(T100INT&);

        T100BOOL                    setWORD(T100WORD);
        T100BOOL                    getWORD(T100WORD&);

        T100BOOL                    setFLOAT(T100FLOAT);
        T100BOOL                    getFLOAT(T100FLOAT&);

        T100BOOL                    eof();

    protected:

    private:
        T100BufferedFile*           m_file          = T100NULL;
};

#endif // T100DIAGRAMTRANSDUCERTARGET_H
