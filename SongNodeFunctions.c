#include <stdlib.h>
#include <stdio.h>

void print_list(struct song_node * myNode) {
  //make new node copy, so as not to modify original pointer.
  struct songnode * newNode = myNode;
  //if current node is null, print nothing!
  if (newNode == NULL) {
    return;
  }
  //if it's not null:
  //loop which stops once there is no next node.
  while (newNode->next != NULL) {
    printf(" %s: %s |on",newNode->artist,newNode->name);
    newNode = newNode->next;
  }
  //there is no next node, but still need to print current (last) node:
  printf(" %s: %s ",newNode->artist,newNode->name);
  //nvm if there is no next
  //printf("]");
  return;
}
