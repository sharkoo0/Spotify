#include "playlist.h"


void playlist::copy(const playlist& other)
{
    this->number=other.number;
    this->capacity=other.capacity;
    this->songs=new song[this->capacity];
    for (size_t i=0; i<this->number; i++)
    {
        this->songs[i]=other.songs[i];
    }
    strcpy(this->name,other.name);
}

void playlist::erase()
{
    delete [] this->songs;
}

void playlist::resize()
{
    this->capacity*=2;
    song* newSongs=new song[this->capacity];
    for (size_t i=0; i<this->songs->getLenght(); i++)
    {
        newSongs[i]=this->songs[i];
    }
    this->erase();
    this->songs=newSongs;
}

playlist::playlist()
{
    strcpy(this->name,"");
    this->number=0;
    this->capacity=8;
    this->songs=new song[this->capacity];
}

playlist::playlist(const playlist& other)
{
    this->copy(other);
}

playlist& playlist::operator=(const playlist& other)
{
    if (this!=&other)
    {
        this->erase();
        this->copy(other);
    }

    return *this;
}

playlist::~playlist()
{
    this->erase();
}
void playlist::addSong(const song& song)
{
    this->number++;
    if (this->number>this->capacity)
    {
        this->resize();
    }
    this->songs[this->number-1]=song;
}

void playlist::removeSong(const char* name)
{
    for (size_t i=0; i<this->number; i++)
    {
        if (strcmp(this->songs[i].getName(),name)==0)
        {
            for (size_t j=i; j<this->number-1; j++)
            {
                this->songs[j]=this->songs[j+1];
            }
            this->number--;
            return;
        }
    }
}

void playlist::playInOrder() const
{
    int counter=0;
    for (size_t i=0; i<this->number; i++)
    {
        this->songs[i].play();
        cout<<endl;
        counter++;
        for (size_t j=0; j<32; j++)
        {
            if (counter==3)
            {
                this->ads[j].play();
                counter=0;
                continue;
            }
            else continue;
        }
    }
}

void playlist::sortAlphabetical()
{
    for (size_t i=0; i<this->number; i++)
    {
        for (size_t j=0; j<this->number-1; j++)
        {
            if (strcmp(this->songs[i].getName(), this->songs[j].getName()))
            {
                swap(this->songs[i],this->songs[j]);
            }
        }
    }
}

size_t playlist::getNumber() const
{
    return this->number;
}

song playlist::getSong(size_t index) const
{
    return this->songs[index];
}

void playlist::renamePlaylist(const char* name)
{
    strcpy(this->name,name);
}

void playlist::setNumber()
{
    this->number++;
}

size_t playlist::getCapacity() const
{
    return this->capacity;
}

const char* playlist::getName() const
{
    return this->name;
}

void playlist::setName(const char* name)
{
    strcpy(this->name, name);
}
