#include "Declarations.h"

Player* newPlayer(char* name)
{
	Player* result = (Player*)malloc(sizeof(Player));
	int lenght= strlen(name);
	result->name = (char*)malloc(sizeof(char)*(lenght +1));

	for (int i = 0; i < lenght; i++)
	{
		result->name[i] = *name;
		name++;
	}
	result->name[lenght] = 0;

	result->lives = 3;
	result->score = 0;
	result->yPosition = 0;
	result->bullets = (Bullet*)malloc(sizeof(Bullet)*NUM_SHOTS);
	for (int i = 0; i < NUM_SHOTS; i++)
	{
		result->bullets[i].shot = false;
		result->bullets[i].pos.x = 0;
		result->bullets[i].pos.y = 0;
	}

    return result;
}

void deletePlayer(Player* mPlayer)
{
	free(mPlayer->bullets);
	free(mPlayer->name);
	free(mPlayer);
}

void movePlayerUp(Player* mPlayer)
{
	
	if (mPlayer->yPosition != 0)
	{
		mPlayer->yPosition -= 1;
	}
		
}

void movePlayerDown(Player* mPlayer)
{
	
	if (mPlayer->yPosition != 9)
	{
		mPlayer->yPosition += 1;
	}
		
}

void newShoot(Player* mPlayer)
{
	bool salir = false;
	for (int i = 0; (i < NUM_SHOTS) && (salir == false); i++)
	{
		if (mPlayer->bullets[i].shot == false)
		{
			mPlayer->bullets[i].shot = true;
			mPlayer->bullets[i].pos.x = 1 ;
			mPlayer->bullets[i].pos.y = mPlayer->yPosition;
			salir = true;
		}
	}
}

void updateBulletsPositions(Player* mPlayer)
{
	for (int i = 0; i < NUM_SHOTS ; i++)
	{
		if (mPlayer->bullets[i].shot == true)
		{
			mPlayer->bullets[i].pos.x += 1;
			if (mPlayer->bullets[i].pos.x > 59)
			{
				mPlayer->bullets[i].shot = false;
			}
		}
	}
}

Enemy* newEnemy()
{
	Enemy* result = (Enemy*)malloc(sizeof(Enemy));
	result->pos.x = 59;
	result->pos.y = rand()%10;
    return result;
}

void deleteEnemy(Enemy* mEnemy)
{
	free(mEnemy);
}

void updateEnemyPosition(Enemy* mEnemy)
{
	mEnemy->pos.x -= 1;
}

bool checkEnemyHit(Enemy* mEnemy)
{
    
	return (mEnemy->pos.x == 0);
}