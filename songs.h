#include "singers.h"

using namespace std;

class song
{
protected:
    char* name;
    size_t lenght;
    size_t capacity;
    char genre[32];
    size_t year;
    size_t views;
    singer Singer;
    char* text;
    size_t textSize;
    size_t textCap;
    bool isAd;
    void copy(const song&);
    void erase();
public:
    song();
    song(const char*, const char*, size_t year, singer, const char*);
    song(const song&);
    virtual song& operator=(const song&);
    virtual ~song();
    size_t getLenght() const;
    const char* getName() const;
    virtual void play() const;
    singer getSinger() const;
    void setName(const char*);
    friend ostream& operator<<(ostream& os,const song& other)
    {
        os<<"Song's name: "<<other.name<<endl;
        os<<"Song's genre: "<<other.genre<<endl;
        os<<"Published: "<<other.year<<endl;
        os<<"Views: "<<other.views<<endl;
        os<<other.Singer;
        os<<"Text: "<<other.text<<endl;

        return os;
    }
    friend istream& operator>>(istream& is, song& other)
    {
        cout<<"Enter name: ";
        is>>other.name;
        cout<<"Enter song's genre: ";
        is>>other.genre;
        cout<<"Enter year of publishing: ";
        is>>other.year;
        cout<<"How many views has the song? ";
        is>>other.views;
        cout<<"How is the singer? ";
        is>>other.Singer;
        cout<<"Enter text: ";
        is>>other.text;

        return is;
    }
    virtual void makeAd();
    bool getIsAd() const;
};









