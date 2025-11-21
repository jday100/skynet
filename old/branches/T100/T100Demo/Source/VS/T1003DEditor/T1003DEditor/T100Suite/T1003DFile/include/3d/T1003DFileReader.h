#ifndef T1003DFILEREADER_H
#define T1003DFILEREADER_H

#include <fstream>
#include "T100Common.h"
#include "T100FileCommon.h"
#include "3d/T1003DFile3DF.h"

class T1003DFileReader
{
    public:
        T1003DFileReader(T100WSTRING, T1003DFILE_TYPE = T1003DFILE_3DF);
        virtual ~T1003DFileReader();

        friend std::ifstream& operator>>(T1003DFileReader&, JSON&);
        friend std::ifstream& operator>>(T1003DFileReader&, T1003DFile3DF&);

    protected:
        T100WSTRING                     m_filename;
        T1003DFILE_TYPE                 m_type;

    private:
        std::ifstream*                  m_ifstream          = T100NULL;

        T100VOID                        init();
        T100VOID                        uninit();
};

#endif // T1003DFILEREADER_H
