#ifndef T100EXECUTABLENORMALBIGFILE_H
#define T100EXECUTABLENORMALBIGFILE_H

#include "T100ExeFileCommon.h"
#include "T100CodeExecutableFile.h"


class T100ExecutableNormalBigFile : public T100CodeExecutableFile
{
    public:
        T100ExecutableNormalBigFile();
        virtual ~T100ExecutableNormalBigFile();

        T100BOOL            load(T100FileData*);
        //T100BOOL            save(T100STDSTRING);

    protected:

    private:

};

#endif // T100EXECUTABLENORMALBIGFILE_H
