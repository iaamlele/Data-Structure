#include <stdio.h>
#include "link2.c"

int main(){
    LIST list = create_list();
    for(int i = 0; i < 10; i++) {
        push_list(list, i+1);
    }
    print_list(list);

    int find_node1 = find_nodevalue(list, 3);
    printf("按值查找结果为：%d\n", find_node1);

    int find_node2 = find_nodekth_value(list, 1);
    printf("按序号查找结果为： %d\n", find_node2);

    delete_node(list, 2);
    delete_node(list, 2);
    add_list(list, 2, 888);
    print_list(list);

    printf("pop链表最后一个元素值为： %d\n", list_pop_node(list));


    printf("The result of list_to_pointer:");
    int * p = list_to_pointer(list);
    for(int i = 0; i < list->length; i++) {
        printf("%d ", p[i]);
    }

    // delete_node(list, 1);
    // print_list(list);

    remove_list(list);
    return 0;
}