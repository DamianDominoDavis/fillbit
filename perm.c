#include "ministack.h"
#include "perm.h"

/*
** print sixteen bits as a square visual
*/
static void tostring(int piece) {
	static char	buf[17] = {0};
	static int	mask = 1;

	for (int i=0; i<16; i++)
		buf[i] = (piece & (mask << i)) ? '#' : '.';
	for (int i=0; i<4; i++)
		printf("%.4s\n", &buf[4*i]);
	printf("%d\n", piece);
}

/*
** driver bruteforces over all possible bit grids, filters on validity, twiddles
** survivors into the normalized set
*/
int main(void) {
	char buf[17] = {0};
	int bytes;
	t_stack *set;

	for (int a=0; a<16; a++)
		for (int b=0; b<16; b++)
			for (int c=0; c<16; c++)
				for (int d=0; d<16; d++) {
					if (a == b || b == c || a == c || a == d || b == d || c == d)
						continue;
					bytes = 0;
					for (int i=0; i<16; i++)
						if (i == a || i == b || i == c || i == d) {
							buf[i] = '#';
							bytes |= 1 << i;
						}
						else
							buf[i] = '.';
					if (ispattern(buf) && bytes == settle(bytes))
						set = setstack(bytes);
				}
	do tostring(set->val); while ((set = set->next));
	stack(-1);
	return 0;
}
