#include "EnemyA.h"
#include "Novice.h"
EnemyA::EnemyA(float posX, float posY, float speedX, float speedY, float radius,bool live)
{
	posX_ = posX;
	posY_ = posY;
	speedX_ = speedX;
	speedY_ = speedY;
	radius_ = radius;
	live_ = live;
}

void EnemyA::Update() {
	posX_ += speedX_;
	posY_ += speedY_;

	if (posX_ - radius_ <= 0 || posX_ + radius_ >= 1280) {
		speedX_ *= -1;
	}
	if (posY_ - radius_ <= 0 || posY_ + radius_ >= 720) {
		speedY_ *= -1;
	}
}

void EnemyA::Draw() {
	Novice::DrawEllipse((int)posX_, (int)posY_, (int)radius_, (int)radius_, 0.0f, BLUE, kFillModeSolid);
}
void EnemyA::Live() {
	live_ = false;
}