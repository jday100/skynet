#ifndef T100STRING_H
#define T100STRING_H

#include "T100StringTypes.h"
#include "T100String32.h"

#define         T100STRING_VECTOR           std::vector<T100String>


T100BOOL        operator == (const T100STDCHAR*, const T100String&);
T100BOOL        operator != (const T100STDCHAR*, const T100String&);

T100BOOL        operator == (const T100CHAR16*, const T100String&);
T100BOOL        operator != (const T100CHAR16*, const T100String&);

T100BOOL        operator == (const T100CHAR32*, const T100String&);
T100BOOL        operator != (const T100CHAR32*, const T100String&);

T100BOOL        operator == (const T100WCHAR*, const T100String&);
T100BOOL        operator != (const T100WCHAR*, const T100String&);

T100BOOL        operator == (const T100String&, const T100String&);
T100BOOL        operator != (const T100String&, const T100String&);

T100String      operator +  (const T100WCHAR*, const T100String&);


class T100String
{
    friend class T100StringEqual;
    friend class T100StringHash;
    public:
        T100String();
        T100String(const T100STDCHAR*);
        T100String(const T100CHAR16*);
        T100String(const T100CHAR32*);
        T100String(const T100WCHAR*);
        T100String(const T100WSTRING);
        T100String(const T100String32);
        virtual ~T100String();

        T100BOOL                    empty();
        T100WORD                    length();
        T100VOID                    clear();

        T100STDSTRING               to_std_string();
        T100WSTRING                 to_wstring();
        T100String32                to_string();

    public:
        T100BOOL        operator == (const T100String&);
        T100BOOL        operator != (const T100String&);

        T100String      operator += (const T100WCHAR);
        T100String      operator +  (const T100WCHAR);

        T100String      operator += (const T100String&);
        T100String      operator +  (const T100String&);

        T100WCHAR       operator [] (const T100WORD);

    protected:
        T100WSTRING                 m_wstring;
        T100String32                m_string32;

    private:

};

#endif // T100STRING_H
