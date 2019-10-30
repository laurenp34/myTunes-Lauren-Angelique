struct song_node {
char name[100];
char artist[100];
struct song_node *next; };
struct song_node * newNode(char artisty[],char songy[] );
struct song_node * insert_song(struct song_node *listy,char *artist,char *song );
struct song_node * insert_front(struct song_node *listy,char *artist,char *song );
void print_list(struct song_node *listy);
struct song_node * find_song(struct song_node *listy, char *artist, char *song);
struct song_node * find_artist(struct song_node *listy,char *artist);
struct song_node * randomly(struct song_node *listy);
struct song_node * remove_song(struct song_node * listy,char *artist, char *song);
struct song_node * free_list(struct song_node *listy);
