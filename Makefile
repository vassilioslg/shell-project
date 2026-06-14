CC = clang
CFLAGS = -Wall -Wextra -g

shell: src/main.c
	$(CC) $(CFLAGS) src/main.c -o shell

clean:
	rm -f shell
