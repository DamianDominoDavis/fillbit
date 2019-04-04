#include "ministack.h"

/*
** self-destructs when out of memory
** call stack(positive_value) to push
** call stack(negative_value) to destroy
** call stack(0) to return the top without change
** otherwise returns top of the stack
*/
t_stack *stack(int v) {
	static t_stack *base = NULL;
	t_stack *push;

	if (v > 0) {
		if (!(push = malloc(sizeof(t_stack))))
			return stack(-1);
		*push = (t_stack){NULL, v, base};
		if (base)
			base->prev = push;
		base = push;
	}
	else if (v < 0) {
		while (base) {
			push = base->next;
			free(base);
			base = push;
		}
	}
	return base;
}
