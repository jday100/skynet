#ifndef T100FIREGAME_H
#define T100FIREGAME_H

#include "game/T1003DGame.h"

class T100FireGame : public T1003DGame
{
    public:
        T100FireGame();
        virtual ~T100FireGame();

        T100BOOL            run();

    protected:

    private:
        T100VOID            create();
        T100VOID            destroy();
};

#endif // T100FIREGAME_H
