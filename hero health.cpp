#include <iostream>
#include <windows.h>
#include <string>

int main()
{
    int playerHealt = 500;

    std::cout << "Esta é a vida do jogador:" << playerHealt << "\n";

    HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    INPUT_RECORD inp;
    DWORD num_of_events;

    bool exit = false;

    do
    {
        // Read Console Input
        ReadConsoleInput(hIn, &inp, 1, &num_of_events);

        switch (inp.EventType)
        {
        case KEY_EVENT:
            switch (inp.Event.KeyEvent.wVirtualKeyCode)
            {
            case VK_SPACE:
                int oldPlayerHealth = playerHealt;
                playerHealt = playerHealt - 10;
                if (playerHealt <= 0) {
                    std::cout << "\ro jogador morreu";
                    exit = true;    
                }
                else if((oldPlayerHealth - 10) == playerHealt) {
                    std::cout << "\ro jogador foi atacado por 10 de dano essa é a nova vida do jogador: " << playerHealt;
                }
                else if (oldPlayerHealth == playerHealt) {
                    std::cout << "\rparabens o jogador nao tomou nenhum dano!";
                }
                else if (playerHealt > oldPlayerHealth) {
                    int extra_life = playerHealt - oldPlayerHealth;
                    std::cout << "\rparabens a vida do jogador aumentou " << extra_life << " de vida extra" << " de dano a vida do jogadore e " << playerHealt;
                }
                else if (oldPlayerHealth > (playerHealt - 10)) {
                    int damage = oldPlayerHealth - playerHealt;
                    std::cout << "\rparabens o jogador tomou menos que 10 de dano, porem ele tomou dano, ele tomou " << damage << " de dano a vida do jogadore e " << playerHealt;
                }
                break;
            }
            break;
        }
    } while (!exit);
}