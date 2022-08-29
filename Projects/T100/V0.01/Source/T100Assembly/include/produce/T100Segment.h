#ifndef T100SEGMENT_H
#define T100SEGMENT_H

#include "T100AssemblyCommon.h"


class T100Segment
{
    public:
        T100Segment();
        virtual ~T100Segment();

        T100WORD                    size();

        T100WORD_VECTOR&            getMem();

        T100WORD                    getOffset();

        T100BOOL                    setWord(T100WORD&, T100WORD);
        T100BOOL                    setString(T100WORD&, T100String);
        T100BOOL                    setArray(T100WORD&, T100WORD);

        T100VOID                    setName(T100String);
        T100String                  getName();

        T100WORD                    getLocation();
        T100WORD                    getLength();



    protected:
        T100String                  m_name;
        T100WORD_VECTOR             m_mem;

        T100WORD                    m_offset            = 0;
        T100WORD                    m_location          = 0;
        T100WORD                    m_length            = 0;

    private:
};

#endif // T100SEGMENT_H
