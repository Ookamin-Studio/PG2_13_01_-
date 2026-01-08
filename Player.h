#pragma once
#include"Bullet.h"

class Player
{
public:
	Bullet* bullet_;
	Vector2 pos_ = { 640,360 };
	int radius_ = 30;
	int speed_ = 5;

public:
	Player();
	~Player();
	void Update(char* keys, char* preKeys);
	void Draw();
};

