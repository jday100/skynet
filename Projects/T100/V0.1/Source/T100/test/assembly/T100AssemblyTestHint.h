#ifndef T100ASSEMBLYTESTHINT_H
#define T100ASSEMBLYTESTHINT_H

#include "T100Hint.h"

namespace T100Assembly{

static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_BYTE_TEST_START                      = L"Assembly byte scanner test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_BYTE_TEST_STOP                       = L"Assembly byte scanner test is stopped . ";

static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_CHAR_TEST_START                      = L"Assembly char scanner test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_CHAR_TEST_STOP                       = L"Assembly char scanner test is stopped . ";

static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_STRING_TEST_START                    = L"Assembly string scanner test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_STRING_TEST_STOP                     = L"Assembly string scanner test is stopped . ";

static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_SENTENCE_TEST_START                  = L"Assembly sentence scanner test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_SENTENCE_TEST_STOP                   = L"Assembly sentence scanner test is stopped . ";

static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_SEGMENT_TEST_START                   = L"Assembly segment scanner test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_SEGMENT_TEST_STOP                    = L"Assembly segment scanner test is stopped . ";

static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_PART_TEST_START                      = L"Assembly part scanner test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_PART_TEST_STOP                       = L"Assembly part scanner test is stopped . ";


static T100WSTRING          T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_BASIC_TEST_START                = L"Assembly real produce basic test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_BASIC_TEST_STOP                 = L"Assembly real produce basic test is stopped . ";

static T100WSTRING          T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_MULTIPLE_TEST_START             = L"Assembly real produce multiple test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_MULTIPLE_TEST_STOP              = L"Assembly real produce multiple test is stopped . ";

static T100WSTRING          T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_SHARE_TEST_START                = L"Assembly real produce share test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_PRODUCE_REAL_SHARE_TEST_STOP                 = L"Assembly real produce share test is stopped . ";


static T100WSTRING          T100TEST_HINT_ASSEMBLY_PRODUCE_VIRTUAL_BASIC_TEST_START             = L"Assembly virtual produce basic test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_PRODUCE_VIRTUAL_BASIC_TEST_STOP              = L"Assembly virtual produce basic test is stopped . ";

static T100WSTRING          T100TEST_HINT_ASSEMBLY_PRODUCE_VIRTUAL_SHARE_TEST_START             = L"Assembly virtual produce share test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_PRODUCE_VIRTUAL_SHARE_TEST_STOP              = L"Assembly virtual produce share test is stopped . ";



class T100AssemblyTestHint : public T100Library::T100Hint
{
    public:
        T100AssemblyTestHint();
        virtual ~T100AssemblyTestHint();

    protected:

    private:
};

}

#endif // T100ASSEMBLYTESTHINT_H
