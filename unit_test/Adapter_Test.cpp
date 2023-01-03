#include "StructMode/Adapter.h"

using  namespace  DP;

int main() {
    std::cout << "Adapter Pattern\n" << std::endl;

    AudioPlayer* player = new AudioPlayer();
    player->play("mp3", "test.mp3");
    player->play("mp4", "test.mp4");
    player->play("vlc", "test.vlc");

    return 0;
}