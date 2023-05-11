#ifndef GLOBAL_H
#define GLOBAL_H

#define gdt_max 128

struct gdt{
    short segment_low ;
    short segment_base_low;
    char segment_base_mid;
    char segment_dsc;
    char segment_set;
    char segment_base_high;

}__attribute__ ((__packed__));
struct gdt_point{
    short gdt_size;
    int gdt_base;
}__attribute__ ((__packed__));
void init_global();




#endif