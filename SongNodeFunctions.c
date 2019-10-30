#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "SongNodeFunctions.h"

void print_list(struct song_node * myNode) {
  //make new node copy, so as not to modify original pointer.
  struct song_node * newNode = myNode;
  //if current node is null, print nothing!
  if (newNode == NULL) {
    printf("{}");
    return;
  }
  //if it's not null:
  //loop which stops once there is no next node.
  while (newNode->next != NULL) {
    printf(" %s: %s ",newNode->artist,newNode->name);
    newNode = newNode->next;
  }
  //there is no next node, but still need to print current (last) node:
  printf(" %s: %s ",newNode->artist,newNode->name);
  printf("\n");
  //nvm if there is no next
  //printf("]");
  return;
}
struct song_node * insert_front(struct song_node *listy,char artisty[],char songy[] ){
  struct song_node *new = malloc(sizeof(struct song_node));
//new->artist=artisty;
strncpy(new->artist, artisty, 100);
strncpy(new->name,songy,100);
return new;
}
void main(){//temporary main to test as we go
struct song_node * listy = malloc(sizeof(struct song_node));
char song[100]  = "Hello";
char artist[100] = "Adele";
listy=insert_front(listy,artist, song);
print_list(listy);
}
