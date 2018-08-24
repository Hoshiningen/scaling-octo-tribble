#include "GameManager.h"

int main()
{
    sot::GameManager& manager = sot::GameManager::getSingleton();
	manager.gameLoop();

	return 0;
}