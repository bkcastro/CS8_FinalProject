//
// Created by Brandon Castro on 12/2/21.
//

#include "Images.h"

std::vector<sf::Texture> Images::images(LAST, sf::Texture());

void Images::loadImage(image img)
{
    images[img].loadFromFile(getImagePath(img));
}

std::string Images::getImagePath(image img)
{
    switch (img)
    {
        case FILE : return "Images/File.png";
        case FOLDER : return "Images/Folder.png";
        case LOGO : return "Images/Logo.jpg";
        case PLAY : return "Images/play.png";
        case PAUSE : return "Images/pause.png";
        default : return "Images/error.png";
    }
}

sf::Texture &Images::getImage(image img)
{
    loadImage(img);
    return images[img];
}