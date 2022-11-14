#include <stdio.h>
#include "d_linked_list.h"

int main(void)
{
	linked_list_t list;
	int data;
	l_init(&list);

	l_insert(&list, 11);
	l_insert(&list, 22);
	l_insert(&list, 33);
	l_insert(&list, 44);
	l_insert(&list, 55);

	printf("현재 데이터의 수 : %d \n", l_count(&list));

	if (l_first(&list, &data)) {
		printf("%d ", data);
		while(l_next(&list, &data)) {
			printf("%d ", data);
		}
	}
	printf("\n\n");

	if (l_first(&list, &data)) {
		if (data == 22) {
			l_remove(&list);
		}
		while(l_next(&list, &data)) {
			if (data == 22) {
				l_remove(&list);
			}
		}
	}

	printf("현재 데이터의 수 : %d \n", l_count(&list));

	if (l_first(&list, &data)) {
		printf("%d ", data);
		while(l_next(&list, &data)) {
			printf("%d ", data);
		}
	}
	return ("\n\n");

	return 0;
}
