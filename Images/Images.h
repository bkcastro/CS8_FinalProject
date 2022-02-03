//
// Created by Brandon Castro on 12/2/21.
//

#ifndef CS8_FINALPROJECT_IMAGES_H
#define CS8_FINALPROJECT_IMAGES_H
#include <SFML/Graphics.hpp>

class Images {
public:
    enum image {
        FILE = 0, FOLDER, LOGO, PLAY, PAUSE, LAST
    };

    static sf::Texture& getImage(image img);
private:
    static std::vector<sf::Texture> images;
    static void loadImage(image img);
    static std::string getImagePath(image img);
};


#endif //CS8_FINALPROJECT_IMAGES_H
