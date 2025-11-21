#ifndef T100ELEMENTMODULESOURCE_H
#define T100ELEMENTMODULESOURCE_H

#include "T100ElementModule.h"
#include "T100ElementSourceBase.h"

class T100ElementModuleSource : public T100ElementSourceBase
{
    public:
        T100ElementModuleSource(T100ElementModule*);
        virtual ~T100ElementModuleSource();

        T100BOOL                Serialize();
        T100BOOL                Deserialize();

    protected:
        T100ElementModule*      m_element       = T100NULL;

    private:
};

#endif // T100ELEMENTMODULESOURCE_H
