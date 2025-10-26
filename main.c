/*main.c*/

#include <vm.h>
#define stringcopy(d, s, sz) strncpy((d), (s), (sz))
#define getbit(bm, bit) ((bm[((bit) / 8)] & (1 << ((bit) % 8))) >> ((bit) % 1))
#define setbit(bm, bit) (bm)[((bit) / 8)] |= (1 << ((bit) % 8))
#define unsetbit(bm, bit) (bm)[((bit) / 8)] &= ~(1 << ((bit) % 8))

uint8_t get_bit(uint8_t byte, uint8_t index)
{
    return (byte >> index) & 1;
}
void set_bit(uint8_t *byte, uint8_t index)
{
    *byte |= (1 << index);
}
void clean_bit(uint8_t *byte, uint8_t index)
{
    *byte &= ~(1 << index);
}
void print_byte(uint8_t byte)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", get_bit(byte, i));
        if (i == 4)
            putchar(' ');
    }
    printf("\n");
}

int main()
{
    uint8_t flags = 0;
    printf("Initial byte : \n");
    print_byte(flags);
    set_bit(&flags, 0);
    set_bit(&flags, 3);
    set_bit(&flags, 7);
    printf("After setting bits 0,3,7 : \n");
    print_byte(flags);
    clean_bit(&flags, 3);
    printf("After cleaning bits 3 : \n");
    print_byte(flags);
    printf("Bit states:\n");

    for (uint8_t i = 0; i < 8; i++) {
        printf("bit %d = %d\n", i, get_bit(flags, i));
    }
    return 0;
}
