#ifndef T100FILETOOLS_H
#define T100FILETOOLS_H

#include "T100Common.h"
#include "T100File.h"

class T100FileTools
{
    public:
        T100FileTools();
        virtual ~T100FileTools();

        static T100FILE_DATA        ReadBinaryFile(T100WSTRING);

        static std::wstring         GetBasePath(const std::wstring&);

        static std::string          GetFileExtension(const std::string& filePath);
        static std::wstring         GetFileExtension(const std::wstring& filePath);

    protected:

    private:
};

#endif // T100FILETOOLS_H
