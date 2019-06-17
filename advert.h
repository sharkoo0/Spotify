#pragma once
#include <iostream>
#include <cstring>
#include "songs.h"

using namespace std;


class advert : public song
{
private:
    char adText[512];
    size_t time;
public:
    advert() : song ()
    {
        strcpy(this->text,"Buy premium account to stop the ads!");
        this->time=30;
    }
    advert(const char* adText, size_t time, const char* name, const char* genre, size_t year, singer singer, const char* text)
    : song(name, genre, year, singer, text)
    {
        strcpy(this->adText,adText);
        this->time=time;
    }
    void playAd() const
    {
        std::cout<<this->adText<<std::endl;
    }

};
