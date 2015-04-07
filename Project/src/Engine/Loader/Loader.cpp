#include "Loader.h"
#include <sstream>
#include <string>



AudioController& Loader::audio_controller = AudioController::instance();
InputController& Loader::input_controller = InputController::instance();
ObjectController& Loader::object_controller = ObjectController::instance();
GameController& Loader::game_controller = GameController::instance();
Strings& Loader::string_controller = Strings::instance();


Loader::~Loader() {
	if (reader.is_open()) {
		reader.close();
	}
}


void Loader::loadLevel(const string filename) {
	// Open the file and make sure it was found:
	reader.open(filename);
	if (!reader.is_open()) {
		cout << "Could not open level file " << filename << endl;
		exit(1);
	}

	bool done    = false;
	bool badData = false;
	stringstream line;
	string word;
	string temp;
	int currentLine = 0;

	// Scan for the start word to begin reading world description:
	while (!done) {
		getline(reader, word);

		// If the end of the file was reached before the start word was found:
		if (!reader && word != LOADER_START_STRING) {
			cout << "Did not find start word in file " << filename << endl;
			cout << word;
			exit(1);
		}

		if (word == LOADER_START_STRING) {
			done = true;
		}
	}

	done = false;

	// Read line by line from the file to determine how to set up the game:
	while (!badData && !done) {
		currentLine++;

		// Get the next line from the level file:
		if (getline(reader, word)) {

			// Getting the whole line and then examining the first word of it:
			line.str(word);
			line >> word;


			// Sound management

			if (word == LOADER_COMMAND_1)  {
				line >> word;

				// Adding a sound
				if (word == LOADER_COMMAND_A) {
					string name, path;
					// Get the name and path of the sound
					if ((line >> name) && (line >> path)) {
						audio_controller.addSound(name, path);
						cout << "Adding sound: " << name << ", " << path << endl;
					}
					else {
						badData = true;
					}
				}
				// Invalid command given after sound
				else {
					badData = true;
				}
			}

			// Texture management

			else if (word == LOADER_COMMAND_2)  {
				line >> word;

				// Adding a texture to an object
				if (word == LOADER_COMMAND_A) {
					string name, path;
					// Get the name of the object the texture goes to and the
					// path to the texture
					if ((line >> name) && (line >> path)) {
						object_controller.registerObjectTexture(string_controller.intern(name), path);
						cout << "Adding texture: " << name << ", " << path << endl;
					}
					else {
						badData = true;
					}
				}

				// Invalid command given after texture
				else {
					badData = true;
				}
			}

			// Input action management

			else if (word == LOADER_COMMAND_3)  {
				line >> word;

				// Adding a new input action mapping
				if (word == LOADER_COMMAND_A) {
					string input, action;
					// Get the input action ID and the action to which it
					// corresponds
					if ((line >> input) && (line >> action)) {
						InputAction actionType;
						// Possible action types:
						if (action == LOADER_ACTION_TYPE_1) {
							actionType = MOVE_UP;
						}
						else if (action == LOADER_ACTION_TYPE_2) {
							actionType = MOVE_DOWN;
						}
						else if (action == LOADER_ACTION_TYPE_3) {
							actionType = MOVE_LEFT;
						}
						else if (action == LOADER_ACTION_TYPE_4) {
							actionType = MOVE_RIGHT;
						}
						else if (action == LOADER_ACTION_TYPE_5) {
							actionType = QUIT;
						}
						else if (action == LOADER_ACTION_TYPE_6) {
							actionType = ATTACK;
						}
						// If no valid action type is given, a default is used:
						else {
							actionType = ATTACK;
						}

						game_controller.registerInputAction(string_controller.intern(input), actionType);
						cout << "Adding input action: " << input << ", " << action << endl;
					}
					else {
						badData = true;
					}
				}

				// Invalid command given after input action
				else {
					badData = true;
				}
			}

			// Player object management
			else if (word == LOADER_COMMAND_4)  {
				line >> word;

				// Registering a new player object
				if (word == LOADER_COMMAND_A) {
					string name, x, y, width, height;
					// Get the name of the player object and its starting
					// values
					if ((line >> name) && (line >> x) && (line >> y) &&
						(line >> width) && (line >> height)) {
						int xVal, yVal, widthVal, heightVal;
						xVal = atoi(x.c_str());
						yVal = atoi(y.c_str());
						widthVal = atoi(width.c_str());
						heightVal = atoi(height.c_str());

						object_controller.registerPlayerObject(string_controller.intern(name), 
							PlayerObject(string_controller.intern(name), xVal, yVal, widthVal, heightVal));
							cout << "Adding player object: " << name << ", " << x << ", " << y << ", " << width 
														     << ", " << height << endl;
					}
					else {
						badData = true;
					}
				}

				// Invalid command given after player object
				else {
					badData = true;
				}
			}

			// AI object management
			else if (word == LOADER_COMMAND_5)  {
				line >> word;

				// Registering a new AI object
				if (word == LOADER_COMMAND_A) {
					string name, x, y, width, height, ai;
					// Get the name of the AI object, its starting values
					// and its AI
					if ((line >> name) && (line >> x) && (line >> y) &&
						(line >> width) && (line >> height) && (line >> ai)) {
						int xVal, yVal, widthVal, heightVal;
						AIType aitype;
						xVal = atoi(x.c_str());
						yVal = atoi(y.c_str());
						widthVal = atoi(width.c_str());
						heightVal = atoi(height.c_str());

						// Possible AI types:
						if (ai == LOADER_AI_TYPE_1) {
							aitype = WANDER;
						}
						// If no valid AI type is given, a default is used:
						else {
							aitype = STILL;
						}
						object_controller.registerAIObject(string_controller.intern(name), 
							AIObject(string_controller.intern(name), xVal, yVal, widthVal, heightVal, aitype));
							cout << "Adding AI object: " << name << ", " << x << ", " << y << ", " << width
														 << ", " << height << ", " << ai << endl;
					}
					else {
						badData = true;
					}
				}

				// Invalid command given after AI object
				else {
					badData = true;
				}
			}

			// Game object management
			else if (word == LOADER_COMMAND_6)  {
				line >> word;

				// Registering a new game object
				if (word == LOADER_COMMAND_A) {
					string name, x, y, width, height, collidable;
					// Get the name of the game object, its starting values,
					// and whether it is collidable or not
					if ((line >> name) && (line >> x) && (line >> y) &&
						(line >> width) && (line >> height) && (line >> collidable)) {
						int xVal, yVal, widthVal, heightVal;
						bool isCollidable;
						xVal = atoi(x.c_str());
						yVal = atoi(y.c_str());
						widthVal = atoi(width.c_str());
						heightVal = atoi(height.c_str());

						// isCollidable is set to true or false if specified,
						// defaulting to false on wrong input.
						if (collidable == "true") {
							isCollidable = true;
						}
						else {
							isCollidable = false;
						}

						object_controller.registerGameObject(string_controller.intern(name), 
							GameObject(string_controller.intern(name), xVal, yVal, widthVal, heightVal, isCollidable));
							cout << "Adding game object: " << name << ", " << x << ", " << y << ", " << width
														   << ", " << height << ", " << collidable << endl;
					}
					else {
						badData = true;
					}
				}

				// Invalid command given after game object
				else {
					badData = true;
				}
			}

			// Background object management
			else if (word == LOADER_COMMAND_7)  {
				line >> word;

				// Registering a new background object
				if (word == LOADER_COMMAND_A) {
					string name, x, y, width, height;
					// Get the name of the background object and its starting
					// values
					if ((line >> name) && (line >> x) && (line >> y) &&
						(line >> width) && (line >> height)) {
						int xVal, yVal, widthVal, heightVal;
						xVal = atoi(x.c_str());
						yVal = atoi(y.c_str());
						widthVal = atoi(width.c_str());
						heightVal = atoi(height.c_str());

						object_controller.registerBackgroundObject(string_controller.intern(name), 
							BackgroundObject(string_controller.intern(name), xVal, yVal, widthVal, heightVal));
							cout << "Adding background object: " << name << ", " << x << ", " << y << ", " << width 
																 << ", " << height << endl;
					}
					else {
						badData = true;
					}
				}

				// Invalid command given after background object
				else {
					badData = true;
				}
			} 

			// HUD object management
			else if (word == LOADER_COMMAND_8)  {
				line >> word;

				// Registering a new HUD object
				if (word == LOADER_COMMAND_A) {
					string name, x, y, width, height, text;
					// Get the name of the hud object, its starting values,
					// and whether it is text HUD eement or not
					if ((line >> name) && (line >> x) && (line >> y) &&
						(line >> width) && (line >> height) && (line >> text)) {
						int xVal, yVal, widthVal, heightVal;
						bool isText;
						xVal = atoi(x.c_str());
						yVal = atoi(y.c_str());
						widthVal = atoi(width.c_str());
						heightVal = atoi(height.c_str());

						// isText is set to true or false if specified,
						// defaulting to false on wrong input.
						if (text == "true") {
							isText = true;
						}
						else {
							isText = false;
						}
						object_controller.registerHUDObject(string_controller.intern(name), 
								HUDObject(string_controller.intern(name), xVal, yVal, widthVal, heightVal, isText));
						cout << "Adding HUD object: " << name << ", " << x << ", " << y << ", " << width 
													  << ", " << height << ", " << text << endl;
					}
				}

				// Invalid command given after HUD object
				else {
					badData = true;
				}
			}

			else if (word == LOADER_COMMAND_9)  {
				line >> word;

				// Registering a new HUD object
				if (word == LOADER_COMMAND_A) {
					string name, value;
					// Get the name of the hud object, its starting values,
					// and whether it is value HUD eement or not
					if ((line >> name) && (line >> value)) {
						// isDebug is set to true or false if specified,
						// defaulting to false on wrong input.
						if(value == "fps") {
							DebugValue temp = FPS;
							game_controller.registerValue(string_controller.intern(name), temp);
							cout << "Registered TEXT object: " << name << " " << value << endl;
						}
					}
				}

				// Invalid command given after HUD object
				else {
					badData = true;
				}
			}

			// End of level data
			else if (word == LOADER_END_STRING) {
				done = true;
			}

			// If an invalid command is used:
			else {
				badData = true;
			}

		}
		// If the end of the file was reached before the end word was found:
		else {
			if (!reader && word != LOADER_END_STRING) {
				cout << "Did not find end word in file " << filename << endl;
				cout << word;
				exit(1);
			}
			else {
				done = true;
			}
		}

		// Clear the string stream to read another line:
		line.clear();
	}


	// Error if an invalid command or format was used:
	if (badData) {
		cout << "Error in level description in file " << filename
			 << " at line of description " << currentLine << ":" << endl;
		cout << line.str() << endl;
		exit(1);
	}

	// Close the file when the end word is found:
	if (reader.is_open()) {
		reader.close();
	}
}
