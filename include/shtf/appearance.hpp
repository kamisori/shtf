#ifndef APPEARANCE_HPP
#define APPEARANCE_HPP

#include <shtf/animation.hpp>
namespace shtf
{
    class Appearance
    {
        public:
            Animation* findByAnimationId( string animationId );
            Appearance();
            ~Appearance();
        protected:

        private:
            const string appearanceId_; //something like player, zombie1, zombie2, ..etc
            vector<Animation*> possibleAnimations_;
    };
}
#endif
