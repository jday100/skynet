#ifndef T100FIREGAME_H
#define T100FIREGAME_H

#include "T100Game.h"

class T100FireGame : public T100Game
{
    public:
        T100FireGame();
        virtual ~T100FireGame();

    protected:

    private:
        T100VOID            create();
        T100VOID            destroy();
};

#endif // T100FIREGAME_H
