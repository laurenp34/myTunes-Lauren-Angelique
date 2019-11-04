#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "SongLibraryFunctions.h"
#include "SongNodeFunctions.h"
// #include "SongNodeFunctions.c"

void initialize_table() {
  int i=0;
  for (int i=0;i<27;i++) {
    table[i] = NULL;
  }
}

void add_song(char * artist, char *song) {
  int listNum = artist[0]-65;
  // printf("list %c\n",(listNum+49)+'0');
  if (table[listNum]==NULL) {
    table[listNum] = newSong(artist,song);
  } else {
    table[listNum] = insert_song(table[listNum], artist, song);
  }
}

struct song_node * search_song(char *artist, char *song) {
  int listNum = artist[0]-65;
  return find_song(table[listNum],artist,song);
}

void print_library() {
  char i=0;
  int empty =0;
  for (i=0;i<27;i++){
    //don't print list if empty
    if (table[i]!=NULL) {
      printf("%c list\n ", (i+49)+'0');
      print_list(table[i]);
      empty=1;
    }
  }
  if (empty==0){
    printf("Library is empty!\n");
  }
}

struct song_node * search_artist(char *artist) {
  int listNum = artist[0]-65;
  return find_artist(table[listNum], artist);
}

void print_letter(char a) {
  int listNum = a - 97;
  if (listNum > 26) {
    return;
  }
  printf("%c list:",a);
  print_list(table[listNum]);
}
void shuffle(){
  int i =0;
  int a =rand()%26;
  for (i=0;i<3;i++){
    print_song(randomly(table[a]));
    a=rand()%26;
  }
}
void delete_song(char *artist, char *song){
  int listNum = artist[0]-65;
  table[listNum]=remove_song(table[listNum],artist,song);
}
void clear(){
  int i;
  for (i=0;i<27;i++){
    free_list(table[i]);
  }
  initialize_table();
}
// int main()  {
//   printf("%d", 'a');
//   return 0;
// }
// int main(){
//   // char test[100] = "ABCDEF";
//   // printf(" %d ",test[0]-65);
//   // printf(" %d ",test[3]-65);
//   // char i = 67;
//   // printf("%d: %c",'S'-65,(49+0)+'0');
//   // return 0;
//   add_song("The Beatles", "Yesterday");
//   print_library();
// }
// int main() {
//   printf("\tAdding artists for each letter...\n");
//   add_song("ABBA", "Dancing Queen");
//   add_song("Bazzi", "Mine");
//   add_song("Beyonce", "Blue");
//   add_song("Billy Joel", "Uptown Girl");
//   add_song("Creedence Clearwater Revival", "Have You Ever Seen The Rain");
//   add_song("Chance the Rapper", "Angels");
//   add_song("Drake", "Hotline Bling");
//   add_song("Daniel Caesar", "Japanese Denim");
//   add_song("Ed Sheeran", "Photograph");
//   add_song("Frank Sinatra", "Fly Me To The Moon");
//   add_song("Flo Rida", "Whistle");
//   add_song("G-Eazy", "Me Myself & I");
//   add_song("H.E.R", "Best Part");
//   add_song("Hozier","Take Me To Church");
//   add_song("Iggy Azalea", "Kream");
//   add_song("J Cole", "Middle Child");
//   add_song("Joji", "SLOW DANCING IN THE DARK");
//   add_song("Kanye West", "Coldest Winter");
//   add_song("Kanye West", "Ultralight Beam");
//   add_song("King Princess", "Talia");
//   add_song("Lana Del Rey", "Radio");
//   add_song("Lizzo", "Good as Hell");
//   add_song("Logic", "1-800-273-8255");
//   add_song("Mac Miller", "Small Worlds");
//   add_song("Michael Jackson", "Billie Jean");
//   add_song("Maroon 5", "Memories");
//   add_song("Nicki Minaj", "Anaconda");
//   add_song("One Direction", "Night Changes");
//   add_song("Pitbull", "Time Of Our Lives");
//   add_song("Pharrell Williams", "Happy");
//   add_song("Queen", "Don't Stop Me Now");
//   add_song("Queen", "Bohemian Rhapsody");
//   add_song("Rex Orange County", "Best Friend");
//   add_song("Rich Brian", "100 Degrees");
//   add_song("SZA", "The Weekend");
//   add_song("Sia", "Chandelier");
//   add_song("Simon and Garfunkel", "Mrs. Robinson");
//   add_song("The Beatles", "Yesterday");
//   add_song("The Rolling Stones", "Satisfaction");
//   add_song("Tracy Chapman", "Fast Car");
//   add_song("The Kinks", "Lola");
//   add_song("Usher", "DJ Got Us Falling in Love");
//   add_song("U2", "With Or Without You");
//   add_song("Vance Joy", "Riptide");
//   add_song("Wu-Tang Clan", "C.R.E.A.M");
//   add_song("Wiz Khalifa", "Black and Yellow");
//   add_song("X Ambassadors", "Renegades");
//   add_song("Y2K", "Lalala");
//   add_song("Zedd", "The Middle");
//   add_song("Zara Larsson", "Lush Life");
//
//   print_library();
//   return 0;
// }
