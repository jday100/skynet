#ifndef T100STRING32_H
#define T100STRING32_H

#include "T100DataTypes.h"
#include "T100StringTypes.h"
class T100String32;

T100BOOL        operator == (const T100CHAR32*, const T100String32&);
T100BOOL        operator != (const T100CHAR32*, const T100String32&);

T100String32    operator +  (const T100CHAR32*, const T100String32&);


class T100String32
{
    public:
        T100String32();
        T100String32(T100CHAR32*);
        virtual ~T100String32();

        T100BOOL                    empty();
        T100VOID                    clear();

        T100WORD                    length();
        T100WORD                    raw_length();
        T100WORD                    byte_length();

        T100CHAR32*                 data();
        T100WORD*                   raw_data();
        T100BYTE*                   byte_data();

    public:
        T100BOOL        operator == (const T100String32&);
        T100BOOL        operator != (const T100String32&);

        T100String32    operator += (const T100CHAR32);
        T100String32    operator +  (const T100CHAR32);

        T100String32    operator += (const T100String32&);
        T100String32    operator +  (const T100String32&);

    protected:

    private:
        T100STRING32                m_string32;

};

#endif // T100STRING32_H
