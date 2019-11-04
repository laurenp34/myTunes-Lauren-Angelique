#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "SongNodeFunctions.h"
#include "SongLibraryFunctions.h"

int main() {
  printf("TESTING SONG NODE FUNCTIONS:\n");

  printf("create new song:\n\t");
  struct song_node * listy;
  char song[100]  = "Hello";
  char artist[100] = "Adele";
  listy=newSong(artist, song);
  listy->next=NULL;
  print_list(listy);

  printf("\nadd song to front:\n");
  insert_front(listy, "ABBA", "Dancing Queen");
  print_list(listy);

  printf("\nadd songs alphabetically:\n");
  listy=insert_song(listy, "NSYNC", "Bye Bye Bye");
  print_list(listy);
  listy=insert_song(listy, "Michael Jackson", "Thriller");
  print_list(listy);
  listy=insert_song(listy, "Prince", "Purple Rain");
  print_list(listy);
  listy=insert_song(listy,"Mg", "You");
  print_list(listy);
  listy=insert_song(listy,"Michael Jackson", "You");
  print_list(listy);
  listy=insert_song(listy, "ABC", "Harmony");
  print_list(listy);
  listy=insert_song(listy, "ABC", "Arms");
  print_list(listy);
  listy=insert_song(listy,"Zedd","Guitar Man");
  print_list(listy);
  listy=insert_song(listy,"ABC","Into it");
  print_list(listy);

  printf("\nfind songs:\n");


}
