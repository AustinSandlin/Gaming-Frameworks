#ifndef _LOADER_H
#define _LOADER_H

#include <iostream>
#include <fstream>
#include "../../Common/Resources/Constants.h"
#include "../../Engine/Input/InputController.h"
#include "../../Engine/Object/ObjectController.h"
#include "../../Engine/Render/RenderController.h"

using namespace std;


class Loader {

  private:
  	fstream reader;
  	static AudioController& audio_controller;
    static InputController& input_controller;
    static ObjectController& object_controller;
    static RenderController& render_controller;

  public:
  	~Loader();

  	void loadLevel(const string filename);
};


#endif
