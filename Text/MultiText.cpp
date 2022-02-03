//
// Created by Brandon Castro on 12/9/21.
//

#include "MultiText.h"

MultiText::MultiText() : MultiText({0,0}, {200,200}) {}

MultiText::MultiText(sf::Vector2f pos, sf::Vector2f par)
{
//    dimensions.left = pos.x;
//    dimensions.top = pos.y;
//    dimensions.width = par.x;
//    dimensions.height = par.y;
//
    position = pos;
    parameter = {pos.x+par.x, pos.y+par.y};
    origin = pos;
    cursor.setPosition(pos);

}

bool MultiText::push_back(char c)
{

// add a char to the list
// if the list is empty then the position of the first char is {0,0}
// if not then we get the positions of the last char and add that with the width
// if the position of the last char does not match the position

    Letter hold(c);

    if (!list.empty())
    {
        Linklist<Letter>::iterator iter = list.endValue();
        sf::FloatRect bounds = (*iter).getGlobalBounds();
        sf::FloatRect holdBounds = hold.getGlobalBounds();

        //check if position matches the tail of the list
        // if not then add the new char at that position


        float tempy = position.y+30;
        // before we add a letter we have to check that it won't go out of bounds
        //std::cout << "Parameter.x " << parameter.x << " bounds.left+bounds.width)+holdBounds.width: " << (bounds.left+bounds.width)+holdBounds.width << std::endl;
        if((bounds.left+bounds.width)+holdBounds.width > parameter.x) // then we enter a new line
        {
            if ((position.y == 0 && parameter.y > 70) || (position.y != 0 && (tempy+40) < parameter.y))
            {
                position.y = position.y+30;
            }
            else
            {
                std::cout << "No more space" << std::endl;
                return false;
            }
        }

        if (position.y != (*iter).getPosition().y && position.x == (*iter).getPosition().x) // enter
        {
            //std::cout << "//enter" << std::endl;
            hold.setPosition(origin.x, position.y);
        }
        else if (position.x != (*iter).getPosition().x) // tap
        {
            //std::cout << "//tap" << std::endl;
            hold.setPosition(position.x, position.y);
        }
        else // normal
        {
            //std::cout << "//normal" << std::endl;
            hold.setPosition({bounds.left+bounds.width, position.y});
        }

        position = hold.getPosition();

        //std::cout << position.x <<  " " << position.y << std::endl;
    }
    else
    {
        hold.setPosition(origin);
    }

    cursor.setPosition({position.x+hold.getGlobalBounds().width, position.y});
    list.insertTail(hold);

    //history.history.push(getString());
    SpecialWords::parse(list);
    return true;
}

bool MultiText::pop()
{

    if (!list.empty())
    {
        Linklist<Letter>::iterator iter = list.endValue();
        //std::cout << "End Value: " << (*iter).getPosition().x << std::endl;
        //std::cout << "Position: " << position.x << " " << position.y << std::endl;

        if (position.x != (*iter).getPosition().x)
        {
            position = {(*iter).getPosition()};
        }
        else
        {
            list.removeTail();

            iter = list.endValue();
            if (iter != list.end())
            {
                position = (*iter).getPosition();
                cursor.setPosition({position.x+(*iter).getGlobalBounds().width, position.y});
            }
            else
            {
                // else the list is empty
                position = origin;
                cursor.setPosition(position);
                return false;
            }
        }
    }
    else
    {
        position = origin;
        cursor.setPosition(position);
    }

    //history.history.push(getString());
    return true;
}

void MultiText::tab()
{
    if (position.x+40 < parameter.x-5)
    {
        position.x = position.x+40;
        push_back(' ');
    }
}

void MultiText::enter()
{
    // delete everything and send data to task
    if (!list.empty())
    {
        TaskSnapshot temp;
        temp.task = function;
        TaskHelper::convert(getString(), temp);

        Task::toDoList.push(temp);

        clear();
    }
    /*
    float tempy = position.y+30;

    if ((position.y == 0 && parameter.y > 70) || (position.y != 0 && (tempy+40) < parameter.y))
    {
        push_back(' ');
        position.y = position.y+30;
        position.x = origin.x;
        cursor.setPosition(position);
    }
    else
    {
        std::cout << "No more space for space haha lol" << std::endl;
    }*/
}

void MultiText::setTask(TaskObjects obj)
{
    function = obj;
}

void MultiText::update()
{
    // do nun rn
    cursor.update();
}

// Here I will add the key to my
void MultiText::addEventHandler(sf::RenderWindow& window, sf::Event event) {

    if (event.type == sf::Event::KeyPressed) {
        if (KeyShortcut::isUndo()) {
            if (!history.history.empty()) {

                addString(history.history.top());
                std::cout << history.history.top() << std::endl;
                history.history.pop();
            } else {

                clear();
            }

            SpecialWords::parse(list);
            return;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num8)) {
                if (push_back('*')) {
                    Linklist<Letter>::iterator iter = list.endValue();
                    (*iter).setFillColor(sf::Color::Green);
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Equal)) {
                if (push_back('+')) {
                    Linklist<Letter>::iterator iter = list.endValue();
                    (*iter).setFillColor(sf::Color::Green);
                }
            }

        } else {
            if (sf::Keyboard::isKeyPressed(
                    sf::Keyboard::Key::BackSpace)) // The enter key is pressed and the command is not deactivated by user
            {
                // backspace delete
                pop();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
                // enter
                // position in multiText needs y value incremented and x to be set to 0

                enter();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Tab)) {
                tab();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
                // space
                push_back(' ');
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Slash)) {
                // space
                if (push_back('/')) {
                    Linklist<Letter>::iterator iter = list.endValue();
                    (*iter).setFillColor(sf::Color::Green);
                }
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Dash)) {
                // space
                if (push_back('-')) {
                    Linklist<Letter>::iterator iter = list.endValue();
                    (*iter).setFillColor(sf::Color::Green);
                }
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Equal)) {
                // space
                if (push_back('=')) {
                    Linklist<Letter>::iterator iter = list.endValue();
                    (*iter).setFillColor(sf::Color::Green);
                }
            } else if (event.key.code > 25 && event.key.code < 36) // number change color!
            {
                const int ascii = 22 + event.key.code;
                if (push_back(char(ascii))) {
                    Linklist<Letter>::iterator iter = list.endValue();
                    (*iter).setFillColor(sf::Color::Red);
                }
            } else if (0 <= event.key.code && event.key.code < 26) {
                const int ascii = 97 + event.key.code;
                push_back(char(ascii));
            }
        }

        history.history.push(getString());
    }

}

void MultiText::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    Linklist<Letter>::iterator iter;
    for (iter = list.begin(); iter != list.end(); ++iter)
    {
        window.draw((*iter));
    }

    window.draw(cursor);
}

void MultiText::setPosition(sf::Vector2f pos) {
    position = pos;
    cursor.setPosition(pos);
    origin = pos;

    //setParameter(parameter);
}

void MultiText::setParameter(sf::Vector2f par) {
    parameter = {position.x+par.x, position.y+par.y};
}

void MultiText::disableCursor()
{
    cursor.disableState(HIDDEN);
}
void MultiText::enableCursor()
{
    cursor.enableState(HIDDEN);
}

Snapshot &MultiText::getSnapshot() {
    Snapshot hold;
    hold.data = getString();

    return hold;
}

void MultiText::applySnapshot(const Snapshot &snapshot) {
    addString(snapshot.data);
}

void MultiText::clear() {
    while(!list.empty())
    {
        pop();
    }
}

void MultiText::addString(std::string text) {
    clear();

    for (int i = 0; i < text.size(); i++)
    {
        push_back(text[i]);
    }
}

std::string MultiText::getString() const {
    std::string hold;
    Linklist<Letter>::iterator iter;

    for (iter = list.begin(); iter != list.end(); ++iter)
    {
        hold += (*iter).getString();
    }

    return hold;
}