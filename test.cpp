#include "dialogue.h"

int main(){
        std::cout<<"\n" << YELLOW << "You stumble upon a temple, its walls covered in sand and its bricks showing centuries of erosion\n" << RESET;
    wait_for_enter();
    std::cout << "\n" << YELLOW << "You see a statue in the distance, an old king perhaps.\nIt is definitely intimidating, if you were opposing him, that would send you running with your tail between your legs.\n" <<RESET;
    wait_for_enter();
    std::cout << "\nHowever, his name must be long forgotten by now.\n";
    wait_for_enter();

    return 0;
}