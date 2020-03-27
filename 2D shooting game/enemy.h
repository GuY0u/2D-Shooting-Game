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
		float x, y;		//�÷��̾� �߽���ǥ
		float speed;		//�ӵ�
		RECT rc;
	};

	struct tagBullet
	{
		float x, y;		//�÷��̾� �߽���ǥ
		float speed;		//�ӵ�
		float gravity;	//�߷�
		bool fire;
		RECT rc;
	};


	image* _baseMov;
	image* _movRight;
	image* _movLeft;
	//�̰��� ���� ����
	int _count;			//������ ���� ī��Ʈ(�ӵ�����)
	int _index;			//������ �̹��� �ε���
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

