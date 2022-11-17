#ifndef T100ASSEMBLYHINT_H
#define T100ASSEMBLYHINT_H

#include "T100Hint.h"
#include "T100String.h"

namespace T100Assembly{
class T100ByteToken;
class T100CharToken;
class T100StringToken;
class T100KeywordToken;
class T100SentenceToken;
class T100SegmentToken;
class T100PartToken;
class T100Sentence;

static T100WSTRING      T100ASSEMBLY_HINT_START                             =   L"Assembly is starting ... ";
static T100WSTRING      T100ASSEMBLY_HINT_STOP                              =   L"Assembly is stopped . ";

static T100WSTRING      T100BYTESCANNER_FILE_OPEN_SUCCESS                   =   L"open file success!";
static T100WSTRING      T100BYTESCANNER_FILE_OPEN_FAILURE                   =   L"open file failure!";
static T100WSTRING      T100BYTESCANNER_FILE_CLOSE_SUCCESS                  =   L"close file success!";
static T100WSTRING      T100BYTESCANNER_FILE_CLOSE_FAILURE                  =   L"close file failure!";

static T100WSTRING      T100BYTESCANNER_BYTE_READ_EOF                       =   L"read file eof!";
static T100WSTRING      T100BYTESCANNER_BYTE_READ_SUCCESS                   =   L"read file success!";
static T100WSTRING      T100BYTESCANNER_BYTE_READ_FAILURE                   =   L"read file failure!";
static T100WSTRING      T100BYTESCANNER_BYTE_CLASSIFY_FINISHED              =   L"byte scanner classify finished!";

static T100WSTRING      T100CHARSCANNER_CHAR_CODING_ERROR                   =   L"coding error!";
static T100WSTRING      T100CHARSCANNER_CHAR_CLASSIFY_FINISHED              =   L"char scanner classify finished!";

static T100WSTRING      T100SENTENCESCANNER_SENTENCE_SYNTX_ERROR            =   L"sentence scanner syntax error!";

static T100WSTRING      T100SENTENCE_ADD_SYNTX_ERROR                        =   L"sentence ADD syntax error!";
static T100WSTRING      T100SENTENCE_SUB_SYNTX_ERROR                        =   L"sentence SUB syntax error!";
static T100WSTRING      T100SENTENCE_MUL_SYNTX_ERROR                        =   L"sentence MUL syntax error!";
static T100WSTRING      T100SENTENCE_DIV_SYNTX_ERROR                        =   L"sentence DIV syntax error!";

static T100WSTRING      T100SENTENCE_AND_SYNTX_ERROR                        =   L"sentence AND syntax error!";
static T100WSTRING      T100SENTENCE_OR_SYNTX_ERROR                         =   L"sentence OR syntax error!";
static T100WSTRING      T100SENTENCE_NOT_SYNTX_ERROR                        =   L"sentence NOT syntax error!";
static T100WSTRING      T100SENTENCE_XOR_SYNTX_ERROR                        =   L"sentence XOR syntax error!";

static T100WSTRING      T100SENTENCE_CMT_SYNTX_ERROR                        =   L"sentence CMT syntax error!";
static T100WSTRING      T100SENTENCE_DEBUG_SYNTX_ERROR                      =   L"sentence DEBUG syntax error!";
static T100WSTRING      T100SENTENCE_LOCK_SYNTX_ERROR                       =   L"sentence LOCK syntax error!";
static T100WSTRING      T100SENTENCE_UNLOCK_SYNTX_ERROR                     =   L"sentence UNLOCK syntax error!";
static T100WSTRING      T100SENTENCE_NOP_SYNTX_ERROR                        =   L"sentence NOP syntax error!";
static T100WSTRING      T100SENTENCE_HALT_SYNTX_ERROR                       =   L"sentence HALT syntax error!";

static T100WSTRING      T100SENTENCE_CALL_SYNTX_ERROR                       =   L"sentence CALL syntax error!";
static T100WSTRING      T100SENTENCE_RET_SYNTX_ERROR                        =   L"sentence RET syntax error!";
static T100WSTRING      T100SENTENCE_INT_SYNTX_ERROR                        =   L"sentence INT syntax error!";
static T100WSTRING      T100SENTENCE_IRET_SYNTX_ERROR                       =   L"sentence IRET syntax error!";

static T100WSTRING      T100SENTENCE_JZ_SYNTX_ERROR                         =   L"sentence JZ syntax error!";
static T100WSTRING      T100SENTENCE_JNZ_SYNTX_ERROR                        =   L"sentence JNZ syntax error!";
static T100WSTRING      T100SENTENCE_JUMP_SYNTX_ERROR                       =   L"sentence JUMP syntax error!";
static T100WSTRING      T100SENTENCE_LOOP_SYNTX_ERROR                       =   L"sentence LOOP syntax error!";

static T100WSTRING      T100SENTENCE_IN_SYNTX_ERROR                         =   L"sentence IN syntax error!";
static T100WSTRING      T100SENTENCE_OUT_SYNTX_ERROR                        =   L"sentence OUT syntax error!";
static T100WSTRING      T100SENTENCE_MOVE_SYNTX_ERROR                       =   L"sentence MOVE syntax error!";

static T100WSTRING      T100SENTENCE_CODE_SYNTX_ERROR                       =   L"sentence CODE syntax error!";
static T100WSTRING      T100SENTENCE_DATA_SYNTX_ERROR                       =   L"sentence DATA syntax error!";
static T100WSTRING      T100SENTENCE_PROCEDURE_SYNTX_ERROR                  =   L"sentence PROCEDURE syntax error!";
static T100WSTRING      T100SENTENCE_END_SYNTX_ERROR                        =   L"sentence END syntax error!";

static T100WSTRING      T100SENTENCE_IMPORT_SYNTX_ERROR                     =   L"sentence IMPORT syntax error!";
static T100WSTRING      T100SENTENCE_MODE_SYNTX_ERROR                       =   L"sentence MODE syntax error!";
static T100WSTRING      T100SENTENCE_LABEL_SYNTX_ERROR                      =   L"sentence LABEL syntax error!";
static T100WSTRING      T100SENTENCE_VARIABLE_SYNTX_ERROR                   =   L"sentence variable syntax error!";

static T100WSTRING      T100PARTSCANNER_IMPORT_FILE                         =   L"part scanner import file!";
//
static T100WSTRING      T100BUILD_MARGER_SUCCESS                            =   L"marger success!";
static T100WSTRING      T100BUILD_MARGER_FAILURE                            =   L"marger failure!";
static T100WSTRING      T100BUILD_SAVE_SUCCESS                              =   L"save success!";
static T100WSTRING      T100BUILD_SAVE_FAILURE                              =   L"save failure!";

static T100WSTRING      T100BUILD_FILE_OPEN_SUCCESS                         =   L"open file success!";
static T100WSTRING      T100BUILD_FILE_OPEN_FAILURE                         =   L"open file failure!";
static T100WSTRING      T100BUILD_FILE_CLOSE_SUCCESS                        =   L"close file success!";
static T100WSTRING      T100BUILD_FILE_CLOSE_FAILURE                        =   L"close file failure!";

static T100WSTRING      T100BUILD_SENTENCE_SUCCESS                          =   L"build sentence success!";
static T100WSTRING      T100BUILD_SENTENCE_FAILURE                          =   L"build sentence failure!";
static T100WSTRING      T100BUILD_SENTENCE_ERROR                            =   L"build sentence error!";

static T100WSTRING      T100BUILD_SEGMENT_LENGTH_LIMIT_ERROR                =   L"build segment length limit error!";
static T100WSTRING      T100BUILD_SEGMENT_ERROR                             =   L"build segment error!";


class T100AssemblyHint : public T100Library::T100Hint
{
    public:
        T100AssemblyHint();
        virtual ~T100AssemblyHint();

        static T100WSTRING      file_hint(T100WSTRING, T100WSTRING);

        static T100WSTRING      byte_hint(T100ByteToken*, T100WSTRING);
        static T100WSTRING      char_hint(T100CharToken*, T100WSTRING);
        static T100WSTRING      string_hint(T100StringToken*, T100WSTRING);
        static T100WSTRING      keyword_hint(T100KeywordToken*, T100WSTRING);
        static T100WSTRING      sentence_hint(T100SentenceToken*, T100WSTRING);
        static T100WSTRING      segment_hint(T100SegmentToken*, T100WSTRING);
        static T100WSTRING      part_hint(T100PartToken*, T100WSTRING);

        static T100WSTRING      build_hint(T100WORD, T100WSTRING, T100WSTRING);

        static T100WSTRING      variable_hint(T100WSTRING, T100WSTRING);
        static T100WSTRING      label_hint(T100WSTRING, T100WSTRING);
        static T100WSTRING      procedure_hint(T100WSTRING, T100WSTRING);

    protected:

    private:
        static T100BOOL         m_detail;

};

}

#endif // T100ASSEMBLYHINT_H
