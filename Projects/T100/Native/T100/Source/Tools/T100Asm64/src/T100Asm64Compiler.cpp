#include "T100Asm64Compiler.h"

#include "T100Asm64ScannerTools.h"

T100Asm64Compiler::T100Asm64Compiler()
{
    //ctor
}

T100Asm64Compiler::~T100Asm64Compiler()
{
    //dtor
}

T100BOOL T100Asm64Compiler::run(T100STRING file)
{
    T100BOOL                        result;
    T100Asm64SourceToken            token;
    T100Asm64SourceScanner*         scanner         = T100NULL;

    result  = T100Asm64ScannerTools::build(file, scanner);

    if(result){

    }else{

    }

    scanner->next(token);

}
