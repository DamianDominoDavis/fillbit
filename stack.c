#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFLEN (int)20

typedef struct s_stack {
	struct s_stack *prev;
	int val;
	struct s_stack *next;
}	t_stack;

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

int main(int c, char **v) {
	int fd;
	t_stack *plist;
	char buf[BUFFLEN+2];
	int count = 0;
	int bytes = 1;

	buf[BUFFLEN+1] = 0;
	if (c == 2 && 0 < (fd = open(v[1], O_RDONLY))) {
		while (0 < (bytes = read(fd, &buf, BUFFLEN+1)) && bytes >= BUFFLEN)
			plist = stack(10);
		while (plist) {
			count++;
			plist = plist->next;
		}
		printf("counted %d\n", count);
	}
	plist = stack(0);
	count = 0;
	while (plist) {
		count++;
		plist = plist->next;
	}
	stack(-1);
	printf((stack(0)==NULL) ? "good\n" : "bad\n");
	return 0;
}
