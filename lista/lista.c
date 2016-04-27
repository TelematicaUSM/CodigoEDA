#include <stdio.h>
#include <stdlib.h>

struct molde_nodo
{
  int data;
  struct molde_nodo *next;
};
typedef struct molde_nodo nodo;

void
push (nodo ** headref, int dato)
{
  nodo *newnode = (nodo *) malloc (sizeof (nodo));
  newnode->data = dato;

  newnode->next = *headref;
  *headref = newnode;
}

int
pop (nodo ** headref)
{
  int result = 0;
  nodo *temp;

  if (*headref != NULL)
    {
      result = (*headref)->data;
      temp = *headref;
      *headref = (*headref)->next;
      free (temp);
    }

  return result;
}

void
imprime_inverso (nodo * head)
{
  if (head != NULL)
    {
      imprime_inverso (head->next);
      printf ("inverso : %d\n", head->data);
    }

}

void
imprime (nodo * head)
{
  while (head != NULL)
    {
      printf ("%d\n", head->data);
      head = head->next;
    }
}

int
main ()
{
  nodo *lista = NULL;
  int i = 0;
  for (i = 1; i <= 20; i++)
    push (&lista, i);

  imprime (lista);

  for (i = 1; i < 6; i++)
    printf ("salio el: %d\n", pop (&lista));

  imprime (lista);
  imprime_inverso (lista);
}
