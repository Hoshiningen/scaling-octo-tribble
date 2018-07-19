#include "GameManager.h"

int main()
{
    GameManager& manager = GameManager::getSingleton();
	manager.gameLoop();

	return 0;
}