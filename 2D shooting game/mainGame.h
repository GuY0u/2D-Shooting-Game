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
		float x, y;		//플레이어 중심좌표
		float speed;		//속도
		bool live;
		float angle;
		RECT rc;
		POINT center;		//탱크의 중점
		POINT cannonEnd;	//포신의 끝점
		int radius;			//탱크 몸통 반지름
		int cannon;			//포신 길이
	};


	struct tagBullet
	{
		float x, y;		//플레이어 중심좌표
		float speed;		//속도
		float gravity;	//중력
		float angle;			//포신 각도
		bool fire;
		bool life;
		int level;
		RECT rc;
	};

	struct tagPlayer
	{
		float x, y;		//플레이어 중심좌표
		float speed;		//속도
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


	//스테이지
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
	//int _loopX, _loopY;	//루프시킬 변수
	//int _loopX2, _loopY2;	//루프시킬 변수
	//int _loopX3, _loopY3;	//루프시킬 변수



	RECT _obj[MAX];
	RECT _obj2[2];


	bool _gameOver;		//충돌시 게임 끝내기
	bool _gameStart;


	int _count;			//프레임 돌릴 카운트(속도조절)
	int _index;			//프레임 이미지 인덱스
	bool _isLeft;		//왼쪽이냐?
	STATE _state;
	int _score;			

	//카운트다운
	char _str[100];		//시간초 출력
	char _str1[100];		//시간초 출력
	bool _time;			//시간초 멈출수 있게
	float _timer;		//타임

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

