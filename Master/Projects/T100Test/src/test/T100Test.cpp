#include "T100Test.h"

T100Test::T100Test(T100Test* parent, T100WSTRING name) :
    T100ObjectTree(parent)
{
    //ctor
    if(parent){
        parent->AddChild(name, this);
    }
}

T100Test::~T100Test()
{
    //dtor
}

T100VOID T100Test::SetGlobalInit(T100BOOL)
{

}

T100VOID T100Test::SetGlobalUninit(T100BOOL)
{

}

T100VOID T100Test::SetInit(T100BOOL)
{

}

T100VOID T100Test::SetUninit(T100BOOL)
{

}

T100RESULT T100Test::TestAll()
{
    T100RESULT      result      = T100RESULT_SUCCESS;

    for(T100ObjectTree* item : m_children.getVector()){
        T100Test*   test    = dynamic_cast<T100Test*>(item);
        if(test){
            T100RESULT temp = test->TestAll();

            if(temp == T100RESULT_SUCCESS){

            }else{
                result  = temp;
            }
        }
    }

    if(result != T100RESULT_SUCCESS){
        return result;
    }
    return DoTest();
}

T100BOOL T100Test::TestUnit(T100WSTRING)
{

}

T100VOID T100Test::List()
{

}

T100BOOL T100Test::Find(T100WSTRING)
{

}

T100VOID T100Test::ShowResult(T100BOOL, T100WSTRING&)
{

}

T100BOOL T100Test::DoInit()
{

}

T100BOOL T100Test::DoUninit()
{

}

T100BOOL T100Test::Init()
{

}

T100BOOL T100Test::Uninit()
{

}

T100BOOL T100Test::DoGlobalInit()
{

}

T100BOOL T100Test::DoGlobalUninit()
{

}

T100BOOL T100Test::GlobalInit()
{

}

T100BOOL T100Test::GlobalUninit()
{

}

T100VOID T100Test::Index()
{

}

T100VOID T100Test::Success()
{

}

T100VOID T100Test::Failure()
{

}

T100VOID T100Test::Create()
{

}

T100VOID T100Test::Destroy()
{

}

T100VOID T100Test::Add()
{

}

T100RESULT T100Test::DoTest()
{

}

T100VOID T100Test::Out(T100WSTRING)
{

}

T100VOID T100Test::OutTestBegin(T100WSTRING&)
{

}

T100VOID T100Test::OutTestEnd(T100BOOL, T100WSTRING&)
{

}

T100VOID T100Test::OutList(T100WSTRING&)
{

}

T100VOID T100Test::OutListBegin()
{

}

T100VOID T100Test::OutListEnd()
{

}

T100VOID T100Test::Insert(T100WSTRING, T100Test*)
{

}

T100VOID T100Test::Append(T100WSTRING, T100Test*)
{

}

T100VOID T100Test::Remove(T100WSTRING)
{

}
