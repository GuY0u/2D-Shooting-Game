#include "stdafx.h"
#include "mainGame.h"

//=============================================================
//	## �ʱ�ȭ ## init()
//=============================================================
HRESULT mainGame::init()
{
	gameNode::init();


	//�̰����� �ʱ�ȭ�� �Ѵ�

	////��׶��� �̹���
	//IMAGEMANAGER->addImage("���", "bgImg.bmp", WINSIZEX, WINSIZEY);
	//IMAGEMANAGER->addImage("����", "decoImg.bmp", 800, 50);
	//IMAGEMANAGER->addImage("�ٴ�", "groundImg.bmp", 800, 200);
	//_enemy = IMAGEMANAGER->addFrameImage("��", "enemy.bmp", 100, 30, 2, 1);
	//_enemy2 = IMAGEMANAGER->addImage("��2", "enemy2.bmp", 100, 200, true, RGB(255, 0, 255));


	_bgImg = IMAGEMANAGER->addImage("���", "image/bgImg.bmp", 900, 3000);

	_enemy1Img = IMAGEMANAGER->addFrameImage("��1", "image/enemy1.bmp", 400, 58, 8, 1);
	_enemy2Img = IMAGEMANAGER->addFrameImage("��2", "image/enemy2.bmp", 350, 58, 7, 1);

	_enemybullet2Img = IMAGEMANAGER->addFrameImage("��2�Ѿ�", "image/enemy2Bullet.bmp", 540, 34, 18, 1);
	_bossBulletImg = IMAGEMANAGER->addFrameImage("�����Ѿ�", "image/enemy2Bullet.bmp", 540, 34, 18, 1);


	_bossbodyImg = IMAGEMANAGER->addImage("������", "image/bossBody.bmp", 193, 300, true, RGB(255, 0, 255));
	_bossleftImg = IMAGEMANAGER->addFrameImage("������", "image/bossLeft.bmp", 700, 323, 7, 1);
	_bossrightImg = IMAGEMANAGER->addFrameImage("������", "image/bossRight.bmp", 700, 323, 7, 1);


	//�÷��̾� Ŭ���� �ʱ�ȭ
	_baseMov = IMAGEMANAGER->addFrameImage("���", "image/baseMov.bmp", 800, 173, 8, 1, true, RGB(255, 0, 255));
	_movLeft = IMAGEMANAGER->addFrameImage("���̵�", "image/movLeft.bmp", 800, 173, 8, 1, true, RGB(255, 0, 255));
	_movRight = IMAGEMANAGER->addFrameImage("���̵�", "image/movRight.bmp", 800, 173, 8, 1, true, RGB(255, 0, 255));
	_bulletImg = IMAGEMANAGER->addFrameImage("�Ѿ�", "image/bullet.bmp", 174, 60, 3, 1, true, RGB(255, 0, 255));
	_deadImg = IMAGEMANAGER->addFrameImage("���", "image/dead.bmp", 1518, 173, 9, 1, true, RGB(255, 0, 255));
	_collision = IMAGEMANAGER->addFrameImage("�浹", "image/collision.bmp", 800, 173, 8, 1, true, RGB(255, 0, 255));
	_count = _index = 0;

	_state = IDLE;

	_num = 0;

	_player.x = 350;
	_player.y = 800;
	for (int i = 0; i < MAX; i++)
	{
		_bullet[i].fire = false;
		_bullet[i].level = 0;
	}


	_player.speed = 2.0f;
	for (int i = 0; i < MAX; i++)
	{
		_bullet[i].speed = 5.0f;
	}


	_time = true;
	_timer = 0.0f;

	_gameStart = false;
	_gameOver = false;

	//�������� ����
	//_stage1 = RectMake(-100, -100, 900, 1100);
	_stage1 = RectMake(0, 0, 900, 3000);
	//bool _stage1S = true;
	//bool _stage2S = false;
	//bool _stage3S = false;]
	_bossbody.rc = RectMake(350, 100, 193, 300);
	_bossleft.rc = RectMake(_bossbody.rc.left - 50, _bossbody.rc.top, 100, 323);
	_bossright.rc = RectMake(_bossbody.rc.right - 50, _bossbody.rc.top, 100, 323);


	_bossbody.angle = PI / 2;	//90���� ���� �����
	_bossbody.cannon = 150;		//���� ����
	_bossbody.radius = 100;		//��ũ ���� ������
	_bossbody.center.x = 400;  //��ũ �߽� x��ǥ
	_bossbody.center.y = 300;		//��ũ �߽� y��ǥ

	for (int i = 0; i < BOSSMAX; i++)
	{
		_bossBullet[i].speed = 0.6f;
		_bossBullet[i].fire = false;
	}





	//enemy1
	_enemy1[0].rc = RectMake(-100, -100, 50, 58);
	_enemy1[1].rc = RectMake(-200, -200, 50, 58);
	_enemy1[2].rc = RectMake(-300, -300, 50, 58);
	_enemy1[3].rc = RectMake(-400, -400, 50, 58);

	_enemy1[4].rc = RectMake(900, -100, 50, 58);
	_enemy1[5].rc = RectMake(1000, -200, 50, 58);
	_enemy1[6].rc = RectMake(1100, -300, 50, 58);
	_enemy1[7].rc = RectMake(1200, -400, 50, 58);

	for (int i = 0; i < 8; i++)
	{
		_enemy1[i].live = true;
		_enemy1[i].speed = 0.0f;
	}

	//enemy2
	_enemy2[0].rc = RectMake(-100, 100, 50, 58);
	_enemy2[1].rc = RectMake(-200, 100, 50, 58);
	_enemy2[2].rc = RectMake(-300, 100, 50, 58);
	_enemy2[3].rc = RectMake(-400, 100, 50, 58);

	_enemy2[4].rc = RectMake(900, 100, 50, 58);
	_enemy2[5].rc = RectMake(1000, 100, 50, 58);
	_enemy2[6].rc = RectMake(1100, 100, 50, 58);
	_enemy2[7].rc = RectMake(1200, 100, 50, 58);

	for (int i = 0; i < 8; i++)
	{
		_enemy2[i].live = true;
		_enemy2[i].speed = 0.0f;
	}

	//enemy2�Ѿ�
	for (int i = 0; i < 8; i++)
	{
		_bulletE2[i].fire = false;
		_bulletE2[i].life = true;
		_bulletE2[i].gravity = 5.0f;
	}

	_bossHP = 20;


	return S_OK;
}

//=============================================================
//	## ���� ## release()
//=============================================================
void mainGame::release()
{
	gameNode::release();
	//�̹��� Ŭ������ ���������� ����� �� ����
	//�����Ҵ� new�� ����ߴٸ� �̰����� SAFE_DELETE() ����Ѵ�

	//�÷��̾� Ŭ���� ����

}

//=============================================================
//	## ������Ʈ ## update()
//=============================================================
void mainGame::update()
{
	gameNode::update();
	//�̰����� ����, Ű����, ���콺��� ������Ʈ�� �Ѵ�
	//�����ϰ� �̰����� �ڵ��Ѵٰ� �����ϸ� �ȴ�
	//�浹ó��

	//����

	//enemy1 ����


	//_loopX += 3;
	//_loopY++;


	if (_gameStart == true &&_gameOver == false)
	{

	_time = true;


	//if (_enemy1[0].live == true)
	//{
	//	_enemy1[0].rc.top++;
	//	_enemy1[0].rc.bottom++;
	//	_enemy1[0].rc.left += _enemy1->speed;
	//	_enemy1[0].rc.right += _enemy1->speed;
	//}

	//if (_enemy1[1].live == true)
	//{
	//	_enemy1[1].rc.top++;
	//	_enemy1[1].rc.bottom++;
	//	_enemy1[1].rc.left -= _enemy1->speed;
	//	_enemy1[1].rc.right -= _enemy1->speed;
	//}

	//enemy1�� �÷��̾��Ѿ��浹
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			RECT temp;
			if (IntersectRect(&temp, &_enemy1[i].rc, &_bullet[j].rc))
			{
				/*_enemy1[i].rc.top = 1000;
				_enemy1[i].rc.bottom = 1000;
				_enemy1[i].rc.left = 1000;
				_enemy1[i].rc.right = 1000;*/
				_bullet[j].fire = false;
				_bullet[j].rc.left = _player.rc.left + 50;
				_bullet[j].rc.top = _player.rc.top - 10;
				_enemy1[i].live = false;
				break;
			}

		}

	}

	//13�� ��2����
	if (_timer > 13.0f)
	{
		for (int i = 0; i < 8; i++)
		{
			if (i < 4 && _enemy1[i].live == true)
			{
				_enemy1[i].rc.top++;
				_enemy1[i].rc.bottom++;
				_enemy1[i].rc.left += 1;
				_enemy1[i].rc.right += 1;
			}
			else if (i > 3 && _enemy1[i].live == true)
			{
				_enemy1[i].rc.top++;
				_enemy1[i].rc.bottom++;
				_enemy1[i].rc.left -= 1;
				_enemy1[i].rc.right -= 1;
			}

			_enemy1[i].speed += 0.01;
		}
	}

	//enemy2�� �÷��̾� �Ѿ� �浹
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			RECT temp;
			if (IntersectRect(&temp, &_enemy2[i].rc, &_bullet[j].rc))
			{
				/*_enemy1[i].rc.top = 1000;
				_enemy1[i].rc.bottom = 1000;
				_enemy1[i].rc.left = 1000;
				_enemy1[i].rc.right = 1000;*/
				_bullet[j].fire = false;
				_bullet[j].rc.left = _player.rc.left + 50;
				_bullet[j].rc.top = _player.rc.top - 10;
				_enemy2[i].live = false;
				break;
			}
		}
	}

	//�÷��̾�� enemy2�Ѿ� �浹
	for (int i = 0; i < 24; i++)
	{
		if (_bulletE2[i].fire == false)continue;
		RECT temp;
		if (IntersectRect(&temp, &_bulletE2[i].rc, &_player.rc))
		{
			_gameOver = true;
			_state = DEAD;
		}
	}

	//enemy2 ��ü �̵�
	for (int i = 0; i < 8; i++)
	{
		if (i < 4 && _enemy2[i].live == true)
		{
			_enemy2[i].rc.left += 1;
			_enemy2[i].rc.right += 1;
		}
		else if (i > 3 && _enemy2[i].live == true)
		{
			_enemy2[i].rc.left -= 1;
			_enemy2[i].rc.right -= 1;
		}

		_enemy2[i].speed += 0.01;
	}

	//���� Ÿ��
	for (int i = 0; i < BOSSMAX; i++)
	{
		if (_timer > 20.0f)
		{
			RECT temp;
			if (IntersectRect(&temp, &_bossbody.rc, &_bullet[i].rc))
			{
				_bossHP--;
				_bullet[i].rc.left = -1000;
				_bullet[i].rc.right = -1000;
				_bullet[i].rc.top = -1000;
				_bullet[i].rc.bottom = -1000;
				break;
			}
			if (IntersectRect(&temp, &_bossleft.rc, &_bullet[i].rc))
			{
				_bossHP--;
				_bullet[i].rc.left = -1000;
				_bullet[i].rc.right = -1000;
				_bullet[i].rc.top = -1000;
				_bullet[i].rc.bottom = -1000;
				break;
			}
			if (IntersectRect(&temp, &_bossright.rc, &_bullet[i].rc))
			{
				_bossHP--;
				_bullet[i].rc.left = -1000;
				_bullet[i].rc.right = -1000;
				_bullet[i].rc.top = -1000;
				_bullet[i].rc.bottom = -1000;
				break;
			}
		}
	}

	if (_timer > 20.0f)
	{
		_bossbody.cannonEnd.x = cosf(_bossbody.angle) + _bossbody.center.x;
		_bossbody.cannonEnd.y = -sinf(_bossbody.angle) + _bossbody.center.y;
		_bossbody.angle -= 1.0f;
	}

	if (_timer > 20.0f)
	{
		this->bossFire();
		this->moveBossBullet();
	}


	//��ü�浹
	for (int i = 0; i < 8; i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &_bossbody.rc, &_player.rc))
		{
			_state = COLLISION;
			break;
		}
		if (IntersectRect(&temp, &_enemy1[i].rc, &_player.rc))
		{
			_state = COLLISION;
			break;
		}
		if (IntersectRect(&temp, &_enemy2[i].rc, &_player.rc))
		{
			_state = COLLISION;
			break;
		}
	}



	//�÷��̾� Ŭ������ �ϲ� ������Ʈ��!!
	//��������
	if (_stage1.bottom != WINSIZEY)
	{
		_stage1.bottom -= 1;
		_stage1.top -= 1;
	}
	//enemy2�Ѿ� �߻�
	if (_timer > 5 && _timer < 6)
	{
		this->fire();
	}



	//�÷��̾�
	//�̵��κ�
	//�� �̵�
	if (INPUT->GetKey(VK_LEFT) && _player.rc.left > 0)
	{
		_state = LEFT;
		_player.x -= 3;
	}
	if (INPUT->GetKeyUp(VK_LEFT))
	{
		_state = IDLE;
	}
	//�� �̵�
	if (INPUT->GetKey(VK_RIGHT) && _player.rc.right < WINSIZEX)
	{
		_state = RIGHT;
		_player.x += 3;
	}
	if (INPUT->GetKeyUp(VK_RIGHT))
	{
		_state = IDLE;
	}
	//�� �̵�
	if (INPUT->GetKey(VK_UP) && _player.rc.top > 0)
	{
		_player.y -= 3;
	}
	//�Ʒ� �̵�
	if (INPUT->GetKey(VK_DOWN) && _player.rc.bottom < WINSIZEY)
	{
		_player.y += 3;
	}
	for (int i = 0; i < MAX; i++)
	{
		if (INPUT->GetKeyDown(VK_F1) && _bullet[i].level < 3)
		{

			_bullet[i].level++;
		}
	}

	//�Ѿ� �߻�
	if (INPUT->GetKeyDown(VK_SPACE))
	{
		this->pFire();
	}


	if (INPUT->GetKeyDown(VK_F2))
	{
		_state = DEAD;
	}





	_player.rc = RectMake(_player.x + 30, _player.y + 40, 60, 103);

	//�Ѿ� �̹��� ����


	this->moveBullet();

	this->animation();


	//RECT temp;
	//for (int i = 0; i < MAX; i++)
	//{
	//	_gameOver = true;
	//	if (IntersectRect(&temp, &_obj[i], &_player->getRect()))
	//	{
	//		WM_DESTROY;
	//		PostQuitMessage(0);
	//		return;
	//	}
	//}

	//RECT temp2;
	//for (int i = 0; i < 2; i++)
	//{
	//	_gameOver = true;
	//	if (IntersectRect(&temp2, &_obj2[i], &_player->getRect()))
	//	{
	//		WM_DESTROY;
	//		PostQuitMessage(0);
	//		return;
	//	}
	//}

	_timer += 0.01f;
	}


	//���� ����
	if (_gameStart == false && _gameOver == false)
	{
		if (INPUT->GetKeyDown(VK_SPACE))
		{
			_gameStart = true;
			_gameOver = false;
		}

	}

	//���� ����
	if (_gameStart == true && _gameOver == true)
	{
		if (INPUT->GetKeyDown(VK_SPACE))
		{
			_gameStart = false;
			_gameOver = false;
			this->init();
		}
	}

}

//=============================================================
//	## ���� ## render()
//=============================================================
void mainGame::render()
{
	//��� �� ��Ʈ��
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//=============================================================	
		//�̰����� WM_PAINT���� �ߴ����� ó���ϸ� �ȴ�


	//��������
	//_stage2 = RectMake(-100, _stage1.top - 1000, 900, 1100);
	//_stage3 = RectMake(-100, _stage2.top - 1000, 900, 1100);

	//Rectangle(getMemDC(), _stage1);
	//HBRUSH Brush1 = CreateSolidBrush(RGB(255, 0, 0));
	//FillRect(getMemDC(), &_stage1, Brush1);

	//Rectangle(getMemDC(), _stage2);
	//HBRUSH Brush2 = CreateSolidBrush(RGB(0, 255, 0));
	//FillRect(getMemDC(), &_stage2, Brush2);

	//Rectangle(getMemDC(), _stage3);
	//HBRUSH Brush3 = CreateSolidBrush(RGB(0, 0, 255));
	//FillRect(getMemDC(), &_stage3, Brush3);





	_bgImg->render(getMemDC(), _stage1.left, _stage1.top);



	//sprintf(_str, "�ð� : %f", _timer);
	//TextOut(getMemDC(), 100, 100, _str, strlen(_str));

	//sprintf(_str1, "��ü�� : %d", _bossHP);
	//TextOut(getMemDC(), 100, 150, _str1, strlen(_str1));



	////enemy1 �簢��
	//for (int i = 0; i < 8; i++)
	//{
	//	if (_enemy1[i].live == false)continue;
	//	Rectangle(getMemDC(), _enemy1[i].rc);
	//}
	//enemy1 �簢���̹���

			//�ൿ����
	switch (_state)
	{
	case IDLE:
		_baseMov->frameRender(getMemDC(), _player.x, _player.y);
		break;
	case LEFT:
		_movLeft->frameRender(getMemDC(), _player.x, _player.y);
		break;
	case RIGHT:
		_movRight->frameRender(getMemDC(), _player.x, _player.y);
		break;
	case COLLISION:
		_collision->frameRender(getMemDC(), _player.x, _player.y);
		break;
	case DEAD:
		_deadImg->frameRender(getMemDC(), _player.x, _player.y);
		break;
	}






	for (int i = 0; i < 8; i++)
	{
		if (_enemy1[i].live == false)continue;
		_enemy1Img->frameRender(getMemDC(), _enemy1[i].rc.left, _enemy1[i].rc.top);

		_count++;
		_enemy1Img->setFrameY(0);
		if (_count % 15 == 0)
		{
			_index++;
			if (_index > 8)
			{
				_index = 0;
			}
			_enemy1Img->setFrameX(_index);
		}
	}

	//enemy2 �簢��
	for (int i = 0; i < 8; i++)
	{
		if (_enemy2[i].live == false)continue;
		//Rectangle(getMemDC(), _enemy2[i].rc);
	}
	//enemy2 �簢���̹���
	for (int i = 0; i < 8; i++)
	{
		if (_enemy2[i].live == false)continue;
		_enemy2Img->frameRender(getMemDC(), _enemy2[i].rc.left, _enemy2[i].rc.top);

		_count++;
		_enemy2Img->setFrameY(0);
		if (_count % 15 == 0)
		{
			_index++;
			if (_index > 7)
			{
				_index = 0;
			}
			_enemy2Img->setFrameX(_index);
		}
	}

	//enemy2�Ѿ�
	for (int i = 0; i < 8; i++)
	{
		if (!_bulletE2[i].fire)continue;


		//Rectangle(getMemDC(), _bulletE2[i].rc);
		_enemybullet2Img->frameRender(getMemDC(), _bulletE2[i].rc.left, _bulletE2[i].rc.top);

		_count++;
		_enemybullet2Img->setFrameY(0);
		if (_count % 15 == 0)
		{
			_index++;
			if (_index > 18)
			{
				_index = 0;
			}
			_enemybullet2Img->setFrameX(_index);
		}
	}

	if (_timer > 20.0f)
	{
		for (int i = 0; i < BOSSMAX; i++)
		{
			if (!_bossBullet[i].fire) continue;
			//EllipseMakeCenter(getMemDC(), _bossBullet[i].x, _bossBullet[i].y, 30, 30);
		}
	}

	if (_timer > 20.0f)
	{
		for (int i = 0; i < BOSSMAX; i++)
		{
			_bossBulletImg->frameRender(getMemDC(), _bossBullet[i].x - 10, _bossBullet[i].y - 20);
			_count++;
			_bossBulletImg->setFrameY(0);
			if (_count % 10 == 0)
			{
				_index++;
				if (_index > 18)
				{
					_index = 0;
				}
				_bossBulletImg->setFrameX(_index);
			}

		}



		_bossbodyImg->render(getMemDC(), _bossbody.rc.left, _bossbody.rc.top);

		_bossleftImg->frameRender(getMemDC(), _bossleft.rc.left, _bossleft.rc.top);
		_count++;
		_bossleftImg->setFrameY(0);
		if (_count % 10 == 0)
		{
			_index++;
			if (_index > 7)
			{
				_index = 0;
			}
			_bossleftImg->setFrameX(_index);
		}

		_bossrightImg->frameRender(getMemDC(), _bossright.rc.left, _bossright.rc.top);
		_count++;
		_bossrightImg->setFrameY(0);
		if (_count % 10 == 0)
		{
			_index++;
			if (_index > 7)
			{
				_index = 0;
			}
			_bossrightImg->setFrameX(_index);
		}
		
	}
	if (_bossHP < 0)
	{
		this->init();
		_gameStart = false;
		_gameOver = false;
	}

	for (int i = 0; i < MAX; i++)
	{
		if (_bullet->fire)
		{
			//Rectangle(getMemDC(), _bullet[i].rc);
		}
		if (!_bullet[i].fire) continue;

		//�Ѿ� �簢��
		//Rectangle(getMemDC(), _bullet[i].rc);

		_bulletImg->frameRender(getMemDC(), _bullet[i].rc.left - 20, _bullet[i].rc.top);

	}


	//�÷��̾�� �ϲ� ������!!
	//Rectangle(getMemDC(), _player.rc);

	//=============================================================
		//������� ������ ȭ��DC�� �׸���
	this->getBackBuffer()->render(getHDC());
}

void mainGame::animation()
{
	switch (_state)
	{
	case IDLE:
		_count++;
		_baseMov->setFrameY(0);
		if (_count % 5 == 0)
		{
			_index++;
			if (_index > 8)
			{
				_index = 0;
			}
			_baseMov->setFrameX(_index);
		}
		break;
	case LEFT:
		_count++;
		_movLeft->setFrameY(0);
		if (_count % 4 == 0)
		{
			_index++;
			if (_index > 8)
			{
				_index = 0;
			}
			_movLeft->setFrameX(_index);
		}
		break;
	case RIGHT:
		_count++;
		_movRight->setFrameY(0);
		if (_count % 4 == 0)
		{
			_index++;
			if (_index > 8)
			{
				_index = 0;
			}
			_movRight->setFrameX(_index);
		}
		break;
	case COLLISION:
		_count++;
		_collision->setFrameY(0);
		if (_count % 4 == 0)
		{
			_index++;
			if (_index > 8)
			{
				_index = 0;
			}
			_collision->setFrameX(_index);
		}
		break;
	case DEAD:
		_count++;
		_deadImg->setFrameY(0);
		if (_count % 4 == 0)
		{
			_index++;
			if (_index > 9)
			{
				_index = 0;
			}
			_deadImg->setFrameX(_index);
		}
		break;
	}



	//�÷��̾�
	//�ൿ����
	switch (_state)
	{
	case IDLE:
		_baseMov->frameRender(getMemDC(), _player.x, _player.y);
		break;
	case LEFT:
		_movLeft->frameRender(getMemDC(), _player.x, _player.y);
		break;
	case RIGHT:
		_movRight->frameRender(getMemDC(), _player.x, _player.y);
		break;
	case DEAD:
		_deadImg->frameRender(getMemDC(), _player.x, _player.y);
		break;
	}


	for (int i = 0; i < MAX; i++)
	{
		if (_bullet[i].fire)
		{
			//Rectangle(getMemDC(), _bullet[i].rc);
		}
		if (!_bullet[i].fire) continue;

		//�Ѿ� �簢��
		//Rectangle(getMemDC(), _bullet[i].rc);

		_bulletImg->frameRender(getMemDC(), _bullet[i].rc.left - 20, _bullet[i].rc.top);

	}


}

void mainGame::fire()
{
	//enemy2�Ѿ�
	for (int i = 0; i < 8; i++)
	{
		if (_enemy2[i].live == false)continue;
		if (_bulletE2[i].fire == true) continue;
		_bulletE2[i].fire = true;
		_bulletE2[i].rc = RectMake(_enemy2[i].rc.left, _enemy2[i].rc.top, 30, 30);
		//�̰� �����ָ� 10���� �ѹ�ó�� ������
		break;
	}
}

void mainGame::pFire()
{
	for (int i = 0; i < MAX; i++)
	{
		if (_bullet[i].fire) continue;
		_bullet[i].fire = true;
		_bullet[i].rc = RectMakeCenter(_player.rc.left + 50, _player.rc.top - 10, 30, 60);
		//�̰� �����ָ� 10���� �ѹ�ó�� ������
		break;
	}
}

void mainGame::bossFire()
{
	for (int i = 0; i < BOSSMAX; i++)
	{
		if (_bossBullet[i].fire) continue;
		_bossBullet[i].fire = true;
		_bossBullet[i].angle = _bossbody.angle;
		_bossBullet[i].x = cosf(_bossbody.angle) + _bossbody.center.x;
		_bossBullet[i].y = -sinf(_bossbody.angle) + _bossbody.center.y;
		break;
	}
}

void mainGame::moveBullet()
{
	//enemy2�Ѿ�
	for (int i = 0; i < 8; i++)
	{
		if (!_bulletE2[i].fire) continue;
		//�Ѿ� �Ʒ����� ���� ��������
		_bulletE2[i].rc.top += 2;
		_bulletE2[i].rc.bottom += 2;

		//�Ѿ��� ȭ�� ������ �������� �ٽ� �ʱ�ȭ
		if (_bulletE2[i].rc.top > WINSIZEY)
		{
			_bulletE2[i].fire = false;
		}
	}

	for (int i = 0; i < MAX; i++)
	{
		if (!_bullet[i].fire) continue;
		//�Ѿ� �Ʒ����� ���� ��������
		_bullet[i].rc.top -= _bullet[i].speed;
		_bullet[i].rc.bottom -= _bullet[i].speed;

		//�Ѿ��� ȭ�� ������ �������� �ٽ� �ʱ�ȭ
		if (_bullet[i].rc.bottom < 0)
		{
			_bullet[i].fire = false;
		}
	}


}

void mainGame::moveBossBullet()
{
	for (int i = 0; i < BOSSMAX; i++)
	{
		if (!_bossBullet[i].fire) continue;
		_bossBullet[i].x += cosf(_bossBullet[i].angle) * _bossBullet[i].speed;
		_bossBullet[i].y += -sinf(_bossBullet[i].angle) * _bossBullet[i].speed;

		//�Ѿ��� ȭ������� ��������
//����
		if (_bossBullet[i].x + 15< 0)
		{
			_bossBullet[i].fire = false;
		}
		//������
		if (_bossBullet[i].x + 15 > WINSIZEX)
		{
			_bossBullet[i].fire = false;
		}
		//��
		if (_bossBullet[i].y + 15 < 0)
		{
			_bossBullet[i].fire = false;
		}
		//�Ʒ�
		if (_bossBullet[i].y - 15 > WINSIZEY)
		{
			_bossBullet[i].fire = false;
		}

	}

}



