#ifndef MINISTACK_H
# define MINISTACK_H
# include <stdlib.h>

typedef struct s_stack {
	struct s_stack	*prev;
	int 			val;
	struct s_stack	*next;
} t_stack;

t_stack	*stack(int v);

#endif
