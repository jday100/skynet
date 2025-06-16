#ifndef T100OBJECT_H
#define T100OBJECT_H

#include "base/T100Class.h"

namespace T100LIBRARY{

class T100Object : public T100Class
{
    public:
        T100Object();
        virtual ~T100Object();

        T100VOID                SetLabel(const T100WSTRING&);
        const T100WSTRING&      GetLabel();

    protected:
        T100WSTRING             m_label;

    private:
};

}

#endif // T100OBJECT_H
