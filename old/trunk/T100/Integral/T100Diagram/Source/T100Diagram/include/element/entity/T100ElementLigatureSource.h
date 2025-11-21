#ifndef T100ELEMENTLIGATURESOURCE_H
#define T100ELEMENTLIGATURESOURCE_H

#include "T100ElementLigature.h"
#include "T100ElementSourceBase.h"

class T100ElementLigatureSource : public T100ElementSourceBase
{
    public:
        T100ElementLigatureSource(T100ElementLigature*);
        virtual ~T100ElementLigatureSource();

        T100BOOL                        Serialize();
        T100BOOL                        Deserialize();

    protected:
        T100ElementLigature*            m_element       = T100NULL;

    private:
};

#endif // T100ELEMENTLIGATURESOURCE_H
