#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <shtf/spacialObject.hpp>
#include <shtf/visualAppearance.hpp>
#include <shtf/gameObjectManager.hpp>
namespace shtf{

    VisualAppearance* GameObjectManager::provideVisualAppearance( std::string* visualAppearanceId )
    {
    }

//    AudioAppearance* GameObjectManager::provideAudioAppearance( std::string* audioAppearanceId )

    //std::string* spacialObjectId, float posX, float posY, PositionInZ posZ, float orientation, bool collides, float collisionR, std::string* visualAppearanceId
    void GameObjectManager::loadObjects( std::string* spacialObjectsFile )
    {
        std::ifstream ifs( (const char*)spacialObjectsFile, std::ifstream::in );

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
            int posXFound = tmp.find(';',idFound);
            int posYFound = tmp.find(';',posXFound);
            int posZFound = tmp.find(';', posYFound);
            int orientFound = tmp.find(';', posZFound);
            int collFound = tmp.find(';', orientFound);
            int collRFound = tmp.find(';', collFound);
            int visAppIdFound = tmp.find(';', collRFound);

            std::string objId = tmp.substr(lastPos, idFound);
            std::string posX = tmp.substr(idFound, posXFound);
            std::string posY = tmp.substr(posXFound, posYFound);
            std::string posZ = tmp.substr(posYFound, posZFound);
            std::string turn = tmp.substr(posZFound, orientFound);
            std::string coll = tmp.substr(orientFound, collFound);
            std::string collR = tmp.substr(collFound, collRFound);
            std::string visAppId = tmp.substr(collRFound, visAppIdFound);

            sf::Vector2f tmpXY;
            tmpXY.x = atof(posX.c_str());
            tmpXY.y = atof(posY.c_str());
            PositionInZ tmpZ;
            tmpZ= (PositionInZ)atoi(posZ.c_str());
            bool tmpcoll;
            tmpcoll = atoi(coll.c_str());
            float tmpR;
            tmpR = atof(collR.c_str());
            float tmpTurn;
            tmpTurn = atof(turn.c_str());

            SpacialObject* temporaryObject = new SpacialObject( &objId, tmpZ, tmpR, &visAppId );
            temporaryObject->warpObject( tmpXY );
            temporaryObject->setCollision( tmpcoll );
            temporaryObject->turnObjectAround( tmpTurn );
            PositionInGame key;
            key.positionZ_ = tmpZ;
            key.position_ = tmpXY;

//check if vector allready exists, get it, insert object, put it back
//            this->allSpacialObjects_.insert();
        }

        delete[] buffer;
    }

    // std::string* visualAppearanceId; std::string* animationsDescriptionFile
    void GameObjectManager::loadVisualAppearances( std::string* visualAppearanceFile )
    {

    }

//    void GameObjectManager::loadAudioAppearances( std::string* audioAppearanceFile )

    GameObjectManager::GameObjectManager()
    {

    }

    GameObjectManager::~GameObjectManager()
    {

    }

/*
    	private:
    	std::vector< PositionInGame >                               occupiedByObjects_;
    	std::map< PositionInGame, std::vector< SpacialObject* > >   allSpacialObjects_;
    	std::vector< VisualAppearance* >                            visualAppearancesLibrary_;
//    	std::vector< AudioAppearance* >                             audioAppearancesLibrary_;
//      std::vector< Script* >                                      scriptLibrary_;
*/

}
