#ifndef T100OBJECT_H
#define T100OBJECT_H

#include "T100Class.h"

class T100Object : public T100Class
{
    public:
        T100Object();
        virtual ~T100Object();

        virtual T100VOID                SetLabel(const T100WSTRING&);
        virtual const T100WSTRING&      GetLabel();

    protected:
        T100WSTRING                     m_label;

    private:
};

#endif // T100OBJECT_H
