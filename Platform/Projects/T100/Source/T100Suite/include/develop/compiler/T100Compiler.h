#ifndef T100COMPILER_H
#define T100COMPILER_H

#include "T100Common.h"
#include "develop/compiler/parser/T100Parser.h"
#include "develop/compiler/analyzer/T100Analyzer.h"
#include "develop/compiler/generator/T100Generator.h"

class T100Compiler
{
    public:
        T100Compiler();
        virtual ~T100Compiler();

        T100VOID                setParser(T100Parser*);
        T100Parser*             getParser();

        T100VOID                setAnalyzer(T100Analyzer*);
        T100Analyzer*           getAnalyzer();

        T100VOID                setGenerator(T100Generator*);
        T100Generator*          getGenerator();

        T100BOOL                run(T100WString, T100WString);

    protected:

    private:
        T100Parser*             m_parser            = T100NULL;
        T100Analyzer*           m_analyzer          = T100NULL;
        T100Generator*          m_generator         = T100NULL;

};

#endif // T100COMPILER_H
