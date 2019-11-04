#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "SongLibraryFunctions.h"
#include "SongNodeFunctions.h"

void add_song(char * artist, char *song) {
  int listNum = artist[0]-65;
  insert_song(table[listNum], artist, song);
}

// int main(){
//   char test[100] = "ABCDEF";
//   printf(" %d ",test[0]-65);
//   printf(" %d ",test[3]-65);
//   return 0;
// }
