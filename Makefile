pwcheck:
	gcc -g -std=c99 -Wall -Wextra -Werror pwcheck.c -o pwcheck
clean:
	rm pwcheck
install:
	gcc -g -std=c99 -Wall -Wextra -Werror pwcheck.c -o pwcheck
