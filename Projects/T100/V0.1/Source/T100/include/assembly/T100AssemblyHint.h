#ifndef T100ASSEMBLYHINT_H
#define T100ASSEMBLYHINT_H

#include "T100Hint.h"
#include "T100String.h"

namespace T100Assembly{
class T100ByteToken;
class T100Sentence;

static T100WSTRING      T100BYTESCAN_BYTE_READ_SUCCESS                      =   L"read success!";
static T100WSTRING      T100BYTESCAN_BYTE_READ_FAILURE                      =   L"read failure!";
static T100WSTRING      T100BYTESCAN_BYTE_CLASSIFY_FINISHED                 =   L"classify finished!";

static T100WSTRING      T100SENTENCESCAN_SENTENCE_READ_SUCCESS          =   L"read success!";

static T100WSTRING      T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR          =   L"syntax error!";

static T100WSTRING      T100SENTENCE_CODE_SYNTAX_ERROR                  =   L"sentence code syntax error!";

static T100WSTRING      T100SENTENCE_DATA_SYNTAX_ERROR                  =   L"sentence data syntax error!";

static T100WSTRING      T100SENTENCE_PROCEDURE_SYNTAX_ERROR             =   L"sentence procedure syntax error!";
static T100WSTRING      T100SENTENCE_MODE_SYNTAX_ERROR                  =   L"sentence mode syntax error!";

static T100WSTRING      T100SENTENCE_VARIABLE_SYNTAX_ERROR              =   L"sentence variable syntax error!";



class T100AssemblyHint : public T100Library::T100Hint
{
    public:
        T100AssemblyHint();
        virtual ~T100AssemblyHint();

        static T100WSTRING      byte_hint(T100ByteToken*, T100WSTRING&);

        static T100WSTRING      sentence_hint(T100Sentence*, T100WSTRING);

        static T100WSTRING      build_hint(T100WORD, T100STRING, T100WSTRING);

    protected:

    private:
};

}

#endif // T100ASSEMBLYHINT_H
