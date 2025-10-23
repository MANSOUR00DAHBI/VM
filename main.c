/*main.c*/

#include <vm.h>
#define stringcopy(d,s,sz) strncpy((d),(s),(sz))
#define getbit(bm,bit)((bm[((bit)/8)] & (1 <<((bit)%8)))>>((bit)%8))
#define setbit(bm,bit) (bm)[((bit)/8)] |= (1<<((bit)%8))
#define unsetbit(bm,bit) (bm)[((bit)/8)] &= ~(1<<((bit)%8))
uint8_t get_bit(uint8_t *value , uint8_t index){
    return  (((value[(index)/8]) & (1 << ((index)%8)) )>> (index%8))
}
uint8_t set_bit(uint8_t *value , uint8_t index){
    return ( (value)[(index)/8]  |= (1<< (((index)%8)))>> (index%8) );
}
uint8_t clear_bit(uint8_t *value , uint8_t index){
    return ( (value)[(index)/8]  &= ~(1<< (((index)%8))));
}
int main(){
    printf("GUI Started!\n");
	bool bm[16]={0};
	bool bit ;
	//bm[13] = false;
	//bm[14] = true ;
      setbit(bm,3);
        setbit(bm,9);
        unsetbit(bm,9);

	for(int8 i = 0 ; i < sizeof(bm)/sizeof(bm[0]);++i){
		bit = getbit(bm,i);
		printf("%0.2ld->bit = %d\n",i,bit);
    }
	
    return 0;
}