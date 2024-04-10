#include "T100Diagram.h"
#include "T100DiagramInfo.h"
#include "T100ElementCircle.h"

#include "T100File.h"
#include "T100FileTest.h"

void load();
void save();
void file();

int main()
{
    //file();

    //save();

    //load();

    T100FileTest        test;

    test.save();
    test.load();
}

void file()
{
    T100BOOL                result;
    T100STRING              filename;

    filename    = L"text.txt";
    T100File                writer(filename);
    T100WORD                value;
    T100WORD                length;
    T100VOID*               data            = T100NULL;

    result  = writer.open();

    if(result){
        value   = 1;
        length  = 1;
        data    = &value;
        result  = writer.write((T100WCHAR*)&value, length);
        result  = writer.close() ? result : T100FALSE;
    }
}

void load()
{

}

void save()
{
    T100BOOL                result;
    T100STRING              filename;
    T100Diagram             diagram;
    T100DiagramInfo         info;

    T100ElementCircle*      circle          = T100NULL;

    circle      = new T100ElementCircle();

    info.getElements()->push_back(circle);

    filename    = L"test.dgm";

    result      = diagram.save(filename, info);
}
