#ifndef T100ELEMENTMODULESOURCE_H
#define T100ELEMENTMODULESOURCE_H

#include "T100ElementSourceBase.h"
#include "T100ElementModule.h"

namespace T100Painter{

class T100ElementModuleSource : public T100ElementSourceBase
{
    public:
        T100ElementModuleSource(T100ElementModule*);
        virtual ~T100ElementModuleSource();

        T100BOOL        serialize();
        T100BOOL        deserialize();

    protected:

    private:
        T100ElementModule*      m_element           = T100NULL;

};

}

#endif // T100ELEMENTMODULESOURCE_H
