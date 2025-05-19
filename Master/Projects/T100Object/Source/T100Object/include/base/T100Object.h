#ifndef T100OBJECT_H
#define T100OBJECT_H

#include "base/T100Class.h"

class T100Object : public T100Class
{
    public:
        T100Object();
        T100Object(T100WSTRING);
        virtual ~T100Object();

        virtual T100VOID                        SetLabel(T100WSTRING);
        virtual T100WSTRING                     GetLabel();

    protected:
        T100WSTRING                             m_label;

    private:
};

#endif // T100OBJECT_H
