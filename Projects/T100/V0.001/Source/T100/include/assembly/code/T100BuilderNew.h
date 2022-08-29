#ifndef T100BUILDERNEW_H
#define T100BUILDERNEW_H

#include "T100AsmCommon.h"
#include "T100FileToken.h"
#include "T100CodeBuilder.h"


class T100Builder
{
    friend class T100Editor;
    public:
        T100Builder();
        virtual ~T100Builder();

        T100BOOL                    add(T100STDSTRING);

        T100BOOL                    run(T100STDSTRING, T100STDSTRING);

        T100BOOL                    clear();

    protected:
        static T100FILE_HASH        m_file_hash;
        static T100FILE_LIST        m_file_list;

        T100BOOL                    parse(T100STDSTRING);

        T100BOOL                    build();

        T100BOOL                    search(T100STDSTRING, T100STDSTRING&);
        T100BOOL                    load(T100String, T100BOOL);
        T100BOOL                    append(T100FileToken&, T100BOOL);
        T100BOOL                    find(T100String);

    private:
        T100STDSTRING               m_root;
        T100STDSTRING_VECTOR        m_imports;
        T100CodeBuilder*            m_builder           = T100NULL;

};

#endif // T100BUILDERNEW_H
