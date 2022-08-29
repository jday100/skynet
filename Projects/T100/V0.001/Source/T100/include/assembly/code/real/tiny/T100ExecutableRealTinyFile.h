#ifndef T100EXECUTABLEREALTINYFILE_H
#define T100EXECUTABLEREALTINYFILE_H

#include "T100CodeFile.h"


class T100ExecutableRealTinyFile : public T100CodeFile
{
    public:
        T100ExecutableRealTinyFile();
        virtual ~T100ExecutableRealTinyFile();

        T100BOOL            load(T100FileData*);
        T100BOOL            save(T100STDSTRING);

    protected:
        T100BOOL            write_head();
        T100BOOL            write_data();
        T100BOOL            write_code();

    private:
        T100FileData*       m_file;
        T100SegmentCode*    m_code;
        T100SegmentData*    m_data;

        std::ofstream*      m_ofs;

};

#endif // T100EXECUTABLEREALTINYFILE_H
