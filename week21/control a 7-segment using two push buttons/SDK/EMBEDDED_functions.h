#ifndef EMBEDDEDFUNCTIONS_H
#define EMBEDDEDFUNCTIONS_H

#define SET_BIT(X,BIT_NUM) X|=(1<<BIT_NUM)
#define CLEAR_BIT(X,BIT_NUM) X&=~(1<<BIT_NUM)
#define READ_BIT(X,BIT_NUM) ((X>>BIT_NUM)&1)
#define TOGGLE_BIT(X,BIT_NUM) X^=(1<<BIT_NUM)

#endif
