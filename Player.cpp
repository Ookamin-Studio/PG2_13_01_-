#include "Player.h"
#include<Novice.h>

Player::Player() {
	bullet_ = new Bullet();
	pos_ = { 640,360 };
	radius_ = 30;
	speed_ = 5;
};

Player::~Player() {
	delete bullet_;
};

void Player::Update(char* keys, char* preKeys) {

	if (keys[DIK_W]) {
		pos_.y -= speed_;
	}
	if (keys[DIK_S]) {
		pos_.y += speed_;
	}
	if (keys[DIK_A]) {
		pos_.x -= speed_;
	}
	if (keys[DIK_D]) {
		pos_.x += speed_;
	}

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		if (!bullet_->isShot_) {
			bullet_->isShot_ = true;
			bullet_->pos_ = pos_;
		}
	}

	bullet_->Update();

}
;
void Player::Draw() {

	bullet_->Draw();
	Novice::DrawEllipse(pos_.x, pos_.y, radius_, radius_, 0.0f, WHITE, kFillModeSolid);

};
