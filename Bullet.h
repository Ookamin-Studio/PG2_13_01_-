#pragma once
struct Vector2 {
	int x;
	int y;
};

class Bullet
{
public:
	Bullet();
	void Update();
	void Draw();

public:
	Vector2 pos_ = { 0,0 };
	int speed_ = 10;
	int radius_ = 5;
	bool isShot_ = false;
};
