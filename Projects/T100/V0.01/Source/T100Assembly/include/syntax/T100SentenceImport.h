#ifndef T100SENTENCEIMPORT_H
#define T100SENTENCEIMPORT_H

#include "T100Sentence.h"


class T100SentenceImport : public T100Sentence
{
    public:
        T100SentenceImport(T100SentenceScanner*);
        virtual ~T100SentenceImport();

        T100String          file;

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:

    private:
};

#endif // T100SENTENCEIMPORT_H
