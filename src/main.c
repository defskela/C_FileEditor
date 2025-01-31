#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "editor.h"
#include "ui.h"

#define MAX_FILENAME 255

int main()
{
    char filename[MAX_FILENAME];
    char **lines = NULL;
    int line_count = 0;
    int running = 1;

    while (running)
    {
        show_menu();
        int command = get_user_command();

        switch (command)
        {
        case 1:
            printf("Введите название файла\n");
            scanf("%s", filename);
            if (load_file(filename, &lines, &line_count) == 0)
            {
                printf("Файл загружен. %d строк\n", line_count);
            }
            else
            {
                printf("Ошибка загрузки файла\n");
            }
            break;
        case 2:
            print_lines(lines, line_count);
            break;
        case 3:
            add_line(&lines, &line_count);
            break;
        case 4:
            delete_line(&lines, &line_count);
            break;
        case 5:
            edit_line(lines, line_count);
            break;
        case 6:
            save_file(filename, lines, line_count);
            break;
        case 7:
            running = 0;
            break;
        default:
            printf("Неизвестная команда");
        }
    }
    free_memory(lines, line_count);

    return 0;
}
