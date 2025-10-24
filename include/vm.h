/*virtuale machine */

#ifndef VM_H
#define  VM_H
#include <interface.h>
#define CAPACITY_STACK 1024

typedef int64_t word ;
typedef struct {
  word Stack[CAPACITY_STACK];
  word instruction_pointer;
  int halt ;

}vm;

#endif