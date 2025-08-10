#ifndef T100TREE_H
#define T100TREE_H

#include "T100Object.h"
#include "T100Vessel.h"

#define     T100TREE_VESSEL                 T100Vessel<T100WSTRING, T100Tree*>

class T100Tree : public T100Object
{
    public:
        T100Tree(T100Tree*, const T100WSTRING&);
        virtual ~T100Tree();

        virtual T100VOID        AppendChild(const T100WSTRING&, T100Tree*);
        virtual T100VOID        RemoveChild(const T100WSTRING&);

    protected:
        T100TREE_VESSEL         m_children;

    private:
};

#endif // T100TREE_H
