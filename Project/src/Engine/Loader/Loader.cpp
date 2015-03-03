#include "Loader.h"
#include <sstream>
#include <windows.h>
#include <string>



AudioController& Loader::audio_controller = AudioController::instance();
InputController& Loader::input_controller = InputController::instance();
ObjectController& Loader::object_controller = ObjectController::instance();
RenderController& Loader::render_controller = RenderController::instance();


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
			Sleep(3000);
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

		if (getline(reader, word)) {

			// Getting the whole line and then examining the first word of it:
			line.str(word);
			cout << line.str() << endl;

			line >> word;

	/*
			if (word == )  {





			}
			else if (word == ) {





			}

			else if (word == ) {





			}
			else */ if (word == LOADER_END_STRING) {
				done = true;
			}
			// If an invalid command is used:
			/*else {
				badData = true;
				break;
			}*/

		}
		// If the end of the file was reached before the end word was found:
		else {
			if (!reader && word != LOADER_END_STRING) {
				cout << "Did not find end word in file " << filename << endl;
				cout << word;
				Sleep(3000);
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
			 << " at the line of description " << currentLine << ":" << endl;
		cout << line.str() << endl;
		exit(1);
	}

	// Close the file when the end word is found:
	if (reader.is_open()) {
		reader.close();
	}
}
