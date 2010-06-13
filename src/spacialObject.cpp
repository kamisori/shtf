#include <string>
#include <SFML/System.hpp>
#include <shtf/visualAppearance.hpp>
#include <shtf/spacialObject.hpp>

namespace shtf
{
            void SpacialObject::calculateNewPosition( float elapsedMsec )
            {
                sf::Vector2f temporaryVector;
                temporaryVector.x = 0;
                temporaryVector.y = 0;
                temporaryVector.x = ( elapsedMsec/1000 ) * this->velocity_.x;
                temporaryVector.y = ( elapsedMsec/1000 ) * this->velocity_.y;

                this->moveObject( temporaryVector );
            }

            void SpacialObject::moveObject( sf::Vector2f addThis )
            {
                this->position_.position_.x += addThis.x;
                this->position_.position_.y += addThis.y;
            }

            void SpacialObject::warpObject( sf::Vector2f newPosition ){
                this->position_.position_ = newPosition;
            }

            void SpacialObject::turnObjectAround( float amount )
            {
                this->orientation_ += amount;
                while( this->orientation_ >= 1.0 )
                {
                    this->orientation_ -= 1.0;
                }
            }

            void SpacialObject::setCollision( bool collision )
            {
                this->collides_ = collision;
            }

//            void SpacialObject::heatUp( float factor );
//            void SpacialObject::SpacialObject::coolDown( float factor );
//            void SpacialObject::wet( float factor );
//            void SpacialObject::dry( float factor );
//            void SpacialObject::accelerate( sf::Vector2f factor )      //??
//            void SpacialObject::slowDown( sf::Vector2f factor )        //friction

    		SpacialObject::SpacialObject(
                            std::string* spacialObjectId,
                            PositionInZ posZ,
                            float collisionR,

//                            float objectHealth,
//                            float objectHardness,
//                            float fireResist,
//                            float temperature,

                            std::string* visualAppearanceId
                            //string* audialAppearanceId
                           )
            {
                this->spacialObjectId_ = spacialObjectId;
                this->position_.position_.x = 0;
                this->position_.position_.y = 0;
                this->position_.positionZ_ = posZ;

                this->collisionRadius_ = collisionR;
                this->acceleration_.x = 0;
                this->acceleration_.y = 0;
                this->velocity_.x = 0;
                this->velocity_.y = 0;
                this->collides_ = false;
                this->orientation_ = 0;

//                this->visualAppearance_ =;
            }


    		SpacialObject::SpacialObject()
            {
                exit(1);
            }

    		SpacialObject::~SpacialObject()
            {
//                delete this->visualAppearance_;
            }

}
