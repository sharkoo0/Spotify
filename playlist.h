#pragma once
#include "advert.h"

class playlist
{
private:
    song* songs;
    size_t number;
    size_t capacity;
    advert ads[32];
    char name[64];
    void copy(const playlist&);
    void erase();
    void resize();
public:
    playlist();
    playlist(const playlist&);
    playlist& operator=(const playlist&);
    ~playlist();
    void addSong(const song&);
    void removeSong(const char*);
    void playInOrder() const;
    void shuffle();
    void sortAlphabetical();
    size_t getNumber() const;
    song getSong(size_t) const;
    void renamePlaylist(const char*);
    void setNumber();
    size_t getCapacity() const;
    const char* getName() const;
    void setName(const char*);
    friend ostream& operator<<(ostream& os,const playlist& other)
    {
        os<<other.name<<endl;
        for (size_t i=0; i<other.number; i++)
        {
            os<<other.songs[i]<<endl;
        }

        return os;
    }
    friend istream& operator>>(istream& is, playlist& other)
    {
        cout<<"Enter name: ";
        is>>other.name;
        cout<<"Enter number of songs: ";
        is>>other.number;
        cout<<"Enter your songs: ";
        for (size_t i=0; i<other.number; i++)
        {
            is>>other.songs[i];
        }

        return is;
    }
};




