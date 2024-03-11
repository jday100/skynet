#include "T100Asm64ScannerTools.h"

#include "T100Asm64LetterScanner.h"
#include "T100Asm64StringScanner.h"
#include "T100Asm64KeywordScanner.h"
#include "T100Asm64SentenceScanner.h"
#include "T100Asm64FunctionScanner.h"


T100Asm64ScannerTools::T100Asm64ScannerTools()
{
    //ctor
}

T100Asm64ScannerTools::~T100Asm64ScannerTools()
{
    //dtor
}

T100BOOL T100Asm64ScannerTools::build(T100STRING file, T100Asm64SourceScanner*& scanner)
{
    T100BOOL            result;

    T100Asm64LetterScanner*         letter_scanner          = T100NULL;
    T100Asm64StringScanner*         string_scanner          = T100NULL;
    T100Asm64KeywordScanner*        keyword_scanner         = T100NULL;
    T100Asm64SentenceScanner*       sentence_scanner        = T100NULL;
    T100Asm64FunctionScanner*       function_scanner        = T100NULL;
    T100Asm64SourceScanner*         source_scanner          = T100NULL;

    letter_scanner      = T100NEW T100Asm64LetterScanner();

    if(letter_scanner){
        result  = letter_scanner->open(file);


    }else{

    }

    string_scanner      = T100NEW T100Asm64StringScanner();

    if(string_scanner){
        string_scanner->setSource(letter_scanner);
    }else{

    }

    keyword_scanner     = T100NEW T100Asm64KeywordScanner();

    if(keyword_scanner){
        keyword_scanner->setSource(string_scanner);
    }else{

    }

    sentence_scanner    = T100NEW T100Asm64SentenceScanner();

    if(sentence_scanner){
        sentence_scanner->setSource(keyword_scanner);
    }else{

    }

    function_scanner    = T100NEW T100Asm64FunctionScanner();

    if(function_scanner){
        function_scanner->setSource(sentence_scanner);
    }else{

    }

    source_scanner      = T100NEW T100Asm64SourceScanner();

    if(source_scanner){
        source_scanner->setSource(function_scanner);

        scanner = source_scanner;
    }else{

    }
}
