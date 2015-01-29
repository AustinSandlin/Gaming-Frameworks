#ifndef _GAME_MODEL_H
#define _GAME_MODEL_H

class GameModel {
public:
	static GameModel & GetInstance() {
		static GameModel singleton;
		return singleton;
	}
private:
	GameModel() {}
	unordered_map< StringID, Object * > objects;
};

#endif
