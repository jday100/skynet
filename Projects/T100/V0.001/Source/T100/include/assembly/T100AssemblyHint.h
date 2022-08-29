#ifndef T100ASSEMBLYHINT_H
#define T100ASSEMBLYHINT_H

#include "T100Hint.h"
#include "T100OrderTypes.h"
#include "T100TokenTypes.h"
class T100ByteToken;
class T100CharToken;
class T100StringToken;
class T100KeywordToken;
class T100SentenceToken;
class T100SegmentToken;
class T100FileToken;
class T100Sentence;
class T100Segment;


extern char*   T100TokenTypeNames[T100TOKEN_MAX+1];

static std::string      T100ASSEMBLY_HINT_START                         =   "Assembly is starting...";
static std::string      T100ASSEMBLY_HINT_STOP                          =   "Assembly is stopped.";

static std::string      T100BYTESCAN_FILE_OPEN_SUCCESS                  =   "open file success!";
static std::string      T100BYTESCAN_FILE_OPEN_FAILURE                  =   "open file failure!";
static std::string      T100BYTESCAN_FILE_CLOSE_SUCCESS                 =   "close file success!";
static std::string      T100BYTESCAN_FILE_CLOSE_FAILURE                 =   "close file failure!";
static std::string      T100BYTESCAN_FILE_READ_EOF                      =   "read file eof!";
static std::string      T100BYTESCAN_BYTE_READ_SUCCESS                  =   "read success!";
static std::string      T100BYTESCAN_BYTE_READ_FAILURE                  =   "read failure!";
static std::string      T100BYTESCAN_BYTE_CLASSIFY_FINISHED             =   "classify finished!";
//
static std::string      T100CHARSCAN_CHAR_READ_SUCCESS                  =   "read success!";
static std::string      T100CHARSCAN_CHAR_READ_FAILURE                  =   "read failure!";
static std::string      T100CHARSCAN_CHAR_CODING_ERROR                  =   "coding error!";
static std::string      T100CHARSCAN_CHAR_CLASSIFY_FINISHED             =   "classify finished!";
//
static std::string      T100STRINGSCAN_STRING_READ_SUCCESS              =   "read success!";
static std::string      T100STRINGSCAN_STRING_READ_FAILURE              =   "read failure!";
//
static std::string      T100KEYWORDSCAN_KEYWORD_READ_SUCCESS            =   "read success!";
static std::string      T100KEYWORDSCAN_KEYWORD_READ_FAILURE            =   "read failure!";
//
static std::string      T100SENTENCESCAN_SENTENCE_READ_SUCCESS          =   "read success!";
static std::string      T100SENTENCESCAN_SENTENCE_READ_FAILURE          =   "read failure!";
static std::string      T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR          =   "syntax error!";
//
static std::string      T100SENTENCE_ADD_SYNTAX_ERROR                   =   "sentence add syntax error!";
static std::string      T100SENTENCE_SUB_SYNTAX_ERROR                   =   "sentence sub syntax error!";
static std::string      T100SENTENCE_MUL_SYNTAX_ERROR                   =   "sentence mul syntax error!";
static std::string      T100SENTENCE_DIV_SYNTAX_ERROR                   =   "sentence div syntax error!";
//
static std::string      T100SENTENCE_AND_SYNTAX_ERROR                   =   "sentence and syntax error!";
static std::string      T100SENTENCE_OR_SYNTAX_ERROR                    =   "sentence or syntax error!";
static std::string      T100SENTENCE_NOT_SYNTAX_ERROR                   =   "sentence not syntax error!";
static std::string      T100SENTENCE_XOR_SYNTAX_ERROR                   =   "sentence xor syntax error!";
//
static std::string      T100SENTENCE_CMT_SYNTAX_ERROR                   =   "sentence cmt syntax error!";
static std::string      T100SENTENCE_DEBUG_SYNTAX_ERROR                 =   "sentence debug syntax error!";
static std::string      T100SENTENCE_LOCK_SYNTAX_ERROR                  =   "sentence lock syntax error!";
static std::string      T100SENTENCE_UNLOCK_SYNTAX_ERROR                =   "sentence unlock syntax error!";
static std::string      T100SENTENCE_NOP_SYNTAX_ERROR                   =   "sentence nop syntax error!";
static std::string      T100SENTENCE_HALT_SYNTAX_ERROR                  =   "sentence halt syntax error!";
//
static std::string      T100SENTENCE_CALL_SYNTAX_ERROR                  =   "sentence call syntax error!";
static std::string      T100SENTENCE_RET_SYNTAX_ERROR                   =   "sentence ret syntax error!";
static std::string      T100SENTENCE_INT_SYNTAX_ERROR                   =   "sentence int syntax error!";
static std::string      T100SENTENCE_IRET_SYNTAX_ERROR                  =   "sentence iret syntax error!";
//
static std::string      T100SENTENCE_JZ_SYNTAX_ERROR                    =   "sentence jz syntax error!";
static std::string      T100SENTENCE_JNZ_SYNTAX_ERROR                   =   "sentence jnz syntax error!";
static std::string      T100SENTENCE_JUMP_SYNTAX_ERROR                  =   "sentence jump syntax error!";
static std::string      T100SENTENCE_LOOP_SYNTAX_ERROR                  =   "sentence loop syntax error!";
//
static std::string      T100SENTENCE_IN_SYNTAX_ERROR                    =   "sentence in syntax error!";
static std::string      T100SENTENCE_OUT_SYNTAX_ERROR                   =   "sentence out syntax error!";
static std::string      T100SENTENCE_MOVE_SYNTAX_ERROR                  =   "sentence move syntax error!";
//
static std::string      T100SENTENCE_CODE_SYNTAX_ERROR                  =   "sentence code syntax error!";
static std::string      T100SENTENCE_DATA_SYNTAX_ERROR                  =   "sentence data syntax error!";
static std::string      T100SENTENCE_PROCEDURE_SYNTAX_ERROR             =   "sentence procedure syntax error!";
static std::string      T100SENTENCE_END_SYNTAX_ERROR                   =   "sentence end syntax error!";
static std::string      T100SENTENCE_IMPORT_SYNTAX_ERROR                =   "sentence import syntax error!";
static std::string      T100SENTENCE_LABEL_SYNTAX_ERROR                 =   "sentence label syntax error!";
static std::string      T100SENTENCE_MODE_SYNTAX_ERROR                  =   "sentence mode syntax error!";
static std::string      T100SENTENCE_VARIABLE_SYNTAX_ERROR              =   "sentence variable syntax error!";
//
static std::string      T100FILESCAN_IMPORT_FILE                        =   "import file!";
//
static std::string      T100BUILD_MARGER_SUCCESS                        =   "marger success!";
static std::string      T100BUILD_MARGER_FAILURE                        =   "marger failure!";
static std::string      T100BUILD_SAVE_SUCCESS                          =   "save success!";
static std::string      T100BUILD_SAVE_FAILURE                          =   "save failure!";
//
static std::string      T100BUILD_FILE_OPEN_SUCCESS                     =   "open file success!";
static std::string      T100BUILD_FILE_OPEN_FAILURE                     =   "open file failure!";
static std::string      T100BUILD_FILE_CLOSE_SUCCESS                    =   "close file success!";
static std::string      T100BUILD_FILE_CLOSE_FAILURE                    =   "close file failure!";
//
static std::string      T100BUILD_FILE_WRITE_HEAD_SUCCESS               =   "write file head success!";
static std::string      T100BUILD_FILE_WRITE_HEAD_FAILURE               =   "write file head failure!";
static std::string      T100BUILD_FILE_WRITE_DATA_SUCCESS               =   "write data success!";
static std::string      T100BUILD_FILE_WRITE_DATA_FAILURE               =   "write data failure!";
static std::string      T100BUILD_FILE_WRITE_CODE_SUCCESS               =   "write code success!";
static std::string      T100BUILD_FILE_WRITE_CODE_FAILURE               =   "write code failure!";
static std::string      T100BUILD_FILE_RELOCATE_CODE_SUCCESS            =   "relocate code success!";
static std::string      T100BUILD_FILE_RELOCATE_CODE_FAILURE            =   "relocate code failure!";
static std::string      T100BUILD_FILE_RELOCATE_CODE_VARIABLE_NOT_FOUND =   "relocate code variable not found!";
static std::string      T100BUILD_FILE_RELOCATE_CODE_LABEL_NOT_FOUND    =   "relocate code label not found!";
static std::string      T100BUILD_FILE_RELOCATE_CODE_PROCEDURE_NOT_FOUND=   "relocate code procedure not found!";
//
static std::string      T100BUILD_SENTENCE_SUCCESS                      =   "build sentence success!";
static std::string      T100BUILD_SENTENCE_FAILURE                      =   "build sentence failure!";
static std::string      T100BUILD_SENTENCE_ERROR                        =   "build sentence error!";
//
static std::string      T100BUILD_SEGMENT_LENGTH_LIMIT_ERROR            =   "build segment length limit error!";
static std::string      T100BUILD_SEGMENT_ERROR                         =   "build segment error!";
//



class T100AssemblyHint : public T100Hint
{
    friend class T100AsmCmdParser;
    public:
        T100AssemblyHint();
        virtual ~T100AssemblyHint();

        static T100STDSTRING        file_hint(T100STDSTRING, T100STDSTRING);

        static T100STDSTRING        byte_hint(T100ByteToken*, T100STDSTRING);
        static T100STDSTRING        char_hint(T100CharToken*, T100STDSTRING);
        static T100STDSTRING        string_hint(T100StringToken*, T100STDSTRING);
        static T100STDSTRING        keyword_hint(T100KeywordToken*, T100STDSTRING);
        static T100STDSTRING        sentence_hint(T100SentenceToken*, T100STDSTRING);
        static T100STDSTRING        sentence_hint(T100Sentence*, T100STDSTRING);
        static T100STDSTRING        segment_hint(T100SegmentToken*, T100STDSTRING);
        static T100STDSTRING        file_hint(T100FileToken*, T100STDSTRING);
        //
        static T100STDSTRING        build_hint(T100WORD, T100String, T100STDSTRING);
        static T100STDSTRING        segment_hint(T100Segment*, T100STDSTRING);
        //
        static T100STDSTRING        info_hint(T100STDSTRING);

        static T100STDSTRING        help_hint(T100STDSTRING);
        //
        static T100STDSTRING        variable_hint(T100STDSTRING, T100STDSTRING);
        static T100STDSTRING        label_hint(T100STDSTRING, T100STDSTRING);
        static T100STDSTRING        procedure_hint(T100STDSTRING, T100STDSTRING);

    protected:
        //
        static T100STDSTRING        token_type_name(T100WORD);

        //
        static T100STDSTRING        byte_to_string(T100BYTE);

    private:
        static T100BOOL             m_detail;
};

#endif // T100ASSEMBLYHINT_H
