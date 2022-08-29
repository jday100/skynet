#ifndef T100EDITORDATA_H
#define T100EDITORDATA_H

#include "T100Common.h"


class T100EditorData
{
    public:
        T100EditorData();
        virtual ~T100EditorData();

        T100String              m_name;
        T100WORD_VECTOR         m_data;

    protected:

    private:

};

#endif // T100EDITORDATA_H
