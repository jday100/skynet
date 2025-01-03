#ifndef T100GAME_H
#define T100GAME_H


class T100Game
{
    public:
        T100Game();
        virtual ~T100Game();

        void            create();
        void            destroy();

        void            load();
        void            unload();

        void            run();

    protected:

    private:
};

#endif // T100GAME_H
