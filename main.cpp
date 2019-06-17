#include "user.h"

using namespace std;

int main()
{
    cout<<"Singer test"<<endl;

    singer s;
    s.print();
    singer S("goshu", false);
    S.print();
    singer a(s);
    a.print();
    a=S;
    a.print();

    cout<<endl<<endl<<endl<<"Song test"<<endl;

    song first;
    first.play();
    song second("dadada", "rap", 2016, S, "dadasdadadasdasfds");
    second.play();

    cout<<endl<<endl<<endl<<"Playlist test"<<endl;

    playlist songs;
    songs.playInOrder();
    songs.addSong(first);
    songs.addSong(second);
    songs.playInOrder();
    songs.removeSong("dadada");
    songs.playInOrder();
    songs.addSong(second);
    songs.sortAlphabetical();
    songs.playInOrder();

    cout<<endl<<endl<<endl<<"User test"<<endl;

    user user1;
    user1.showPlaylist();
    user1.addSongInPlaylist(first,1);
    user1.showPlaylist();

    cout<<endl<<endl<<endl<<"Sorting test"<<endl;

    playlist q;
    playlist w;
    first.setName("baba");
    second.setName("abaa");
    q.addSong(first);
    q.addSong(second);
    q.sortAlphabetical();
    cout<<q;

    return 0;
}
