// struct song_node {
// char name[100];
// char artist[100];
// struct song_node *next; };
struct song_node * table[27];
void add_song(char * artist, char *song);
struct song_node * search_song(char *artist, char *song);
struct song_node * search_artist(char *artist);
void print_letter(char a);
void print_artist(char *artist);
void print_library();
void shuffle();
void delete_song();
void clear();
/*Add song nodes.
Search for a song given song and artist name (return a pointer).
Search for an artist.
Print out all the entries under a certain letter.
Print out all the songs of a certain artist
Print out the entire library.
Shuffle - print out a series of randomly chosen songs.
Delete a song
Clear the library.
*/
