//
// Created by Brandon Castro on 12/7/21.
//

#include "FileTree.h"

void FileTree::push(FileNode *&root, Images::image icon, std::string parent, std::string text)
{
    if (root->getAddress() == parent)
    {

        FileItem item;

        item.setIcon(icon);
        item.setSize({250,50});
        item.setText(parent+"/"+text);

        auto* temp = new FileNode;
        temp->setData(item);

        sf::Vector2f pos;
        pos.x = root->getData().getPosition().x+250;
        pos.y = (50*static_cast<float>(root->getChildren().size()));

        temp->getData().setPosition(pos);

        root->getChildren()[temp->getData().getText()] = temp;

    }
    else
    {

        FileNode* hold;
        hold = find(root, parent);

        if (hold == nullptr)
        {
            std::cout << "path invalid, item not added" << std::endl;
        }
        else
        {
            FileItem item;

            item.setIcon(icon);
            item.setSize({250,50});
            item.setText(text);

            auto* temp = new FileNode;
            temp->setData(item);

            sf::Vector2f pos;
            pos.x = hold->getData().getPosition().x+250;
            pos.y = (50*static_cast<float>(hold->getChildren().size()));

            temp->getData().setPosition(pos);

            hold->getChildren()[temp->getData().getText()] = temp;

        }
    }
}

void FileTree::traverse(FileNode *&root, sf::RenderWindow &window, sf::Event event)
{

}

FileTree::FileTree()
{
    FileItem item;

    item.setIcon(Images::FOLDER);
    item.setPosition({0,0});
    item.setSize({250,50});
    item.setText("Files");

    auto*temp = new FileNode;
    temp->getData() = item;

    root = temp;
}

void FileTree::push(std::string parent, std::string item)
{
    push(Images::image::FILE, parent, item);
}

void FileTree::push(Images::image icon, std::string parent, std::string item)
{
    push(root, icon, parent, item);
}

void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(*root);
}

void FileTree::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    root->addEventHandler(window, event);
}

void FileTree::update()
{
    root->update();
}

sf::FloatRect FileTree::getGlobalBounds() {
    return sf::FloatRect();
}

FileNode* FileTree::find(FileNode* root, std::string parent)
{
    if (root->getAddress() == parent)
    {
        return root;
    }
    else
    {

        std::map<std::string, FileNode*>::iterator iter;

        for (iter = root->begin(); iter != root->end(); iter++)
        {
            auto* temp = new FileNode;
            temp = find(iter->second, parent);

            if (temp != nullptr)
            {
                return temp;
            }
        }
    }

    return nullptr;
}