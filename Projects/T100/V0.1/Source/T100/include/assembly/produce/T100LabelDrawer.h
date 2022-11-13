#ifndef T100LABELDRAWER_H
#define T100LABELDRAWER_H

#include "T100AssemblyCommon.h"
#include "T100String.h"
#include "T100StringHash.h"
#include "T100StringEqual.h"
#include "T100ProduceInfo.h"

namespace T100Assembly{

class T100LabelDrawer
{
    public:
        T100LabelDrawer();
        virtual ~T100LabelDrawer();

        static T100BOOL                 setLabelDefine(T100STRING, T100LABEL_DEFINE*);
        static T100LABEL_DEFINE*        getLabelDefine(T100STRING);

        static T100BOOL                 clear();

    protected:
        static T100LABEL_HASH           m_label_hash;

    private:
};

}

#endif // T100LABELDRAWER_H
