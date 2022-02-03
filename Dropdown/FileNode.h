//
// Created by Brandon Castro on 12/7/21.
//

#ifndef CS8_FINALPROJECT_FILENODE_H
#define CS8_FINALPROJECT_FILENODE_H
#include "FileItem.h"
#include "../Tools/States.h"
#include <map>
#include "../Tools/MouseEvents.h"
#include "hack.h"
class FileNode : public sf::Drawable, public States
{
private:
    //This is the data represented in the tree
    FileItem data;

    //this is all the child nodes in the tree, a vector would also work just fine
    std::map<std::string, FileNode*> children;

    //this tells the draw function whether or not to show the node's children
    //this is done by toggling a state on and off
    void toggleChlidren();

    //this is called in the draw function to reposition the children so they
    //are indented and below the parent
    void reposition() const;

    std::string currentFile;

public:
    // this is so I can use the iterator for the children map publicly
    typedef typename std::map<std::string, FileNode*>::iterator iterator;

    FileNode();
    FileNode(Images::image icon, std::string text, sf::Vector2f size, sf::Vector2f position);

    std::string getCurrentFile();

    //this draws the node. This is a recursive function to draw all the children nodes as well
    // this will only draw the node's children when it is in the proper state
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;


    //This calls the addEventHandler for all the children. It calls the toggleChildren function
    // when the node's data (FileItem) is clicked on
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    //does nothing now
    virtual void update();
    //does nothing now
    sf::FloatRect getGlobalBounds();
    //returns true if the node has no children, otherwise false
    bool isLeaf() const;

    //getters and setters
    FileItem &getData();
    void setData(const FileItem &data);
    std::map<std::string, FileNode*>& getChildren();
    void printChildren() const;

    std::string getAddress() const;
    //iterators
    iterator begin();
    iterator end();

};
#endif //CS8_FINALPROJECT_FILENODE_H
