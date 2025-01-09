#ifndef T100SCENE_H
#define T100SCENE_H

#include "T100Entity.h"

class T100Scene
{
    public:
        T100Scene();
        virtual ~T100Scene();

        T100ENTITY_VECTOR       entities;

        T100BOOL                Load();

    protected:

    private:
};

#endif // T100SCENE_H
