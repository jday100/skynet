#ifndef T100ELEMENTTRANSDUCERTARGET_H
#define T100ELEMENTTRANSDUCERTARGET_H

#include "T100BufferedFileReader.h"
#include "T100BufferedFileWriter.h"
#include "T100TransducerTarget.h"

namespace T100Painter{

class T100ElementTransducerTarget : public T100Library::T100TransducerTarget
{
    public:
        T100ElementTransducerTarget(T100Library::T100BufferedFileWriter*);
        virtual ~T100ElementTransducerTarget();

        T100BOOL        setWORD(T100WORD);
        T100BOOL        setFLOAT(T100FLOAT);

    protected:

    private:
        T100Library::T100BufferedFileWriter*        m_writer            = T100NULL;

};

}

#endif // T100ELEMENTTRANSDUCERTARGET_H
