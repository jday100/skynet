#ifndef T100FILETOKEN_H
#define T100FILETOKEN_H

#include "T100String.h"
#include "T100StringHash.h"
#include "T100Token.h"
#include "T100SegmentToken.h"


#define     T100FILE_VECTOR         std::vector<T100FileToken*>
#define     T100FILE_HASH           std::unordered_map<T100String, T100FileToken*, T100StringHash>
#define     T100FILE_LIST           std::list<T100FileToken*>



class T100FileToken : public T100Token
{
    public:
        T100FileToken();
        virtual ~T100FileToken();

        T100BOOL                master      = T100FALSE;
        T100String              path;
        T100String              file;

        T100VOID                clear();
        T100FileToken*          copy();

        T100STDSTRING           tostring();

        T100SEGMENT_VECTOR      segments;

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
};

#endif // T100FILETOKEN_H
