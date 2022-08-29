#ifndef T100STRINGTYPES_H
#define T100STRINGTYPES_H

#include <string>
class T100String;


//STD
#define     T100STDCHAR8                char
#define     T100STDCHAR16               char16_t
#define     T100STDCHAR32               char32_t
#define     T100STDWCHAR                wchar_t

#define     T100STDCHAR                 T100STDCHAR8

#define     T100STDSTRING8              std::string
#define     T100STDSTRING16             std::u16string
#define     T100STDSTRING32             std::u32string
#define     T100STDWSTRING              std::wstring

#define     T100STDSTRING               T100STDSTRING8

//
#define     T100CHAR8                   T100BYTE
#define     T100CHAR16                  T100STDCHAR16
#define     T100CHAR32                  T100STDCHAR32
#define     T100WCHAR                   T100STDWCHAR

#define     T100CHAR                    T100CHAR32

#define     T100STRING8                 T100STDSTRING8
#define     T100STRING16                T100STDSTRING16
#define     T100STRING32                T100STDSTRING32
#define     T100WSTRING                 T100STDWSTRING

#define     T100STRING                  T100String


#endif // T100STRINGTYPES_H
