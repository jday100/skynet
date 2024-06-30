#ifndef T100SCENE_H
#define T100SCENE_H

#include "T100Common.h"

class T100Scene
{
    public:
        T100Scene();
        virtual ~T100Scene();

        virtual T100VOID            Load() = 0;

    protected:

    private:
};

#endif // T100SCENE_H
