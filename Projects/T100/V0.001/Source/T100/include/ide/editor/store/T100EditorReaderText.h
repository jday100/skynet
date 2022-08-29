#ifndef T100EDITORREADERTEXT_H
#define T100EDITORREADERTEXT_H

#include "T100Reader.h"


class T100EditorReaderText : public T100Reader
{
    public:
        T100EditorReaderText();
        virtual ~T100EditorReaderText();

        static T100BOOL         load(T100STDSTRING, T100WORD_VECTOR&);

    protected:

    private:
};

#endif // T100EDITORREADERTEXT_H
