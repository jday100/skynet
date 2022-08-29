#ifndef T100PARTDRAWER_H
#define T100PARTDRAWER_H

#include "T100AssemblyCommon.h"
#include "T100String.h"
#include "T100PartInfo.h"


class T100PartDrawer
{
    public:
        T100PartDrawer();
        virtual ~T100PartDrawer();

        static T100BOOL                     exists(T100String);

        static T100BOOL                     append(T100String&, T100PartInfo*);

        static T100PART_INFO_VECTOR&        getPartInfos();



        static T100BOOL                     load(T100String, T100PartInfo*);
        static T100BOOL                     save(T100String, T100PartInfo*);

    protected:
        static T100String                   getName(T100String);

    private:
        static T100PART_INFO_VECTOR         m_part_vector;
        static T100PART_INFO_HASH           m_part_hash;

};

#endif // T100PARTDRAWER_H
