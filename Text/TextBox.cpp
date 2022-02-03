//
// Created by Brandon Castro on 12/10/21.
//

#include "TextBox.h"


TextBox::TextBox() : TextBox({0,0},{200,40}) {

}

TextBox::TextBox(sf::Vector2f pos, sf::Vector2f size) : TextBox("", pos,size){

}

TextBox::TextBox(std::string input, sf::Vector2f pos, sf::Vector2f size)
{
    sf::FloatRect hold(pos, size);
    absolute = hold;

    enableState(DISABLE);
    text.enableCursor();

    if (input.empty())
    {
        title.setString(input); // no title
        title.setPosition(pos);

        box.setPosition(pos);
        box.setSize(size);

        text.setPosition({pos.x+2, pos.y});
        text.setParameter({size.x-5,size.y});
    }
    else
    {
        std::cout << input << std::endl;
        input.push_back(':');
        title.setString(input);
        title.setPosition(pos);

        sf::Vector2f newPosition = {title.getGlobalBounds().width+title.getGlobalBounds().left+5, pos.y}; // +10 to make things a bit spaced out
        sf::Vector2f newSize = {title.getGlobalBounds().width+size.x, size.y};


        box.setPosition(newPosition);
        box.setSize(newSize);

        text.setPosition({newPosition.x+2, newPosition.y});
        text.setParameter({newSize.x-10,newSize.y});
    }
}

void TextBox::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(title);
    window.draw(box);
    window.draw(text);
}

void TextBox::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if (MouseEvents<Box>::mouseClicked(window,event))
    {
        if (MouseEvents<Box>::mouseClicked(box, window))
        {
            disableState(DISABLE);
            text.disableCursor();
        }
        else
        {
            enableState(DISABLE);
            text.enableCursor();
        }
    }

    if (!checkState(DISABLE))
    {
        text.addEventHandler(window,event);
    }
}

void TextBox::update() {
    if (!checkState(DISABLE)) {
        text.update();
    }
}

void TextBox::setTask(TaskObjects obj)
{
    text.setTask(obj);
}


sf::FloatRect TextBox::getGlobalBounds() const
{
    return box.getGlobalBounds();
}

void TextBox::setLabel(std::string label)
{

    std::cout << "Absolute: left: " << absolute.left<< " top:" << absolute.top << " width:" << absolute.width << " height:" << absolute.height << std::endl;
    label.push_back(':');
    title.setString(label);
    title.setPosition({absolute.left, absolute.top});

    sf::Vector2f newPosition = {title.getGlobalBounds().width+title.getGlobalBounds().left+5, absolute.top}; // +10 to make things a bit spaced out
    sf::Vector2f newSize = {absolute.width, absolute.height};

    box.setPosition(newPosition);
    box.setSize({absolute.width, absolute.height});

    text.setPosition({newPosition.x+2, newPosition.y});
    text.setParameter({newSize.x-10,newSize.y});

}

// size only affects the box and the text
// size is kinda like a float rect in a way
void TextBox::setSize(sf::Vector2f size)
{
    absolute.width = size.x;
    absolute.height = size.y;

    if (title.getString().isEmpty())
    {
        text.setParameter({size.x-10,size.y});
        box.setSize(size);
    }
    else
    {
        sf::Vector2f newSize = {absolute.width, absolute.height};

        text.setParameter({newSize.x-10,newSize.y});
        box.setSize(size);
    }
}

void TextBox::setPosition(sf::Vector2f pos)
{
    absolute.left = pos.x;
    absolute.top = pos.y;



    if (title.getString().isEmpty())
    {
        text.setPosition({pos.x+2, pos.y});
        box.setPosition(pos);
    }
    else
    {
        title.setPosition(pos);

        sf::Vector2f newPosition = {title.getGlobalBounds().width+title.getGlobalBounds().left+5, pos.y}; // +10 to make things a bit spaced out

        box.setPosition(newPosition);

        text.setPosition({newPosition.x+2, newPosition.y});
        sf::Vector2f newSize = {absolute.width, absolute.height};
        text.setParameter({newSize.x-10,newSize.y});
    }
}