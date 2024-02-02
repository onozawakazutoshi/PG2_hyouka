#include "Enemy.h"
#include "Novice.h"

Enemy::Enemy() {
	
}

void Enemy::Update() {
	posX_ += speedX_;
	posY_ += speedY_;

	if (posX_ - radius_ <= 0 || posX_ + radius_ >= 1280) {
		speedX_ *= -1;
	}
	if (posY_ - radius_ <= 0 || posY_ + radius_ >= 720) {
		speedY_ *= -1;
	}
}

void Enemy::Draw() {
	Novice::DrawEllipse((int)posX_, (int)posY_, (int)radius_, (int)radius_, 0.0f, BLUE, kFillModeSolid);
}

void Enemy::Live() {
	live_ = false;
}