//设置页表，页目录，内存申请，内存释放，···
//页目录结构体
#include </home/heige/source/include/type.h>
#include </home/heige/source/include/memory.h>
#include </home/heige/source/include/setcr0_cr2_cr3.h>


/*

该文件所有变量定义

////////////////////////////////////////////////
///  page_contents       页目录--位于0x1000   ///
///  page_tables_1       首页表---位于0x2000  ///
////////////////////////////////////////////////

*/
//页目录and页表
struct page_content * page_contents= 0x1000;
struct page_table * page_tables_1 = 0x2000;



//初始化页表个数
int page_table_number =2;







void init_page(){
    //初始化页表和页目录
    for (int i=0;i<1024;i++){
        page_contents[i].present=1;
        page_contents[i].write=1;
        page_contents[i].user=1;
        page_contents[i].pwt=1;
        page_contents[i].pcd=1;
        page_contents[i].accessed=0;
        page_contents[i].dirty=0;
        page_contents[i].pat=0;
        page_contents[i].ignored=0;
        page_contents[i].index=i+2;
    }
    for (int i=0;i<page_table_number*1024;i++){
        page_tables_1[i].present=1;
        page_tables_1[i].write=1;
        page_tables_1[i].user=1;
        page_tables_1[i].pwt=1;
        page_tables_1[i].pcd=1;
        page_tables_1[i].accessed=0;
        page_tables_1[i].dirty=0;
        page_tables_1[i].pat=0;
        page_tables_1[i].ignored=0;
        page_tables_1[i].index=i;
    }

    set_cr3(0x1000);
    set_cr0(0x80000000);

   
}
   
//修改页表

void change_page_table(int index,int page_address,char user,char present,char write ){
    page_tables_1[index].index = page_address>>12;
    page_tables_1[index].user = user;
    page_tables_1[index].present = present;
    page_tables_1[index].write = write;

}


//修改页目录

void change_table_content(int index,int page_address,char user,char present,char write){
    page_contents[index].index = page_address>>12;
    page_contents[index].user = user;
    page_contents[index].present = present;
    page_contents[index].write = write;
}