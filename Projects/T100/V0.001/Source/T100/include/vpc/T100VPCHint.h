#ifndef T100VPCHINT_H
#define T100VPCHINT_H

#include "T100Hint.h"
#include "T100OrderTypes.h"

static std::string      T100VPC_HINT_APP_START                          =   "VPC is starting...";
static std::string      T100VPC_HINT_APP_STOP                           =   "VPC is stopped.";
static std::string      T100VPC_HINT_APP_IS_RUNNING                     =   "VPC is running...";

static std::string      T100VPC_HINT_VIEW_START                         =   "VPC View is starting...";
static std::string      T100VPC_HINT_VIEW_STOP                          =   "VPC View is stopped.";

static std::string      T100VPC_HINT_SERVE_START                        =   "VPC Serve is starting...";
static std::string      T100VPC_HINT_SERVE_STOP                         =   "VPC Serve is stopped.";

static std::string      T100VPC_HINT_SCREEN_REFRESH                     =   "Screen refresh!";

//
static std::string      T100VPC_ORDER_EXECUTE                           =   "execute!";
static std::string      T100VPC_ORDER_EXECUTE_ERROR                     =   "execute order error!";

//
static std::string      T100VPC_ORDER_EXECUTE_ADD                       =   "execute order add!";
static std::string      T100VPC_ORDER_EXECUTE_SUB                       =   "execute order sub!";
static std::string      T100VPC_ORDER_EXECUTE_MUL                       =   "execute order mul!";
static std::string      T100VPC_ORDER_EXECUTE_DIV                       =   "execute order div!";
//
static std::string      T100VPC_ORDER_EXECUTE_AND                       =   "execute order and!";
static std::string      T100VPC_ORDER_EXECUTE_OR                        =   "execute order or!";
static std::string      T100VPC_ORDER_EXECUTE_NOT                       =   "execute order not!";
static std::string      T100VPC_ORDER_EXECUTE_XOR                       =   "execute order xor!";
//
static std::string      T100VPC_ORDER_EXECUTE_CMT                       =   "execute order cmt!";
static std::string      T100VPC_ORDER_EXECUTE_DEBUG                     =   "execute order debug!";
static std::string      T100VPC_ORDER_EXECUTE_LOCK                      =   "execute order lock!";
static std::string      T100VPC_ORDER_EXECUTE_UNLOCK                    =   "execute order unlock!";
static std::string      T100VPC_ORDER_EXECUTE_NOP                       =   "execute order nop!";
static std::string      T100VPC_ORDER_EXECUTE_HALT                      =   "execute order halt!";
//
static std::string      T100VPC_ORDER_EXECUTE_CALL                      =   "execute order call!\n\n\n";
static std::string      T100VPC_ORDER_EXECUTE_RET                       =   "execute order ret!\n\n\n";
static std::string      T100VPC_ORDER_EXECUTE_INT                       =   "execute order int!";
static std::string      T100VPC_ORDER_EXECUTE_IRET                      =   "execute order iret!";
//
static std::string      T100VPC_ORDER_EXECUTE_JZ                        =   "execute order jz!";
static std::string      T100VPC_ORDER_EXECUTE_JNZ                       =   "execute order jnz!";
static std::string      T100VPC_ORDER_EXECUTE_JUMP                      =   "execute order jump!";
static std::string      T100VPC_ORDER_EXECUTE_LOOP                      =   "execute order loop!";
//
static std::string      T100VPC_ORDER_EXECUTE_IN                        =   "execute order in!";
static std::string      T100VPC_ORDER_EXECUTE_OUT                       =   "execute order out!";
static std::string      T100VPC_ORDER_EXECUTE_MOVE                      =   "execute order move!";
//

class T100VPCHint : public T100Hint
{
    public:
        T100VPCHint();
        virtual ~T100VPCHint();
        //
        static T100STDSTRING        order_hint(T100WORD, T100STDSTRING);
        static T100STDSTRING        order_hint(T100WORD, T100WORD, T100STDSTRING);
        static T100STDSTRING        order_hint(T100WORD, T100WORD, T100OPERATOR_DOUBLE&, T100STDSTRING);
        static T100STDSTRING        order_hint(T100WORD, T100WORD, T100OPERATOR_DOUBLE&, T100OPERATOR_DOUBLE&, T100STDSTRING);
        //
        static T100STDSTRING        cmt_hint(T100WORD, T100WORD, T100WORD, T100STDSTRING);

    protected:

    private:
};

#endif // T100VPCHINT_H
