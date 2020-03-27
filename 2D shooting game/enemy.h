#pragma once
#include "gameNode.h"




enum ENEMYSTATE
{
	IDLE,
	MOVE,
	ATTACK,
	COLLISION,
	DEAD
};

class enemy : public gameNode
{
private:
	struct tagEnemy
	{
		float x, y;		//플레이어 중심좌표
		float speed;		//속도
		RECT rc;
	};

	struct tagBullet
	{
		float x, y;		//플레이어 중심좌표
		float speed;		//속도
		float gravity;	//중력
		bool fire;
		RECT rc;
	};


	image* _baseMov;
	image* _movRight;
	image* _movLeft;
	//이곳에 변수 선언
	int _count;			//프레임 돌릴 카운트(속도조절)
	int _index;			//프레임 이미지 인덱스
	ENEMYSTATE _state;

	int _num;






public:
	HRESULT init();
	void release();
	void update();
	void render();
	RECT getEnemy() { return _enemy1[8].rc; }

	void animation();

	void fire();

	void moveBullet();


	enemy() {}
	~enemy() {}
};

