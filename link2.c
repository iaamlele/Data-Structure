#include <stdio.h>
#include <stdlib.h>


typedef struct L_NODE {
    int data;
    struct L_NODE * next;
    struct L_NODE * last;
} * LIST_NODE;

typedef struct {
    LIST_NODE head;
    LIST_NODE tail;
    int length;
} * LIST;

LIST_NODE find_nodekth(LIST my_list, int x);

LIST create_list() {
    LIST my_list = (LIST)malloc(sizeof(LIST));
    my_list->head = NULL;
    my_list->tail = NULL;
    my_list->length = 0;
    return my_list;
}

void remove_list(LIST my_list) {
    if(my_list->length != 0) {
        LIST_NODE current = my_list->head;
        while(current != NULL) {
            LIST_NODE next = current->next;
            free(current);
            current = next;
        }
    }
    free(my_list);
}

//插入：往最后一个位置push值num
void push_list(LIST my_list, int num) {
    LIST_NODE new_node = (LIST_NODE)malloc(sizeof(LIST_NODE));
    new_node->data = num;
    new_node->next = NULL;

    if(my_list->length == 0){
        my_list->head = new_node;
        my_list->tail = new_node;
    }else {
        my_list->tail->next = new_node;
        new_node->last = my_list->tail;
        my_list->tail = my_list->tail->next;
    }
    my_list->length++;
   
}

//插入：从第x个位置插入值num
void add_list(LIST my_list, int x, int num) {
    if(x < 1 || x > my_list->length) {
        return;
    }else {
        LIST_NODE current = (LIST_NODE)malloc(sizeof(struct L_NODE));
        current->data = num;

        LIST_NODE p = find_nodekth(my_list, x);
        LIST_NODE pre_p = p->last;
        pre_p->next = current;
        current->last = pre_p;
        current->next = p;
        p->last = current;

        my_list->length++;
    }
}

//查找：按值查找
LIST_NODE find_nodevalue(LIST my_list, int x){
    if(my_list->length == 0) {
        return NULL;
    }else {
        LIST_NODE current = my_list->head;
        int i = 1;
        while(current->next != NULL && current->data != x){
            current = current->next;
            i++;
        }
        if(current->data == x)
            return current;
        else 
            return NULL;
    }
}

//查找：按序号查找
LIST_NODE find_nodekth(LIST my_list, int x) {
    if(my_list->length == 0 || x > my_list->length || x < 1) {
        return NULL;
    }else {
        int i = 1;
        LIST_NODE current = my_list->head;
        if(x > (my_list->length / 2)) {
            i = my_list->length;
            while(i > x && current->last != NULL) {
                current = current->last;
                i--;
            }
        }else {
            while(i < x && current->next != NULL) {
                current = current->next;
                i++;
            }
        }
        if(i == x) return current;
        else return NULL; 
    }
}

//删除：删除第x个结点
void delete_node(LIST my_list, int x) {
    if(my_list->length < x || x <= 0) {
        return;
    }else {
        if(x == 1){
            LIST_NODE current = my_list->head;
            my_list->head = current->next;
            free(current);
            my_list->head->last = NULL;
            my_list->length--;
        }else {
            //方法一：双向链表
            LIST_NODE current = find_nodekth(my_list, x);
            LIST_NODE pre_current = current->last;
            pre_current->next = current->next;
            current->next->last = pre_current;

            //方法二：先找pre_current,再找current
            // LIST_NODE pre_current = find_nodekth(my_list, x-1);
            // LIST_NODE current = pre_current->next;
            // pre_current->next = current->next;
            free(current);
            my_list->length--;
            
        }
        
    }
}

//弹出链表最后一个元素
int list_pop_node(LIST my_list) {
    return my_list->tail->data;
}

//链表转指针
int * list_to_pointer(LIST my_list){
    int * p = (int *) malloc(my_list->length * sizeof(int));
    LIST_NODE current = my_list->head;
    int i = 0;
    while(current != NULL) {
        p[i] = current->data;
        current = current->next;
        i++;
    }
    return p;
}

//打印链表
void print_list(LIST my_list) {
    if(my_list->length != 0){
        LIST_NODE current = my_list->head;
        while(current != NULL) {
            printf("%d\n", current->data);
            current = current->next;
        }
    }else {
        printf("NULL");
    }
    
}

