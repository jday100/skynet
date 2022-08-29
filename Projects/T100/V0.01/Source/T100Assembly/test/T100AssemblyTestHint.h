#ifndef T100ASSEMBLYTESTHINT_H
#define T100ASSEMBLYTESTHINT_H


#include "T100Hint.h"

static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_FILE_TEST_START                      = L"Assembly file scanner test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_FILE_TEST_STOP                       = L"Assembly file scanner test is stopped . ";

static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_BUFFER_TEST_START                    = L"Assembly buffer scanner test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_BUFFER_TEST_STOP                     = L"Assembly buffer scanner test is stopped . ";

static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_BYTE_TEST_START                      = L"Assembly byte scanner test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_BYTE_TEST_STOP                       = L"Assembly byte scanner test is stopped . ";

static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_CHAR_TEST_START                      = L"Assembly char scanner test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_CHAR_TEST_STOP                       = L"Assembly char scanner test is stopped . ";

static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_CHAR_UNICODE_TEST_START              = L"Assembly char scanner unicode test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_CHAR_UNICODE_TEST_STOP               = L"Assembly char scanner unicode test is stopped . ";

static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_STRING_TEST_START                    = L"Assembly string scanner test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_STRING_TEST_STOP                     = L"Assembly string scanner test is stopped . ";

static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_KEYWORD_TEST_START                   = L"Assembly keyword scanner test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_KEYWORD_TEST_STOP                    = L"Assembly keyword scanner test is stopped . ";

static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_SENTENCE_TEST_START                  = L"Assembly sentence scanner test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_SENTENCE_TEST_STOP                   = L"Assembly sentence scanner test is stopped . ";

static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_SEGMENT_TEST_START                   = L"Assembly segment scanner test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_SEGMENT_TEST_STOP                    = L"Assembly segment scanner test is stopped . ";

static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_PART_TEST_START                      = L"Assembly part scanner test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_PART_TEST_STOP                       = L"Assembly part scanner test is stopped . ";

static T100WSTRING          T100TEST_HINT_ASSEMBLY_TEST_START                                   = L"Assembly test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_TEST_STOP                                    = L"Assembly test is stopped . ";

static T100WSTRING          T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_TEST_START                      = L"Assembly real produce test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_TEST_STOP                       = L"Assembly real produce test is stopped . ";

static T100WSTRING          T100TEST_HINT_ASSEMBLY_PRODUCE_VIRTUAL_TEST_START                   = L"Assembly virtual produce test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_PRODUCE_VIRTUAL_TEST_STOP                    = L"Assembly virtual produce test is stopped . ";


class T100AssemblyTestHint
{
    public:
        T100AssemblyTestHint();
        virtual ~T100AssemblyTestHint();

    protected:

    private:
};

#endif // T100ASSEMBLYTESTHINT_H
