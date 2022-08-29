#ifndef T100SENTENCELABEL_H
#define T100SENTENCELABEL_H

#include "T100Sentence.h"


class T100SentenceLabel : public T100Sentence
{
    public:
        T100SentenceLabel(T100SentenceScanner*);
        virtual ~T100SentenceLabel();

        T100String          name;

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:

    private:
};

#endif // T100SENTENCELABEL_H
