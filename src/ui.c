#include <stdio.h>
#include "ui.h"

void show_menu()
{
    printf("\nТекстовый редактор\n");
    printf("1. Открыть файл\n");
    printf("2. Просмотреть текст\n");
    printf("3. Добавить строку\n");
    printf("4. Удалить строку\n");
    printf("5. Изменить строку\n");
    printf("6. Сохранить файл\n");
    printf("7. Выйти\n");
    printf("Выберите действие: ");
}

int get_user_command()
{
    int command;
    scanf("%d", &command);
    return command;
}

void print_lines(char **lines, int line_count)
{
    if (line_count == 0)
    {
        printf("\nВы не выбрали файл или файл пуст\n");
        return;
    }

    printf("\nТекущий текст\n");
    for (int i = 0; i < line_count; i++)
    {
        printf("%d. %s", i, lines[i]);
    }
}