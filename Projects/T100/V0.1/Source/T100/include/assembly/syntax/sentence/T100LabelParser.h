#ifndef T100LABELPARSER_H
#define T100LABELPARSER_H

#include "T100SentenceCommon.h"
#include "T100ParserBase.h"

namespace T100SentenceBase{

class T100LabelParser : public T100ParserBase
{
    public:
        T100LabelParser(T100SentenceBase*);
        virtual ~T100LabelParser();

        T100BOOL            parse(T100OPERATOR&);

    protected:

    private:
};

}

#endif // T100LABELPARSER_H
