#include <stdio.h>

struct Node {
  int coefficient;
  int exponent;
  struct Node *next;
}*polynomial=NULL;

void create() {
  struct Node *t, *last;
  int num, i;

  for(i = 0; i < num; i++) {
    t = (struct Node *)mallac(sizeof(struct Node));
    scanf("%d%d", &t -> coefficient, &t -> exponent);
    //linking to link list
    t -> next = NULL;
    if(polynomial)
  }
}

int main() {
  return 0;
}
