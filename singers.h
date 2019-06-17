#pragma once
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class singer
{
private:
    char* singersName;
    size_t size;
    size_t cap;
    bool gender; ///true is male, false is female
    size_t career;
    size_t numberOfSongs;
    void copy(const singer&);
    void erase();
public:
    singer();
    singer(const char*, bool);
    singer(const singer&);
    singer& operator=(const singer&);
    ~singer();
    void print() const;
    void setNumberOfSongs(size_t);
    friend ostream& operator<<(ostream& os,const singer& other)
    {
        os<<"Singer's name: "<<other.singersName<<endl;
        os<<"Gender: "<<other.gender<<endl;
        os<<"Career: "<<other.career<<" years"<<endl;
        os<<"Number of songs: "<<other.numberOfSongs<<endl;

        return os;
    }
    friend istream& operator>>(istream& is, singer& other)
    {
        cout<<"Enter singer's name: ";
        is>>other.singersName;
        cout<<"Enter singer's gender (1 = male, 0 = female) ";
        is>>other.gender;
        cout<<"How many year he/she is on the stage? ";
        is>>other.career;
        cout<<"How many songs has the singer? ";
        is>>other.numberOfSongs;

        return is;
    }
};






