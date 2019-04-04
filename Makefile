FLAGS = -Wall -Wextra -Werror

all: perm

perm:
	gcc $(FLAGS) perm.c ministack.c validation.c -o perm
