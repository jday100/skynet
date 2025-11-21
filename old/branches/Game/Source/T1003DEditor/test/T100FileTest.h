#ifndef T100FILETEST_H
#define T100FILETEST_H


class T100FileTest
{
    public:
        T100FileTest();
        virtual ~T100FileTest();

        int             test();

    protected:
        int             test_gltf();
        int             test_3df();
        int             test_h3d();

        int             json_test();

    private:
};

#endif // T100FILETEST_H
