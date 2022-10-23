// ###   Бінарне дерево пошуку   ###
// Варіант №15

// За заданим збалансованим бінарним деревом, елементами якого є випадкові цілі числа,
// створити два нових збалансованих бінарних дерева, в одному з яких розмістити парні
// значення вершин заданого дерева, а у другому – непарні.
// Передбачити виведення вмісту вершин побудованих дерев.

#include <cstdlib>
#include <iostream>
using namespace std;
struct Tree
{
    int data;
    Tree *left;
    Tree *rigth;
};
// Рекурсивна функція створення збалансованого дерева
Tree *tree_balance(int n)
{
    Tree *q;
    int nl, nr;
    if (n == 0)
        q = 0;
    else
    {
        nl = n / 2;
        nr = n - nl - 1;
        q = new Tree;
        q->data = rand() % 100 - 50;
        q->left = tree_balance(nl);
        q->rigth = tree_balance(nr);
    };
    return q;
}
// Виведення елементів збалансованого дерева
void PrintTree(Tree *t, int h)
{
    if (t != 0)
    {
        PrintTree(t->left, h + 1);
        for (int i = 1; i <= h; i++)
            cout << "  ";
        cout << t->data << "\n";
        cout << "\n";
        PrintTree(t->rigth, h + 1);
    }
    return;
}
void PrintTree(Tree *t, Tree *even, Tree *odd)
{
    for 
    
}
// Основна програма
int main()
{
    int n;
    // сout << "Inpun N ";
    cin >> n;
    srand(time(0));
    Tree *root = tree_balance(n);
    Tree *even, *odd;
    PrintTree(root, 0);
    cout << "\n";
    // system("PAUSE");
    int i = 0, fl = 0;

    while(i < n){
        if(root->data % 2 == 0){
            fl = func(&even, root->data, fl);
        }
    }
    return 0;
}

int func(Tree* even, int data){
        even->left = new Tree;
        even->left->data = data;
        if(fl == 1){
            even->rigth = data;
            
        }
}
// // Дерево пошуку
// #include <stdlib.h>
// #include <stdio.h>
// #include <time.h>
// //using namespace std;
// struct Tree
//     {        int data;
//              Tree *left;
//              Tree *rigth;
//     };
// // Cтворення бінарного дерева пошуку
// Tree *seach(Tree *&q, int x)
//     {
//            if (q!=0)
//                if (x<q->data) seach(q->left,x);
//                else seach(q->rigth,x);
//            else {
//                    q=malloc(sizeof(Tree));
//                    q->data=x;
//                    q->left=0;
//                    q->rigth=0;
//                 };
//            return q;
//     }
// // Виведення елементів бінарного дерева пошуку
// void PrintTree(Tree *t, int h)
// {
//      if (t!=0)
//      {
//               PrintTree(t->rigth,h+1);
//               for (int i=1;i<=h;i++)
//               {
//                   printf("      ");
//                   };
//               printf("%d\n",t->data);
//               PrintTree(t->left,h+1);
//               }
// }
// // Пошук самого правого найбільшого елемента
// void find_element(Tree *&r,Tree *&q)
//      {
//           if (r->rigth!=0)
//              find_element(r->rigth,q);
//           else {
//                    q->data=r->data;
//                    q=r;
//                    r=r->left;
//                };
//       };
// // Видалення елемента у бінарному дереві пошуку
//  del_tree(Tree *&p, int x)
// {
//       Tree *q;
//       if (p==0) printf("Element not found\n");
//       else if (x<p->data) del_tree(p->left,x);
//            else if (x>p->data) del_tree(p->rigth,x);
//                 else {
//                        q=p;
//                        if (q->rigth==0) p=q->left;
//                        else if (q->left==0) p=q->rigth;
//                             else find_element(q->left,q);
//                        delete(q);
//                      };
//  };
// // Основна програма
// int main(int argc, char *argv[])
// {
//     printf("Input N ");
//     int n; Tree *p;
//     scanf("%d",&n);
//     srand(time(0));
//     p=0;
//     for (int i=1; i<=n; i++)
//     {
//        int x=rand()%100-50;
//        printf("%d",x);
//        seach(p,x);
//     };
//     printf("\n");
//     PrintTree(p,0);
//     int x;
//     printf("What delete? ");
//     scanf("%d",&x);
//     del_tree(p,x);
//     PrintTree(p,0);
//     printf("\n");
//     system("PAUSE");
// }

// #include <iostream>
// using namespace std;

// struct node {
//     int key;
//     struct node* left, * right;
// };

// struct node* newNode(int item) {
//     struct node* temp = (struct node*)malloc(sizeof(struct node));
//     temp->key = item;
//     temp->left = temp->right = NULL;
//     return temp;
// }

// // Вивід бінарного дерева.
// void inorder(struct node* root) {
//     if (root != NULL) {
//         // Перехід у ліво.
//         inorder(root->left);

//         // Перехід у корінь.
//         cout << root->key << " ";

//         // Перехід у право.
//         inorder(root->right);
//     }
// }

// // Вводить вузол.
// struct node* insert(struct node* node, int key) {
//     // Повертає новий вузол, якщо дерево пусте.
//     if (node == NULL) return newNode(key);

//     // Перейде до потрібного місця та вставить у вузол.
//     if (key < node->key)
//         node->left = insert(node->left, key);
//     else
//         node->right = insert(node->right, key);

//     return node;
// }

// // Знаходить наступника за порядком.
// struct node* minValueNode(struct node* node) {
//     struct node* current = node;

//     // Знайде крайній лівий лист.
//     while (current && current->left != NULL)
//         current = current->left;

//     return current;
// }

// // Видалення вузлів.
// struct node* deleteNode(struct node* root, int key) {
//     // Повертає, якщо вузол пустий.
//     if (root == NULL) return root;

//     // Знаходить вузол для видалення.
//     if (key < root->key)
//         root->left = deleteNode(root->left, key);
//     else if (key > root->key)
//         root->right = deleteNode(root->right, key);
//     else {
//         // Якщо вузол лише з одним дочірнім елементом або без нього.
//         if (root->left == NULL) {
//             struct node* temp = root->right;
//             free(root);
//             return temp;
//         }
//         else if (root->right == NULL) {
//             struct node* temp = root->left;
//             free(root);
//             return temp;
//         }

//         // Якщо вузол має двох потомків.
//         struct node* temp = minValueNode(root->right);

//         // Вставить наступного за порядком вузла на місці вузла, який потрібно видалити.
//         root->key = temp->key;

//         // Видалить наступника по порядку.
//         root->right = deleteNode(root->right, temp->key);
//     }
//     return root;
// }

// int main() {
// 	struct node* root = NULL;
// 	// root = insert(root, your_value); ## Введення елемента у дерево. ##
// 	// inorder(root);  ## Вивід елементів дерева.  ##
// 	// deleteNode(root, your_value); ## Видалення елемента з дерева. ##

// }
