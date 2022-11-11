#ifndef T100PARTDRAWER_H
#define T100PARTDRAWER_H

#include "T100AssemblyCommon.h"
#include "T100String.h"
#include "T100PartInfo.h"

namespace T100Assembly{

class T100PartDrawer
{
    public:
        T100PartDrawer();
        virtual ~T100PartDrawer();

        static T100BOOL                     existe(T100STRING);

        static T100BOOL                     append(T100STRING&, T100PartInfo*);

        static T100PartInfo*                getPartInfo(T100STRING&);

        static T100PART_INFO_VECTOR&        getPartInfos();

        static T100BOOL                     clear();

        static T100BOOL                     load(T100STRING, T100PartInfo*);
        static T100BOOL                     save(T100STRING, T100PartInfo*);

    protected:
        static T100STRING                   getName(T100STRING);

    private:
        static T100PART_INFO_VECTOR         m_part_vector;
        static T100PART_INFO_HASH           m_part_hash;

};

}

#endif // T100PARTDRAWER_H
