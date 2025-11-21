#include "os/user/display.h"

void outbyte(char value)
{
    while(!(*SRREG & TRDY));
    *TXREG = GDB_QUOTE_CHAR;
    while(!(*SRREG & TRDY));
    *TXREG = (unsigned short)value;
}
