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
  printf(" %s: %s",newNode->artist, newNode->name);
  //there is no next node, but still need to print current (last) node:
  //printf(" %s: %s ",newNode->artist,newNode->name);
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
  //to put it at the front
  if (strcmp(artisty,newNode->artist)<0){
    new->next=listy;
    return new;
  }
  if (strcmp(artisty,newNode->artist)==0){
    if (strcmp(songy,newNode->name)<0){
      new->next=listy;
      return new;}
    }
  while (newNode->next!=NULL){
    if (strcmp(artisty,newNode->next->artist)<0){
        new->next=newNode->next;
        newNode->next=new;
        return listy;
    }
    else if (strcmp(artisty,newNode->next->artist)==0){
      while(strcmp(artisty,newNode->next->artist)==0){
        if (strcmp(songy,newNode->next->name)<0){
            new->next=newNode->next;
            newNode->next=new;
            return listy;}
    newNode=newNode->next;}
  }
    else newNode=newNode->next;
  }
  newNode->next=new;
  new->next=NULL;
  return listy;
}
struct song_node * find_song(struct song_node *listy, char *artisty, char *songy){
    struct song_node * newNode = listy;
while (newNode!=NULL){
  if (strcmp(newNode->artist, artisty)==0 && strcmp(newNode->name,songy)==0){
    printf("Song found!\n");
    printf("%s: %s\n",artisty,songy);
    return newNode;
  }
  newNode=newNode->next;
}
printf("Song not found!\n");
return NULL;
}

void main(){//temporary main to test as we go
struct song_node * listy;
char song[100]  = "Hello";
char artist[100] = "Adele";
listy=newSong(artist, song);
listy->next=NULL;
//listy=insert_front(listy,"Artist 2","Song 2");
listy=insert_song(listy, "Michael Jackson", "Thriller");
listy=insert_song(listy, "NSYNC", "Bye Bye Bye");
char a = 'a';
char b= 'b';
char * lettera = &a;
char * letterb = &b;
//printf("comparing a to be: %d", strcmp(lettera,letterb));
print_list(listy);
listy=insert_song(listy,"Mg", "You");
printf("\n");
listy=insert_song(listy,"Michael Jackson", "You");
listy=insert_song(listy, "ABC", "Harmony");
listy=insert_song(listy, "ABC", "Arms");
listy=insert_song(listy,"Zedd","Guitar Man");
listy=insert_song(listy,"ABC","Into it");
print_list(listy);
printf("\nLooking for Michael Jackson: Thriller\n");
find_song(listy,"Michael Jackson","Thriller");
printf("\nLooking for Zedd: Guitar Man\n");
find_song(listy,"Zedd","Guitar Man");
print_list(listy);
printf("\nLooking for ABC: Arms\n");
find_song(listy,"ABC","Arms");
printf("\nLooking for ABC: Hello\n");
find_song(listy,"ABC","Hello");
printf("\nLooking for Taylor Swift: Love Story\n");
find_song(listy,"Taylor Swift","Love Story");
}
