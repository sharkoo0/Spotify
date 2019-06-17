#pragma once
#include "playlist.h"

class user
{
private:
    char name[64];
    playlist* playlists;
    bool isPremium;
    char password[32];
    char email[64];
    size_t numberOfPlaylists;
    size_t maxPlaylists;
    void copy(const user&);
    void erase();
    void resize();
public:
    user();
    user(const char* , bool , const char* , const char* );
    user(const user&);
    user& operator=(const user&);
    ~user();
    void playByName(const char*) const;
    void play() const;
    void addSongInPlaylist(const song&,size_t);
    void showPlaylist() const;
    void addPlaylist(const playlist&);
    friend ostream& operator<<(ostream& os,const user& other)
    {
        os<<other.name<<endl;
        os<<other.email<<endl;
        os<<other.password<<endl;
        os<<other.isPremium<<endl;
        for (size_t i=0; i<other.numberOfPlaylists; i++)
        {
            os<<other.playlists[i]<<endl;
        }

        return os;
    }
    friend istream& operator>>(istream& is, user& other)
    {
        cout<<"Enter name: ";
        is>>other.name;
        cout<<"Enter email: ";
        is>>other.email;
        cout<<"Enter password: ";
        is>>other.password;
        cout<<"Is you account premium? ";
        is>>other.isPremium;
        cout<<"Enter number of playlists: ";
        is>>other.numberOfPlaylists;
        cout<<"Enter your playlists: ";
        for (size_t i=0; i<other.numberOfPlaylists; i++)
        {
            is>>other.playlists[i];
        }

        return is;
    }
};
