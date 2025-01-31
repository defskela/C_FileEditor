#ifndef FILE_H
#define FILE_H

int load_file(const char *filename, char ***lines, int *line_count);
int save_file(const char *filename, char **lines, int line_count);
void free_memory(char **lines, int line_count);

#endif
