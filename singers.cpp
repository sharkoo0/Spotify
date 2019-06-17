#include "singers.h"

void singer::copy(const singer& other)
{
    this->size=other.size;
    this->cap=other.cap;
    this->singersName=new char[strlen(other.singersName)+1];
    strcpy(this->singersName,other.singersName);
    this->gender=other.gender;
    this->career=other.career;
    this->numberOfSongs=other.numberOfSongs;
}

void singer::erase()
{
    delete [] this->singersName;
}

singer::singer()
{
    this->size=0;
    this->cap=8;
    this->career=0;
    this->singersName=new char[this->cap];
    strcpy(this->singersName, "" );
    this->numberOfSongs=0;
    this->gender=true;
}

singer::singer(const char* name, bool gender)
{
    this->gender=gender;
    this->singersName=new char[strlen(name)+1];
    this->size=strlen(name);
    this->cap=strlen(name)+1;
    strcpy(this->singersName, name);
    this->numberOfSongs=0;
    this->career=0;
}

singer& singer::operator=(const singer& other)
{
    if (this!=&other)
    {
        this->erase();
        this->copy(other);
    }

    return *this;
}

singer::singer(const singer& other)
{
    this->copy(other);
}

singer::~singer()
{
    this->erase();
}

void singer::print() const
{
    cout<<"Name: "<<this->singersName<<endl;
    cout<<"He is "<<this->gender<<". //1 = male, 0 = female"<<endl;
    cout<<"He is on the stage for "<< this->career<<" years."<<endl;
    cout<<"He has "<<this->numberOfSongs<<" songs upto now"<<endl;
}

void singer::setNumberOfSongs(size_t i)
{
    this->numberOfSongs=i;
}




