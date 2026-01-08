#pragma once
#include"Bullet.h"

class Enemy {
public:
	Enemy(Vector2 pos, int speedX, int speedY);
	~Enemy();

	void Update();
	void Draw();

public:
	static bool allAlive;
	Vector2 pos_ = { 0,0 };
	int speedX_ = 0;
	int speedY_ = 0;
	int radius_ = 20;

};