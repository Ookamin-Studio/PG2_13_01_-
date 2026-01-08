#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet() {
	pos_ = { 0,0 };
	speed_ = 10;
	radius_ = 5;
	isShot_ = false;
};

void Bullet::Update() {
	if (isShot_) {
		pos_.y -= speed_;
	}
	if (pos_.y <= -radius_) {
		isShot_ = false;
	};
}
void Bullet::Draw() {
	if (isShot_) {
		Novice::DrawEllipse(pos_.x, pos_.y, radius_, radius_, 0.0f, RED, kFillModeSolid);
	}
};
