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
void print_song(struct song_node * myNode){
printf(" %s: %s |",myNode->artist,myNode->name);
}
void print_list(struct song_node * myNode) {
  //make new node copy, so as not to modify original pointer.
  struct song_node * newNode = myNode;
  //if current node is null, print nothing!
  if (newNode == NULL) {
    printf("{}\n");
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

void debug_print_list(struct song_node * myNode) {
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
    printf(" %s: %s |\n",newNode->artist,newNode->name);
    printf("NEXT:: %s: %s\n\n", newNode->next->artist, newNode->next->name);
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
struct song_node * find_artist(struct song_node *listy,char *artisty){
struct song_node * newNode = listy;
while (newNode!=NULL){
if (strcmp(newNode->artist, artisty)==0){
  return newNode;
}
newNode=newNode->next;
}
return NULL;
}
int findlength(struct song_node *listy){
  int length=0;
  struct song_node * newNode = listy;
  while (newNode!=NULL){
    length++;
    newNode=newNode->next;
  }
  return length;
}
struct song_node * randomly(struct song_node *listy){
  srand(time(NULL));
  int length=findlength(listy);
  int a =rand()%length;
  //printf("A is: %d",a);
    struct song_node * newNode = listy;
  while (a>0){
    newNode=newNode->next;
      a--;
  }
  return newNode;
}

struct song_node * remove_song(struct song_node * listy, char * artist, char * song) {
  if (listy == NULL) return listy;
  struct song_node * current = listy;
  //if first node is a match:
  if (strcmp(current->artist,artist)==0 && strcmp(current->name,song)==0) {
    //return 2nd node (to be new start)
    current = current->next;
    free(listy);
    return current;
  }
  //will stop at 2nd to last node(which checks last node)
  while (current->next->next != NULL) {
    //if artist and song matches (compare strings)
    if (strcmp(current->next->artist,artist)==0 && strcmp(current->next->name,song)==0) {
      //set prev node to next one after skip
      // print_song(current); printf("   ->    "); print_song(current->next->next);
      // printf("\nremoving: ");
      // print_song(current->next);
      struct song_node * temp = current;
      current->next=current->next->next;
      // printf("\n\n");
      // // debug_print_list(listy);
      // free(temp->next->artist);
      // free(temp->next->name);

      //^^ every time  Itried freeing the data, the next node's name was messed up.

      // debug_print_list(listy);

      // printf("\n\n");
      // debug_print_list(listy);
      // printf("\n%s\n",current->next->name);
      return listy;
    }
    current=current->next;
  }
  //check the last song:
  //was on 2nd to last node (even though already checked to see if match):
  if (strcmp(current->next->artist,artist)==0 && strcmp(current->next->name,song)==0) {
    //set new last node to have null next (current is new last bc it is second to last)
    current->next = NULL;
    free(current->next);
    return listy;
  }
  //song not found:
  return listy;
}


int main(){//temporary main to test as we go
struct song_node * listy;
struct song_node * other;
char song[100]  = "Hello";
char artist[100] = "Adele";
listy=newSong(artist, song);
listy->next=NULL;
//listy=insert_front(listy,"Artist 2","Song 2");
listy=insert_song(listy, "Michael Jackson", "Thriller");
listy=insert_song(listy, "NSYNC", "Bye Bye Bye");
listy=insert_song(listy, "Prince", "Purple Rain");

//testing remove:
printf("------------------");
debug_print_list(listy);
printf("\n");
remove_song(listy, "Michael Jackson", "Thriller");
print_list(listy);
printf("\n");
remove_song(listy, "Prince", "Purple Rain");
print_list(listy);

printf("------------------------\n\n");

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
printf("\nLooking for Michael Jackson\n");
other=find_artist(listy,"Michael Jackson");
print_list(other);
printf("\nGenerating random song:\n");
other=randomly(listy);
print_song(other);
printf("\nGenerating random song:\n");
other=randomly(listy);
print_song(other);
return 0;
}
