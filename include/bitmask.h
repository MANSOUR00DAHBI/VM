/*bitmask*/
#ifndef BITMASK_H
#define BITMASK_H
#define symoble 0xdb
#define stringcopy(d, s, sz) strncpy((d), (s), (sz))
#define getbit(bm, bit) ((bm[((bit) / 8)] & (1 << ((bit) % 8))) >> ((bit) % 1))
#define setbit(bm, bit) (bm)[((bit) / 8)] |= (1 << ((bit) % 8))
#define unsetbit(bm, bit) (bm)[((bit) / 8)] &= ~(1 << ((bit) % 8))

uint8_t get_bit(uint8_t byte, uint8_t index);
void set_bit(uint8_t *byte, uint8_t index);
void clean_bit(uint8_t *byte, uint8_t index);
void print_byte(uint8_t byte);
void set_bitmask(uint8_t *bm, uint32_t index);
void clear_bitmask(uint8_t *bm, uint32_t index);
uint8_t get_bitmask(const uint8_t *bm, uint32_t index);
void print_bitmask(const uint8_t *bm, uint32_t size);
void toggle_bit(uint8_t *bm, uint32_t index); 
uint32_t count_bits(const uint8_t *bm , uint32_t size );
uint8_t bitmask_equals(const uint8_t *a , const uint8_t *b , uint32_t size );
void print_pixel_line(uint8_t byte);
void print_bitmap(uint8_t *bitmap, int rows);


#endif 

#ifdef BITMASK_H

void print_bitmap(uint8_t *bitmap, int rows){
    for (int y = 0; y < rows; y++){
        for (int x = 0; x < 8; x++){
            int bit = y * 8 + x;
            if(get_bitmask(bitmap,bit))printf("%c",symoble);
            else printf(" ");
        }
        putchar('\n');
    }
}

void print_pixel_line(uint8_t byte){
    for (int i = 7; i >= 0; --i){
        if(get_bit(byte,i))printf("%c",symoble);
        else printf(" ");
    }
    putchar('\n');
}

uint8_t bitmask_equals(const uint8_t *a , const uint8_t *b , uint32_t size ){
    for (uint32_t  i = 0; i < (size + 7)/ 8; i++){
        if(a[i] != b[i])return 0;
    }
    return 1;
    
}

uint32_t count_bits(const uint8_t *bm , uint32_t size ){
    uint32_t count = 0;
    for (uint32_t i = 0; i < size; i++){
        if(get_bitmask(bm,i)) count++;
    }
    return count ;
}


void toggle_bit(uint8_t *bm, uint32_t index){
    bm[index /8 ] ^= (1 << (index % 8));
}

void set_bitmask(uint8_t *bm , uint32_t index){
    bm[index / 8 ] |= (1 <<( 7 - (index % 8)));
}
uint8_t get_bitmask(const uint8_t *bm , uint32_t index){
    return (bm[index / 8] >> (( 7 - (index % 8)) & 1));
}
void print_bitmask(const uint8_t *bm , uint32_t size){
    for (uint32_t i = 0; i < size; i++){
        printf("%d",get_bitmask(bm,i));
        if(i % 8 == 3)putchar(' ');
        if(i % 8 == 7)putchar('\n');
    }
}
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

#endif