#ifndef T100DIAGRAMTRANSDUCERTARGET_H
#define T100DIAGRAMTRANSDUCERTARGET_H

#include "T100BufferedFileReader.h"
#include "T100BufferedFileWriter.h"
#include "T100TransducerTarget.h"

class T100DiagramTransducerTarget : public T100TransducerTarget
{
    public:
        T100DiagramTransducerTarget(T100BufferedFileReader*);
        T100DiagramTransducerTarget(T100BufferedFileWriter*);
        virtual ~T100DiagramTransducerTarget();

        T100BOOL            SetUINT(T100UINT);
        T100BOOL            GetUINT(T100UINT&);

        T100BOOL            SetINTEGER(T100INT);
        T100BOOL            GetINTEGER(T100INT&);

        T100BOOL            SetFLOAT(T100FLOAT);
        T100BOOL            GetFLOAT(T100FLOAT&);

        T100BOOL            SetSTRING(T100WSTRING&);
        T100BOOL            GetSTRING(T100WSTRING&);

        T100BOOL            Reset();
        T100BOOL            Eof();

    protected:
        T100BufferedFileReader*         m_reader        = T100NULL;
        T100BufferedFileWriter*         m_writer        = T100NULL;

    private:
};

#endif // T100DIAGRAMTRANSDUCERTARGET_H
