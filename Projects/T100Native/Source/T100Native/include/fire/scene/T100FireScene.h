#ifndef T100FIRESCENE_H
#define T100FIRESCENE_H

#include "T100Scene.h"
class T100Render;

class T100FireScene : public T100Scene
{
    public:
        T100FireScene();
        virtual ~T100FireScene();

        virtual T100VOID            Load();

        T100VOID                    SetRender(T100Render*);
        T100Render*                 GetRender();

    protected:
        T100Render*                 m_render            = T100NULL;

    private:
};

#endif // T100FIRESCENE_H
