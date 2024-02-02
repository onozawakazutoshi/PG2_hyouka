#pragma once
#include"bullet.h"

class Player
{
public:
	Player(float posX, float posY, float speed, float radius,bool live);
	bullet* Bullet = new bullet();

	void Update(char keys[]);

	void Draw();

	bool Getlive() { return live_; };

	float GetPosX() { return posX_; };
	float GetPosY() { return posY_; };
	float Getradius() { return radius_; };

	void Live();
private:
	float posX_;
	float posY_;
	float speed_;
	float radius_;
	bool bulletflag = false;
	bool live_ = true;
};

