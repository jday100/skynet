#ifndef T100CODEEXECUTABLEFILE_H
#define T100CODEEXECUTABLEFILE_H

#include "T100CodeFile.h"
#include "T100ExeFileCommon.h"


class T100CodeExecutableFile : public T100CodeFile
{
    public:
        T100CodeExecutableFile();
        virtual ~T100CodeExecutableFile();

        T100BOOL            load(T100STDSTRING);
        T100BOOL            save(T100STDSTRING);

        T100BOOL            setData(T100FileData*);

    protected:
        T100BOOL            write_head();
        T100BOOL            write_table();
        T100BOOL            write_code();
        T100BOOL            write_data();
        T100BOOL            write_share();

        T100BOOL            write_table(T100WORD, T100SEGMENTDATA_VECTOR&);
        T100BOOL            write_share_table(T100WORD, T100SEGMENTDATA_VECTOR&);

        T100BOOL            write_segment(T100Segment*);

    private:
        T100FileData*       m_data      = T100NULL;
        std::ofstream*      m_ofs       = T100NULL;
        T100WORD            m_offset    = 0;

        T100EXECUTABLE_FILE_HEAD        m_head;

        T100BOOL            create_head(T100FileData*, T100EXECUTABLE_FILE_HEAD&);

};

#endif // T100CODEEXECUTABLEFILE_H
