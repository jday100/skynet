#ifndef T100ASSEMBLYHINT_H
#define T100ASSEMBLYHINT_H

#include "T100Hint.h"
#include "T100OrderTypes.h"
#include "T100AssemblyCommon.h"
class T100ByteToken;
class T100CharToken;
class T100StringToken;
class T100KeywordToken;
class T100SentenceToken;
class T100SegmentToken;
class T100PartToken;
class T100Sentence;
class T100Segment;


extern wchar_t*   T100TokenTypeNames[T100TOKEN_MAX+1];

static T100WSTRING      T100ASSEMBLY_HINT_START                         =   L"Assembly is starting...";
static T100WSTRING      T100ASSEMBLY_HINT_STOP                          =   L"Assembly is stopped.";

static T100WSTRING      T100BYTESCAN_FILE_OPEN_SUCCESS                  =   L"open file success!";
static T100WSTRING      T100BYTESCAN_FILE_OPEN_FAILURE                  =   L"open file failure!";
static T100WSTRING      T100BYTESCAN_FILE_CLOSE_SUCCESS                 =   L"close file success!";
static T100WSTRING      T100BYTESCAN_FILE_CLOSE_FAILURE                 =   L"close file failure!";
static T100WSTRING      T100BYTESCAN_FILE_READ_EOF                      =   L"read file eof!";
static T100WSTRING      T100BYTESCAN_BYTE_READ_SUCCESS                  =   L"read success!";
static T100WSTRING      T100BYTESCAN_BYTE_READ_FAILURE                  =   L"read failure!";
static T100WSTRING      T100BYTESCAN_BYTE_CLASSIFY_FINISHED             =   L"classify finished!";
//
static T100WSTRING      T100CHARSCAN_CHAR_READ_SUCCESS                  =   L"read success!";
static T100WSTRING      T100CHARSCAN_CHAR_READ_FAILURE                  =   L"read failure!";
static T100WSTRING      T100CHARSCAN_CHAR_CODING_ERROR                  =   L"coding error!";
static T100WSTRING      T100CHARSCAN_CHAR_CLASSIFY_FINISHED             =   L"classify finished!";
//
static T100WSTRING      T100STRINGSCAN_STRING_READ_SUCCESS              =   L"read success!";
static T100WSTRING      T100STRINGSCAN_STRING_READ_FAILURE              =   L"read failure!";
//
static T100WSTRING      T100KEYWORDSCAN_KEYWORD_READ_SUCCESS            =   L"read success!";
static T100WSTRING      T100KEYWORDSCAN_KEYWORD_READ_FAILURE            =   L"read failure!";
//
static T100WSTRING      T100SENTENCESCAN_SENTENCE_READ_SUCCESS          =   L"read success!";
static T100WSTRING      T100SENTENCESCAN_SENTENCE_READ_FAILURE          =   L"read failure!";
static T100WSTRING      T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR          =   L"syntax error!";
//
static T100WSTRING      T100SENTENCE_ADD_SYNTAX_ERROR                   =   L"sentence add syntax error!";
static T100WSTRING      T100SENTENCE_SUB_SYNTAX_ERROR                   =   L"sentence sub syntax error!";
static T100WSTRING      T100SENTENCE_MUL_SYNTAX_ERROR                   =   L"sentence mul syntax error!";
static T100WSTRING      T100SENTENCE_DIV_SYNTAX_ERROR                   =   L"sentence div syntax error!";
//
static T100WSTRING      T100SENTENCE_AND_SYNTAX_ERROR                   =   L"sentence and syntax error!";
static T100WSTRING      T100SENTENCE_OR_SYNTAX_ERROR                    =   L"sentence or syntax error!";
static T100WSTRING      T100SENTENCE_NOT_SYNTAX_ERROR                   =   L"sentence not syntax error!";
static T100WSTRING      T100SENTENCE_XOR_SYNTAX_ERROR                   =   L"sentence xor syntax error!";
//
static T100WSTRING      T100SENTENCE_CMT_SYNTAX_ERROR                   =   L"sentence cmt syntax error!";
static T100WSTRING      T100SENTENCE_DEBUG_SYNTAX_ERROR                 =   L"sentence debug syntax error!";
static T100WSTRING      T100SENTENCE_LOCK_SYNTAX_ERROR                  =   L"sentence lock syntax error!";
static T100WSTRING      T100SENTENCE_UNLOCK_SYNTAX_ERROR                =   L"sentence unlock syntax error!";
static T100WSTRING      T100SENTENCE_NOP_SYNTAX_ERROR                   =   L"sentence nop syntax error!";
static T100WSTRING      T100SENTENCE_HALT_SYNTAX_ERROR                  =   L"sentence halt syntax error!";
//
static T100WSTRING      T100SENTENCE_CALL_SYNTAX_ERROR                  =   L"sentence call syntax error!";
static T100WSTRING      T100SENTENCE_RET_SYNTAX_ERROR                   =   L"sentence ret syntax error!";
static T100WSTRING      T100SENTENCE_INT_SYNTAX_ERROR                   =   L"sentence int syntax error!";
static T100WSTRING      T100SENTENCE_IRET_SYNTAX_ERROR                  =   L"sentence iret syntax error!";
//
static T100WSTRING      T100SENTENCE_JZ_SYNTAX_ERROR                    =   L"sentence jz syntax error!";
static T100WSTRING      T100SENTENCE_JNZ_SYNTAX_ERROR                   =   L"sentence jnz syntax error!";
static T100WSTRING      T100SENTENCE_JUMP_SYNTAX_ERROR                  =   L"sentence jump syntax error!";
static T100WSTRING      T100SENTENCE_LOOP_SYNTAX_ERROR                  =   L"sentence loop syntax error!";
//
static T100WSTRING      T100SENTENCE_IN_SYNTAX_ERROR                    =   L"sentence in syntax error!";
static T100WSTRING      T100SENTENCE_OUT_SYNTAX_ERROR                   =   L"sentence out syntax error!";
static T100WSTRING      T100SENTENCE_MOVE_SYNTAX_ERROR                  =   L"sentence move syntax error!";
//
static T100WSTRING      T100SENTENCE_CODE_SYNTAX_ERROR                  =   L"sentence code syntax error!";
static T100WSTRING      T100SENTENCE_DATA_SYNTAX_ERROR                  =   L"sentence data syntax error!";
static T100WSTRING      T100SENTENCE_PROCEDURE_SYNTAX_ERROR             =   L"sentence procedure syntax error!";
static T100WSTRING      T100SENTENCE_END_SYNTAX_ERROR                   =   L"sentence end syntax error!";
static T100WSTRING      T100SENTENCE_IMPORT_SYNTAX_ERROR                =   L"sentence import syntax error!";
static T100WSTRING      T100SENTENCE_LABEL_SYNTAX_ERROR                 =   L"sentence label syntax error!";
static T100WSTRING      T100SENTENCE_MODE_SYNTAX_ERROR                  =   L"sentence mode syntax error!";
static T100WSTRING      T100SENTENCE_VARIABLE_SYNTAX_ERROR              =   L"sentence variable syntax error!";
//
static T100WSTRING      T100FILESCAN_IMPORT_FILE                        =   L"import file!";
//
static T100WSTRING      T100BUILD_MARGER_SUCCESS                        =   L"marger success!";
static T100WSTRING      T100BUILD_MARGER_FAILURE                        =   L"marger failure!";
static T100WSTRING      T100BUILD_SAVE_SUCCESS                          =   L"save success!";
static T100WSTRING      T100BUILD_SAVE_FAILURE                          =   L"save failure!";
//
static T100WSTRING      T100BUILD_FILE_OPEN_SUCCESS                     =   L"open file success!";
static T100WSTRING      T100BUILD_FILE_OPEN_FAILURE                     =   L"open file failure!";
static T100WSTRING      T100BUILD_FILE_CLOSE_SUCCESS                    =   L"close file success!";
static T100WSTRING      T100BUILD_FILE_CLOSE_FAILURE                    =   L"close file failure!";
//
static T100WSTRING      T100BUILD_FILE_WRITE_HEAD_SUCCESS               =   L"write file head success!";
static T100WSTRING      T100BUILD_FILE_WRITE_HEAD_FAILURE               =   L"write file head failure!";
static T100WSTRING      T100BUILD_FILE_WRITE_DATA_SUCCESS               =   L"write data success!";
static T100WSTRING      T100BUILD_FILE_WRITE_DATA_FAILURE               =   L"write data failure!";
static T100WSTRING      T100BUILD_FILE_WRITE_CODE_SUCCESS               =   L"write code success!";
static T100WSTRING      T100BUILD_FILE_WRITE_CODE_FAILURE               =   L"write code failure!";
static T100WSTRING      T100BUILD_FILE_RELOCATE_CODE_SUCCESS            =   L"relocate code success!";
static T100WSTRING      T100BUILD_FILE_RELOCATE_CODE_FAILURE            =   L"relocate code failure!";
static T100WSTRING      T100BUILD_FILE_RELOCATE_CODE_VARIABLE_NOT_FOUND =   L"relocate code variable not found!";
static T100WSTRING      T100BUILD_FILE_RELOCATE_CODE_LABEL_NOT_FOUND    =   L"relocate code label not found!";
static T100WSTRING      T100BUILD_FILE_RELOCATE_CODE_PROCEDURE_NOT_FOUND=   L"relocate code procedure not found!";
//
static T100WSTRING      T100BUILD_SENTENCE_SUCCESS                      =   L"build sentence success!";
static T100WSTRING      T100BUILD_SENTENCE_FAILURE                      =   L"build sentence failure!";
static T100WSTRING      T100BUILD_SENTENCE_ERROR                        =   L"build sentence error!";
//
static T100WSTRING      T100BUILD_SEGMENT_LENGTH_LIMIT_ERROR            =   L"build segment length limit error!";
static T100WSTRING      T100BUILD_SEGMENT_ERROR                         =   L"build segment error!";
//



class T100AssemblyHint : public T100Hint
{
    friend class T100AsmCmdParser;
    public:
        T100AssemblyHint();
        virtual ~T100AssemblyHint();

        static T100WSTRING        file_hint(T100WSTRING, T100WSTRING);

        static T100WSTRING        byte_hint(T100ByteToken*, T100WSTRING);
        static T100WSTRING        char_hint(T100CharToken*, T100WSTRING);
        static T100WSTRING        string_hint(T100StringToken*, T100WSTRING);
        static T100WSTRING        keyword_hint(T100KeywordToken*, T100WSTRING);
        static T100WSTRING        sentence_hint(T100SentenceToken*, T100WSTRING);
        static T100WSTRING        sentence_hint(T100Sentence*, T100WSTRING);
        static T100WSTRING        segment_hint(T100SegmentToken*, T100WSTRING);
        static T100WSTRING        file_hint(T100PartToken*, T100WSTRING);
        //
        static T100WSTRING        build_hint(T100WORD, T100String, T100WSTRING);
        static T100WSTRING        segment_hint(T100Segment*, T100WSTRING);
        //
        static T100WSTRING        info_hint(T100WSTRING);

        static T100WSTRING        help_hint(T100WSTRING);
        //
        static T100WSTRING        variable_hint(T100WSTRING, T100WSTRING);
        static T100WSTRING        label_hint(T100WSTRING, T100WSTRING);
        static T100WSTRING        procedure_hint(T100WSTRING, T100WSTRING);

    protected:
        //
        static T100WSTRING        token_type_name(T100WORD);

        //
        static T100WSTRING        byte_to_string(T100BYTE);

    private:
        static T100BOOL             m_detail;
};

#endif // T100ASSEMBLYHINT_H
