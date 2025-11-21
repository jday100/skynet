#ifndef T100FILE3DF_H
#define T100FILE3DF_H

#include "T100JSON.h"
#include "entity/T100Entity.h"
#include "data/T100Camera.h"
#include "data/T100Light.h"
#include "data/T100Texture.h"
#include "data/T100Material.h"
#include "entity/T100Dot.h"

class T100File3DF
{
    friend class T1003DFileReader;
    friend class T1003DFileWriter;
    public:
        T100File3DF();
        virtual ~T100File3DF();

        T100JSON&           GetJSON();

    protected:
        T100JSON            m_json;

    private:
};

#endif // T100FILE3DF_H
