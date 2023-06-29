#include "func.c"


int main(int argc, char* argv[]) {
    // Проверяем, передано ли имя файла и хотя бы один аргумент
    if (argc < 2) {
        printf("Usage: ./word_count filename [sorting_order]\n");
        return 1;
    }
    // Открываем файл для чтения
    FILE* file = fopen(argv[1], "r");

    // Проверяем, удалось ли открыть файл
    if (file == NULL) {
        printf("Unable to open file: %s\n", argv[1]);
        return 1;
    }

    // Создаем корень бинарного дерева
    struct TreeNode* root = NULL;

    // Читаем слова из файла и вставляем их в бинарное дерево
    char word[100];
    while (fscanf(file, "%s", word) != EOF) {
        root = insertNode(root, word);
    }

    // Закрываем файл
    fclose(file);

    // Проверяем, передан ли аргумент для сортировки
    char* order = "ASC"; // По умолчанию сортируем в порядке возрастания
    if (argc >= 3) {
        if (strcmp(argv[2], "-o") == 0 && argc >= 4) {
            if (strcmp(argv[3], "ASC") == 0 || strcmp(argv[3], "DESC") == 0) {
                order = argv[3];
            } else {
                printf("Invalid sorting order. Using default order: ASC\n");
            }
        } else {
            printf("Invalid arguments. Using default order: ASC\n");
        }
    }

    // Выполняем обход бинарного дерева и выводим результаты
    inOrderTraversal(root, order);

    // Освобождаем память, занятую бинарным деревом
    freeTree(root);

    return 0;
}