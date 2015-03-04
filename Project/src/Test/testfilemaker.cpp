#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    ofstream outfile;
    outfile.open("test.txt");

    outfile << "start" << endl;
    outfile << "sound add collision ../Sounds/buzzer.wav" << endl;
    outfile << "sound add background ../Sounds/elevator.wav" << endl;

    outfile << "input add w move_up" << endl;
    outfile << "input add s move_down" << endl;
    outfile << "input add a move_left" << endl;
    outfile << "input add d move_right" << endl;
    outfile << "input add \\x1b quit" << endl;

    outfile << "gameobject add obstacle1 384 320 32 32 true" << endl;
    outfile << "gameobject add obstacle2 576 320 32 32 false" << endl;
    outfile << "texture add obstacle1 ../Images/black.bmp" << endl;
    outfile << "texture add obstacle2 ../Images/white.bmp" << endl;

    outfile << "playerobject add player 160 160 32 32" << endl;
    outfile << "texture add player ../Images/player_down.bmp" << endl;
    outfile << "texture add player ../Images/player_up.bmp" << endl;
    outfile << "texture add player ../Images/player_left.bmp" << endl;
    outfile << "texture add player ../Images/player_right.bmp" << endl;

    outfile << "aiobject add ai 320 320 32 32 WANDER" << endl;
    outfile << "texture add ai ../Images/red.bmp" << endl;

    outfile << "hudobject add hud_element 960 704 32 32 false" << endl;
    outfile << "texture add hud_element ../Images/purple_circle.bmp" << endl;

    outfile << "hudobject add fps_counter 990 744 64 64 true" << endl;
    outfile << "debug add fps_counter fps" << endl;

    for(int i = 0; i < 32; ++i) {
        for(int j = 0; j < 24; ++j) {
            std::stringstream ss;
            ss << "background_tile_" << i << "_" << j;
            string name = ss.str();

            outfile << "backgroundobject add " << name << " " << i*32 << " " << j*32 << " 32 32" << endl;
            if((i+j) % 2 == 1) {
                outfile << "texture add " << name << " ../Images/green.bmp" << endl;
            }
            else {
                outfile << "texture add " << name << " ../Images/yellow.bmp" << endl;
            }
        }
    }

    for(int i = 0; i < 32; ++i) {
        for(int j = 0; j < 24; ++j) {
            if(i == 0 || j == 0 || i == 31 || j == 23) {
                std::stringstream ss;
                ss << "wall_" << i << "_" << j;
                string name = ss.str();

                outfile << "gameobject add " << name << " " << i*32 << " " << j*32 << " 32 32 true" << endl;
                outfile << "texture add " << name << " ../Images/red.bmp" << endl;
            }
        }
    }

    outfile << "end" << endl;

    outfile.close();
    outfile.clear();

    return 0;
}

    

    

