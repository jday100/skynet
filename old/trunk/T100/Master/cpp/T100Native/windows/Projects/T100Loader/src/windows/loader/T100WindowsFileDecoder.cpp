#include "T100WindowsFileDecoder.h"

#include "T100WindowsFile.h"
#include "storage/file/binary/T100BinaryFileReader.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

T100WindowsFileDecoder::T100WindowsFileDecoder(T100WindowsFile* file) :
    m_binaryFile(file)
{
    //ctor
}

T100WindowsFileDecoder::~T100WindowsFileDecoder()
{
    //dtor
}

T100BOOL T100WindowsFileDecoder::Decode(T100WindowsFileInfo& info)
{
    T100BOOL                    result      = T100TRUE;
    T100BinaryFileReader*       reader      = T100NULL;

    reader  = m_binaryFile->CreateReader();
    if(!reader){
        return T100FALSE;
    }

    T100UINT64          length;
    T100UINT64          value;

    length  = m_binaryFile->GetLength();
    if(length == 0){
        return T100FALSE;
    }

    T100BYTE*           buffer  = T100NEW T100BYTE[length];


    value  = reader->Read(buffer, length);

    if(value != length){
        result = T100FALSE;
    }

    if(result){
        IMAGE_DOS_HEADER*   header      = (IMAGE_DOS_HEADER*)buffer;

        result = Verify(header, info);
    }

    if(result){
        IMAGE_NT_HEADERS*   ntHeader    = (IMAGE_NT_HEADERS*)(buffer + info.DosHeader.e_lfanew);

        result = VerifyPE(ntHeader, info);
    }

    if(result){
        T100BYTE*       header      = (T100BYTE*)(buffer + info.DosHeader.e_lfanew);
        result = VerifyFile(header, info);
    }

    m_binaryFile->DestroyReader(reader);
    T100SAFE_DELETES(buffer);
    return result;
}

T100BOOL T100WindowsFileDecoder::Verify(IMAGE_DOS_HEADER* header, T100WindowsFileInfo& info)
{
    T100BOOL        result;

    if(!header){
        return T100FALSE;
    }else{
        result  = T100TRUE;
    }

    if(header->e_magic != IMAGE_DOS_SIGNATURE){
        return T100FALSE;
    }

    memcpy(&info.DosHeader, header, sizeof(IMAGE_DOS_HEADER));

    return result;
}

T100BOOL T100WindowsFileDecoder::VerifyPE(IMAGE_NT_HEADERS* header, T100WindowsFileInfo& info)
{
    T100BOOL        result;

    if(!header){
        return T100FALSE;
    }else{
        result  = T100TRUE;
    }

    if(header->Signature != IMAGE_NT_SIGNATURE){
        return T100FALSE;
    }

    memcpy(&info.NTHeader, header, sizeof(IMAGE_NT_HEADERS));

    if(info.NTHeader.FileHeader.Characteristics & IMAGE_FILE_32BIT_MACHINE){
        info.Type   = T100FILE_32;
    }else{
        info.Type   = T100FILE_64;
    }

    if(info.NTHeader.FileHeader.Characteristics & IMAGE_FILE_DLL){
        info.Type2  = T100FILE_DLL;
    }else{
        info.Type2  = T100FILE_EXE;
    }

    return result;
}

T100BOOL T100WindowsFileDecoder::VerifyFile(T100BYTE* data, T100WindowsFileInfo& info)
{
    T100BOOL        result;

    if(info.Type == T100FILE_64 && info.Type2 == T100FILE_EXE){
        result  = T100TRUE;
    }else{
        return T100FALSE;
    }

    IMAGE_NT_HEADERS64*     header      = (IMAGE_NT_HEADERS64*)data;

    if(!header){
        return T100FALSE;
    }

    T100BYTE*       offset      = data + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER);

    memcpy(&info.OptionalHeader64, offset, sizeof(IMAGE_OPTIONAL_HEADER64));


    return result;
}

}
