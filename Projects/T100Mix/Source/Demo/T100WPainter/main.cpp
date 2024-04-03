#include "T100Diagram.h"
#include "T100DiagramInfo.h"
#include "T100ElementCircle.h"

void load();
void save();

int main()
{
    save();

    load();
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
