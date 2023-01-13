#ifndef T100ELEMENTTRANSDUCERTARGET_H
#define T100ELEMENTTRANSDUCERTARGET_H

#include "T100BufferedFileReader.h"
#include "T100BufferedFileWriter.h"
#include "T100DiagramTransducerTarget.h"

namespace T100Painter{

class T100ElementTransducerTarget : public T100DiagramTransducerTarget
{
    public:
        T100ElementTransducerTarget(T100Library::T100BufferedFileReader*);
        T100ElementTransducerTarget(T100Library::T100BufferedFileWriter*);
        virtual ~T100ElementTransducerTarget();

    protected:

    private:

};

}

#endif // T100ELEMENTTRANSDUCERTARGET_H
