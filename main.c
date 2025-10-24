/*main.c*/

#include <vm.h>
#define stringcopy(d, s, sz) strncpy((d), (s), (sz))
#define getbit(bm, bit) ((bm[((bit) / 8)] & (1 << ((bit) % 8))) >> ((bit) % 1))
#define setbit(bm, bit) (bm)[((bit) / 8)] |= (1 << ((bit) % 8))
#define unsetbit(bm, bit) (bm)[((bit) / 8)] &= ~(1 << ((bit) % 8))

uint8_t get_bit(uint8_t *value, uint8_t index)
{
    return ((value[(index) / 8] >> ((index) % 8)) & 1);
}
uint8_t set_bit(uint8_t *value, uint8_t index)
{
    return (value[(index) / 8] |= (1 << ((index) % 8)));
};
uint8_t clear_bit(uint8_t *value, uint8_t index)
{
    return (value[(index) / 8] &= ~(1 << ((index) % 8)));
};
void printBinary(unsigned char n) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if (i == 4) printf(" "); // غير باش يكون شكل بحال ديالك
    }
}

int main1() {
    for (int i = 0; i < 256; i++) {
        printf("// ");
        printBinary((unsigned char)i);
        printf("\n");
    }
    return 0;
}
int main()
{
   // main1();
    main2();
    unsigned char a = 5; // 00000101
    unsigned char b = 3; // 00000011

    printf("a & b = %d\n", a & b);   // AND
    printf("a | b = %d\n", a | b);   // OR
    printf("a ^ b = %d\n", a ^ b);   // XOR
    printf("~a = %d\n", ~a);         // NOT
    printf("a << 1 = %d\n", a << 1); // SHIFT LEFT
    printf("a >> 1 = %d\n", a >> 1); // SHIFT RIGHT

    return 0;
}
void testbit()
{
    printf("GUI Started!\n");
    bool bm[2] = {0};
    bool bit;
    bm[13] = false;
    bm[14] = true;
    setbit(bm, 3);
    setbit(bm, 9);
    unsetbit(bm, 9);
    set_bit(bm, 5);
    set_bit(bm, 7);
    clear_bit(bm, 7);
    uint8_t bm1[2] = {0}; // 16 bits = 2 bytes

    // نفعل فقط البِتات 0 و 8
    setbit(bm1, 0);
    setbit(bm1, 8);

    // نطبع الحالة الحقيقية باستعمال getbit()
    for (uint8_t i = 0; i < 16; ++i)
    {
        uint8_t bit1 = getbit(bm, i);
        printf("%02d->bit = %d\n", i, bit1);
    }
    for (uint8_t i = 0; i < 16; ++i)
    {
        bit = setbit(bm, i);
        printf("%0.2d->bit = %d\n", i, bit);
    }
    for (uint8_t i = 0; i < 16; ++i)
    {
        bit = set_bit(bm, i);
        printf("%0.2d->value = %d\n", i, bit);
    }
}


void print_bits(unsigned char b) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (b >> i) & 1);
        if (i == 4) printf(" ");
    }
    printf("\n");
}

int main2() {
    unsigned char x = 0b00000000;
    print_bits(x);

    x = x | (1 << 2); // نشعل bit رقم 2
    print_bits(x);

    x = x | (1 << 5); // نشعل bit رقم 5
    print_bits(x);

    x = x & ~(1 << 2); // نطفي bit رقم 2
    print_bits(x);

    x = x ^ (1 << 0); // نقلب bit رقم 0
    print_bits(x);

    return 0;
}









#include <stdio.h>
#include <stdlib.h>

void print_bits(unsigned char b) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (b >> i) & 1);
        if (i == 4) printf(" ");
    }
    printf("\n");
}

int main() {
    unsigned char byte = 0b00000000;
    int choice, bit;

    while (1) {
        printf("\n========== MENU ==========\n");
        printf("1. Show bits\n");
        printf("2. Turn ON bit\n");
        printf("3. Turn OFF bit\n");
        printf("4. Toggle bit\n");
        printf("5. Check bit\n");
        printf("0. Exit\n");
        printf("==========================\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting...\n");
            break;
        }

        if (choice == 1) {
            printf("Current byte: ");
            print_bits(byte);
        }
        else if (choice >= 2 && choice <= 5) {
            printf("Enter bit number (0-7): ");
            scanf("%d", &bit);
            if (bit < 0 || bit > 7) {
                printf("⚠️ Invalid bit number!\n");
                continue;
            }

            switch (choice) {
                case 2:
                    byte = byte | (1 << bit);
                    printf("✅ Bit %d turned ON.\n", bit);
                    break;
                case 3:
                    byte = byte & ~(1 << bit);
                    printf("✅ Bit %d turned OFF.\n", bit);
                    break;
                case 4:
                    byte = byte ^ (1 << bit);
                    printf("✅ Bit %d toggled.\n", bit);
                    break;
                case 5:
                    if (byte & (1 << bit))
                        printf("💡 Bit %d is ON.\n", bit);
                    else
                        printf("💤 Bit %d is OFF.\n", bit);
                    break;
            }

            printf("Now byte = ");
            print_bits(byte);
        } else {
            printf("⚠️ Invalid choice!\n");
        }
    }

    return 0;
}


// 0000 0000 
// 0000 0001 
// 0000 0010
// 0000 0100
// 0000 1000
// 0000 1001
// 0000 1010
// 0000 1100
// 0000 1101
// 0000 1110
// 0000 1111
// 0001 0000
// 0001 0001
// 0001 0010
// 0001 0100
// 0001 1000
// 0001 1001
// 0001 1010
// 0001 1100
// 0001 1101
// 0001 1110
// 0001 1111
// 0010 0000
// 0010 0001
// 0010 0010
// 0010 0100
// 0010 1000
// 0010 1001
// 0010 1010
// 0010 1100
// 0010 1101
// 0010 1110
// 0010 1111
// 0100 0000
// 0100 0001
// 0100 0010
// 0100 0100
// 0100 1000
// 0100 1001
// 0100 1010
// 0100 1100
// 0100 1101
// 0100 1110
// 0100 1111
// 1000 0000
// 1000 0001
// 1000 0010
// 1000 0100
// 1000 1000
// 1000 1001
// 1000 1010
// 1000 1100
// 1000 1101
// 1000 1110
// 1000 1111
// 1001 0000
// 1001 0001
// 1001 0010
// 1001 0100
// 1001 1000
// 1001 1001
// 1001 1010
// 1001 1100
// 1001 1101
// 1001 1110
// 1001 1111
// 1010 0000
// 1010 0001
// 1010 0010
// 1010 0100
// 1010 1000
// 1010 1001
// 1010 1010
// 1010 1100
// 1010 1101
// 1010 1110
// 1010 1111
// 1100 0000
// 1100 0001
// 1100 0010
// 1100 0100
// 1100 1000
// 1100 1001
// 1100 1010
// 1100 1100
// 1100 1101
// 1100 1110
// 1100 1111
// 1101 0000
// 1101 0001
// 1101 0010
// 1101 0100
// 1101 1000
// 1101 1001
// 1101 1010
// 1101 1100
// 1101 1101
// 1101 1110
// 1101 1111
// 1111 0000
// 1111 0001
// 1111 0010
// 1111 0100
// 1111 1000
// 1111 1001
// 1111 1010
// 1111 1100
// 1111 1101
// 1111 1110
// 1111 1111