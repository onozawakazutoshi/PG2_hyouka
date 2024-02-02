#pragma once
class Enemy
{
public:
	Enemy();


	virtual void Update();

	virtual void Draw();

	virtual void Live();

	float GetPosX() { return posX_; };
	float GetPosY() { return posY_; };
	float Getradius() { return radius_; };

public:
	float posX_;
	float posY_;
	float speedX_;
	float speedY_;
	float radius_;
	bool live_;
};

