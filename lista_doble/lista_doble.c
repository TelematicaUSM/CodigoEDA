#include <assert.h>
#include <error.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
  int dato;
  struct node *next;
  struct node *prev;
};
typedef struct node nodo;

void push (nodo **, int);
int pop (nodo **);
void imprime (nodo *);

int
main ()
{
  nodo *lista = NULL;
  int i;

  for (i = 0; i < 10; i++)
    push (&lista, i);
  imprime (lista);

  int popped_node;
  while (lista != NULL)
    {
      popped_node = pop (&lista);
      printf ("%d salio de la lista!\n", popped_node);
      imprime (lista);
    }
}

void
push (nodo ** headref, int data)
{
  nodo *newnode = (nodo *) malloc (sizeof (nodo));
  if (newnode == NULL)
    exit (EXIT_FAILURE);

  newnode->dato = data;
  newnode->prev = NULL;
  newnode->next = *headref;

  if (*headref != NULL)
    (*headref)->prev = newnode;

  *headref = newnode;
}

int
pop (nodo ** headref)
{
  if (*headref == NULL)
    error (EXIT_FAILURE, 0, "no se puede ejecutar pop sobre una lista vacia");

  nodo *popped_node = *headref;
  int result = popped_node->dato;

  *headref = (popped_node->next);

  if (*headref != NULL)
    (*headref)->prev = NULL;

  free (popped_node);
  return result;
}


void
imprime (nodo * head)
{
  nodo *current = head;
  nodo *temp = head;

  if (head == NULL)
    {
      printf ("Lista vacia!\n");
    }
  else
    {
      while (current != NULL)
        {
          printf ("%d ", current->dato);
          temp = current;
          current = current->next;
        }
      printf ("\n");

      while (temp != head)
        {
          printf ("%d ", temp->dato);
          temp = temp->prev;
        }
      printf ("%d\n\n", temp->dato);
    }
}
