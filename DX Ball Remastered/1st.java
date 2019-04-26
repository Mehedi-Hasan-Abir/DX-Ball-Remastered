/*
Project Name : DX BALL Remastered ;
*/

# include "iGraphics.h"

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
int ballPosition_X = 300;
int ballPosition_Y = 0;
int ballWidth = 20;
int ballHeight = 20;
int ballSpeed_X = 5;
int ballSpeed_Y = 5;
int ballDirection = 1;
int ballPoint = 0;


/*
Paddle
*/
char paddleImage[50] = "Image\\Paddle.bmp";
int paddlePosition_X = 425;
int paddlePosition_Y = 0;
int paddleWidth = 150;
int paddleHeight = 19;
int paddleSpeed = 20;

/*
Brick
*/

char brickImage[50] = "Image\\brick.bmp";
//int  brick[9] ;
//bool showBrick[9] = {true};
/*
int brick1Position_X;
int brick1Position_Y;
int brick2Position_X;
int brick2Position_Y;
int brick3Position_X;
int brick3Position_Y;
int brick4Position_X;
int brick4Position_Y;
int brick5Position_X;
int brick5Position_Y;
int brick6Position_X;
int brick6Position_Y;

*/

int brickWidth = 50;
int brickHeight = 25;
int brickGap_X;
int brickGap_Y;
int brickFirst_X = 250;
int brickFirst_Y = 500;
int brickRow = 5;
int brickCol = 10;

struct Brick
{
	int brickPosition_X;
	int brickPosition_Y;
	bool showBrick;

}brick[5][10];



//////////         Loop Parameter
//////////
int i, j;

int mposx, mposy;

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
				iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, brickImage);
				//iFilledRectangle(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, 150, 30);
			}



		}
	}
}

/*
BallMovement
*/

void ballMovememnt()
{


	for (i = 0; i < brickRow; i++)
	{
		for (j = 0; j < brickCol; j++)
		{

			if (ballPosition_Y + ballHeight >= brick[i][j].brickPosition_Y && ballPosition_Y <= brick[i][j].brickPosition_Y + brickHeight && ballPosition_X  >= brick[i][j].brickPosition_X && ballPosition_X  <= brick[i][j].brickPosition_X + brickWidth && brick[i][j].showBrick == true)
			{
				//ballPoint = ballPosition_X + 10;


				//if ()
				//{
					printf("1st %d", ballDirection);
					brick[i][j].showBrick = false;

					if (ballDirection == 3)
					{
						ballDirection = 4;
					}
					else if (ballDirection == 1)
					{
						ballDirection = 6;
					}
					else if (ballDirection == 2)
					{
						ballDirection = 5;
					}
					else if (ballDirection == 4)
					{
						ballDirection = 3;
					}
					else if (ballDirection == 6)
					{
						ballDirection = 1;
					}
					else if (ballDirection == 5)
					{
						ballDirection = 2;
					}

					break;
				//}

			}

			else if (ballPosition_X + ballWidth >= brick[i][j].brickPosition_X && ballPosition_X <= brick[i][j].brickPosition_X + brickWidth && brick[i][j].showBrick == true)
			{


                     ballPoint = ballPosition_Y;
				

				if (ballPoint >= brick[i][j].brickPosition_Y &&  ballPoint <= brick[i][j].brickPosition_Y + brickHeight)
				{
					printf("2nd %d", ballDirection);
					brick[i][j].showBrick = false;

					if (ballDirection == 3)
					{
						ballDirection = 1;
					}
					else if (ballDirection == 1)
					{
						ballDirection = 3;
					}
					else if (ballDirection == 6)
					{
						ballDirection = 4;
					}
					else if (ballDirection == 4)
					{
						ballDirection = 6;
					}
					else if (ballDirection == 2)
					{
						ballDirection = 5;
					}
					else if (ballDirection == 5)
					{
						ballDirection = 2;
					}
					break;
				}

			}



		}
		if (brick[i][j].showBrick = false)
		{
			break;
		}

	}



	/*
	if (ballPosition_X + ballWidth >= brick[i][j].brickPosition_X  && brick[i][j].showBrick == true)						// brick Left Border
	{
	brick[i][j].showBrick = false;

	if (ballDirection == 3)
	{
	ballDirection = 1;
	}
	else if (ballDirection == 4)
	{
	ballDirection = 6;
	}

	break ;
	}
	else if (ballPosition_X <= brick[i][j].brickPosition_X + brickWidth && brick[i][j].showBrick == true)  //Right Border
	{
	//brick[i][j].showBrick = false;

	if (ballDirection == 1)
	{
	ballDirection = 3;
	}
	else if (ballDirection == 6)
	{
	ballDirection = 4;
	}
	break ;
	}
	else if (ballPosition_Y + ballHeight >= brick[i][j].brickPosition_Y && brick[i][j].showBrick == true) // low Border
	{
	brick[i][j].showBrick = false;

	if (ballDirection == 3)
	{
	ballDirection = 4;
	}
	else if (ballDirection == 1)
	{
	ballDirection = 6;
	}
	else if (ballDirection == 2)
	{
	ballDirection = 5;
	}
	break ;

	}
	else if (ballPosition_Y <= brick[i][j].brickPosition_Y + brickHeight && brick[i][j].showBrick == true) //Upper Border
	{
	brick[i][j].showBrick = false;

	if (ballDirection == 4)
	{
	ballDirection = 3;
	}
	else if (ballDirection == 6)
	{
	ballDirection = 1;
	}
	else if (ballDirection == 5)
	{
	ballDirection = 2;
	}
	break ;


	}

	}
	//if (brick[i][j].showBrick = false)
	//{

	//break;
	//}

	}

	*/

	// Direction Changing 

	if (ballPosition_X <= 0)						// Left Border 
	{
		if (ballDirection == 1)
		{
			ballDirection = 3;
		}
		else if (ballDirection == 6)
		{
			ballDirection = 4;
		}
	}
	else if (ballPosition_X >= screenWidth - ballWidth)  //Right Border 
	{
		if (ballDirection == 3)
		{
			ballDirection = 1;
		}
		else if (ballDirection == 4)
		{
			ballDirection = 6;
		}
	}
	else if (ballPosition_Y >= screenHeight - ballHeight) //Upper Border
	{
		if (ballDirection == 3)
		{
			ballDirection = 4;
		}
		else if (ballDirection == 1)
		{
			ballDirection = 6;
		}
		else if (ballDirection == 2)
		{
			ballDirection = 5;
		}
	}
	/*else if (ballPosition_Y <= 0)  //Lower
	{
	if (ballDirection == 6)
	{
	ballDirection = 1;
	}
	else if (ballDirection == 4)
	{
	ballDirection = 3;
	}
	}
	*/
	if (ballPosition_Y <= -30)										//Paddle
	{
		exit(0);
	}
	if (ballPosition_Y <= 19)
	{
		ballPoint = ballPosition_X;

		if (ballPoint >= paddlePosition_X && ballPoint <= paddlePosition_X + 45)
		{
			ballDirection = 1;
		}
		else if (ballPoint > paddlePosition_X + 45 && ballPoint <= paddlePosition_X + 105)
		{
			ballDirection = 2;
		}
		else if (ballPoint > paddlePosition_X + 105 && ballPoint <= paddlePosition_X + 150)
		{
			ballDirection = 3;
		}

	}
	//bricks

	/*
	if (ballPosition_Y >= 500 && ballPosition_Y <= 520 && showBrick[0] == true)
	{
	ballPoint = ballPosition_X + 15;

	if (ballPoint >= 500 && ballPoint <= 650)
	{
	showBrick[0] = false;
	ballDirection = 1;
	}

	}

	*/






	/*
	if (ballPosition_Y >= 500 && ballPosition_Y <= 520 && showBrick[0] == true)
	{
	ballPoint = ballPosition_X + 15;

	if (ballPoint >= 500 && ballPoint <= 650)
	{
	showBrick[0] = false;
	ballDirection = 1;
	}

	}

	brick[i][j].brickPosition_X = 250 + brickGap_X;
	brick[i][j].brickPosition_Y = 500 + brickGap_Y;

	iShowBMP(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, brickImage);
	//iFilledRectangle(brick[i][j].brickPosition_X, brick[i][j].brickPosition_Y, 150, 30);

	}
	}


	*/








	if (ballDirection == 1)						// Initializing Directions
	{
		ballPosition_X -= ballSpeed_X;
		ballPosition_Y += ballSpeed_Y;
	}
	else if (ballDirection == 2)
	{
		//ballPosition_X += ballSpeed_X;
		ballPosition_Y += ballSpeed_Y;
	}
	else if (ballDirection == 3)
	{
		ballPosition_X += ballSpeed_X;
		ballPosition_Y += ballSpeed_Y;
	}
	else if (ballDirection == 4)
	{
		ballPosition_X += ballSpeed_X;
		ballPosition_Y -= ballSpeed_Y;
	}
	else if (ballDirection == 5)
	{
		//ballPosition_X += ballSpeed_X;
		ballPosition_Y -= ballSpeed_Y;
	}
	else if (ballDirection == 6)
	{
		ballPosition_X -= ballSpeed_X;
		ballPosition_Y -= ballSpeed_Y;
	}
}


/*
function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here
	iClear();
	iShowBMP2(ballPosition_X, ballPosition_Y, ballImage, 0);
	//iFilledCircle(ballPosition_X, ballPosition_Y, 15);
	iShowBMP2(paddlePosition_X, paddlePosition_Y, paddleImage, 0);

	//if (showBrick[0]){
	//iFilledRectangle(500, 500, 150, 20);
	//}

	brickPattern();
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
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
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
	if (key == 'd' && paddlePosition_X <= 850)
	{
		paddlePosition_X += paddleSpeed;
	}
	else if (key == 'a' && paddlePosition_X >= 0)
	{
		paddlePosition_X -= paddleSpeed;
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
//
int main()
{
	for (i = 0; i < brickRow; i++)
	{
		for (j = 0; j < brickCol; j++)
		{
			brick[i][j].showBrick = true;
		}
	}

	iSetTimer(25, ballMovememnt);


	//place your own initialization codes here.
	iInitialize(screenWidth, screenHeight, name);
	return 0;
}