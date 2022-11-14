#include <stdio.h>
#include <stdlib.h>
#include "d_linked_list.h"

void l_init(linked_list_t *p_list)
{
	p_list->head = (node_t*) calloc(sizeof(node_t), 1);
	p_list->head->next = NULL;
	p_list->comp = NULL;
	p_list->before = NULL;
	p_list->num_of_data = 0;
}

void f_insert(linked_list_t *p_list, l_data_t data)
{
	node_t *p_new_node = (node_t*) calloc(sizeof(node_t), 1);
	p_new_node->data = data;

	p_new_node->next = p_list->head->next;
	p_list->head->next = p_new_node;
}

void s_insert(linked_list_t *p_list, l_data_t data)
{

}

void l_insert(linked_list_t *p_list, l_data_t data)
{
	if (p_list->comp == NULL) {
		f_insert(p_list, data);
	} else {
		s_insert(p_list, data);
	}
}

int l_first(linked_list_t *p_list, l_data_t *p_data)
{
	if (p_list->head->next == NULL) {
		return FALSE;
	}

	p_list->before = p_list->head;
	p_list->cur = p_list->head->next;
	*p_data = p_list->cur->data;
	return TRUE;
}
int l_next(linked_list_t *p_list, l_data_t *p_data)
{
	if (p_list->cur->next == NULL) {
		return FALSE;
	}
	p_list->before = p_list->cur;
	p_list->cur = p_list->cur->next;

	*p_data = p_list->cur->data;
	return TRUE;
}

l_data_t l_remove(linked_list_t *p_list)
{
	node_t *r_pos = p_list->cur;
	l_data_t r_data = r_pos->data;

	p_list->before->next = p_list->cur->next;
	p_list->cur = p_list->before;

	free(r_pos);
	(p_list->num_of_data);
	return r_data;

}

int l_count(linked_list_t *p_list)
{
	return p_list->num_of_data;
}

void set_sort_rule(linked_list_t *p_list, int (*comp)(l_data_t d1, l_data_t d2))
{

}
