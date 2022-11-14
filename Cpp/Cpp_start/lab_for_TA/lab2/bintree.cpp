/******************************************************************************

Варіант №9

Створити збалансоване бінарне дерево, елементами якого є випадкові цілі числа. 
Перетворити задане дерево таким чином, щоб у ньому всі від’ємні значення вершин були замінені їх модулями.
Передбачити виведення вмісту вершин побудованих дерев.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Tree
 {       
    int data;
    struct Tree *left;     //Tree *left; 
    struct Tree *rigth;   //Tree *rigth; 
  };


struct Tree *tree_balance(int n)
{
  struct Tree *q;
  int nl,nr;
  if (n==0) q=0;                                  //q=NULL;
  else {
          nl=n/2; 
          nr=n-nl-1;
          q=malloc(sizeof(struct Tree));   //(C++) q=new Tree;
          q->data=rand()%(100-1)+1;
          q->left=tree_balance(nl);
          q->rigth=tree_balance(nr);
       }
  return q;   
}

int PrintTree(struct Tree *t, int h)
{   int i;
  if (t!=0)
  {
      PrintTree(t->rigth,h+1);
      for (i=1;i<=h;i++)   printf ("      ");       // cout << "      ";
      printf("%d\n", t->data);                         // cout << t->data<<"\n";
      printf("\n");                                           // cout <<"\n";
      PrintTree(t->left,h+1);
   }
  return 0;
}

void change(struct Tree *p)
{
   
   if (p==NULL) 
      printf("Element not found\n"); 
    
    else if (p->data < 0) p->data = p->data * -1;
    
    
     
   if ( p->left != NULL ){
      
      if (p->left->data < 0) p->left->data = p->left->data * -1;
      
      
    change(p->left);  
   }
   else p->rigth;
   
   
  if ( p->rigth != NULL ){
      
      if (p->rigth->data < 0) p->rigth->data = p->rigth->data * -1;
      
      
    change(p->rigth);  
   }

 }


////////////////////////////////////////////////////////////////////////////////////////////////////////////
void even_numbers(struct Tree *p ,int* count_p, int* a_p)
{ int i = *count_p;
   
   if (p==NULL) 
      printf("Element not found\n"); 
    
    else if( ((p->data % 2 ) == 0) && (p->data >= 0) ){
       i = *count_p;
       a_p[i] = p->data;
       *count_p += 1;
       printf(" \n nomer %d--->%d ", *count_p , p->data );
       p->data*= -1;
    }
    
     
   if ( p->left != NULL ) {
      
      if (((p->left->data % 2) == 0)  && (p->left->data >= 0) ){
      i = *count_p;
      a_p[i] =  p->left->data;
      *count_p += 1;
      printf(" \n nomer %d--->%d ", *count_p , p->left->data );
      p->left->data*= -1 ;
      }
      
    even_numbers(p->left, *(&count_p), *(&a_p));  
   }
   else p->rigth;
   
   
  if ( p->rigth != NULL ){
      
      if (((p->rigth->data % 2) == 0)  && (p->rigth->data >= 0) ){
         i = *count_p;
      a_p[i] = p->rigth->data;   
      *count_p += 1;
      printf(" \n nomer %d--->%d ", *count_p , p->rigth->data );
      p->rigth->data *= -1 ; 
      }
      
    even_numbers(p->rigth, *(&count_p), *(&a_p));  
   }

 }

/////////////////////////////////////////////////////////////////////////////////////////////

void odd_numbers(struct Tree *p ,int* count_n, int* a_n)
{ int i = *count_n;
   
   if (p==NULL) 
      printf("Element not found\n"); 
    
    else if( ((p->data % 2 ) != 0) && (p->data >= 0) ){
       i = *count_n;
       a_n[i] = p->data;
       *count_n += 1;
       printf(" \n nomer %d--->%d ", *count_n , p->data );
       p->data*= -1;
    }
    
     
   if ( p->left != NULL ) {
      
      if (((p->left->data % 2) != 0)  && (p->left->data >= 0) ){
      i = *count_n;
      a_n[i] =  p->left->data;
      *count_n += 1;
      printf(" \n nomer %d--->%d ", *count_n , p->left->data );
      p->left->data*= -1 ;
      }
      
    odd_numbers(p->left, *(&count_n), *(&a_n));  
   }
   
   else p->rigth;
   
   
  if ( p->rigth != NULL ){
      
      if (((p->rigth->data % 2) != 0)  && (p->rigth->data >= 0) ){
         i = *count_n;
         a_n[i] = p->rigth->data;   
         *count_n += 1;
         printf(" \n nomer %d--->%d ", *count_n , p->rigth->data );
         p->rigth->data *= -1 ; 
      }
      
    odd_numbers(p->rigth, *(&count_n), *(&a_n));  
   }

 }

//////////////////////////////////////////////////////////////////////////////////////////////////

struct Tree *even_tree(int n, int a_p[] , int* i)
{
   
  struct Tree *q;
  int nl,nr;
  if (n==0) q=0;                                  
  else {
          nl=n/2; 
          nr=n-nl-1;
          q=malloc(sizeof(struct Tree));
          q->data= a_p[*i];
          
          *i = *i+1;
          q->left=even_tree(nl, a_p, &(*i));
          q->rigth=even_tree(nr, a_p, &(*i));
       }
  return q;   
}








///////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
   printf("Input N: ");       // cout<< "Input N: ";
   int n, i, count_p = 0, count_n = 0;
   struct Tree *root, *even_t, *odd_t;
   scanf("%d",&n);
   
   int a_p[n], a_n[n];
   
   
   srand(time(NULL));
   root=tree_balance(n);

   PrintTree(root,n);
   
   /////////////////////////////////********************************************************
   
   even_numbers(root, &count_p, &a_p[0]);
   change(root);
   
   printf(" \n Кількість парних = %d \n", count_p);
   for (i=0; i<count_p;i++){
      printf("%d|", a_p[i]);
   }
   printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
   //***********************************************************************************************
   odd_numbers(root, &count_n, &a_n[0]);
   change(root);
   
   printf(" \n Кількість непарних = %d \n", count_n);
   for (i=0; i<count_n;i++){
      printf("%d|", a_n[i]);
   }
   printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
   PrintTree(root,n);
   
  ////////////////////////////////////////////////////////////////////////////////////////////////////// 
   
   
   
   
 //*************************************************************************************////////////  
   printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
   printf("\n Надрукуємо дерево з парними числами \n");
   i = 0;
   
   even_t = even_tree(count_p, a_p, &i );
   PrintTree(even_t, count_p);
   
   /////////////////////////////////////////////////////////////////////////////////////////////////////////////
   printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
   printf("\n Надрукуємо дерево з НЕ парними числами \n");
   i = 0;
   
   odd_t = even_tree(count_n, a_n, &i );
   PrintTree(odd_t, count_n);
   
    return 0;
}




