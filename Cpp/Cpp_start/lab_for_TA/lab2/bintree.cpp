// ###   Бінарне дерево пошуку   ###
// Варіант №15

// За заданим збалансованим бінарним деревом, елементами якого є випадкові цілі числа,
// створити два нових збалансованих бінарних дерева, в одному з яких розмістити парні
// значення вершин заданого дерева, а у другому – непарні. 
// Передбачити виведення вмісту вершин побудованих дерев.
#include <iostream>
using namespace std;
 
struct node {
    int key;
    struct node* left, * right;
};
 
struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Вивід бінарного дерева.
void inorder(struct node* root) {
    if (root != NULL) {
        // Перехід у ліво.
        inorder(root->left);
 
        // Перехід у корінь.
        cout << root->key << " ";
 
        // Перехід у право.
        inorder(root->right);
    }
}
 
// Вводить вузол.
struct node* insert(struct node* node, int key) {
    // Повертає новий вузол, якщо дерево пусте.
    if (node == NULL) return newNode(key);
 
    // Перейде до потрібного місця та вставить у вузол.
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 
    return node;
}
 
// Знаходить наступника за порядком.
struct node* minValueNode(struct node* node) {
    struct node* current = node;
 
    // Знайде крайній лівий лист.
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
 
// Видалення вузлів.
struct node* deleteNode(struct node* root, int key) {
    // Повертає, якщо вузол пустий.
    if (root == NULL) return root;
 
    // Знаходить вузол для видалення.
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Якщо вузол лише з одним дочірнім елементом або без нього.
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        // Якщо вузол має двох потомків.
        struct node* temp = minValueNode(root->right);
 
        // Вставить наступного за порядком вузла на місці вузла, який потрібно видалити.
        root->key = temp->key;
 
        // Видалить наступника по порядку.
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
 
int main() {
	struct node* root = NULL;
	// root = insert(root, your_value); ## Введення елемента у дерево. ##
	// inorder(root);  ## Вивід елементів дерева.  ##
	// deleteNode(root, your_value); ## Видалення елемента з дерева. ##
 
}