//
// Created by Brandon Castro on 12/7/21.
//

#ifndef CS8_FINALPROJECT_FILETREE_H
#define CS8_FINALPROJECT_FILETREE_H
#include "FileNode.h"

class FileTree : public sf::Drawable
{
private:
    //the root node of the tree
    FileNode* root = nullptr;

    std::string currentFile;

    //finds the parent and add the item to the parent.
    // If the parent isn't found, a new parent is created
    void push(FileNode*& root, Images::image icon, std::string parent, std::string item);

    //traverses the tree ad adds the evenhandlers for each of the nodes
    void traverse(FileNode* &root, sf::RenderWindow& window, sf::Event event);
    sf::Vector2f initPosition = {0, 0};
public:
    //constructors
    FileTree();

    std::string getCurrentFile();

    //this is the public version of push
    void push(std::string parent, std::string item = "NULL");
    void push(Images::image icon, std::string parent, std::string item);

    //draws the root node of the tree
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //calls the traverse function to add the event handlers to each node
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

    //does nothing now
    virtual void update();
    virtual sf::FloatRect getGlobalBounds();


    FileNode* find(FileNode* root, std::string parent);
};
#endif //CS8_FINALPROJECT_FILETREE_H
