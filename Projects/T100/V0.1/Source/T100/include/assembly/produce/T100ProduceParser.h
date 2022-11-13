#ifndef T100PRODUCEPARSER_H
#define T100PRODUCEPARSER_H

#include "T100Common.h"
#include "T100ParseInfo.h"
#include "T100PartToken.h"
#include "T100ProduceInfo.h"

namespace T100Assembly{
class T100ClassPathDrawer;


class T100ProduceParser
{
    public:
        T100ProduceParser();
        virtual ~T100ProduceParser();

        T100VOID                    setClassPathDrawer(T100ClassPathDrawer*);
        T100ClassPathDrawer*        getClassPathDrawer();

        T100BOOL                    run(T100STRING&, T100ProduceInfo&);

    protected:
        T100BOOL                    load(T100STRING&, T100BOOL);
        T100BOOL                    scan(T100WSTRING&, T100BOOL);
        T100BOOL                    append(T100PartToken&);

        T100BOOL                    add(T100WSTRING&, T100PartToken&);

        T100BOOL                    search(T100STRING, T100STRING&);

    private:
        T100ProduceInfo*            m_produce           = T100NULL;
        T100ClassPathDrawer*        m_path_drawer       = T100NULL;

};

}

#endif // T100PRODUCEPARSER_H
