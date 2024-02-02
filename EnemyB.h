#pragma once
#include "Enemy.h"
class EnemyB :
	public Enemy
{

public:
	EnemyB(float posX, float posY, float speedX, float speedY, float radius,bool live);


	void Update()override;

	void Draw()override;
	void Live()override;

	float GetPosX() { return posX_; };
	float GetPosY() { return posY_; };
	float Getradius() { return radius_; };
	
};

