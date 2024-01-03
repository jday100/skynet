#ifndef T100FILEANALYZER_H
#define T100FILEANALYZER_H

#include "T100CmdLine.h"


class T100FileAnalyzer
{
    public:
        T100FileAnalyzer();
        virtual ~T100FileAnalyzer();

        int run(T100CmdLine&);

    protected:
        int load(char*);

    private:
};

#endif // T100FILEANALYZER_H
