#ifndef T100TREE_H
#define T100TREE_H

#include <vector>
#include "base/T100Object.h"

namespace T100LIBRARY{

#define     T100TREE_VECTOR             std::vector<T100Tree*>

class T100Tree : public T100Object
{
    public:
        T100Tree();
        T100Tree(T100Tree*, const T100WSTRING& = L"");
        virtual ~T100Tree();

        virtual T100VOID            Create(T100Tree*, const T100WSTRING& = L"");
        virtual T100VOID            Destroy();

        T100VOID                    SetRoot(T100Tree*);
        T100Tree*                   GetRoot();

        T100VOID                    SetParent(T100Tree*);
        T100Tree*                   GetParent();

        T100TREE_VECTOR&            GetChildren();

        T100VOID                    AppendChild(T100Tree*);
        T100VOID                    RemoveChild(T100Tree*);

    protected:
        T100Tree*                   m_root          = T100NULL;
        T100Tree*                   m_parent        = T100NULL;
        T100TREE_VECTOR             m_children;

    private:
        T100VOID                    init(T100Tree*);
        T100VOID                    uninit();
};

}

#endif // T100TREE_H
