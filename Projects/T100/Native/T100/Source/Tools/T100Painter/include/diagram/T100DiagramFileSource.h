#ifndef T100DIAGRAMFILESOURCE_H
#define T100DIAGRAMFILESOURCE_H

#include "T100DiagramInfo.h"
#include "T100ElementBaseSource.h"
#include "T100DiagramTransducerSource.h"

class T100DiagramFileSource : public T100DiagramTransducerSource
{
    public:
        T100DiagramFileSource(T100DiagramInfo*);
        virtual ~T100DiagramFileSource();

        T100BOOL                    serialize();
        T100BOOL                    deserialize();

        T100WORD                    getSign();
        T100WORD                    getType();
        T100WORD                    getVersion();

    protected:
        T100DiagramInfo*            m_diagram           = T100NULL;

        T100ElementBaseSource*      getElementSource(T100WORD);

        T100BOOL                    LoadDiagramFileHead();
        T100BOOL                    LoadElements();
        T100BOOL                    LoadElement(T100ElementBase*&);

        T100BOOL                    SaveDiagramFileHead();
        T100BOOL                    SaveElements();
        T100BOOL                    SaveElement(T100ElementBase*&);

    private:
        T100WORD                    m_sign              = 0;
        T100WORD                    m_type              = 0;
        T100WORD                    m_version           = 0;
};

#endif // T100DIAGRAMFILESOURCE_H
