#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    ofstream outfile;
    outfile.open("level.txt");

    outfile << "start" << endl;
    outfile << "sound add collision ../Sounds/buzzer.wav" << endl;
    outfile << "sound add background ../Sounds/elevator.wav" << endl;

    outfile << "input add w move_up" << endl;
    outfile << "input add s move_down" << endl;
    outfile << "input add a move_left" << endl;
    outfile << "input add d move_right" << endl;
    outfile << "input add q quit" << endl;

    outfile << "playerobject add player 160 160 50 50" << endl;
    outfile << "texture add player ../Images/player_down.bmp" << endl;
    outfile << "texture add player ../Images/player_up.bmp" << endl;
    outfile << "texture add player ../Images/player_left.bmp" << endl;
    outfile << "texture add player ../Images/player_right.bmp" << endl;

    outfile << "aiobject add ai1 250 1700 50 50 STILL" << endl;
    outfile << "texture add ai1 ../Images/turret.bmp" << endl;
    outfile << "aiobject add ai2 400 1550 50 50 STILL" << endl;
    outfile << "texture add ai2 ../Images/turret.bmp" << endl;
    outfile << "aiobject add ai3 250 1400 50 50 STILL" << endl;
    outfile << "texture add ai3 ../Images/turret.bmp" << endl;
    outfile << "aiobject add ai4 400 1250 50 50 STILL" << endl;
    outfile << "texture add ai4 ../Images/turret.bmp" << endl;
    outfile << "aiobject add ai5 250 1100 50 50 STILL" << endl;
    outfile << "texture add ai5 ../Images/turret.bmp" << endl;
    outfile << "aiobject add ai6 550 1750 50 50 STILL" << endl;
    outfile << "texture add ai6 ../Images/turret.bmp" << endl;
    outfile << "aiobject add ai7 1350 1800 50 50 STILL" << endl;
    outfile << "texture add ai7 ../Images/turret.bmp" << endl;
    outfile << "aiobject add ai8 550 200 50 50 STILL" << endl;
    outfile << "texture add ai8 ../Images/turret.bmp" << endl;
    outfile << "aiobject add ai9 750 200 50 50 STILL" << endl;
    outfile << "texture add ai9 ../Images/turret.bmp" << endl;
    outfile << "aiobject add ai10 1350 700 50 50 STILL" << endl;
    outfile << "texture add ai10 ../Images/turret.bmp" << endl;
    outfile << "aiobject add ai11 550 500 50 50 STILL" << endl;
    outfile << "texture add ai11 ../Images/turret.bmp" << endl;
    outfile << "aiobject add ai12 550 700 50 50 STILL" << endl;
    outfile << "texture add ai12 ../Images/turret.bmp" << endl;
    outfile << "aiobject add ai13 950 1300 50 50 STILL" << endl;
    outfile << "texture add ai13 ../Images/turret.bmp" << endl;

    outfile << "aiobject add ai14 200 850 50 50 STILL" << endl;
    outfile << "texture add ai14 ../Images/red.bmp" << endl;
    outfile << "aiobject add ai15 600 1150 50 50 STILL" << endl;
    outfile << "texture add ai15 ../Images/red.bmp" << endl;
    outfile << "aiobject add ai16 800 1350 50 50 STILL" << endl;
    outfile << "texture add ai16 ../Images/red.bmp" << endl;
    outfile << "aiobject add ai17 1000 1850 50 50 STILL" << endl;
    outfile << "texture add ai17 ../Images/red.bmp" << endl;
    outfile << "aiobject add ai18 1200 1100 50 50 STILL" << endl;
    outfile << "texture add ai18 ../Images/red.bmp" << endl;
    outfile << "aiobject add ai19 1000 750 50 50 STILL" << endl;
    outfile << "texture add ai19 ../Images/red.bmp" << endl;
    outfile << "aiobject add ai20 400 350 50 50 STILL" << endl;
    outfile << "texture add ai20 ../Images/red.bmp" << endl;
    outfile << "aiobject add ai21 200 100 50 50 STILL" << endl;
    outfile << "texture add ai21 ../Images/red.bmp" << endl;
    outfile << "aiobject add ai22 1000 100 50 50 STILL" << endl;
    outfile << "texture add ai22 ../Images/red.bmp" << endl;
    outfile << "aiobject add ai23 1400 1500 50 50 STILL" << endl;
    outfile << "texture add ai23 ../Images/red.bmp" << endl;

    outfile << "gameobject add coin1 100 1500 25 25 true" << endl;
    outfile << "texture add coin1 ../Images/coin.bmp" << endl;
    outfile << "gameobject add coin2 100 1300 25 25 true" << endl;
    outfile << "texture add coin2 ../Images/coin.bmp" << endl;
    outfile << "gameobject add coin3 100 1100 25 25 true" << endl;
    outfile << "texture add coin3 ../Images/coin.bmp" << endl;
    outfile << "gameobject add coin4 250 1750 25 25 true" << endl;
    outfile << "texture add coin4 ../Images/coin.bmp" << endl;
    outfile << "gameobject add coin5 400 1600 25 25 true" << endl;
    outfile << "texture add coin5 ../Images/coin.bmp" << endl;
    outfile << "gameobject add coin6 250 1450 25 25 true" << endl;
    outfile << "texture add coin6 ../Images/coin.bmp" << endl;
    outfile << "gameobject add coin7 400 1300 25 25 true" << endl;
    outfile << "texture add coin7 ../Images/coin.bmp" << endl;
    outfile << "gameobject add coin8 250 1150 25 25 true" << endl;
    outfile << "texture add coin8 ../Images/coin.bmp" << endl;
    outfile << "gameobject add coin9 550 1850 25 25 true" << endl;
    outfile << "texture add coin9 ../Images/coin.bmp" << endl;
    outfile << "gameobject add coin10 1350 1700 25 25 true" << endl;
    outfile << "texture add coin10 ../Images/coin.bmp" << endl;
    outfile << "gameobject add coin11 500 1250 25 25 true" << endl;
    outfile << "texture add coin11 ../Images/coin.bmp" << endl;
    outfile << "gameobject add coin12 550 100 25 25 true" << endl;
    outfile << "texture add coin12 ../Images/coin.bmp" << endl;
    outfile << "gameobject add coin13 500 550 25 25 true" << endl;
    outfile << "texture add coin13 ../Images/coin.bmp" << endl;
    outfile << "gameobject add coin14 600 650 25 25 true" << endl;
    outfile << "texture add coin14 ../Images/coin.bmp" << endl;
    outfile << "gameobject add coin15 750 100 25 25 true" << endl;
    outfile << "texture add coin15 ../Images/coin.bmp" << endl;
    outfile << "gameobject add coin16 1350 400 25 25 true" << endl;
    outfile << "texture add coin16 ../Images/coin.bmp" << endl;
    outfile << "gameobject add coin17 1350 600 25 25 true" << endl;
    outfile << "texture add coin17 ../Images/coin.bmp" << endl;

    outfile << "hudobject add hud_element 900 900 50 50 false" << endl;
    outfile << "texture add hud_element ../Images/purple_circle.bmp" << endl;

    outfile << "hudobject add fps_counter 900 900 50 50 true" << endl;
    outfile << "debug add fps_counter fps" << endl;

    outfile << "backgroundobject add background 50 -100 2048 2048" << endl;
    outfile << "texture add background ../Images/background.bmp" << endl;

    for(int i = 0; i < 30; ++i) {
        for(int j = 0; j < 40; ++j) {
            if(i == 0 || j == 0 || i == 29 || j == 39) {
                std::stringstream ss;
                ss << "wall_" << i << "_" << j;
                string name = ss.str();

                outfile << "gameobject add " << name << " " << i*50 << " " << j*50 << " 50 50 true" << endl;
                outfile << "texture add " << name << " ../Images/wall.bmp" << endl;
            }
        }
    }

    outfile << "end" << endl;

    outfile.close();
    outfile.clear();

    return 0;
}

    

    

