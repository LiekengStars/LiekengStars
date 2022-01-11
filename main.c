
#include "linux_list.h"


int main()
{
    Plane list1 = list_init();
    int i,num;
    for(i=0;i<6;i++)
    {
        scanf("%d",&num);
        add_abs_del(list1,num);
        list_display(list1);
    }

    return 0;
}