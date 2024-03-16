#ifndef T100STRING_H
#define T100STRING_H

#include "T100Common.h"
#include "T100String32.h"

class T100String
{
    public:
        T100String();
        T100String(const T100STDCHAR*);
        T100String(const T100CHAR16*);
        T100String(const T100CHAR32*);
        T100String(const T100STRING8&);
        T100String(const T100STRING16&);
        T100String(const T100STRING32&);
        T100String(const T100String32&);
        virtual ~T100String();

        T100BOOL                    empty();
        T100WORD                    length();
        T100VOID                    clear();

        T100STDSTRING               to_std_string();
        T100WSTRING                 to_wstring();
        T100String32&               to_string32();

    protected:
        T100BOOL                    operator == (const T100String&);
        T100BOOL                    operator != (const T100String&);

        T100String                  operator += (const T100WCHAR);
        T100String                  operator +  (const T100WCHAR);

        T100String                  operator += (const T100String&);
        T100String                  operator +  (const T100String&);

        T100WCHAR                   operator [] (const T100WORD);

    private:
        T100WSTRING                 m_wstring;
        T100String32                m_string32;
};

#endif // T100STRING_H
