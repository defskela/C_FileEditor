CC = gcc
CFLAGS = -Wall -Wextra

all: text_editor

text_editor: src/main.c src/editor.c src/file.c src/ui.c
	$(CC) $(CFLAGS) src/main.c src/editor.c src/file.c src/ui.c -o text_editor

clean:
	rm -f text_editor