#ifndef T100PARTTOKEN_H
#define T100PARTTOKEN_H

#include "T100SegmentToken.h"
#include "T100String.h"
#include "T100StringHash.h"

#define     T100FILE_VECTOR         std::vector<T100PartToken*>
#define     T100FILE_HASH           std::unordered_map<T100String, T100PartToken*, T100StringHash>
#define     T100FILE_LIST           std::list<T100PartToken*>


class T100PartToken : public T100Token
{
    public:
        T100PartToken();
        virtual ~T100PartToken();

        T100BOOL                master          = T100FALSE;
        T100STRING              path;
        T100STRING              file;

        T100SEGMENT_VECTOR      segments;

        T100PartToken*          copy();
        T100VOID                clear();

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
};

#endif // T100PARTTOKEN_H
