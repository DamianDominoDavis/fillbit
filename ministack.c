#include "ministack.h"

/*
** is a stack of positive-valued ints
** self-destructs when out of memory
** call with a positive value) to push it
** call with any negative value to free the stack
** call with 0 to peek
** returns top of the stack
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

/*
** ministack additionally behaves as a set
*/
t_stack *setstack(int k) {
	t_stack *top = stack(0);

	while(top)
		if (top->val == k)
			return stack(0);
		else
			top = top->next;
	return stack(k);
}
