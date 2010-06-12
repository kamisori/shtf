#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <string>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
namespace shtf
{
    class Animation
    {
        public:
            //increase currentFrame_ and return new current Sprite*
            sf::Sprite* nextFrame();
            std::string getAnimationId();
            //data will be provided from a csv style file something like
            //"running_fox";"fox1.bmp";3;5; with 3 rows of frames and 5 collumns:
            Animation( std::string animationId, std::string fileName, sf::Vector2i rowsAndCollumns );

            Animation();
            ~Animation();
        protected:

        private:
            void next();
            const std::string* animationId_;  //something like run, attack1, attack2, ..etc
            const sf::Image* allFrames_;
            std::vector< sf::Sprite* > frames_;
            unsigned int currentFrame_;
    };
}
#endif
