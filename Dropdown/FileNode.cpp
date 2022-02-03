//
// Created by Brandon Castro on 12/7/21.
//

#include "FileNode.h"

void FileNode::toggleChlidren() {

}

void FileNode::reposition() const {

}

FileNode::FileNode() {

}

FileNode::FileNode(Images::image icon, std::string text, sf::Vector2f size, sf::Vector2f position) {

    data.setIcon(icon);
    data.setText(text);
    data.setSize(size);
    data.setPosition(position);
}

void FileNode::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(data);

    if (States::checkState(ACTIVE))
    {
        for ( const auto &p : children ) {
            window.draw(*(p.second));
        }
    }
}

std::string FileNode::getCurrentFile() {return currentFile;};

void FileNode::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    data.addEventHandler(window, event);

    if (States::checkState(ACTIVE))
    {
        std::map<std::string, FileNode*>::iterator iter;

        for (iter = children.begin(); iter != children.end(); iter++)
        {
            iter->second->addEventHandler(window, event);
        }
    }

    if (MouseEvents<FileItem>::mouseClicked(data, window))
    {
        if (States::checkState(ACTIVE))
        {
            States::disableState(ACTIVE);
        }
        else
        {
            States::enableState(ACTIVE);
        }

        hack::currentFile = data.getAddress();
    }

}

void FileNode::update() {

    data.update();

    if (States::checkState(ACTIVE))
    {
        std::map<std::string, FileNode*>::iterator iter;

        for (iter = children.begin(); iter != children.end(); iter++)
        {
            iter->second->update();
        }
    }
}

std::map<std::string, FileNode *>::iterator FileNode::begin() {
    return children.begin();
}

std::map<std::string, FileNode *>::iterator FileNode::end() {
    return children.end();
}

void FileNode::setData(const FileItem &data)
{
    this->data = data;
}

void FileNode::printChildren() const
{
    for ( const auto &p : children )
    {
        std::cout << p.first << std::endl;
    }
}

//sf::FloatRect FileNode::getGlobalBounds() {
//    return sf::FloatRect();
//}

//bool FileNode::isLeaf() const {
//    return false;
//}
//

FileItem &FileNode::getData() {
    return data;
}



std::map<std::string, FileNode *> &FileNode::getChildren() {
    return children;
}


std::string FileNode::getAddress() const
{
    return data.getAddress();
}