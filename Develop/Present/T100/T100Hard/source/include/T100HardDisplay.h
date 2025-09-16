#ifndef T100HARDDISPLAY_H
#define T100HARDDISPLAY_H

#ifdef __cplusplus
extern "C" {
#endif

#define     HARD_DISPLAY_BUFFER_ADDRESS                     0XB8000


void hard_print(const char*);

#ifdef __cplusplus
}
#endif

#endif // T100HARDDISPLAY_H
            