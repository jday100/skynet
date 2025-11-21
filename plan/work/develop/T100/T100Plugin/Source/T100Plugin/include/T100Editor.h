#ifndef T100EDITOR_H
#define T100EDITOR_H


class T100Editor
{
    public:
        T100Editor();
        virtual ~T100Editor();

        void            Create();
        void            Message();

    protected:
        int*            m_value         = nullptr;

    private:
};

#endif // T100EDITOR_H
