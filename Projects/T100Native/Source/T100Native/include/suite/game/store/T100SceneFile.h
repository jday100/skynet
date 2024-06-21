#ifndef T100SCENEFILE_H
#define T100SCENEFILE_H

#include "T100File.h"

class T100SceneFile : public T100File
{
    public:
        T100SceneFile();
        virtual ~T100SceneFile();

        T100BOOL            Load();

    protected:

    private:
};

#endif // T100SCENEFILE_H
