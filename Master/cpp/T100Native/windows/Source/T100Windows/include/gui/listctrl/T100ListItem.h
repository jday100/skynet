#ifndef T100LISTITEM_H
#define T100LISTITEM_H

#include "base/T100Class.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

class T100ListView;

class T100ListItem : public T100Class
{
    public:
        T100ListItem(const T100WSTRING&);
        T100ListItem(T100ListView*, const T100WSTRING&);
        virtual ~T100ListItem();

        virtual T100VOID            Create(T100ListView*);
        virtual T100VOID            Destroy();

    protected:

    private:
        T100VOID                    init(T100ListView*);
        T100VOID                    uninit();
};

}

#endif // T100LISTITEM_H
