/*
Project Name : DX BALL Remastered ;
*/
#define _CRT_SECURE_NO_DEPRECATE
#include "iGraphics.h"
#include<string.h>
#include<stdlib.h>

/*
SCREEN
*/

#define screenWidth 1000
#define screenHeight 600
char  name[50] = "DX Ball Remastered";

/*
Background
*/

/*
Ball
*/

char ballImage[50] = "Image\\DXBall20.bmp";
int ballPosition_X = (int)screenWidth / 2;
int ballPosition_Y = 19;
int ballWidth = 20;
int ballHeight = 20;
int ballSpeed_X = 5;
int ballSpeed_Y = 7;
int ballDirection = 1;
int ballPoint = 0;


/*
Paddle
*/
char paddleImage[50] = "Image\\Paddle.bmp";
int paddlePosition_X = (int)screenWidth / 2 - 150 / 2;
int paddlePosition_Y = 0;
int paddleWidth = 150;
int paddleHeight = 19;
int paddleSpeed = 20;

/////// paddle2 

char paddleImage2[50] = "Image\\Paddle.bmp";
int paddlePosition2_X = (int)screenWidth / 2 - 150 / 2;
int paddlePosition2_Y = 581;
int paddleWidth2 = 150;
int paddleHeight2 = 19;

/*
Brick
*/

char brickImage[50] = "Image\\brick.bmp";
char brickImageRed[50] = "Image\\brick_red.bmp";

int brickWidth = 50;
int brickHeight = 25;
int brickGap_X;
int brickGap_Y;
int brickFirst_X = 0;
int brickFirst_Y = 500;
#define brickRow  15
#define brickCol  20

struct Brick
{
	int brickPosition_X;
	int brickPosition_Y;
	bool showBrick;
}brick[brickRow][brickCol];




//////////         Loop Parameter
//////////
int i, j, k, l, m, n;

//////// restart 
bool gameOn = false;


/////////
////////
bool gameOver = false;
char textTest[50] = "Say Who gives a fuck";
#define PI 3.1415926535898
int degree = 0;
int v = 8;

////////
/////// Power up 

////// speedball
char powerUp[50] = "image\\speedBall.bmp";
char fireballImage[50] = "image\\fireBall.bmp";
int speedBallX = 100;
int speedBallY = 500;
bool speedBallActive = true;
bool sb;
bool fireBall;

////// paddleBig
char paddleBig[50] = "image\\paddleBig.bmp";
char bigPaddle[50] = "image\\bigPaddle.bmp";
int paddleBigX = brick[0][0].brickPosition_X;
int paddleBigY = brick[0][0].brickPosition_X;
bool paddleBigActive = true;
bool pb;

////// paddleMini
char paddleMini[50] = "image\\paddleMini.bmp";
char miniPaddle[50] = "image\\miniPaddle.bmp";
int paddleMiniX = 400;
int paddleMiniY = 500;
bool paddleMiniActive = true;
bool pm;

//// shoot

char shoot[50] = "image\\shoot.bmp";
char bulletimage[50] = "image\\bullet.bmp";
int shootX = 700;
int shootY = 500;
char redPaddle[50] = "image\\redPaddle.bmp";
char redPaddleMini[50] = "image\\redPaddleMini.bmp";
char redPaddleBig[50] = "image\\redPaddleBig.bmp";
bool redpaddleActive;

struct
{
	int bulletX;
	int bulletY;
	int bulletCount;
	bool bulletShow;

}bullet[5000];

int bulletHeight = 25;
int bulletWidth = 5;
int bulletSpeed = 8;

int noOfbullets = 0;
bool shootActive = true;
bool st;
bool st2;
bool st3;


///// extraLife
char extraLife[50] = "image\\extraLife.bmp";
int extraLifeX = 700;
int extraLifeY = 500;
bool extraLifeActive = true;
bool el;



///// life

char lifeImage[50] = "image\\Paddlelife.bmp";
int life = 3;

bool die = false;

//// Level
int level = 1;
int levelCount1;
int levelCount2;
int levelCount3;
int levelCount4;
bool levelStarted1;
bool levelStarted2;
bool levelStarted3;
bool levelStarted4;

////// timer

int ballTimer;
int levelTimer;
int bulletTimer;
int soundTimer;
bool paddleResume = true;

///// timeLevel

int second = 120;
char secondchar[50];
bool timeLevelStart;


//// page 

int page = 1; 
char firstPage[3][50] = { "image\\firstPage1.bmp", "image\\firstPage2.bmp", "image\\firstPage3.bmp" };
int firstPageIndex = 0;
char spinBall[9][50] = { "image\\Background\\spinBall1.bmp","image\\Background\\spinBall2.bmp","image\\Background\\spinBall3.bmp","image\\Background\\spinBall4.bmp","image\\Background\\spinBall5.bmp","image\\Background\\spinBall6.bmp","image\\Background\\spinBall7.bmp","image\\Background\\spinBall8.bmp","image\\Background\\spinBall9.bmp" };
int spinBallIndex = 0;

int firstPageX = 0;
int firstPageY = 0;

int spinBallX = 600;
int spinBallY = 40;

int mposx, mposy;

bool gamePageActive = false;
bool instructionPageActive = false; 
bool creditPageActive = false;
bool highScorePageActive = false;

/////?????????????????
//*^&%^&%^&%^&%^&%^&    High Score 

struct highScore
{
	char name[20];
	int score;

}player, saved[6], temp;

int length ;

FILE *fp;

bool takeInput;
bool newHighScore;


/////// Scoring 

char showScore[20];
int brickPoint = 5;
int levelPoint = 100;
char highScore0[20];
char highScore1[20]; 
char highScore2[20];
char highScore3[20];
char highScore4[20];

////////////////////////////////////////////////////////////////////////////////////////#@!#@!#@!#!@#!@#!@#!#@$@#@#$@#$@#$
//$@#$@#$@#$@#$@#$@#$@#$@#$@#$@#$@#$@#$ function prototype

void restart();
void gameOverPage();
void lifeCount();
void brickPattern();
void ballDirectionDefine();
void collision();
void screenBorder();
void paddle();
void paddle2();
void ballMovement();
/////initial
void initialize();
void bulletActive();
void brickActive();
void scoreSort();
void batDesign();
void smileDesign();
void dpDesign();
void timelevelDesign();
/////////levels
void timeShow();
void timeControl();
void brickPatternChange();
void timeLevel();
void speedBallActivem();
void paddleBigActivem();
void paddleMiniActivem();
void bulletCollision();
void bulletShow();
void bulletMove();
void bulletPosition();
void shootActivem();
void extraLifeActivem();
void speedBallActiveWm();
void extraLifeActiveWm();
void shootActiveWm();
void paddleMiniActiveWm();
void paddleBigActiveWm();
void powerUps();

bool newGame = false;

void initialize()
{
	newGame = false;
	brickActive();  //Active f()
	brickPattern();
	bulletActive();
	player.score = 0; 
	paddleResume = true; 
	ballPoint = 0;
	brickFirst_X = 0;
	brickFirst_Y = 500;
	gameOver = false;
	degree = 0;
	speedBallX = brick[2][10].brickPosition_X;
	speedBallY = brick[2][10].brickPosition_Y;
	paddleBigX = brick[10][10].brickPosition_X;
	paddleBigY = brick[10][10].brickPosition_X;
	paddleMiniX = brick[13][5].brickPosition_X;
	paddleMiniY = brick[13][5].brickPosition_Y;
	shootX = brick[5][14].brickPosition_X;
	shootY = brick[5][14].brickPosition_Y;
	extraLifeX = brick[12][8].brickPosition_X;
	extraLifeY = brick[12][8].brickPosition_X;
	noOfbullets = 0;
	paddleMiniActive = true;
	speedBallActive = true; 
	sb=false;
	fireBall=false;
	shootActive = true;
	extraLifeActive = true;
	pm=false;
	st = false;
	el=false;
	life = 3;		//life
	level = 1;
	levelCount1=0;				/// levels initial
	levelCount2=0;
	levelCount3=0;
	levelCount4=0;
	levelStarted1=false;
	levelStarted2=false;
	levelStarted3=false;
	levelStarted4=false;
	second = 120;
	secondchar[49] = {0};
	timeLevelStart = false;
	gamePageActive = false;         /// pageinitial
	instructionPageActive = false;
	creditPageActive = false; 
	highScorePageActive = false;
	takeInput = false;
	die = false;
	restart();					// just calling
}



void scoreSort()
{
	fp=fopen("High Scores.txt", "w");
	for (i = 0; i < 6; i++)
	{
		for (j = 5; j > i; j--)
		{
			if (saved[j].score > saved[j-1].score)
			{
				strcpy(temp.name, saved[j].name);
				strcpy(saved[j].name, saved[j-1].name);
				strcpy(saved[j-1].name, temp.name);

				temp.score = saved[j].score;
				saved[j].score = saved[j-1].score;
				saved[j-1].score = temp.score;
			}
		}
	}

	for (int j = 0; j <= 5; j++)
	{
		fputs(saved[j].name, fp);
		fprintf(fp, " %d\n", saved[j].score);
	}

	fclose(fp);
}

void timeShow()
{
	sprintf_s(secondchar, "%d", second);
	iText(420, 550, "TIME :", GLUT_BITMAP_TIMES_ROMAN_24);

	if (second < 20)
	{
		iSetColor(255, 0, 0);
		iText(500, 550, secondchar, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else
		iText(500, 550, secondchar, GLUT_BITMAP_TIMES_ROMAN_24);

	if (!timeLevelStart)
	{
		iShowBMP(0,0,"image\\timeLevel.bmp");

	}
}

void timeControl()
{
	second--;
}

void brickPatternChange()
{
	for (i = 0, brickGap_Y = 0; i < brickRow; i++, brickGap_Y = brickGap_Y - brickHeight)
	{
		for (j = 0, brickGap_X = 0; j < brickCol; j++, brickGap_X = brickGap_X + brickWidth)
		{
			if (second <= 60 && second >= 51)
			{
				brick[i][j].brickPosition_X = brickFirst_X + brickGap_X;
				brick[i][j].brickPosition_Y = brickFirst_Y + brickGap_Y;
			}
			if (second <= 50 && second >= 41)
			{
				brick[i][j].brickPosition_X = brickFirst_X + brickGap_X;
				brick[i][j].brickPosition_Y = brickFirst_Y + brickGap_Y - 10 ;
			}
			if (second <= 40 && second >=31)
			{
				brick[i][j].brickPosition_X = brickFirst_X + brickGap_X;
				brick[i][j].brickPosition_Y = brickFirst_Y + brickGap_Y - 20;
			}
			if (second <= 30 && second >=21)
			{
				brick[i][j].brickPosition_X = brickFirst_X + brickGap_X;
				brick[i][j].brickPosition_Y = brickFirst_Y + brickGap_Y - 30;
			}
			if (second <= 20 && second >=11)
			{
				brick[i][j].brickPosition_X = brickFirst_X + brickGap_X;
				brick[i][j].brickPosition_Y = brickFirst_Y + brickGap_Y - 45;
			}
			if (second <= 10 && second >= 0)
			{
				brick[i][j].brickPosition_X = brickFirst_X + brickGap_X;
				brick[i][j].brickPosition_Y = brickFirst_Y + brickGap_Y - 60;
			}


			if (brick[i][j].showBrick == true)
			{
				iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_green.bmp");

				if (brick[i][j].brickPosition_Y <= 100)
				{
					page = 6;
				}
			}
		}
	}
}

void timeLevel()
{
	brickPatternChange();

	if (second <= 0)
	{
		page = 6;
	}
}

void brickActive()
{
	for (i = 0; i < brickRow; i++)
	{
		for (j = 0; j < brickCol; j++)
		{
			brick[i][j].showBrick = true;
		}
	}
}
void bulletActive()
{
	for (i = 0; i < 5000; i++)
	{
		bullet[i].bulletShow = true;
	}
}

void speedBallActivem()
{
	if (ballSpeed_X < 0 && ballSpeed_Y < 0)
	{
		ballSpeed_X = -15;
		ballSpeed_Y = -15;
	}
	if (ballSpeed_X < 0 && ballSpeed_Y > 0)
	{
		ballSpeed_X = -15;
		ballSpeed_Y = 15;
	}
	if (ballSpeed_X > 0 && ballSpeed_Y < 0)
	{
		ballSpeed_X = 15;
		ballSpeed_Y = -15;
	}
	if (ballSpeed_X > 0 && ballSpeed_Y > 0)
	{
		ballSpeed_X = 15;
		ballSpeed_Y = 15;
	}

	v = 20;
	speedBallActive = false;
	fireBall = true;
	sb = false;
}

void paddleBigActivem()
{
	printf("I m in");
	paddleWidth = 220;
	paddleBigActive = false;
	pb = false;
}
void paddleMiniActivem()
{
	printf("I m in");
	paddleWidth = 80;
	paddleMiniActive = false;
	pm = false;
}
void bulletCollision()
{
	for (k = 0; k < noOfbullets; k++)
	{
		for (i = 0; i < brickRow; i++)
		{
			for (j = 0; j < brickCol; j++)
			{
				if (bullet[k].bulletY + bulletHeight >= brick[i][j].brickPosition_Y && brick[i][j].showBrick == true && bullet[k].bulletShow == true && st3)
				{

					if (bullet[k].bulletX >= brick[i][j].brickPosition_X && bullet[k].bulletX <= brick[i][j].brickPosition_X + brickWidth)
					{
						brick[i][j].showBrick = false;
						bullet[k].bulletShow = false;
						player.score += brickPoint;

						++levelCount2;
						printf("LvelCount2 %d\n", levelCount2);

						if (levelCount2 >= 90) //280
						{
							level = 3;
							player.score += levelPoint;
							levelStarted3 = true;
							die = false;
							restart();
						}

						break;
					}

				}

			}

		}
	}
}
void bulletMove()
{
	for (i = 0; i < noOfbullets; i++)
	{
		bullet[i].bulletY += bulletSpeed;
	}
	bulletCollision();
}

void bulletShow()
{
	for (i = 0; i < noOfbullets; i++)
	{
		if (bullet[i].bulletShow)
		{
			iShowBMP(bullet[i].bulletX, bullet[i].bulletY, bulletimage);
		}
	}

}

void bulletPosition()
{
	++noOfbullets;
	if (noOfbullets != 0 )
	{
		if (noOfbullets % 2 == 0)
		{
			bullet[noOfbullets - 1].bulletX = paddlePosition_X + paddleWidth - 10;
		}
		else
		{
			bullet[noOfbullets - 1].bulletX = paddlePosition_X;
		}
		bullet[noOfbullets - 1].bulletY = paddlePosition_Y + 5;
	}
	else
	{
		bullet[noOfbullets].bulletX = paddlePosition_X + paddleWidth;
		bullet[noOfbullets].bulletY = paddlePosition_Y + 5;
	}
}

void shootActivem()
{
	if (st2 && st3)
	{
		bulletPosition();
		PlaySound("gunFire.wav", NULL, SND_ASYNC);
	}
}
void extraLifeActivem()
{
	life++;
	extraLifeActive = false;
	el = false;
}
void speedBallActiveWm()
{
	if (speedBallY <= 19 && speedBallY > 0)
	{
		if (speedBallX >= paddlePosition_X && speedBallX <= paddlePosition_X + paddleWidth)
		{
			if (sb)
			{
				speedBallActivem();
			}
		}
	}

}

void paddleBigActiveWm()
{
	if (paddleBigY <= 19 && paddleBigY > 0)
	{
		if (paddleBigX >= paddlePosition_X && paddleBigX <= paddlePosition_X + paddleWidth)
		{
			if (pb)
			{
				paddleBigActivem();
			}
		}
	}

}

void paddleMiniActiveWm()
{
	if (paddleMiniY <= 19 && paddleMiniY > 0)
	{
		if (paddleMiniX >= paddlePosition_X && paddleMiniX <= paddlePosition_X + paddleWidth)
		{
			if (pm)
			{
				paddleMiniActivem();
			}
		}
	}

}
void shootActiveWm()
{
	if (shootY <= 19 && shootY > 0)
	{
		if (shootX >= paddlePosition_X && shootX <= paddlePosition_X + paddleWidth)
		{
			if (st)
			{
				iResumeTimer(bulletTimer);
				redpaddleActive = true;
				st3 = true;
			}
		}
	}
}
void extraLifeActiveWm()
{
	if (extraLifeY <= 19 && extraLifeY > 0)
	{
		if (extraLifeX >= paddlePosition_X && extraLifeX <= paddlePosition_X + paddleWidth)
		{
			if (el)
			{
				extraLifeActivem();
			}
		}
	}

}

//void powerUpsm(int X, int Y)
//{
//	if (Y <= 19)
//	{
//		if (X >= paddlePosition_X && X <= paddlePosition_X + paddleWidth)
//		{
//			if (sb)
//			{
//				speedBallActivem();
//			}
//			if (pb)
//			{
//				paddleBigActivem();
//			}
//			if (st)
//			{
//				shootActivem();
//			}
//			if (el)
//			{
//				extraLifeActivem();
//			}
//		}
//	}
//
//}

void powerUps()
{
	if (brick[2][10].showBrick == false && speedBallActive)
	{
		iShowBMP(speedBallX, speedBallY, powerUp);
		speedBallY = speedBallY - 5;
		sb = true;
		speedBallActiveWm();
	}
	if (brick[10][10].showBrick == false && paddleBigActive)
	{
		iShowBMP(paddleBigX, paddleBigY, paddleBig);
		paddleBigY = paddleBigY - 5;
		pb = true;
		paddleBigActiveWm();
	}
	if (brick[13][5].showBrick == false && paddleMiniActive)
	{
		iShowBMP(paddleMiniX, paddleMiniY, paddleMini);
		paddleMiniY = paddleMiniY - 5;
		pm = true;
		paddleMiniActiveWm();
	}
	if (brick[5][14].showBrick == false && shootActive)
	{
		iShowBMP(shootX, shootY, shoot);
		shootY = shootY - 5;
		st = true;
		st2 = true;
		shootActiveWm();
		//powerUpsm(shootX, shootY);
	}
	if (brick[12][8].showBrick == false && extraLifeActive)
	{
		iShowBMP(extraLifeX, extraLifeY, extraLife);
		extraLifeY = extraLifeY - 5;
		el = true;
		extraLifeActiveWm();
	}



}


void lifeCount()
{
	if (life == 4)
	{
		iShowBMP(610, 570, lifeImage);
		iShowBMP(700, 570, lifeImage);
		iShowBMP(790, 570, lifeImage);
		iShowBMP(880, 570, lifeImage);
		printf("life 4 \n");
	}
	else if (life == 3)
	{
		iShowBMP(700, 570, lifeImage);
		iShowBMP(790, 570, lifeImage);
		iShowBMP(880, 570, lifeImage);

	}
	else if (life == 2)
	{
		iShowBMP(790, 570, lifeImage);
		iShowBMP(880, 570, lifeImage);

	}
	else if (life == 1)
	{
		iShowBMP(880, 570, lifeImage);
		printf("life 1 \n");
	}
}

void gameOverPage()
{
	iPauseTimer(ballTimer);
	iPauseTimer(bulletTimer);
	iPauseTimer(levelTimer);
	paddleResume = false;
	iShowBMP(0, 0, "image\\Game_Over.bmp");
}

void restart()
{
	if (die)
	{
		life--;
	}

	ballPosition_X = (int)screenWidth / 2;
	ballPosition_Y = paddleHeight;

	ballSpeed_X = 5;         //// level 1
	ballSpeed_Y = 7;
	v = 10;

	paddlePosition_X = (int)screenWidth / 2 - paddleWidth / 2;    /// level 3
	paddlePosition_Y = 0;
	paddlePosition2_X = (int)screenWidth / 2 - paddleWidth / 2;
	paddlePosition2_Y = 581;
	paddleWidth = 150;

	gameOn = false;

	fireBall = false;            /// level 2
	redpaddleActive = false;
	st2 = false;
	st3 = false;

	if (life == 0)
	{
		gameOver = true;
		page = 6;
		gameOverPage();
	}
}


/*
BrickManagement
*/

void brickPattern()
{


	for (i = 0, brickGap_Y = 0; i < brickRow; i++, brickGap_Y = brickGap_Y - brickHeight)
	{
		for (j = 0, brickGap_X = 0; j < brickCol; j++, brickGap_X = brickGap_X + brickWidth)
		{

			brick[i][j].brickPosition_X = brickFirst_X + brickGap_X;
			brick[i][j].brickPosition_Y = brickFirst_Y + brickGap_Y;

			if (brick[i][j].showBrick == true)
			{
				if (level == 1)
				{
					iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, brickImageRed);
					if (i == 0 && j == 9)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y,"image\\brick_red_1.bmp");
					}
					if (i == 0 && j == 10)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_red_2.bmp");
					}
				}
				if (level == 2)
				{
					iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, brickImage);
				}
				if (level == 3)
				{

					iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_white.bmp");

					if (i == 0 && j == 7)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 0 && j == 8)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 1 && j == 12)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 0 && j == 9)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 0 && j == 10)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 0 && j == 11)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 1 && j == 7)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 1 && j == 8)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 1 && j == 9)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 1 && j == 10)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 1 && j == 11)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 2 && j == 6)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 3 && j == 6)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 4 && j == 6)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 5 && j == 6)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 6 && j == 6)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 2 && j == 7)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 11 && j == 9)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 12 && j == 9)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 2 && j == 11)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 2 && j == 12)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 3 && j == 12)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 4 && j == 12)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");
					}
					if (i == 5 && j == 12)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 6 && j == 12)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_greenmd.bmp");

					}
					if (i == 8 && j == 7)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_red_md.bmp");

					}
					if (i == 9 && j == 7)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_red_md.bmp");

					}
					if (i == 8 && j == 11)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_red_md.bmp");

					}
					if (i == 9 && j == 11)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_red_md.bmp");

					}
					if (i == 11 && j == 7)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_violet.bmp");

					}
					if (i == 11 && j == 8)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_violet.bmp");

					}
					if (i == 11 && j == 10)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_violet.bmp");

					}
					if (i == 11 && j == 11)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_violet.bmp");

					}
					if (i == 12 && j == 7)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_violet.bmp");

					}
					if (i == 12 && j == 8)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_violet.bmp");

					}
					if (i == 12 && j == 10)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_violet.bmp");

					}
					if (i == 12 && j == 11)
					{
						iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, "image\\brick_violet.bmp");

					}

				}
				if (level == 4)
				{

					iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, brickImageRed);
				}

				//iFilledRectangle(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, 150, 30);
			}

		}
	}
}


////////////
//////////// Batman Design 
void batDesign()
{
	brick[0][8].showBrick = false;
	//brick[0][9].showBrick = false;
	//brick[0][10].showBrick = false;
	brick[0][11].showBrick = false;
	brick[1][8].showBrick = false;
	brick[1][11].showBrick = false;
	for (i = 2; i < brickRow; i++)
	{
		for (j = 0; j < i - 1; j++)
		{
			brick[i][j].showBrick = false;
		}
	}
	for (i = 2; i < (brickRow - 1); i++)
	{
		for (j = brickCol; j > brickCol - i; j--)
		{
			brick[i][j].showBrick = false;
		}

	}

	for (i = 10; i <= 19; i++)
	{
		brick[14][i].showBrick = false;
	}
	//for (i = 0; i < 4; i++)
	//{
	//	brick[11][14 + i].showBrick = false;
	//}
	//for (i = 0; i < 3; i++)
	//{
	//	brick[10][15 + i].showBrick = false;
	//}
	////brick[3][11].showBrick = false;
	////brick[3][12].showBrick = false;
	////brick[2][12].showBrick = false;

}

//////smileface
void smileDesign()
{
	if (levelStarted2)
	{
		brickActive();
		levelStarted2 = false;
	}
	brick[3][6].showBrick = false;
	brick[3][7].showBrick = false;
	brick[4][6].showBrick = false;
	brick[4][7].showBrick = false;
	brick[3][12].showBrick = false;
	brick[3][13].showBrick = false;
	brick[4][12].showBrick = false;
	brick[4][13].showBrick = false;  //smile
	brick[9][4].showBrick = false;
	brick[10][5].showBrick = false;
	brick[11][6].showBrick = false;
	brick[12][7].showBrick = false;
	brick[13][8].showBrick = false;
	brick[13][9].showBrick = false;
	brick[13][10].showBrick = false;
	brick[13][11].showBrick = false;
	brick[13][12].showBrick = false;
	brick[12][13].showBrick = false;
	brick[11][14].showBrick = false;
	brick[10][15].showBrick = false;

}

///// doublePaddle design
void dpDesign()
{
	if (levelStarted3)
	{
		brickActive();
		levelStarted3 = false;
	}
	for (i = 0; i < 20; i++)
	{
		brick[13][i].showBrick = false;
		brick[14][i].showBrick = false;
	}
	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 6;j++)
		{
			brick[i][j].showBrick = false;
		}
			
	}
	for (i = 0; i < 13; i++)
	{
		for (j = 13; j < 20; j++)
		{
			brick[i][j].showBrick = false;
		}
	}
	brick[0][6].showBrick = false;//
	brick[1][6].showBrick = false;
	brick[7][6].showBrick = false;
	brick[8][6].showBrick = false;
	brick[9][6].showBrick = false;
	brick[10][6].showBrick = false;
	brick[11][6].showBrick = false;
	brick[12][6].showBrick = false;
	brick[10][7].showBrick = false;
	brick[5][8].showBrick = false;
	brick[6][8].showBrick = false;
	brick[7][8].showBrick = false;
	brick[9][8].showBrick = false;
	brick[9][9].showBrick = false;
	brick[9][10].showBrick = false;
	brick[5][10].showBrick = false;
	brick[6][10].showBrick = false;
	brick[10][11].showBrick = false;
	brick[0][12].showBrick = false;
	brick[7][12].showBrick = false;
	brick[8][12].showBrick = false;
	brick[9][12].showBrick = false;
	brick[10][12].showBrick = false;
	brick[11][12].showBrick = false;
	brick[12][12].showBrick = false;

}

void timelevelDesign()
{
	if (levelStarted4)
	{
		brickActive();
		levelStarted4 = false;
	}
	brick[4][0].showBrick = false;
	brick[5][0].showBrick = false;
	brick[6][0].showBrick = false;
	brick[7][0].showBrick = false;
	brick[8][0].showBrick = false;
	brick[9][0].showBrick = false;
	brick[10][0].showBrick = false;
	brick[5][1].showBrick = false;
	brick[6][1].showBrick = false;
	brick[7][1].showBrick = false; //X
	brick[8][1].showBrick = false;
	brick[9][1].showBrick = false;
	brick[6][2].showBrick = false;
	brick[7][2].showBrick = false;
	brick[8][2].showBrick = false;
	brick[7][3].showBrick = false;
	brick[4][19].showBrick = false;
	brick[5][19].showBrick = false;
	brick[6][19].showBrick = false;
	brick[7][19].showBrick = false;
	brick[8][19].showBrick = false;
	brick[9][19].showBrick = false;
	brick[10][19].showBrick = false;
	brick[5][18].showBrick = false;
	brick[6][18].showBrick = false;
	brick[7][18].showBrick = false;
	brick[9][18].showBrick = false;
	brick[6][17].showBrick = false;
	brick[7][17].showBrick = false;
	brick[8][17].showBrick = false;
	brick[8][18].showBrick = false;
	brick[7][16].showBrick = false;
	brick[14][7].showBrick = false;
	brick[14][8].showBrick = false;
	brick[14][9].showBrick = false;
	brick[14][10].showBrick = false;
	brick[14][11].showBrick = false;
	brick[14][12].showBrick = false;
	brick[14][13].showBrick = false;
	brick[13][8].showBrick = false;
	brick[13][9].showBrick = false;
	brick[13][10].showBrick = false;
	brick[13][11].showBrick = false;
	brick[13][12].showBrick = false;
	brick[12][9].showBrick = false;
	brick[12][10].showBrick = false;
	brick[12][11].showBrick = false;
	brick[11][10].showBrick = false;
	brick[0][7].showBrick = false;
	brick[0][8].showBrick = false;
	brick[0][9].showBrick = false;
	brick[0][10].showBrick = false;
	brick[0][11].showBrick = false;
	brick[0][12].showBrick = false;
	brick[0][13].showBrick = false;
	brick[1][8].showBrick = false;
	brick[1][9].showBrick = false;
	brick[1][10].showBrick = false;
	brick[1][11].showBrick = false;
	brick[1][12].showBrick = false;
	brick[2][9].showBrick = false;
	brick[2][10].showBrick = false;
	brick[2][11].showBrick = false;
	brick[3][10].showBrick = false;
}

//////////////
//////////// Ball Direction 
void ballDirectionDefine()
{

	ballPosition_X += ballSpeed_X;
	ballPosition_Y += ballSpeed_Y;

}
////////
/////////							collision
/////////////
void collision()
{

	for (i = 0; i < brickRow; i++)
	{
		for (j = 0; j < brickCol; j++)
		{
			if (ballPosition_X + ballWidth >= brick[i][j].brickPosition_X && ballPosition_X <= brick[i][j].brickPosition_X + brickWidth && brick[i][j].showBrick == true)
			{


				ballPoint = ballPosition_Y + 10;


				if (ballPoint >= brick[i][j].brickPosition_Y &&  ballPoint <= brick[i][j].brickPosition_Y + brickHeight)
				{
					printf("2nd %d\t", ballDirection);
					brick[i][j].showBrick = false;
					player.score += brickPoint; 
					PlaySound("brickSound.wav", NULL, SND_ASYNC);


					ballSpeed_Y = -ballSpeed_Y;
					if (level == 1)
					{
						++levelCount1;
						if (levelCount1 >= 5)           //126
						{
							level = 2;
							player.score += levelPoint; 
							levelStarted2 = true;
							die = false;
							restart();
						}
					}

					if (level == 2)     
					{
						++levelCount2;
						printf("LvelCount2 %d\n", levelCount2);
						if (levelCount2 >= 5) //281
						{
							level = 3;
							player.score += levelPoint;
							levelStarted3 = true;
							die = false;
							restart();
						}
					}

					if (level == 3)			
					{
						++levelCount3;
						if (levelCount3 >= 10) //67
						{
							level = 4;
							player.score += levelPoint;
							levelStarted4 = true;
							die = false;
							restart();
						}
					}

					if (level == 4)   
					{
						++levelCount4;
						printf("4 = %d\n", levelCount4);
						if (levelCount4 >= 10) //237
						{
							player.score += levelPoint;
							page = 6;
						}
					}

					break;
				}

			}
			else if (ballPosition_Y + ballHeight >= brick[i][j].brickPosition_Y && ballPosition_Y <= brick[i][j].brickPosition_Y + brickHeight  && brick[i][j].showBrick == true)
			{


				//ballPoint = ballPosition_X + 10;
				if (ballPosition_X + 10 >= brick[i][j].brickPosition_X && ballPosition_X + 10 <= brick[i][j].brickPosition_X + brickWidth)
				{
					printf("1st %d\t", ballDirection);
					brick[i][j].showBrick = false;
					PlaySound("brickSound.wav", NULL, SND_ASYNC);


					ballSpeed_X = -ballSpeed_X;

					if (level == 1)
					{
						++levelCount1;
						{
							if (levelCount1 >= 3)
							{
								level = 2;
								player.score += levelPoint;
								levelStarted2 = true;
								die = false;
								restart();
							}
						}
					}
					if (level == 2)
					{
						++levelCount2;
						if (levelCount2 >= 5)
						{
							level = 3;
							player.score += levelPoint;
							levelStarted3 = true;
							die = false;
							restart();
						}
					}

					if (level == 3)
					{
						++levelCount3;
						if (levelCount3 >= 10)
						{
							level = 4;
							player.score += levelPoint;
							levelStarted4 = true;
							die = false;
							restart();
						}
					}

					if (level == 4)
					{
						++levelCount4;
						if (levelCount4 >= 10)
						{							
							player.score += levelPoint;							
							page = 6;
						}
					}

					break;
				}

			}
		}

	}
}

void screenBorder()
{
	// Direction Changing 



	if (ballPosition_X <= 0)						// Left Border 
	{

		ballSpeed_X = -ballSpeed_X;
		PlaySound("borderSound.wav", NULL, SND_ASYNC);

	}
	else if (ballPosition_X >= screenWidth - ballWidth)  //Right Border 
	{

		ballSpeed_X = -ballSpeed_X;
		PlaySound("borderSound.wav", NULL, SND_ASYNC);
	}

	else if (ballPosition_Y >= screenHeight - ballHeight && level != 3) //Upper Border
	{
		ballSpeed_Y = -ballSpeed_Y;
		PlaySound("borderSound.wav", NULL, SND_ASYNC);
	}

}

void paddle()
{
	if (ballPosition_Y <= -20)										//Paddle
	{
		die = true;
		restart();
	}
	if (ballPosition_Y <= 19)
	{

		ballPoint = ballPosition_X + 10;

		if (ballPoint >= paddlePosition_X && ballPoint <= paddlePosition_X + paddleWidth)
		{
			if (paddleWidth == 150)
			{
				degree = (paddlePosition_X + paddleWidth - ballPosition_X) + 15;
			}
			if (paddleWidth == 220)
			{
				degree = (paddlePosition_X + paddleWidth - ballPosition_X) - 30;
			}
			if (paddleWidth == 80)
			{
				degree = (paddlePosition_X + paddleWidth - ballPosition_X) + 50;
			}

			PlaySound("paddleSound.wav", NULL, SND_ASYNC);

			ballSpeed_X = (int)v*cos(degree*PI / 180);
			ballSpeed_Y = (int)v*sin(degree*PI / 180);

			printf("x =%d ", ballSpeed_X);
			printf("y =%d ", ballSpeed_Y);
			printf("degree = %d", degree);

		}

	}
}

void paddle2()
{

	if (ballPosition_Y >= 600 + 20)										//Paddle2
	{
		die = true;
		restart();
	}
	if (ballPosition_Y >= 600 - 39)
	{
		ballPoint = ballPosition_X;

		if (ballPoint >= paddlePosition2_X && ballPoint <= paddlePosition2_X + paddleWidth2)
		{
			printf("%d", paddlePosition2_X);
			degree = (paddlePosition2_X + paddleWidth2 - ballPosition_X) + 15;

			ballSpeed_X = (int)v*cos(degree*PI / 180);
			ballSpeed_Y = (int)v*sin(degree*PI / 180);
			ballSpeed_Y = -ballSpeed_Y;
		}

	}


}

/*
BallMovement
*/

void ballMovement()
{
	if (gameOn)
	{
		ballDirectionDefine();

		collision();

		screenBorder();

		paddle();

		if (level == 3)
		{
			paddle2();
		}
	}

}


void firstPageRender()
{
	firstPageIndex++;

	if (firstPageIndex > 2)
	{
		firstPageIndex = 0;
	}
}

void playSound()
{
	if (page == 1 || page == 2)
	{
		PlaySound("theGame.wav", NULL, SND_ASYNC);
	}
	
}



/*
function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here
	iClear();
	sprintf_s(showScore, "%d", player.score);

	if (page == 1)
	{
		iShowBMP(firstPageX, firstPageY, firstPage[firstPageIndex]);

		iShowBMP2(spinBallX, spinBallY, spinBall[spinBallIndex], 1);

		spinBallIndex++;

		if (spinBallIndex > 8)
		{
			spinBallIndex = 0;
		}


		}

		if (page == 2)
		{
			iShowBMP(0, 0, "image\\startPage.bmp");

			if (gamePageActive)
			{
				page = 3;
			}
			else
			{
				iShowBMP(400, 300, "image\\startGame1.bmp");
			}

			if (instructionPageActive)
			{
				page = 4;
			}
			else
			{
				iShowBMP(400, 200, "image\\instruction1.bmp");
			}

			if (creditPageActive)
			{
				page = 5;
			}
			else
			{
				iShowBMP(10, 80, "image\\credits1.bmp");
			}
			if (highScorePageActive)
			{
				page = 8;
			}
			else
			{
				iShowBMP(400, 100, "image\\highScore1.bmp");
			}
			
			iShowBMP(10, 20, "image\\quit1.bmp");

		}
		if (page == 4)
		{
			iShowBMP(0, 0, "image\\instructionPage.bmp");
		}
		if (page == 5)
		{
			iShowBMP(0, 0, "image\\creditsPage.bmp");
		}

		if (page == 3 && !gameOver)
		{
			if (level == 1 || level == 2 || level == 3)
			{
				brickPattern();
			}

			if (level == 1)
			{
				batDesign();
			}
			if (level == 2)
			{
				smileDesign();
				bulletShow();
				powerUps();
				//bulletMove();
			}
			if (level == 3)
			{
				dpDesign();
				iShowBMP2(paddlePosition2_X, paddlePosition2_Y, paddleImage2, 0);
			}

			if (level == 4)
			{
				timelevelDesign();
				timeShow();
				if (timeLevelStart)
				{
					timeLevel();
				}

			}

			lifeCount();

			if (fireBall)
			{
				iShowBMP(ballPosition_X, ballPosition_Y, fireballImage);
			}
			else
			{
				iShowBMP2(ballPosition_X, ballPosition_Y, ballImage, 0);
			}

			if (paddleWidth == 150 && !redpaddleActive)
			{
				iShowBMP2(paddlePosition_X, paddlePosition_Y, paddleImage, 0);
			}
			if (paddleWidth == 220 && !redpaddleActive)
			{
				iShowBMP2(paddlePosition_X, paddlePosition_Y, bigPaddle, 0);
			}
			if (paddleWidth == 80 && !redpaddleActive)
			{
				iShowBMP2(paddlePosition_X, paddlePosition_Y, miniPaddle, 0);
			}
			if (paddleWidth == 150 && redpaddleActive)
			{
				iShowBMP2(paddlePosition_X, paddlePosition_Y, redPaddle, 0);
			}
			if (paddleWidth == 80 && redpaddleActive)
			{
				iShowBMP2(paddlePosition_X, paddlePosition_Y, redPaddleMini, 0);
			}
			if (paddleWidth == 220 && redpaddleActive)
			{
				iShowBMP2(paddlePosition_X, paddlePosition_Y, redPaddleBig, 0);
			}

			iText(10, 550, showScore, GLUT_BITMAP_TIMES_ROMAN_24);

		}
		if (page == 6)
		{
			gameOverPage();
		}
		if (page == 7)
		{
			
			if (takeInput)
			{
				iShowBMP(0, 0, "image\\nameInput2.bmp");
				iSetColor(255, 0, 0);
				iText(490, 180, player.name, GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else iShowBMP(0, 0, "image\\nameInput1.bmp");

			iSetColor(0, 0, 255);
			iText(550, 450, showScore, GLUT_BITMAP_TIMES_ROMAN_24);
					
		}

		if (page == 8)
		{
			if (takeInput)
			{
				iShowBMP(0, 0, "image\\highScorePage2.bmp");
			}
			else 
				iShowBMP(0, 0, "image\\highScorePage.bmp");
			

			iSetColor(0, 0, 255);
			iText(280, 170, saved[4].name, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(650, 170, highScore4, GLUT_BITMAP_TIMES_ROMAN_24);
			sprintf(highScore4, "%d", saved[4].score);

			iSetColor(0, 0, 255);
			iText(280, 210, saved[3].name, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(650, 210, highScore3, GLUT_BITMAP_TIMES_ROMAN_24);
			sprintf(highScore3, "%d", saved[3].score);

			iSetColor(0, 0, 255);
			iText(280, 260, saved[2].name, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(650, 260, highScore2, GLUT_BITMAP_TIMES_ROMAN_24);
			sprintf(highScore2, "%d", saved[2].score);

			iSetColor(0, 0, 255);
			iText(280, 310, saved[1].name, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(650, 310,highScore1, GLUT_BITMAP_TIMES_ROMAN_24);
			sprintf(highScore1, "%d", saved[1].score);

			iSetColor(0, 0, 255);
			iText(280, 370, saved[0].name, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(650, 370, highScore0, GLUT_BITMAP_TIMES_ROMAN_24);
			sprintf(highScore0, "%d", saved[0].score);
		}
	
}


/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if (page == 2)
		{
			if (mx >= 400 && mx <= 619 && my >= 300 && my <= 384)
			{
				PlaySound("menuButton.wav", NULL, SND_ASYNC);
				gamePageActive = true;
				
			}
			if (mx >= 400 && mx <= 619 && my >= 200 && my <= 284)
			{
				PlaySound("menuButton.wav", NULL, SND_ASYNC);
				instructionPageActive = true;
				
			}
			if (mx >= 400 && mx <= 619 && my >= 100 && my <= 184)
			{
				PlaySound("menuButton.wav", NULL, SND_ASYNC);
				highScorePageActive = true;
			}
			if (mx >= 10 && mx <= 110 && my >= 80 && my <= 130)
			{
				PlaySound("menuButton.wav", NULL, SND_ASYNC);
				creditPageActive = true;
			}
			if (mx >= 10 && mx <= 110 && my >= 20 && my <= 70)
			{
				PlaySound("menuButton.wav", NULL, SND_ASYNC);
				exit(0);
			}
		}
		if (page == 3)
		{
			shootActivem();
			st2 = true;
		}

		if (page == 7)
		{
			if (mx >= 480 && mx <= 720 && my >= 160 && my <= 220)
			{
				takeInput = true;
			}
		}
		
	}
	if (page == 8)
	{
		if (takeInput)
		{
			if (mx >= 10 && mx <= 110 && my >= 20 && my <= 60)
			{
				page = 2;
				newGame = true;
				initialize();
			}
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here

		if (page == 4 || page == 5 )
		{
			instructionPageActive = false;
			creditPageActive = false;
			page = 2;
		}
		if (page == 8)
		{
			highScorePageActive = false;
			if (!takeInput)
			{
				page = 2;
			}	
		}
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx, int my)
{
	//place your code here

	mposx = mx;
	mposy = my;
	if (mx == 2){}        /*Something to do with mx*/
	else if (my == 2){}   /*Something to do with my*/

}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (page == 3)
	{
		if (paddleResume)
		{
			if (key == 'd')
			{
				if (paddlePosition_X < screenWidth - paddleWidth)
				{
					paddlePosition_X += paddleSpeed;

					if (level == 3)
					{
						paddlePosition2_X += paddleSpeed;
						printf("%d\n%d", paddlePosition_X, paddlePosition2_X);
					}

					if (!gameOn)
					{
						ballPosition_X += paddleSpeed + 2;	
					}
				}
			}
			else if (key == 'a')
			{
				if (paddlePosition_X > 5)
				{
					paddlePosition_X -= paddleSpeed;
					if (level == 3)
					{
						paddlePosition2_X -= paddleSpeed;
					}

					if (!gameOn)
					{
						ballPosition_X -= paddleSpeed + 2;
					}
				}

			}
		}

		if (key == ' ')
		{
			gameOn = true;
			iResumeTimer(ballTimer);
		}
		
	}

	if (page == 7)
	{
		if (takeInput)
		{
			if (key == '\r')
			{
				saved[5].score = player.score;
				for (i = 0; player.name[i] != NULL; i++)
				{
					saved[5].name[i] = player.name[i];
				}

				saved[5].name[i] = NULL;

				fp = fopen("High Scores.txt", "w");

				for (int j = 0; j <= 5; j++)
				{
					fputs(saved[j].name, fp);
					fprintf(fp, " %d\n", saved[j].score);
				}
				fclose(fp);

				scoreSort();

				for (int j = 0; j < length; j++)
				{
					player.name[j] = 0;
				}
				length = 0;

				page = 8;
			}
			else
			{
				player.name[length] = key;
				length++;
			}
		}
		
	}
	if (page == 6)
	{
		if (key == '\r')
		{
			page = 7;
		}

	}
	if (page == 1)
	{
		if (key == '\r')
		{
			iPauseTimer(soundTimer);
			page = 2;
		}
	}

	if (page == 3 && level == 4)
	{
		if (key == '\r')
		{
			iResumeTimer(levelTimer);
			timeLevelStart = true;
		}

	}

	if (page == 3)
	{
		if (key == 'p')          //// pause resume
		{
			iPauseTimer(ballTimer);
			iPauseTimer(levelTimer);
			iPauseTimer(bulletTimer);
			paddleResume = false;
		}
		if (key == 'r')
		{
			iResumeTimer(ballTimer);
			iResumeTimer(levelTimer);
			iResumeTimer(bulletTimer);
			paddleResume = true;
		}
	}

	if (key == 'i')
	{
		brick[2][10].showBrick = false;
	}
	if (key == 'j')
	{
		brick[10][10].showBrick = false;
	}
	if (key == 'l')
	{
		brick[13][5].showBrick = false;
	}
	if (key == 'k')
	{
		brick[12][8].showBrick = false;
	}
	if (key == 'o')
	{
		brick[5][14].showBrick = false;
	}
	if (key == '=')  //cheat
	{
		for (i = 0; i < brickRow; i++)
		{
			for (j = 0; j < brickCol; j++)
			{
				brick[i][j].showBrick = false;
			}
		}

	}
	if (key == 'c')
	{
		level++;
	}
	if (key == 'm')
	{
		page = 7;
	}

	//place your codes for other keys here
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}


int main()
{
	fp = fopen("High Scores.txt", "r");
	while ((fscanf(fp, "%s %d", saved[i].name, &saved[i].score)) != EOF)
		i++;
	fclose(fp);

	initialize();

	ballTimer = iSetTimer(25, ballMovement);
	iPauseTimer(ballTimer);
	bulletTimer = iSetTimer(25, bulletMove);
	iPauseTimer(bulletTimer);
	soundTimer=iSetTimer(1, playSound);
	iPauseTimer(soundTimer);
	levelTimer = iSetTimer(1000, timeControl);
	iPauseTimer(levelTimer);
	iSetTimer(400, firstPageRender);

	//place your own initialization codes here.
	iInitialize(screenWidth, screenHeight, name);
	return 0;
}