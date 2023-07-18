#ifndef MEMORY_H
#define MEMOEY_H
#include </home/heige/source/include/direct_handle_memory.h>
#include </home/heige/source/include/type.h>

//内存申请


//内存释放


//可用内存空间查询

//初始化分页机制
void init_page();

//初始化页使用情况表
void init_pageuse_table();

//修改页表

void change_page_table(int index,int page_address,char user,char present,char write);


//修改页目录

void change_table_content(int index,int page_address,char user,char present,char write);

//申请页
int allow_page(int index);

//释放页
int free_page(int index,int page_address);


//内存拷贝
char memory_copy(int * from,int* to,int bits);

//页目录
struct page_content{
    u8 present:1; //在内存中
    u8 write:1; //0只读 1可读可写
    u8 user:1;//1所有人0超级用户
    u8 pwt:1;//1直写模式0回写模式
    u8 pcd :1;//禁止该页缓冲
    u8 accessed:1;//被访问过
    u8 dirty:1;//该页缓存被写过
    u8 pat:1;//页大小4k/4m 0/1
    u8 global:1;//全局不可刷新
    u8 ignored:3;//交给操作系统
    u32 index:20;
}__attribute__ ((__packed__));;


//页表结构体
struct page_table{
    u8 present:1; //在内存中
    u8 write:1; //0只读 1可读可写
    u8 user:1;//1所有人0超级用户
    u8 pwt:1;//1直写模式0回写模式
    u8 pcd :1;//禁止该页缓冲
    u8 accessed:1;//被访问过
    u8 dirty:1;//该页缓存被写过
    u8 pat:1;//页大小4k/4m 0/1
    u8 global:1;//全局不可刷新
    u8 ignored:3;//交给操作系统
    u32 index:20;
}__attribute__ ((__packed__));



struct memory_info
{
    char use:1;//该页是否被使用
    char use_times:7;//该页被使用的次数
}__attribute__ ((__packed__));







#endif
