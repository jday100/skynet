#ifndef T100ELEMENTRECTANGLESOURCE_H
#define T100ELEMENTRECTANGLESOURCE_H

#include "T100ElementSourceBase.h"
#include "T100ElementRectangle.h"

namespace T100Painter{

class T100ElementRectangleSource : public T100ElementSourceBase
{
    public:
        T100ElementRectangleSource(T100ElementRectangle*);
        virtual ~T100ElementRectangleSource();

        T100BOOL            serialize();
        T100BOOL            deserialize();

    protected:

    private:
        T100ElementRectangle*       m_element           = T100NULL;

};

}

#endif // T100ELEMENTRECTANGLESOURCE_H
