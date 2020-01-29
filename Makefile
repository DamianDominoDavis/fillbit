FLAGS = -Wall -Wextra -Werror

all: perm

perm:
	@gcc $(FLAGS) perm.c ministack.c validation.c -o perm

clean:
	@rm -f perm

fclean: clean

re: fclean
	@make

.phony: all perm clean fclean re
