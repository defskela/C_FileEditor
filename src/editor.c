#include "editor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void add_line(char ***lines, int *line_count)
{
    printf("Введите новую строку: ");

    char buffer[MAX_LINE_LENGTH];
    getchar();
    fgets(buffer, MAX_LINE_LENGTH, stdin);

    (*line_count)++;
    *lines = realloc(*lines, sizeof(char) * (*line_count));
    (*lines)[*line_count - 1] = strdup(buffer);
}

void delete_line(char ***lines, int *line_count)
{
    printf("Введите номер строки для удаления: ");

    int row_number;
    scanf("%d", &row_number);

    if (row_number < 1 || row_number > *line_count)
    {
        printf("Ошибка: неверный номер строки.\n");
        return;
    }

    free((*lines)[row_number - 1]);
    for (int i = row_number - 1; i < *line_count; i++)
    {
        lines[i] = lines[i + 1];
    }

    (*line_count)--;
    *lines = realloc(*lines, (*line_count) * sizeof(char *));
}

void edit_line(char **lines, int line_count)
{
    printf("Введите номер строки: ");

    char buffer[MAX_LINE_LENGTH];
    int row_number;
    scanf("%d", &row_number);

    if (row_number < 1 || row_number > line_count)
    {
        printf("Ошибка: неверный номер строки.\n");
        return;
    }

    printf("Введите новый текст: ");
    getchar();
    fgets(buffer, MAX_LINE_LENGTH, stdin);

    free(lines[row_number - 1]);
    lines[row_number - 1] = strdup(buffer);
}
