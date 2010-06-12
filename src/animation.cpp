#include <string>
#include <vector>
#include <shtf/animation.hpp>
namespace shtf
{
    void Animation::next(){
        this->currentFrame_++;
        if( this->currentFrame_ == this->frames_.size() ){
            this->currentFrame_ = 0;
        }
    }

    //increase currentFrame_ and return new current Sprite*
    sf::Sprite* Animation::nextFrame()
    {
        this->next();
        return this->frames_[this->currentFrame_];
    }

    std::string Animation::getAnimationId()
    {
        return* this->animationId_;
    }

    //data will be provided from a csv style file something like "running_fox";"fox1.bmp";3;5; with 3 rows of frames and 5 collumns
    Animation::Animation( std::string animationId, std::string fileName, sf::Vector2i rowsAndCollumns ){
        this->animationId_ = &animationId;
        sf::Image temporaryImage = sf::Image();
        if( !temporaryImage.LoadFromFile( fileName ) ){
            exit(1);
        }
        this->allFrames_ = &temporaryImage;

        sf::Vector2i* imageDimensions = new sf::Vector2i();
        sf::Vector2i* spriteDimensions = new sf::Vector2i();
        imageDimensions->y = this->allFrames_->GetHeight();
        imageDimensions->x = this->allFrames_->GetWidth();

        spriteDimensions->y = imageDimensions->y / rowsAndCollumns.y;
        spriteDimensions->x = imageDimensions->x / rowsAndCollumns.x;
        for( int y = 0; y <= imageDimensions->y - spriteDimensions->y; y += spriteDimensions->y ){
            for( int x = 0; x <= imageDimensions->x - spriteDimensions->x; x += spriteDimensions->x ){
                sf::Sprite* temporarySprite = new sf::Sprite();
                temporarySprite->SetSubRect( sf::IntRect( x, y, spriteDimensions->x, spriteDimensions->y ) );
                this->frames_.push_back( temporarySprite );
            }
        }
        if( this->frames_.size() != (unsigned) ( rowsAndCollumns.x * rowsAndCollumns.y ) )
        {
            exit(1);
        }
    }

    Animation::Animation(){
        exit(1);
    }
    Animation::~Animation(){
        this->frames_.clear();
        delete this->allFrames_;
        delete this->animationId_;
    }
}
