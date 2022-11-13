#ifndef T100SENTENCEIMPORT_H
#define T100SENTENCEIMPORT_H

#include "T100Sentence.h"

namespace T100Assembly{

class T100SentenceImport : public T100Sentence
{
    public:
        T100SentenceImport(T100SentenceScanner*);
        virtual ~T100SentenceImport();

        T100STRING          file;

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:

    private:
};

}

#endif // T100SENTENCEIMPORT_H
