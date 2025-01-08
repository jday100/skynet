#ifndef T100FIREGAME_H
#define T100FIREGAME_H

#include "game/T1003DGame.h"

class T100FireGame : public T1003DGame
{
    public:
        T100FireGame(HINSTANCE, HINSTANCE, LPSTR, int);
        virtual ~T100FireGame();

        T100BOOL            create(T100WORD, T100WORD, T100WString);
        T100BOOL            destroy();

        T100BOOL            show();
        T100INT             run();

    protected:

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100FIREGAME_H
