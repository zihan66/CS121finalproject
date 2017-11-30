#include "game_data.h"

	
	GameData::GameData(const GameData& d) {
		(*this) = d;
	}
    int GameData::findindex() {
		int j = 0;
		while (data[j] != 0) {
			++j;
		}
    return j;
		
	}
	int GameData::incorrect_tiles(){
		int incorrect = 0;
		 for (int i = 0; i < data.size(); ++i) {
         if (data[i] != correct[i])
                incorrect++;
         }
	return incorrect;
	}
	
	bool GameData::color_tiles(int i){
		bool iscorrect = false;
        if (data[i] == correct[i])
                iscorrect = true;
			
		return iscorrect;
	}
	
	int& GameData::at(int j) {
		return data.at(j);	
	}
	int GameData::size(){
		return data.size();
	}
	GameData& GameData::operator=(const GameData& d) {
		data = d.data;
		return (*this);
	}
