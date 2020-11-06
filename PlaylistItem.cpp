#include "PlaylistItem.hpp"

//constructor
PlaylistItem::PlaylistItem(std::string title, double length, std::string genre)
{
    title_ = title;
    length_ = length; 
    genre_ = genre;
}
//getters
std::string PlaylistItem::getTitle() const
{
    return title_;
}

double PlaylistItem ::getLength() const
{
    return length_;
}

std::string PlaylistItem ::getGenre() const
{
    return genre_;
}

//setters
void PlaylistItem::setTitle(std::string title)
{
    title_ = title;
}

void PlaylistItem ::setLength(double length)
{
    length_ = length;
}

void PlaylistItem ::setGenre(std::string genre)
{
    genre_ = genre;
}