#include "player.h"

Player::Player(int socket, size_t id)
{
    ID = id;
    time = 0;
    I = 0;
    this->socket = socket;
}

bool Player::registretion()
{
    if (aim.shoot())
    {
        desk.close_target(I);
        I ++;
        //aim.replace();
        /*Если попал, то наложить текстуру в виде белого круга, радиусом чуть меньше, чем мишень.
         * Затем переходим на следующую мишень*/
        return true;
    }
    else
    {
        //штрафное время t += n;
        I ++;
        //aim.replace();
        return false;
    }

}
