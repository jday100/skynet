#include "T100WindowsFile.h"

#include <sstream>
#include "console/T100Console.h"
#include "T100WindowsFileDecoder.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

T100WindowsFile::T100WindowsFile(const T100WSTRING& file) :
    T100BinaryFile(file)
{
    //ctor
}

T100WindowsFile::~T100WindowsFile()
{
    //dtor
}

T100BOOL T100WindowsFile::Load()
{
    T100WindowsFileInfo             info;
    T100WindowsFileDecoder          decoder(this);

    decoder.Decode(info);

    PrintDosHeader(&info.DosHeader);
    PrintOptionalHeader(&info.OptionalHeader64);
}

T100VOID T100WindowsFile::PrintDosHeader(IMAGE_DOS_HEADER* header)
{
    T100Console             console;

    std::wstringstream      wsstream;

    wsstream << L"DOS HEADER:\n";

    wsstream << L"Magic:" << header->e_magic << std::endl;
    wsstream << L"" << header->e_cblp << std::endl;
    wsstream << L"" << header->e_cp << std::endl;
    wsstream << L"" << header->e_crlc << std::endl;
    wsstream << L"" << header->e_cparhdr << std::endl;
    wsstream << L"MinAlloc:" << header->e_minalloc << std::endl;
    wsstream << L"MaxAlloc:" << header->e_maxalloc << std::endl;
    wsstream << L"SS:" << header->e_ss << std::endl;
    wsstream << L"SP:" << header->e_sp << std::endl;
    wsstream << L"" << header->e_csum << std::endl;
    wsstream << L"IP:" << header->e_ip << std::endl;
    wsstream << L"CS:" << header->e_cs << std::endl;
    wsstream << L"" << header->e_lfarlc << std::endl;
    wsstream << L"" << header->e_ovno << std::endl;
    wsstream << L"" << header->e_res[0] << std::endl;
    wsstream << L"" << header->e_oemid << std::endl;
    wsstream << L"" << header->e_oeminfo << std::endl;
    wsstream << L"" << header->e_res2[0] << std::endl;
    wsstream << L"" << header->e_lfanew << std::endl;

    console.OutLine(wsstream.str());
}

T100VOID T100WindowsFile::PrintOptionalHeader(IMAGE_OPTIONAL_HEADER64* header)
{
    T100Console             console;
    std::wstringstream      wsstream;

    wsstream << L"OPTIONAL HEADER64:" << std::endl;
    wsstream << L"Magic:" << header->Magic << std::endl;
    wsstream << L"MajorLinkerVersion:" << header->MajorLinkerVersion << std::endl;
    wsstream << L"MinorLinkerVersion:" << header->MinorLinkerVersion << std::endl;
    wsstream << L"SizeOfCode:" << header->SizeOfCode << std::endl;
    wsstream << L"SizeOfInitializedData:" << header->SizeOfInitializedData << std::endl;
    wsstream << L"SizeOfUninitializedData:" << header->SizeOfUninitializedData << std::endl;
    wsstream << L"AddressOfEntryPoint:" << header->AddressOfEntryPoint << std::endl;
    wsstream << L"BaseOfCode:" << header->BaseOfCode << std::endl;
    wsstream << L"ImageBase:" << header->ImageBase << std::endl;
    wsstream << L"SectionAlignment:" << header->SectionAlignment << std::endl;
    wsstream << L"FileAlignment:" << header->FileAlignment << std::endl;
    wsstream << L"MajorOperatingSystemVersion:" << header->MajorOperatingSystemVersion << std::endl;
    wsstream << L"MinorOperatingSystemVersion:" << header->MinorOperatingSystemVersion << std::endl;
    wsstream << L"MajorImageVersion:" << header->MajorImageVersion << std::endl;
    wsstream << L"MinorImageVersion:" << header->MinorImageVersion << std::endl;
    wsstream << L"MajorSubsystemVersion:" << header->MajorSubsystemVersion << std::endl;
    wsstream << L"MinorSubsystemVersion:" << header->MinorSubsystemVersion << std::endl;
    wsstream << L"Win32VersionValue:" << header->Win32VersionValue << std::endl;
    wsstream << L"SizeOfImage:" << header->SizeOfImage << std::endl;
    wsstream << L"SizeOfHeaders:" << header->SizeOfHeaders << std::endl;
    wsstream << L"CheckSum:" << header->CheckSum << std::endl;
    wsstream << L"Subsystem:" << header->Subsystem << std::endl;
    wsstream << L"DllCharacteristics:" << header->DllCharacteristics << std::endl;
    wsstream << L"SizeOfStackReserve:" << header->SizeOfStackReserve << std::endl;
    wsstream << L"SizeOfStackCommit:" << header->SizeOfStackCommit << std::endl;
    wsstream << L"SizeOfHeapReserve:" << header->SizeOfHeapReserve << std::endl;
    wsstream << L"SizeOfHeapCommit:" << header->SizeOfHeapCommit << std::endl;
    wsstream << L"LoaderFlags:" << header->LoaderFlags << std::endl;
    wsstream << L"NumberOfRvaAndSizes:" << header->NumberOfRvaAndSizes << std::endl;


    console.OutLine(wsstream.str());
}

}
