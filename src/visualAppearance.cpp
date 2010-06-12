#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <shtf/animation.hpp>
#include <shtf/visualAppearance.hpp>

namespace shtf
{
    void VisualAppearance::currentAnimationByAnimationId( std::string* animationId )
    {
        std::vector< Animation*>::iterator it;
        for( it = possibleAnimations_.begin(); it < possibleAnimations_.end(); it++ )
        {
            if( animationId->compare( (*it)->getAnimationId() ) == 0 )
            {
                this->currentAnimation_ = *it;
            }
        }
        this->currentAnimation_ = NULL;
    }

    Animation*  VisualAppearance::currentAnimation()
    {
        return this->currentAnimation_;
    }

    VisualAppearance::VisualAppearance( std::string* visualAppearanceId, std::string* animationsDescriptionFile )
    {
        this->visualAppearanceId_ = visualAppearanceId;

        std::ifstream ifs( (const char*)animationsDescriptionFile, std::ifstream::in );

        char* buffer;
        int length;

        ifs.seekg( 0,std::ios::end );
        length = ifs.tellg();
        ifs.seekg( 0,std::ios::beg );
        buffer = new char[ length ];
        ifs.read( buffer, length );
        ifs.close();

        std::string tmp = buffer;
        //running_fox;fox1.bmp;3;5;
        int lastPos = 0;
        while( tmp.find(';') != std::string::npos )
        {
            int idFound = tmp.find(';', lastPos);
            int fileFound = tmp.find(';', idFound);
            int rowFound = tmp.find(';', fileFound);
            int collumnFound = tmp.find(';', rowFound);
            std::string animationId = tmp.substr(lastPos, idFound);
            std::string fileName = tmp.substr(idFound, fileFound);
            std::string row = tmp.substr(fileFound, rowFound);
            std::string collumn = tmp.substr(rowFound, collumnFound);
            sf::Vector2i rowsAndCollumns;
            rowsAndCollumns.x = atoi(row.c_str());
            rowsAndCollumns.y = atoi(collumn.c_str());

            Animation* temporaryAnimation = new Animation( animationId, fileName, rowsAndCollumns );

            this->possibleAnimations_.push_back( temporaryAnimation );
        }

        delete[] buffer;
    }

    VisualAppearance::VisualAppearance()
    {
        exit(1);
    }

    VisualAppearance::~VisualAppearance()
    {
        this->possibleAnimations_.clear();
        delete this->visualAppearanceId_;
        delete this->currentAnimation_;
    }
}
