#ifndef T100BASICSCENE_H
#define T100BASICSCENE_H

#include "T100Scene.h"
class T100Render;

class T100BasicScene : public T100Scene
{
    public:
        T100BasicScene();
        virtual ~T100BasicScene();

        virtual T100VOID            Load();

        T100VOID                    SetRender(T100Render*);
        T100Render*                 GetRender();

    protected:
        T100Render*                 m_render            = T100NULL;

    private:
};

#endif // T100BASICSCENE_H
