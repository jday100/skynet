#ifndef T100FILESCANNER_H
#define T100FILESCANNER_H

#include "T100File.h"
#include "T100GrammarScanner.h"

class T100FileScanner : public T100GrammarScanner
{
    public:
        T100FileScanner();
        virtual ~T100FileScanner();

        virtual T100BOOL            SetSource(T100File&);
        virtual T100File&           GetSource();

        virtual T100BOOL            Next();

    protected:

    private:
        T100File*                   m_file          = T100NULL;
};

#endif // T100FILESCANNER_H
