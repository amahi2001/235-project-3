#ifndef SONG_H
#define SONG_H

#include "PlaylistItem.hpp"
#include <iostream>

class Song : public PlaylistItem
{
private:
    std::string artist_;

public:
    /*
    Parameterized Construtor
    Parameters: title, length, genre, artist
    Goal: Update member variables with given parameters
*/
    Song(std::string title, double length, std::string genre,
         std::string artist);

    /************************ Getter Functions ************************/

    /*
    Goal: Return the value of artist_
*/
    std::string getArtist() const;

    /************************ Setter Functions ************************/

    /*
    Goal: Update the value of artist_ with the given parameter
*/
    void setArtist(std::string artist);

    /************************ Other Functions ************************/

    /*
    Goal: Displays the member variables to the console. 
          Format is based on the given example in songExample.txt.
*/
    void display() const;
};

#endif