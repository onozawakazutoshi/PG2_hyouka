#pragma once
class bullet
{
private:
	float x_;
	float y_;
	float radius_ = 5;

public:
	bool Bullet();
	void farst(float, float);

	float Getx() { return x_; };
	float Gety() { return y_; };
	float Getradius() { return radius_; };

};

