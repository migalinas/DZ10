#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    char* word;
    int count;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* createNode(char* word) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->word = strdup(word);
    newNode->count = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertNode(struct TreeNode* root, char* word) {
    // Если дерево пустое, создаем новый узел и возвращаем его
    if (root == NULL)
        return createNode(word);

    // Иначе рекурсивно вставляем узел в подходящее поддерево
    int cmp = strcmp(word, root->word);
    if (cmp < 0)
        root->left = insertNode(root->left, word);
    else if (cmp > 0)
        root->right = insertNode(root->right, word);
    else
        root->count++; // Если слово уже существует, увеличиваем счетчик повторений

    return root;
}


void inOrderTraversal(struct TreeNode* root, char* order) {
    if (root != NULL) {
        if (strcmp(order, "ASC") == 0) {
            inOrderTraversal(root->left, order);
            printf("%s: %d\n", root->word, root->count);
            inOrderTraversal(root->right, order);
        } else if (strcmp(order, "DESC") == 0) {
            inOrderTraversal(root->right, order);
            printf("%s: %d\n", root->word, root->count);
            inOrderTraversal(root->left, order);
        }
    }
}

void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root->word);
        free(root);
    }
}
