#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "SongNodeFunctions.h"

struct song_node * newSong(char artisty[],char songy[] ){
  struct song_node *new = malloc(sizeof(struct song_node));
strncpy(new->artist, artisty, 100);
strncpy(new->name,songy,100);
return new;
}
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
    printf(" %s: %s |",newNode->artist,newNode->name);
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
  struct song_node *new = newSong(artisty,songy);
new->next=listy;
return new;
}
struct song_node * insert_song(struct song_node *listy,char artisty[],char songy[] ){
  struct song_node * newNode = listy;
  struct song_node *new = newSong(artisty,songy);
  while (newNode->next!=NULL){
    if (strcmp(artisty,newNode->next->artist)>0){
        new->next=newNode->next;
        newNode->next=new;
    }
    else if (strcmp(artisty,newNode->next->artist)==0){
      while(strcmp(artisty,newNode->next->artist)==0){
        if (strcmp(songy,newNode->next->name)>0){
            new->next=newNode->next;
            newNode->next=new;}
    }

  }
    else newNode=newNode->next;
  }
  return listy;
}
void main(){//temporary main to test as we go
struct song_node * listy;
char song[100]  = "Hello";
char artist[100] = "Adele";
listy=insert_front(listy,artist, song);
listy=insert_front(listy,"Artist 2","Song 2");
listy=insert_front(listy, "Michael Jackson", "Thriller");
listy=insert_front(listy, "NSYNC", "Bye Bye Bye");
print_list(listy);
}
