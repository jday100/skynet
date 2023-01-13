#ifndef T100DIAGRAMTRANSDUCERTARGET_H
#define T100DIAGRAMTRANSDUCERTARGET_H

#include "T100String.h"
#include "T100BufferedFileReader.h"
#include "T100BufferedFileWriter.h"
#include "T100TransducerTarget.h"

namespace T100Painter{

class T100DiagramTransducerTarget : public T100Library::T100TransducerTarget
{
    public:
        T100DiagramTransducerTarget(T100Library::T100BufferedFileReader*);
        T100DiagramTransducerTarget(T100Library::T100BufferedFileWriter*);
        virtual ~T100DiagramTransducerTarget();

        T100BOOL        setINTEGER(T100INT);
        T100BOOL        getINTEGER(T100INT&);

        T100BOOL        setWORD(T100WORD);
        T100BOOL        getWORD(T100WORD&);

        T100BOOL        setFLOAT(T100FLOAT);
        T100BOOL        getFLOAT(T100FLOAT&);

        T100BOOL        setSTRING(T100STRING&);
        T100BOOL        getSTRING(T100STRING&);

        T100BOOL        reset();
        T100BOOL        eof();

    protected:
        T100Library::T100BufferedFileReader*        m_reader            = T100NULL;
        T100Library::T100BufferedFileWriter*        m_writer            = T100NULL;

    private:
};

}

#endif // T100DIAGRAMTRANSDUCERTARGET_H
