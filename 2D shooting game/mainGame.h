#pragma once
#include "gameNode.h"

#define MAX 10
#define BOSSMAX 200

#define PI 3.1415926f
enum STATE
{
	IDLE,
	LEFT,
	RIGHT,
	COLLISION,
	RUN,
	DEAD
};

class mainGame : public gameNode
{
private:
	struct tagEnemy
	{
		float x, y;		//�÷��̾� �߽���ǥ
		float speed;		//�ӵ�
		bool live;
		float angle;
		RECT rc;
		POINT center;		//��ũ�� ����
		POINT cannonEnd;	//������ ����
		int radius;			//��ũ ���� ������
		int cannon;			//���� ����
	};


	struct tagBullet
	{
		float x, y;		//�÷��̾� �߽���ǥ
		float speed;		//�ӵ�
		float gravity;	//�߷�
		float angle;			//���� ����
		bool fire;
		bool life;
		int level;
		RECT rc;
	};

	struct tagPlayer
	{
		float x, y;		//�÷��̾� �߽���ǥ
		float speed;		//�ӵ�
		RECT rc;
	};


	image* _baseMov;
	image* _movRight;
	image* _movLeft;
	image* _bulletImg;
	image* _deadImg;
	image* _collision;

	int _num;


	//enemy1
	tagEnemy _enemy1[8];
	image* _enemy1Img;
	tagEnemy _enemy2[8];
	tagBullet _bulletE2[24];
	image* _enemy2Img;
	image* _enemybullet2Img;


	image* _bossbodyImg;
	image* _bossleftImg;
	image* _bossrightImg;
	image* _bossBulletImg;
	tagEnemy _bossbody;
	tagEnemy _bossleft;
	tagEnemy _bossright;
	int _bossHP;
	tagBullet _bossBullet[BOSSMAX];


	//��������
private:
	image* _bgImg;

	image* _stageImg1;
	image* _stageImg2;
	image* _stageImg3;

	RECT _stage1;
	bool _stage1S;
	//RECT _stage2;
	//bool _stage2S;
	//RECT _stage3;
	//bool _stage3S;

	bool _stageRun;

private:
	//int _loopX, _loopY;	//������ų ����
	//int _loopX2, _loopY2;	//������ų ����
	//int _loopX3, _loopY3;	//������ų ����



	RECT _obj[MAX];
	RECT _obj2[2];


	bool _gameOver;		//�浹�� ���� ������
	bool _gameStart;


	int _count;			//������ ���� ī��Ʈ(�ӵ�����)
	int _index;			//������ �̹��� �ε���
	bool _isLeft;		//�����̳�?
	STATE _state;
	int _score;			

	//ī��Ʈ�ٿ�
	char _str[100];		//�ð��� ���
	char _str1[100];		//�ð��� ���
	bool _time;			//�ð��� ����� �ְ�
	float _timer;		//Ÿ��

	tagPlayer _player;
	tagBullet _bullet[MAX];

public:
	HRESULT init();
	void release();
	void update();
	void render();
	tagBullet* getPbullet() { return _bullet; }
	bool getFire() { return _bullet[MAX].fire; }


	void setState(STATE name) { _state = name; }
	STATE getState(STATE name) { return _state; }


	void animation();

	void fire();
	void pFire();
	void bossFire();

	void moveBullet();
	void moveBossBullet();


	mainGame() {}
	~mainGame() {}
};

