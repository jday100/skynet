#ifndef T100STRING_H
#define T100STRING_H

#include "T100StringCommon.h"
#include "T100String32.h"

#define     T100STRING          T100Library::T100String


namespace T100Library{

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

T100BOOL        operator +  (const T100WCHAR*, const T100String&);


class T100String : public T100Class
{
    friend class T100StringHash;
    friend class T100StringEqual;
    public:
        T100String();
        T100String(const T100STDCHAR*);
        T100String(const T100CHAR16*);
        T100String(const T100CHAR32*);
        T100String(const T100WCHAR*);
        T100String(const T100WSTRING&);
        T100String(const T100String32&);
        virtual ~T100String();

        T100BOOL            empty();
        T100WORD            length();
        T100VOID            clear();

        T100STDSTRING&      to_std_string();
        T100WSTRING&        to_wstring();
        T100String32&       to_string32();

    public:
        T100BOOL            operator == (const T100String&);
        T100BOOL            operator != (const T100String&);

        T100String&         operator += (const T100WCHAR);
        T100String&         operator +  (const T100WCHAR);

        T100String&         operator += (const T100String&);
        T100String&         operator +  (const T100String&);

        T100WCHAR           operator [] (const T100WORD);

    protected:

    private:
        T100WSTRING         m_wstring;
        T100String32        m_string32;

};

}

#endif // T100STRING_H
