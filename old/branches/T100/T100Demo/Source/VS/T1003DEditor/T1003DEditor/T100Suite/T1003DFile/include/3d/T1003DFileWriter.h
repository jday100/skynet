#ifndef T1003DFILEWRITER_H
#define T1003DFILEWRITER_H

#include <fstream>
#include "T100Common.h"
#include "T100FileCommon.h"
#include "3d/T1003DFile3DF.h"

class T1003DFileWriter
{
    public:
        T1003DFileWriter(T100WSTRING, T1003DFILE_TYPE = T1003DFILE_3DF);
        virtual ~T1003DFileWriter();

        friend std::ofstream& operator<<(T1003DFileWriter&, const JSON&);
        friend std::ofstream& operator<<(T1003DFileWriter&, T1003DFile3DF&);

    protected:
        T100WSTRING                     m_filename;
        T1003DFILE_TYPE                 m_type;

    private:
        std::ofstream*                  m_ofstream          = T100NULL;

        T100VOID                        init();
        T100VOID                        uninit();
};

#endif // T1003DFILEWRITER_H
