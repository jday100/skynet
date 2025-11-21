#ifndef DISPLAY_H
#define DISPLAY_H

#define     _TX                             0x40
#define     _SR                             0x86

#define     UART0_BASE                      0x10009000
#define     UART1_BASE                      0x1000a000

#define     UART_BASE                       UART0_BASE

#define     TRDY                            0x2000

#define     GDB_QUOTE_CHAR                  15

#define     TXREG                           ((volatile unsigned short*)(UART_BASE + _TX))
#define     SRREG                           ((volatile unsigned short*)(UART_BASE + _SR))

void outbyte(char value);


#endif // DISPLAY_H
