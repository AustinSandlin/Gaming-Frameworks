#ifndef _LOADER_H
#define _LOADER_H

#include <fstream>
#include "../../Common/Resources/Constants.h"


class Loader {

  private:
  	fstream reader;
    static AudioController& audio_controller;
    static InputController& input_controller;
    static ObjectController& object_controller;
    static RenderController& render_controller;
    static GameController& game_controller;


  public:
  	loader();
  	~loader();

  	void loadLevel(const string filename);

};


#endif
