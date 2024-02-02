#include "bullet.h"
#include "Player.h"
#include <Novice.h>

void bullet::farst(float playerX, float playerY) {
	x_ = playerX;
	y_ = playerY;
}
bool bullet::Bullet() {

	Novice::DrawEllipse((int)x_, (int)y_, (int)radius_, (int)radius_, 0.0f, 0xFF00FFFF, kFillModeSolid);
	y_ -= 5;

	if (y_ < 0) {
		return false;
	}
	else {
		return true;
	}

}
