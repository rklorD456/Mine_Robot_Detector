#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

#define WDG_163MS 0
#define WDG_325MS 1
#define WDG_65MS 2
#define WDG_13S 3
#define WDG_26S 4
#define WDG_52S 5
#define WDG_1 6
#define WDG_2_1 7

void func_init(u8 prescaler);
void WDT_ON(void);
void WDT_OFF(void);

#endif
