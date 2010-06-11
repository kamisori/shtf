#ifndef SPACIALOBJECT_HPP
#define SPACIALOBJECT_HPP

#include <SFML/Vector2.hpp>

namespace shtf
{
    class Collision
    {
    	public:
    		Collision();
    		~Collision();
    	protected:

    	private:
    		bool  collides_;
    		float collisionRadius_;
    };

    enum height {FLOOR, FOOT, WAIST, HEAD, FOOTWAIST, FOOTHEAD, WAISTHEAD};
    class SpacialObject
    {
    	public:
    		SpacialObject();
    		~SpacialObject();
    	protected:

    	private:
            string          objectId_;
    		sf::Vector2f    position_;
    		height          positionZ_;

    		float           objectHealth_;              //objects can be damaged
    		float           objectHardness_;            //some objects resist damage better than others
                                                        //combined with collision, this means, you can
                                                        //use anything and everything as a shield against attacks.

            float           fireResistance_;            //wood burns, steel doesn't.
            float           temperature_;               //might be implemented, heat stuff up to make them softer,
                                                        //also might do damage to other objects.

    		float           orientation_;
    		sf::Vector2f    velocity_;
    		sf::Vector2f    acceleration_;

    		Appearance*     objectAppearance_;          //null means, this is either a zone for a script,
                                                        //or something is attached to the ground, like a
                                                        //pole for a line or something

            Collision*      objectCollision_;           //objects don't collide with objects they are attached to.

    		//Attachment*   attachedTo_;                //Attach one Object to another
                                                        //in example: Flashlight to Shovel
                                                        //attachmentStrength determines if object can be removed
                                                        //objectHealth must be higher than attachment strength, else object breaks during removal
                                                        //orientation relative to attached object
                                                        //attached at top, bottom, hind, front, one side or the other
            //Script*       objectScript_;
    };
}
#endif
