#include "Song.hpp"

Song ::Song(std::string title, double length, std::string genre, std::string artist) : PlaylistItem(title, length, genre)
{
    artist_ = artist;
}

std::string Song ::getArtist() const
{
    return artist_;
}

void Song::setArtist(std::string artist)
{
    artist_ = artist;
}

void Song::display() const
{
    std::cout << getTitle() << std::endl;
    std::cout << "Artist: " << artist_ << std::endl;
    std::cout << "Genre: " << getGenre() << std::endl; 
    std::cout << "Length: "<< getLength() << std::endl; 
    std::cout << std::endl;
}
