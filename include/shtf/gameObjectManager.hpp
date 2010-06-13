#ifndef GAMEOBJECTMANAGER_HPP
#define GAMEOBJECTMANAGER_HPP

#include <string>
#include <vector>
#include <map>
#include <shtf/spacialObject.hpp>
#include <shtf/visualAppearance.hpp>

namespace shtf{

    class GameObjectManager
    {
    	public:
            VisualAppearance* provideVisualAppearance( std::string* visualAppearanceId );
//            AudioAppearance* provideAudioAppearance( std::string* audioAppearanceId );

            void loadObjects( std::string* spacialObjectsFile );
            void loadVisualAppearances( std::string* visualAppearanceFile );
//            void loadAudioAppearances( std::string* audioAppearanceFile );
    		GameObjectManager();
    		~GameObjectManager();
    	protected:

    	private:
    	std::vector< PositionInGame >                               occupiedByObjects_;
    	std::map< PositionInGame, std::vector< SpacialObject* > >   allSpacialObjects_;
    	std::vector< VisualAppearance* >                            visualAppearancesLibrary_;
//    	std::vector< AudioAppearance* >                             audioAppearancesLibrary_;
//      std::vector< Script* >                                      scriptLibrary_;
    };

}

#endif
