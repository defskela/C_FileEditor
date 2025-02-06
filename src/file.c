#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int load_file(const char *filename, char ***lines, int *line_count)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        return -1;
    }

    char buffer[MAX_LINE_LENGTH];
    *line_count = 0;
    *lines = NULL;

    while (fgets(buffer, MAX_LINE_LENGTH, file))
    {
        (*line_count)++;
        *lines = realloc(*lines, sizeof(char *) * (*line_count));
        (*lines)[(*line_count) - 1] = strdup(buffer);
    }

    fclose(file);
    return 0;
}

int save_file(const char *filename, char **lines, int line_count)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        return -1;
    }

    for (int i = 0; i < line_count; i++)
    {
        fprintf(file, "%s", lines[i]);
    }

    fclose(file);
    return 0;
}

void free_memory(char **lines, int line_count)
{
    for (int i = 0; i < line_count; i++)
    {
        free(lines[i]);
    }
}
