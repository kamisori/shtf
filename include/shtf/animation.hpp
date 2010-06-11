#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <SFML/Graphics.hpp>

namespace shtf
{
    class Animation
    {
        public:
            sf::Sprite* nextFrame();    //increase currentFrame_ and
                                        //return new current Sprite*

            Animation( string animationId, string fileName );
            ~Animation();
        protected:

        private:
            const string animationId_;  //something like run, attack1, attack2, ..etc
            const sf::Image* allFrames_;
            const vector<sf::Sprite*> frames_;
            int currentFrame_;
    };
}
#endif
