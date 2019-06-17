#include "user.h"
#include "playlist.h"

user::user()
{
    this->numberOfPlaylists=0;
    this->maxPlaylists=8;
    this->playlists=new playlist[this->maxPlaylists];
    strcpy(this->name,"");
    strcpy(this->password,"**********");
    strcpy(this->email,"default@email.email");
    this->isPremium=false;

}

user::user(const char* name, bool isPremium, const char* password, const char* email)
{
    this->numberOfPlaylists=0;
    this->maxPlaylists=8;
    this->playlists=new playlist[this->maxPlaylists];
    strcpy(this->name,name);
    strcpy(this->password,password);
    strcpy(this->email,email);
    this->isPremium=isPremium;
}

void user::play() const
{
    if (!this->isPremium)
    {
        for (size_t i=0; i<this->numberOfPlaylists; i++)
        {
            this->playlists[i].playInOrder();
        }
    }
}

void user::playByName(const char* name) const
{
    if (this->isPremium)
    {
        for (size_t i=0; i<this->numberOfPlaylists; i++)
        {
            for (size_t j=0; j<this->playlists[i].getNumber(); j++)
            {
                if (strcmp(this->playlists[i].getSong(j).getName(),name)==0)
                {
                    this->playlists[i].getSong(j).play();
                }
            }
        }
    }
}

void user::addSongInPlaylist(const song& other, size_t index)
{
    for (size_t i=0; i<this->numberOfPlaylists; i++)
    {
        if (i==index)
        {
            this->playlists[i].addSong(other);
        }
    }
}

void user::showPlaylist() const
{
    for (size_t i=0; i<this->numberOfPlaylists; i++)
    {
        cout<<this->playlists[i].getName()<<": "<<endl;
        for (size_t j=0; j<this->playlists[i].getNumber(); j++)
        {
            cout<<j<<". "<<this->playlists[i].getSong(j).getName()<<endl;
        }
        cout<<endl;
    }
}

void user::addPlaylist(const playlist& other)
{
    this->numberOfPlaylists++;
    if (this->numberOfPlaylists>this->maxPlaylists)
    {
        this->resize();
    }
    this->playlists[this->numberOfPlaylists-1]=other;
}

void user::copy(const user& other)
{
    strcpy(this->name,other.name);
    strcpy(this->password,other.password);
    strcpy(this->email, other.email);
    this->isPremium=other.isPremium;
    this->numberOfPlaylists=other.numberOfPlaylists;
    this->maxPlaylists=other.maxPlaylists;
    this->playlists=new playlist[this->maxPlaylists];
}

void user::erase()
{
    delete [] this->playlists;
}

void user::resize()
{
    this->maxPlaylists*=2;
    playlist* newsongs=new playlist[this->maxPlaylists];
    for (size_t i=0; i<this->numberOfPlaylists; i++)
    {
        newsongs[i]=this->playlists[i];
    }
    this->erase();
    this->playlists=newsongs;
}

user::user(const user& other)
{
    this->copy(other);
}

user& user::operator=(const user& other)
{
    if (this != &other)
    {
        this->erase();
        this->copy(other);
    }

    return *this;
}

user::~user()
{
    this->erase();
}




