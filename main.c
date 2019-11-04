#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "SongNodeFunctions.h"
//#include "SongNodeFunctions.c"
//#include "SongLibraryFunctions.c"
#include "SongLibraryFunctions.h"

int main() {
  printf("TESTING SONG NODE FUNCTIONS:\n");

  printf("CREATE NEW SONG:\n\t");
  struct song_node * listy;
  char song[100]  = "Hello";
  char artist[100] = "Adele";
  listy=newSong(artist, song);
  listy->next=NULL;
  print_list(listy);

  printf("\nADD SONGS TO FRONT:\n");
  insert_front(listy, "ABBA", "Dancing Queen");
  print_list(listy);

  printf("\nADD SONGS ALPHABETICALLY:\n");
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

  printf("\nFIND SONGS:\n");
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
  printf("\nLooking for Michael Jackson: Thriler\n");
  find_song(listy, "Michael Jackson", "Thriler");

  printf("\nFIND ARTISTS:\n");
  struct song_node * other;
  printf("\nLooking for Michael Jackson\n");
  other=find_artist(listy,"Michael Jackson");
  print_list(other);
  printf("\nLooking for ABC\n");
  other=find_artist(listy,"ABC");
  print_list(other);
  printf("\nLooking for Zedd\n");
  other=find_artist(listy,"Zedd");
  print_list(other);
  printf("\nLooking for Taylor Swift\n");
  other=find_artist(listy,"Taylor Swift");
  print_list(other);

  printf("\nTESTING RANDOM SONG:\n");
  srand(time(NULL));
  printf("\nGenerating random song:\n");
  other=randomly(listy);
  print_song(other);
  printf("\nGenerating random song:\n");
  other=randomly(listy);
  print_song(other);

  printf("\n\nTESTING REMOVE SONG:\n");
  printf("Remove first song- ABC: Arms\n");
  listy = remove_song(listy, "ABC", "Arms");
  print_list(listy);
  printf("Remove last song- Zedd: Guitar Man\n");
  listy = remove_song(listy, "Zedd", "Guitar Man");
  print_list(listy);
  printf("Remove middle song- Mg: You\n");
  listy = remove_song(listy, "Mg", "You");
  print_list(listy);
  printf("Remove last song- Prince: Purple Rain\n");
  listy = remove_song(listy, "Prince", "Purple Rain");
  print_list(listy);
  printf("Remove first song- ABC: Harmony\n");
  listy = remove_song(listy, "ABC", "Harmony");
  print_list(listy);
  printf("Remove wrong song- Calvin Harris: Slide\n");
  listy = remove_song(listy, "Calvin Harris", "Slide");
  print_list(listy);

  printf("\n\nTESTING FREE_LIST:\n");
  listy = free_list(listy);
  print_list(listy);

  printf("\n\n-------------------------\n");
  printf("TESTING SONG LIBRARY FUNCTIONS:\n");
  printf("-------------------------\n\n");

  printf("TESTING ADD SONGS:\n");
  printf("\tAdding artists for each letter...\n");
  add_song("ABBA", "Dancing Queen");
  add_song("Bazzi", "Mine");
  add_song("Beyonce", "Blue");
  add_song("Billy Joel", "Uptown Girl");
  add_song("Creedence Clearwater Revival", "Have You Ever Seen The Rain");
  add_song("Chance the Rapper", "Angels");
  add_song("Drake", "Hotline Bling");
  add_song("Daniel Caesar", "Japanese Denim");
  add_song("Ed Sheeran", "Photograph");
  add_song("Frank Sinatra", "Fly Me To The Moon");
  add_song("Flo Rida", "Whistle");
  add_song("G-Eazy", "Me Myself & I");
  add_song("H.E.R", "Best Part");
  add_song("Hozier","Take Me To Church");
  add_song("Iggy Azalea", "Kream");
  add_song("J Cole", "Middle Child");
  add_song("Joji", "SLOW DANCING IN THE DARK");
  add_song("Kanye West", "Coldest Winter");
  add_song("Kanye West", "Ultralight Beam");
  add_song("King Princess", "Talia");
  add_song("Lana Del Rey", "Radio");
  add_song("Lizzo", "Good as Hell");
  add_song("Logic", "1-800-273-8255");
  add_song("Mac Miller", "Small Worlds");
  add_song("Michael Jackson", "Billie Jean");
  add_song("Maroon 5", "Memories");
  add_song("Nicki Minaj", "Anaconda");
  add_song("One Direction", "Night Changes");
  add_song("Pitbull", "Time Of Our Lives");
  add_song("Pharrell Williams", "Happy");
  add_song("Queen", "Don't Stop Me Now");
  add_song("Queen", "Bohemian Rhapsody");
  add_song("Rex Orange County", "Best Friend");
  add_song("Rich Brian", "100 Degrees");
  add_song("SZA", "The Weekend");
  add_song("Sia", "Chandelier");
  add_song("Simon and Garfunkel", "Mrs. Robinson");
  add_song("The Beatles", "Yesterday");
  add_song("The Rolling Stones", "Satisfaction");
  add_song("Tracy Chapman", "Fast Car");
  add_song("The Kinks", "Lola");
  add_song("Usher", "DJ Got Us Falling in Love");
  add_song("U2", "With Or Without You");
  add_song("Vance Joy", "Riptide");
  add_song("Wu-Tang Clan", "C.R.E.A.M");
  add_song("Wiz Khalifa", "Black and Yellow");
  add_song("X Ambassadors", "Renegades");
  add_song("Y2K", "Lalala");
  add_song("Zedd", "The Middle");
  add_song("Zara Larsson", "Lush Life");

  print_library();

  printf("\n\nTESTING FIND SONG: \n");
  printf("Find Pharrell Williams: Happy\n");
  search_song("Pharrell Williams", "Happy");
  printf("\nFind Flo Rida: Whistle\n");
  search_song("Flo Rida", "Whistle");
  printf("\nFind Billy Joel: Uptown Girl\n");
  search_song("Billy Joel", "Uptown Girl");
  printf("\nFind The Beatles: Penny Lane\n");
  search_song("The Beatles", "Penny Lane");

  printf("\n\nTESTING SEARCH ARTIST:\n");
  printf("Searching for Lana Del Rey: \n");
  other = search_artist("Lana Del Rey");
  printf("Searching for Queen: \n");
  other = search_artist("Queen");
  printf("Searching for Taylor Swift: \n");
  other = search_artist("Taylor Swift");

  printf("\n\nTESTING PRINT LETTER: \n");
  print_letter('e');
  print_letter('z');
  print_letter('h');

}
