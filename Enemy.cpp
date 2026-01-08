#include "Enemy.h"
#include<Novice.h>

bool Enemy::globalAlive = true;

Enemy::Enemy(Vector2 pos, int speedX, int speedY) {
	pos_.x = pos.x;
	pos_.y = pos.y;
	speedX_ = speedX;
	speedY_ = speedY;
}

Enemy::~Enemy() {
}


void Enemy::Update() {
	if (globalAlive) {
		if (isAlive_) {
			pos_.x += speedX_;

			if (pos_.x - radius_ <= 0 || pos_.x + radius_ >= 1280) {
				speedX_ *= -1;
			}
		}
	}
	else {
		isAlive_ = false;
	}
}

void Enemy::Draw() {
	if (globalAlive && isAlive_) {
		Novice::DrawEllipse(pos_.x, pos_.y, radius_, radius_, 0.0f, RED, kFillModeSolid);
	}
}

void Enemy::KillAll() {
	globalAlive = false;
}

void Enemy::RespownAll() {
	isAlive_ = true;
	globalAlive = true;
}