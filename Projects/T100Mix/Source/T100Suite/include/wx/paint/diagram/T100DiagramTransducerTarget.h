#ifndef T100DIAGRAMTRANSDUCERTARGET_H
#define T100DIAGRAMTRANSDUCERTARGET_H

#include "fs\file\T100FileBufferedReader.h"
#include "base\T100TransducerTarget.h"

class T100DiagramTransducerTarget : public T100TransducerTarget
{
    public:
        T100DiagramTransducerTarget(T100FileBufferedReader*);
        virtual ~T100DiagramTransducerTarget();

    protected:

    private:
};

#endif // T100DIAGRAMTRANSDUCERTARGET_H
