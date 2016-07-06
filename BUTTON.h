#ifndef __BUTTON_H

#define __BUTTON_H

void button_init(void);

int button_detect(void); //button_detect should be used with button_release() together.

void button_release(void);

#endif