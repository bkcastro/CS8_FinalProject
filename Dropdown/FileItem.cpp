//
// Created by Brandon Castro on 12/7/21.
//

#include "FileItem.h"

FileItem::FileItem() {
    Item::deactivateBorder();
    Item::setTask(FILETYPE);
}

//FileItem::FileItem(Images::image icon, std::string text, sf::Vector2f position) : FileItem(icon, text, Item::getFitSize(Helper::getTitle(text)),position)
//{}

FileItem::FileItem(Images::image icon, std::string text, sf::Vector2f size, sf::Vector2f position)
{
    this->icon.setTexture(Images::getImage(icon));
    this->icon.setPosition(position);
    this->addressString = text;
    this->address = Helper::split(text);

    Item::deactivateBorder();


    if (icon == Images::image::FOLDER)
    {
        this->icon.scale({.04,.04});
    }
    else
    {
        this->icon.scale({.087,.087});
    }



    std::string temp = Helper::getTitle(text);

    Item::setText(temp);
    Item::setSize(size);
    Item::setPosition(position);
}

void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    Item::draw(window, states);
    window.draw(this->icon);
}

void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    Item::addEventHandler(window, event);

}

void FileItem::update()
{
    Item::update();
}

sf::FloatRect FileItem::getGlobalBounds() const
{
    return Item::getGlobalBounds();
}

sf::Vector2f FileItem::getSize() const
{
    return Item::getSize();
}

sf::Vector2f FileItem::getPosition() const
{
    return Item::getPosition();
}

void FileItem::setPosition(sf::Vector2f pos)
{
    icon.setPosition(pos);
    Item::setPosition(pos);
}

void FileItem::setSize(sf::Vector2f size)
{
    Item::setSize(size);
}

void FileItem::setText(std::string text)
{
    this->addressString = text;
    this->address = Helper::split(text);

    Item::setText(Helper::getTitle(text));
}

void FileItem::setIcon(Images::image icon)
{
    this->icon.setTexture(Images::getImage(icon));

    if (icon == Images::image::FOLDER)
    {
        this->icon.scale({.04,.04});
    }
    else
    {
        this->icon.scale({.087,.087});
    }
}

std::string FileItem::getAddress() const
{
    return addressString;
}