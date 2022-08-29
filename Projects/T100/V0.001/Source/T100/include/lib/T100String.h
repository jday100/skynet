#ifndef T100STRING_H
#define T100STRING_H

#include <vector>
#include <string>
#include "T100DataTypes.h"


//标准字符类型
typedef     char                            T100STDCHAR;
typedef     std::string                     T100STDSTRING;
typedef     std::u32string                  T100STDSTRING32;

//自定义字符类型
typedef     T100BYTE                        T100CHAR8;
typedef     wchar_t                         T100CHAR16;
typedef     char32_t                        T100CHAR32;

typedef     T100CHAR32                      T100CHAR;
#define     T100STRING                      T100String


#define     T100STRING_CHAR_VECTOR          std::vector<T100CHAR>
#define     T100STRING_VECTOR               std::vector<T100String>



class T100String
{
    friend class T100SegmentHash;
    friend class T100SegmentEqual;
    friend class T100StringHash;
    friend class T100StringEqual;
    public:
        T100String();
        virtual ~T100String();

        T100String(T100STDSTRING);
        T100String(T100STDSTRING32);

        T100BOOL                            empty();

        T100WORD                            getLength();
        T100WORD                            getRawLength();
        T100WORD                            getByteLength();

        T100WORD*                           getRawData();
        T100BYTE*                           getByteData();

        const T100CHAR                      operator[](T100WORD index)const;

        const T100String                    operator+(const T100String&);
        const T100String&                   operator+=(const T100String&);
        const T100String                    operator=(const T100String&);

        T100BOOL                            operator==(const T100String&)const;
        T100BOOL                            operator!=(const T100String&)const;

        T100BOOL                            append(T100CHAR);

        T100VOID                            clear();

        T100STDSTRING                       to_std_string();
        T100STDSTRING32                     to_std_string32();

    protected:
        T100BOOL                            m_flag_stdstring        = T100FALSE;
        T100BOOL                            m_flag_string           = T100FALSE;

        T100BOOL                            plus(T100String&, T100STDSTRING32&);
        T100BOOL                            plus(T100String&, const T100STRING_CHAR_VECTOR&);
        T100BOOL                            verify(T100String&);

    private:
        T100STDSTRING                       m_std_string;
        T100STDSTRING32                     m_string;
        T100STRING_CHAR_VECTOR              m_raw_string;
};

#endif // T100STRING_H
