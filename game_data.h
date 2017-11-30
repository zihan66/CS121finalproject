#include "Simple_window.h"
class GameData {
	private:
	vector<int> data;
	public: 
	const vector<int> correct{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0 };
	GameData(vector<int> v)
	: data (v) {}
	
	GameData()
    : data (16)	{}
	
	GameData(const GameData& d);
	
    int findindex();
	int incorrect_tiles();
	
	bool color_tiles(int i);
	
	int& at(int j);
	int size();
	GameData& operator=(const GameData& d);
};

