#include "GameManager.h"


int main()
{
	GameManager manager{ 1200, 800 };

	manager.gameLoop();
	return 0;
}