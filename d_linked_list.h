#ifndef D_LINKED_LIST_H_
#define D_LINKED_LIST_H_


#define TRUE 1
#define FALSE 0

typedef int l_data_t;
typedef struct _node
{
		l_data_t data;
		struct _node *next;
}node_t;

typedef struct _linked_list
{
		node_t *head;
		node_t * cur;
		node_t * before;
		int num_of_data;
		int (*comp)(l_data_t d1, l_data_t d2);
}linked_list_t;

void l_init(linked_list_t * p_list);
void l_insert(linked_list_t *p_list, l_data_t data);

int l_first(linked_list_t* p_list, l_data_t *p_data);
int l_next(linked_list_t * p_list, l_data_t *p_data);

l_data_t l_remove(linked_list_t * p_list);
int l_count(linked_list_t * p_list);

void set_sort_rule(linked_list_t * p_list,int (*comp)(l_data_t d1, l_data_t d2));

#endif /* D_LINKED_LIST_H_ */
