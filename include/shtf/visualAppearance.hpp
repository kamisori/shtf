#ifndef VISUALAPPEARANCE_HPP
#define VISUALAPPEARANCE_HPP

#include <shtf/animation.hpp>
namespace shtf
{
    class VisualAppearance
    {
        public:
            Animation* findByAnimationId( string animationId );
            VisualAppearance();
            ~VisualAppearance();
        protected:

        private:
            const string visualAppearanceId_; //something like player, zombie1, zombie2, ..etc
            vector<Animation*> possibleAnimations_;
    };
}
#endif
