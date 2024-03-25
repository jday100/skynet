#ifndef T100DIAGRAMTRANSDUCERTARGET_H
#define T100DIAGRAMTRANSDUCERTARGET_H

#include "T100BufferedFile.h"

class T100DiagramTransducerTarget
{
    public:
        T100DiagramTransducerTarget(T100BufferedFile*);
        virtual ~T100DiagramTransducerTarget();

        T100BOOL            setWord(T100WORD);
        T100BOOL            getWord(T100WORD&);

        T100BOOL            eof();

    protected:

    private:
        T100BufferedFile*           m_file          = T100NULL;
};

#endif // T100DIAGRAMTRANSDUCERTARGET_H
