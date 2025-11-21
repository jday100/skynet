#include "T100FileTools.h"

#include <fstream>
#include "T100Unicode.h"

T100FileTools::T100FileTools()
{
    //ctor
}

T100FileTools::~T100FileTools()
{
    //dtor
}

T100FILE_DATA T100FileTools::ReadBinaryFile(T100WSTRING file)
{
    T100FILE_DATA       result;

    struct _stat64      fileStat;
    int fileExists  = _wstat64(file.c_str(), &fileStat);

    if(fileExists == -1){
        return result;
    }

    T100STRING      filename;

    filename        = T100Unicode::to_string8(file);
    std::ifstream   ifs(filename, std::ios::in | std::ios::binary);
    if(!ifs){
        return result;
    }

    result.Length   = fileStat.st_size;

    result.Data     = (T100BYTE*)malloc(result.Length);
    ifs.read((char*)result.Data, result.Length);
    ifs.close();

    return result;
}

std::wstring T100FileTools::GetBasePath(const std::wstring& filePath)
{
    size_t lastSlash;
    if ((lastSlash = filePath.rfind(L'/')) != std::wstring::npos)
        return filePath.substr(0, lastSlash + 1);
    else if ((lastSlash = filePath.rfind(L'\\')) != std::wstring::npos)
        return filePath.substr(0, lastSlash + 1);
    else
        return L"";
}

std::string T100FileTools::GetFileExtension(const std::string& filePath)
{
    std::string fileName = (filePath);
    size_t extOffset = fileName.rfind('.');
    if (extOffset == std::wstring::npos)
        return "";

    return fileName.substr(extOffset + 1);
}

std::wstring T100FileTools::GetFileExtension(const std::wstring& filePath)
{
    std::wstring fileName = (filePath);
    size_t extOffset = fileName.rfind(L'.');
    if (extOffset == std::wstring::npos)
        return L"";

    return fileName.substr(extOffset + 1);
}
