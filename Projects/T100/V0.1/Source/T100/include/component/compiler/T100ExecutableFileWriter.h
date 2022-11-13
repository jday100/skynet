#ifndef T100EXECUTABLEFILEWRITER_H
#define T100EXECUTABLEFILEWRITER_H

#include "T100FileWriter.h"
#include "T100ExecutableInfo.h"
#include "T100AssemblyCommon.h"
#include "T100Segment.h"

namespace T100Component{

class T100ExecutableFileWriter : public T100Library::T100FileWriter
{
    public:
        T100ExecutableFileWriter(T100STRING);
        virtual ~T100ExecutableFileWriter();

        T100BOOL                        save(T100ExecutableInfo&);

    protected:
        T100BOOL                        write_head();
        T100BOOL                        write_table();
        T100BOOL                        write_code();
        T100BOOL                        write_data();
        T100BOOL                        write_share();

        T100BOOL                        write_table(T100WORD, T100SEGMENT_CODE_VECTOR&);
        T100BOOL                        write_table(T100WORD, T100SEGMENT_DATA_VECTOR&);
        T100BOOL                        write_share_table(T100WORD, T100SEGMENT_CODE_VECTOR&);
        T100BOOL                        write_share_table(T100WORD, T100SEGMENT_DATA_VECTOR&);

        T100BOOL                        write_segment(T100Assembly::T100Segment*);

        T100BOOL                        create_head();

        T100BOOL                        count(T100SEGMENT_CODE_VECTOR&, T100WORD&, T100WORD&);
        T100BOOL                        count(T100SEGMENT_CODE_VECTOR&, T100WORD&, T100WORD&, T100WORD&);
        T100BOOL                        count(T100SEGMENT_DATA_VECTOR&, T100WORD&, T100WORD&);
        T100BOOL                        count(T100SEGMENT_DATA_VECTOR&, T100WORD&, T100WORD&, T100WORD&);

    private:
        T100ExecutableInfo*             m_info          = T100NULL;

        T100EXECUTABLE_FILE_HEAD        m_head;

        T100WORD                        m_offset        = 0;

};

}

#endif // T100EXECUTABLEFILEWRITER_H
