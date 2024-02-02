#include "Player.h"
#include"Novice.h"
#include"bullet.h"

bullet* Bullet = new bullet();
Player::Player(float posX, float posY, float speed, float radius,bool live) {
	posX_ = posX;
	posY_ = posY;
	speed_ = speed;
	radius_ = radius;
	live_ = live;
}

void Player::Update(char keys[]) {
	if (keys[DIK_A]) {
		posX_ -= speed_;
	}
	if (keys[DIK_D]) {
		posX_ += speed_;
	}
	if (keys[DIK_W]) {
		posY_ -= speed_;
	}
	if (keys[DIK_S]) {
		posY_ += speed_;
	}
	if (keys[DIK_SPACE] && !bulletflag) {
		bulletflag = true;
		Bullet->farst(posX_,posY_);
	}
	if (bulletflag) {
		bulletflag = Bullet->Bullet();
	}

	if (posX_ > 1280) {
		posX_ -= speed_;
	}
	if (posX_ < 0) {
		posX_ += speed_;
	}
	if (posY_ > 720) {
		posY_ -= speed_;
	}
	if (posY_ < 0) {
		posY_ += speed_;
	}
}

void Player::Draw() {
	Novice::DrawEllipse((int)posX_, (int)posY_, (int)radius_, (int)radius_, 0.0f, RED, kFillModeSolid);
}

void Player::Live() {
	live_ = false;
}