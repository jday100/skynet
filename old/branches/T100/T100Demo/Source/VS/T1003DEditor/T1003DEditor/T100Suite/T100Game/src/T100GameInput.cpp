#include "T100GameInput.h"

T100GameInput::T100GameInput() :
    T1003DInput()
{
    //ctor
}

T100GameInput::~T100GameInput()
{
    //dtor
}

T100VOID T100GameInput::SetMotionPtr(T100GameMotion* motion)
{
    m_motionPtr = motion;
}

T100GameMotion* T100GameInput::GetMotionPtr()
{
    return m_motionPtr;
}

T100VOID T100GameInput::OnKeyDown(T100INT key)
{
    switch(key){
    case 69:        //E
        {
            m_motionPtr->Forward();
        }
        break;
    case 68:        //D
        {
            m_motionPtr->Backward();
        }
        break;
    case 83:        //S
        {
            m_motionPtr->MoveLeft();
        }
        break;
    case 70:        //F
        {
            m_motionPtr->MoveRight();
        }
        break;
    case 87:        //W
        {
            m_motionPtr->MoveUp();
        }
        break;
    case 82:        //R
        {
            m_motionPtr->MoveDown();
        }
        break;
    case 81:        //Q
        {
            m_motionPtr->LookUp();
        }
        break;
    case 84:        //T
        {
            m_motionPtr->LookDown();
        }
        break;
    case 65:        //A
        {
            m_motionPtr->TurnLeft();
        }
        break;
    case 71:        //G
        {
            m_motionPtr->TurnRight();
        }
        break;
    case 90:        //Z
        {
            m_motionPtr->LeftHead();
        }
        break;
    case 86:        //V
        {
            m_motionPtr->RightHead();
        }
        break;
    case 66:        //B
        {
            m_motionPtr->RightHead();
        }
        break;
    case 88:        //X
        {
            m_motionPtr->LeftHead();
        }
        break;
    case 67:        //C
        {
            m_motionPtr->Reset();
        }
        break;
    case 306:       //SHIFT
        {

        }
        break;
    case 307:       //ALT
        {

        }
        break;
    case 308:       //CTRL
        {

        }
        break;
    }
}

T100VOID T100GameInput::OnKeyUp(T100INT key)
{

}
