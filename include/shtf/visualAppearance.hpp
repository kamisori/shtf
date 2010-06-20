#ifndef VISUALAPPEARANCE_HPP
#define VISUALAPPEARANCE_HPP

#include <string>
#include <vector>
#include <shtf/animation.hpp>
namespace shtf
{
    class VisualAppearance
    {
        public:
            void        currentAnimationByAnimationId( std::string animationId );
            Animation*  currentAnimation();
            std::string getVisualAppearanceId();

            VisualAppearance( std::string visualAppearanceId, std::string animationsDescriptionFile );
            VisualAppearance();
            ~VisualAppearance();
        protected:

        private:
            const std::string*          visualAppearanceId_; //something like player, zombie1, zombie2, ..etc
            std::vector< Animation* >   possibleAnimations_;
            Animation*                  currentAnimation_;
    };
}
#endif
