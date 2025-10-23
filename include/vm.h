/*virtuale machine */

#ifndef VM_H
#define  VM_H
#include <interface.h>
#define CAPACITY_STACK 1024
typedef int64_t Word ;
typedef struct {
  Word Stack[CAPACITY_STACK];
  Word instruction_pointer;
  int halt ;

}

#endif