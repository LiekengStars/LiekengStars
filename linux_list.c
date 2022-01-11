#include "linux_list.h"

Plane list_init()
{
    Plane head = (Plane)malloc(sizeof(Plane));
    if(head == NULL)
    {
        perror("malloc failed\n");
        return NULL;
    }
    INIT_LIST_HEAD(&(head->ptr));   //大结构下内链的地址申请
    return head;
}

bool list_add_head(Plane head,int data) //头插法
{
    Plane new_node = (Plane)malloc(sizeof(Plane));
    if(new_node == NULL)
    {
        perror("malloc failed\n");
        return NULL;
    }
    new_node->data = data;
    list_add(&(new_node->ptr),&(head->ptr));
}

void list_display(Plane head) //遍历链表
{
    Plane p;
    list_for_each_entry(p,&(head->ptr),ptr)
    {
        printf("%d->",p->data);
    }
    printf("\n");

}

bool del_list(Plane head,int data)
{
    Plane p;
    list_for_each_entry(p,&(head->ptr),ptr)
    {
        if(p->data == data)
        {
            list_del(&(p->ptr));
            free(p);
            printf("Delect Success\n");
            return true;
        }
    }
    printf("No Find\n");
    return false;
}

void destory_list(Plane head) //销毁链表
{
    Plane p,n;
    list_for_each_entry_safe(p,n,&(head->ptr),ptr)
    {
        list_del(&(p->ptr));
        free(p);
    }
    free(head);
}

void add_abs_del(Plane head,int data) //加入正数，删除负数
{
    if(data < 0)
    {
        del_list(head,-data);
    }
    else
    {
        list_add_head(head,data);
    }
}

