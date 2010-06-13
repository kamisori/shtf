#ifndef SPACIALOBJECT_HPP
#define SPACIALOBJECT_HPP

#include <string>
#include <SFML/System.hpp>
#include <shtf/visualAppearance.hpp>

namespace shtf
{
    enum PositionInZ {FLOOR, FOOT, WAIST, HEAD, FOOTWAIST, FOOTHEAD, WAISTHEAD};
    struct PositionInGame
    {
            sf::Vector2f        position_;
            PositionInZ         positionZ_;
    };

    class SpacialObject
    {
    	public:

            void calculateNewPosition( float elapsedMsec );
            void moveObject( sf::Vector2f addThis );
            void warpObject( sf::Vector2f newPosition );
            void turnObjectAround( float amount );
            void setCollision( bool collision );
//            void heatUp( float factor );
//            void coolDown( float factor );
//            void wet( float factor );
//            void dry( float factor );
            void accelerate( sf::Vector2f factor );      //??
            void slowDown( sf::Vector2f factor );        //friction

    		SpacialObject(
                            std::string* spacialObjectId,
                            PositionInZ posZ,
                            float collisionR,

//                            float objectHealth,
//                            float objectHardness,
//                            float fireResist,
//                            float temperature,

                            std::string* visualAppearanceId
                            //string* audialAppearanceId
                           );

    		SpacialObject();
    		~SpacialObject();
    	protected:

    	private:
            const std::string*       spacialObjectId_;

    		PositionInGame      position_;

    		bool                collides_;                  //objects don't collide with objects they are attached to.
    		float               collisionRadius_;           //which means, that there wont be a check neccessary when
                                                            //something is attached to another object. this flag here still applies to the rest of the gameworld

//          float               objectMass_;
//    		float               objectHealth_;              //objects can be damaged
//    		float               objectHardness_;            //some objects resist damage better than others
                                                            //combined with collision, this means, you can
                                                            //use anything and everything as a shield against attacks.

//            float               fireResistance_;            //wood burns, steel doesn't.
//            float               temperature_;               //might be implemented, heat stuff up to make them softer,
                                                            //also might do damage to other objects.

    		float               orientation_;
    		sf::Vector2f        velocity_;                  //momentum, velocity in pixel/s one pixel is roughly 0.5cm
    		sf::Vector2f        acceleration_;              //propelled by something?

            VisualAppearance*   visualAppearance_;          //null means, this is either a zone for a script,
                                                            //or something is attached to the ground, like a
                                                            //pole for a line or something

            //AudioAppearance*    audialAppearance_;        //basically the same as visualAppearance.
                                                            //holds the samples this objects can play.

            //Attachment*         attachedTo_;              //Attach one Object to another
                                                            //in example: Flashlight to Shovel
                                                            //attachmentStrength determines if object can be removed
                                                            //objectHealth must be higher than attachment strength, else object breaks during removal
                                                            //orientation relative to attached object
                                                            //attached at top, bottom, hind, front, one side or the other

            //Script*             objectScript_;            //also for AI
    };
}

#endif
