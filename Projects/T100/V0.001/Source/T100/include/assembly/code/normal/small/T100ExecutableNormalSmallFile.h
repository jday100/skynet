#ifndef T100EXECUTABLENORMALSMALLFILE_H
#define T100EXECUTABLENORMALSMALLFILE_H

#include "T100ExeFileCommon.h"
#include "T100CodeExecutableFile.h"


class T100ExecutableNormalSmallFile : public T100CodeExecutableFile
{
    public:
        T100ExecutableNormalSmallFile();
        virtual ~T100ExecutableNormalSmallFile();

        T100BOOL            load(T100FileData*);

    protected:

    private:
};

#endif // T100EXECUTABLENORMALSMALLFILE_H
