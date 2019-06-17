#include "songs.h"

void song::copy(const song& other)
{
    this->lenght=other.lenght;
    this->capacity=other.capacity;
    this->name=new char[this->capacity];
    strcpy(this->name, other.name);
    this->year=other.year;
    this->views=other.views;
    strcpy(this->genre,other.genre);
    this->Singer=other.Singer;
    this->textSize=0;
    this->textCap=512;
    this->text=new char[this->textCap];
    strcpy(this->text,other.text);
    this->Singer.setNumberOfSongs(1);
}

void song::erase()
{
    delete [] this->name;
    delete [] this->text;
}

song::song()
{
    this->lenght=0;
    this->capacity=8;
    this->name=new char[this->capacity];
    strcpy(this->name,"");
    strcpy(this->genre, "music");
    this->views=0;
    this->year=2019;
    singer singer;
    this->textSize=0;
    this->textCap=512;
    this->text=new char[this->textCap];
    strcpy(this->text,"");
    this->Singer.setNumberOfSongs(1);
}

song::song(const char* name, const char* genre, size_t year, singer singer, const char* text)
{
    this->name= new char[strlen(name)+1];
    this->lenght=strlen(name);
    strcpy(this->name,name);
    this->capacity=this->lenght+1;
    strcpy(this->genre,genre);
    this->year=year;
    this->views=0;
    this->Singer=singer;
    this->textSize=strlen(text);
    this->textCap=strlen(text)+1;
    this->text=new char[this->textCap];
    strcpy(this->text,text);
    this->Singer.setNumberOfSongs(1);
}

song::song(const song& other)
{
    this->copy(other);
}

song& song::operator=(const song& other)
{
    if (this!=&other)
    {
        this->erase();
        this->copy(other);
    }

    return *this;
}

song::~song()
{
    this->erase();
}

size_t song::getLenght() const
{
    return this->lenght;
}

const char* song::getName() const
{
    return this->name;
}

void song::play() const
{
    cout<<"The name of the song is "<<this->name<<endl;
    cout<<"The genre is "<<this->genre<<endl;
    cout<<"Published in "<<this->year<<endl;
    cout<<"With "<<this->views<<" views"<<endl;
    cout<<"And the singer is: "<<endl;
    this->Singer.print();
    cout<<"The song's text is: "<<this->text<<endl;

    cout<<endl;
}

void song::setName(const char* name)
{
    strcpy(this->name, name);
}

void song::makeAd()
{
    this->isAd = true;
}

bool song::getIsAd() const
{
    return this->isAd;
}
