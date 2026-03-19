/*main.c*/

#include <vm.h>
#define symoble 0xdb
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

    for (uint8_t i = 0; i < 8; i++)
    {
        printf("bit %d = %d\n", i, get_bit(flags, i));
    }

    printf("---------------------------------------\n");
    uint8_t bm[2] = {
     0
    }; // 64 bits

    print_bitmap(bm, 8);
    set_bitmask(bm, 1);
    set_bitmask(bm, 3);
    set_bitmask(bm, 7);
    set_bitmask(bm, 13);
    for (uint8_t i = 0; i < 8; i++)
    {
        printf("bit %d = %d\n", i, get_bit(bm[i], i));
    }

    print_bitmap(bm, 8);
    printf("Bitmask state:\n");
    print_bitmask(bm, 8);

    clean_bit(bm, 0);

    printf("\nAfter clearing bit 5:\n");
    print_bitmask(bm, 8);
    printf("\n---------------------------------------\n");
    toggle_bit(bm, 0); // تعكس البِت 0
    printf("After toggle bit 1:\n");
    print_bitmask(bm, 8);
     print_bitmap(bm, 8);
    printf("\n---------------------------------------\n");

    uint32_t active = count_bits(bm, 8);
    printf("\nActive bits: %u\n", active);
    printf("---------------------------------------\n");
    uint8_t image[9] = {
        0b00011000,
        0b00111100,
        0b01111110,
        0b11111111,
        0b11111111,
        0b11111111,
        0b01111110,
        0b00111100,
        0b00011000,
    };

    for (int i = 0; i <= 8; i++)
    {
        print_pixel_line(image[i]);
    }
    printf("\n---------------------------------------\n");
    // for (int i = 0; i < 256; i++){
    //     printf("-> %x | %c ",i,i);
    // }
    //    printf("\n---------------------------------------\n");
    uint8_t bitmap[8] = {
        0b00111100,
        0b01111110,
        0b11111111,
        0b11111111,
        0b11111111,
        0b01111110,
        0b00111100,
        0b00011000};

    print_bitmap(bitmap, 8);

    return 0;
}
