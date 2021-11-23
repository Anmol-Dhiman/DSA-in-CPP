#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define Max 100
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13
#define ESC 27
#define PAUSE 63
#define R 3
#define left -1
#define right 1
#define ROW 20
#define COL 17
#define HD 35 /*means hirizontal distance*/
#define VD 17 /*means vertical distance*/

int ball = 3, score = 0, m = 0, x = 254, y = 446, q = 0, find = 0, direction = 0, level = 1, e, k = 1, l = 2;

#define FAILURE 0
#define BAT 1
#define WALL 2
#define BRICK 3
#define VALID 4
#define TWOWALL 5
#define BAT_WALL 6
#define BRICK_WALL 7

#define PATH_SAVE "a:\\save.azad"
#define PATH_RANK "a:\\ranking.azad"

/**************************Two structures Which I use************************/
/*structure for save game*/

struct
{
	int l;		   //for level
	int s;		   //for score
	int ba;		   //for ball
	int a[20][12]; //for brick
	int x1;		   //for x axis
	int y1;		   //for y axis
	int d;		   //for direction
} se;

/*structure for save top score and his name*/

typedef struct
{
	char name[10];
	int hscore;
} record;

record rank[5] = {"sharif", 50,
				  "asad", 40,
				  "zihad", 30,
				  "forqan", 20,
				  "azad", 10};

/***********************Two files which I use*******************************/

FILE *f;
FILE *p;

/************************Functions which I use*******************************/

void ballcalculation();
void checkbat();
int check();
void checkupath(int, int);
void drawbrick();
void drawbat();
void drawball();
void deleteball();
void deletebat();
void deletebrick();
void deletefubrick(int a, int b);
void deletefdbrick(int a, int b);
void deleteflbrick(int a, int b);
void deletefrbrick(int a, int b);
void ddirection();
void fsave();
void gname();
void graphmenu();
void graph(int x1, int y1, int x2, int y2, char *a, char *b);
void gameover();
void hi_score();
void help();
void levelgraph();
char *lineeditor(int x, int y, char *s, char *t);
void levelmenu();
void level_1();
void level_2();
void level_3();

void l_level();
void load();
// void music(int type);
void move();
void option();
void personal();
void restart();
void r_ank();
void save();
void scoregraph();
void scorecalculation();
void user_control();
void valid();
void insert(int);
void insert(int x) // insert the element x into the array a in sorted order
{				   //bubble sort
	int i, j, la;
	char *a;
	record tr;
	rank[4].hscore = x;
	lineeditor(150, 350, "Enter your name:", a);
	strcpy(rank[4].name, a);
	for (i = 0; i < 4; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			if (rank[j].hscore > rank[i].hscore)
			{
				tr = rank[i];
				rank[i] = rank[j];
				rank[j] = tr;
			}
		}
	}
}

//////////////////////////////End of Function///////////////////////////////////////////

void r_ank()
{
	int i, area;
	char *a;
	char ptr[100];
	area = imagesize(150, 280, 430, 433);
	a = (char *)malloc(area);
	getimage(150, 280, 430, 433, a);
	p = fopen(PATH_RANK, "r+");
	if (p == NULL)
	{
		printf("Error : Cannot open file\n");
		return;
	}
	int ti;
	char temp[100];
	int len;
	for (i = 0; i < 5; i++)
	{
		fgets(temp, 100, p);
		len = strlen(temp);
		if (temp[len - 1] == '\n')
			temp[len - 1] = 0;
		strcpy(rank[i].name, temp);
		fgets(temp, 100, p);
		ti = atoi(temp);
		rank[i].hscore = ti;
	}

	if (score < rank[4].hscore)
		return;
	outtextxy(150, 300, "You bit a top score!");
	insert(score);
	putimage(150, 280, a, COPY_PUT);
	fclose(p);
	p = fopen("a:\\ranking.azad", "w");
	char t[2];
	t[0] = '\n';
	t[1] = 0;
	for (i = 0; i < 5; i++)
	{
		fputs(rank[i].name, p);
		//fputs(t,p);
		fprintf(p, "\n");
		itoa(rank[i].hscore, temp, 10);
		fputs(temp, p);
		//fputs(t,p);
		fprintf(p, "\n");
	}
	fclose(p);
}
void hi_score()
{
	int i, ti;
	char a[30], temp[100], c;
	cleardevice();
	p = fopen(PATH_RANK, "r+");
	if (p == NULL)
	{
		printf("Could not open file");
		return;
	}
	outtextxy(150, 130, " The best five scorer");
	setfillstyle(1, 7);
	bar(150, 150, 400, 400);
	setcolor(15);
	line(150, 150, 400, 150);
	line(400, 150, 400, 400);
	setcolor(8);
	line(151, 200, 399, 200);
	line(151, 250, 399, 250);
	line(151, 300, 399, 300);
	line(151, 350, 399, 350);
	int len;

	for (i = 0; i < 5; i++)
	{
		fgets(temp, 100, p);

		len = strlen(temp);
		if (temp[len - 1] == '\n')
			temp[len - 1] = 0;

		strcpy(rank[i].name, temp);
		fgets(temp, 100, p);
		ti = atoi(temp);
		rank[i].hscore = ti;
	}
	for (i = 0; i < 5; i++)
	{
		itoa(rank[i].hscore, a, 10);
		outtextxy(160, 175 + i * 50, rank[i].name);
		outtextxy(160 + textwidth("Mohiuddin      "), 175 + i * 50, a);
	}
	fclose(p);
	setfillstyle(1, 7);
	bar(150, 420, 200, 450);
	bar(330, 420, 365, 450);
	setcolor(WHITE);
	line(150, 420, 200, 420);
	line(200, 420, 200, 450);
	outtextxy(160, 432, "Back");
	line(330, 420, 365, 420);
	line(365, 420, 365, 450);
	outtextxy(340, 432, "OK");
	setcolor(WHITE);
	line(155, 427, 155, 443);
	line(155, 443, 195, 443);
	setcolor(0);
	line(155, 427, 195, 427);
	line(195, 427, 195, 443);
	moveto(150, 425);
	c = getch();
	while (c != ENTER)
	{
		switch (c)
		{
		case 0:
			c = getch();
			switch (c)
			{
			case LEFT:
				moveto(150, 425);
				setcolor(7);
				rectangle(335, 427, 360, 443);
				setcolor(WHITE);
				line(155, 427, 155, 443);
				line(155, 443, 195, 443);
				setcolor(0);
				line(155, 427, 195, 427);
				line(195, 427, 195, 443);
				break;
			case RIGHT:
				moveto(330, 425);
				setcolor(7);
				rectangle(155, 427, 195, 443);
				setcolor(WHITE);
				line(335, 427, 335, 443);
				line(335, 443, 360, 443);
				setcolor(0);
				line(335, 427, 360, 427);
				line(360, 427, 360, 443);
			}
		}
		c = getch();
	}
	if (getx() == 150)
	{
		cleardevice();
		option();
	}
}
int dx[] = {1, -1, -1, 1};
int dy[] = {-1, -1, 1, 1};
int array[] = {228, 454, 272, 454, 273, 455, 273, 456, 272, 457, 228, 457, 227, 456, 227, 455, 228, 454};
void levelgraph()
{
	int i, j;

	setcolor(0);

	for (i = 0; i <= 20; i++)
		//for horizontal line
		line(37, 30 + i * VD, 462, 30 + i * VD);

	for (i = 0; i <= 17; i++)
		//for vertical  line
		line(37 + i * HD, 30, 37 + i * HD, 377);
}
void levelmenu()
{
	char o[Max];
	gname();
	setcolor(7);
	setfillstyle(1, 7);
	rectangle(230, 250, 300, 300);
	rectangle(210, 230, 320, 320);
	floodfill(220, 240, 7);
	setcolor(15);
	line(210, 230, 320, 230);
	line(320, 230, 320, 320);
	setcolor(2);
	outtextxy(240, 275, "Level ");
	outtextxy(240 + textwidth("Level "), 275, itoa(level, o, 10));
	getch();
	cleardevice();
}
void level_1()
{
	int i, j;
	int bri1[20][12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < 20; i++)
		for (j = 0; j < 12; j++)
		{
			if ((se.a[i][j] = bri1[i][j]) != 0)
			{
				if (i > 10)
					setfillstyle(1, 12);
				else
					setfillstyle(1, 2);
				bar(37 + j * HD, 30 + i * VD, 37 + j * HD + HD, 30 + i * VD + VD);
				setcolor(15);
				line(38 + j * HD, 31 + i * VD, 38 + j * HD + HD - 2, 31 + i * VD);
				line(38 + j * HD + HD - 2, 31 + i * VD, 38 + j * HD + HD - 2, 31 + i * VD + VD - 2);
			}
		}
	levelgraph(); //for some coloring
}
void level_2()
{
	int i, j;
	int bri2[20][12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1,
						0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1,
						0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1,
						0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1,
						0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1,
						0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1,
						0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1,
						0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1,
						0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0,
						0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < 20; i++)
		for (j = 0; j < 12; j++)
		{
			if ((se.a[i][j] = bri2[i][j]) != 0)
			{
				if (i > 9)
					setfillstyle(1, 12);

				else
					setfillstyle(1, 2);
				bar(37 + j * HD, 30 + i * VD, 37 + j * HD + HD, 30 + i * VD + VD);
				setcolor(15);
				line(38 + j * HD, 31 + i * VD, 38 + j * HD + HD - 2, 31 + i * VD);
				line(38 + j * HD + HD - 2, 31 + i * VD, 38 + j * HD + HD - 2, 31 + i * VD + VD - 2);
			}
		}
	levelgraph(); //for some coloring
}
void level_3()
{
	int i, j;
	int bri3[20][12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
						0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
						0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < 20; i++)
		for (j = 0; j < 12; j++)
		{
			if ((se.a[i][j] = bri3[i][j]) != 0)
			{
				if (i > 12)
					setcolor(12);

				setfillstyle(1, 2);
				bar(37 + j * HD, 30 + i * VD, 37 + j * HD + HD, 30 + i * VD + VD);
				setcolor(15);
				line(38 + j * HD, 31 + i * VD, 38 + j * HD + HD - 2, 31 + i * VD);
				line(38 + j * HD + HD - 2, 31 + i * VD, 38 + j * HD + HD - 2, 31 + i * VD + VD - 2);
			}
		}
	levelgraph(); //for some coloring
}

void graphmenu()
{

	setfillstyle(1, 7);
	bar(34, 18, 470, 26);	//for upper wall
	bar(26, 18, 33, 460);	//for left wall
	bar(26, 460, 474, 468); //for down wall
	bar(467, 18, 474, 460); //for right wall
	bar(500, 20, 620, 467); //another bar for calculation
	setfillstyle(1, 0);		//dividing this bar into some groups
	bar(510, 40, 610, 124);
	setcolor(RED);
	outtextxy(520, 60, "Press ESC");
	outtextxy(520, 80 + textheight("P"), "to QUIT");
	bar(510, 208, 610, 272);
	outtextxy(520, 228, "Score=");
	bar(510, 376, 610, 440);
	outtextxy(520, 396, "ball=");
}
void l_level()
{
	int i, j;
	for (i = 0; i < 20; i++)
		for (j = 0; j < 12; j++)
		{
			if (se.a[i][j])
			{
				setfillstyle(1, 2);
				bar(37 + j * HD, 30 + i * VD, 37 + j * HD + HD, 30 + i * VD + VD);
				setcolor(15);
				line(38 + j * HD, 31 + i * VD, 38 + j * HD + HD - 2, 31 + i * VD);
				line(38 + j * HD + HD - 2, 31 + i * VD, 38 + j * HD + HD - 2, 31 + i * VD + VD - 2);
			}
		}
	levelgraph();
}
void save()
{
	char *azad;
	int i, j;
	f = fopen(PATH_SAVE, "w");
	if (f == NULL)
	{
		printf("Could not open file");
		return;
	}
	se.l = level;
	se.s = score;
	se.ba = ball;
	se.x1 = x;
	se.y1 = y;
	se.d = direction;
	fwrite(&se, sizeof se, 1, f);
}
void fsave()
{
	char c, *a;
	int area;
	area = imagesize(180, 280, 430, 430);
	a = (char *)malloc(area);
	getimage(180, 280, 430, 430, a);
	setcolor(7);
	rectangle(190, 290, 420, 420);
	rectangle(180, 280, 430, 430);
	setfillstyle(1, 7);
	floodfill(185, 285, 7);
	setcolor(WHITE);
	line(180, 280, 430, 280);
	line(430, 280, 430, 430);
	settextstyle(4, 0, 0);
	setusercharsize(1, 2, 2, 2);
	outtextxy(200, 300, "Do you want to save the game");
	bar(240, 350, 250 + textwidth("YES") + 10, 360 + textheight("Y") + 5);
	outtextxy(250, 350, "YES");
	outtextxy(350, 350, "NO");
	moveto(250, 350);
	c = getch();
	while (c != ENTER)
	{
		switch (c)
		{
		case 0:
			c = getch();

			switch (c)
			{
			case LEFT:
				moveto(250, 350);
				setfillstyle(1, 0);
				bar(340, 350, 350 + textwidth("NO") + 10, 360 + textheight("N") + 5);
				outtextxy(350, 350, "NO");
				setfillstyle(1, 7);
				bar(240, 350, 250 + textwidth("YES") + 10, 360 + textheight("Y") + 5);
				outtextxy(250, 350, "YES");
				break;
			case RIGHT:
				moveto(350, 350);
				setfillstyle(1, 0);
				bar(240, 350, 250 + textwidth("YES") + 10, 360 + textheight("Y") + 5);
				outtextxy(250, 350, "YES");
				setfillstyle(1, 7);
				bar(340, 350, 350 + textwidth("NO") + 10, 360 + textheight("N") + 5);
				outtextxy(350, 350, "NO");
			}
		}
		c = getch();
	}
	putimage(180, 280, a, COPY_PUT);
	if (getx() == 250)
		save();
}

void checkbat()
{
	int mid = (array[0] + array[2]) / 2;
	if (mid <= x)
		direction = 0;
	else
		direction = 1;
	if (x <= (mid + 7) && x >= (mid - 7))
	{
		k = 1;
		l = 1;
	}
	else if (x <= (mid + 12) && x >= (mid - 12))
	{
		k = 2;
		l = 1;
	}
	else
	{
		k = 1;
		l = 2;
	}
}

void ballcalculation()
{
	char b[Max];
	setfillstyle(1, 0);
	bar(520 + textwidth("ball="), 376, 610, 440);
	itoa(ball, b, 10);
	setcolor(4);
	outtextxy(520 + textwidth("ball="), 396, b);
	if (!ball)
		q = 1;
}
void scoregraph()
{
	char s[Max];
	setfillstyle(1, 0);
	bar(520 + textwidth("score="), 208, 610, 272);
	itoa(score, s, 10);
	setcolor(4);
	outtextxy(520 + textwidth("Score="), 228, s);
}
void scorecalculation()
{
	scoregraph();
	if (f)
	{
		l_level();
		f = NULL;
	}
	else if (score == 0)
		level_1();
	else if (score == 360)
	{
		// music(4);
		level++;
		deleteball();
		setcolor(9);
		outtextxy(100, 100, "Congratulation!");
		outtextxy(100, 150, "Now you are going to second level");
		getch();
		cleardevice();
		levelmenu();
		graphmenu();
		level_2();
		ballcalculation();
		restart();
		scoregraph();
	}
	else if (score == 630 + 360)
	{
		// music(4);
		level++;
		deleteball();
		setcolor(9);
		outtextxy(100, 100, "Congratulation!");
		outtextxy(100, 150, "Now you are going to third level");
		getch();
		cleardevice();
		levelmenu();
		graphmenu();
		level_3();
		ballcalculation();
		restart();
		scoregraph();
	}
	else if (score == 630 + 360 + 510)
	{
		// music(4);
		setcolor(9);
		outtextxy(100, 100, "Congratulation!");
		outtextxy(100, 150, "You have finished your mission");
		delay(500);
		q = 1;
		find = 1;
	}
}
void gameover()
{
	int i;
	setfillstyle(1, 7);
	bar(getmaxx() / 2 - 100, 270, getmaxx() / 2 + 30, 290);
	for (i = 0; i < 80; i += 10)
	{
		bar(getmaxx() / 2 - 100, 270 - i, getmaxx() / 2 - 90, 290);
		bar(getmaxx() / 2 + 30, 270 - i, getmaxx() / 2 + 40, 290);
		delay(25);
	}
	bar(getmaxx() / 2 - 100, 190, getmaxx() / 2 + 40, 210);
	setcolor(WHITE);
	line(getmaxx() / 2 - 100, 190, getmaxx() / 2 + 40, 190);
	line(getmaxx() / 2 + 40, 190, getmaxx() / 2 + 40, 290);
	line(getmaxx() / 2 - 90, 210, getmaxx() / 2 - 90, 270);
	line(getmaxx() / 2 - 90, 270, getmaxx() / 2 + 29, 270);
	delay(35);
	settextstyle(0, 0, 0);
	setcolor(11);
	outtextxy(getmaxx() / 2 - 60, 240, "Game Over");
	delay(100);
}
// void music(int type)
// {
// 	//natural frequencies of 7 notes
// 	float o[] = {130.81, 146.83, 164.81, 174.61, 196, 220, 246.94};
// 	int n, i;
// 	switch (type)
// 	{
// 	case 1:
// 		for (i = 0; i < 7; i++)
// 		{
// 			sound(o[i] * 35);
// 			delay(0);
// 		}
// 		nosound();
// 		break;
// 	case 2:
// 		for (i = 0; i < 15; i++)
// 		{
// 			n = random(7);
// 			sound(o[n] * 4);
// 			delay(0);
// 		}
// 		nosound();
// 		break;
// 	case 3:
// 		n = random(7);
// 		sound(o[n] * 4);
// 		delay(0);
// 		nosound();
// 		break;
// 	case 4:
// 		for (i = 4; i >= 0; i--)
// 		{
// 			sound(o[i] * 4);
// 			delay(0);
// 		}
// 		nosound();
// 		break;
// 	case 5:
// 		sound(o[6] * 5);
// 		delay(10);
// 		nosound();
// 	}
// }
void load()
{
	f = fopen("a:\\save.azad", "r");
	fread(&se, sizeof se, 1, f);
	level = se.l;
	score = se.s;
	ball = se.ba;
	x = se.x1;
	y = se.y1;
	direction = se.d;
}
void personal()
{
	cleardevice();
	gname();
	setcolor(12);
	outtextxy(120, 150, "Mohammad Mohiuddin azad");
	outtextxy(120, 175, "Roll:0105107");
	outtextxy(120, 200, "Level -> 1 Term -> 1");
	outtextxy(120, 225, "CSE,BUET.");
	setcolor(15);
	outtextxy(150, 400, "Press any key to go to main menu");
	getch();
	cleardevice();
	option();
}
void help()
{
	cleardevice();
	gname();
	setcolor(12);
	outtextxy(120, 150, "1.Press RIGHT ARROW to move the bar to right.");
	outtextxy(120, 175, "2.Press LEFT ARROW to move the bar to left.");
	outtextxy(120, 200, "3.Press ESC to exit any time.");
	outtextxy(120, 225, "4.Press F5 to PAUSE.");
	setcolor(15);
	outtextxy(150, 400, "Press any key to go to main menu");
	getch();
	cleardevice();
	option();
}
void graph(int x1, int y1, int x2, int y2, char *a, char *b)
{
	setfillstyle(1, 0);
	bar(x1 - 10, y1 - 20, x1 + textwidth(a) + 10, y1 + 20);
	setcolor(15);
	outtextxy(x1, y1, a);
	setfillstyle(1, 7);
	bar(x2 - 10, y2 - 20, x2 + textwidth(b) + 10, y2 + 20);
	setcolor(6);
	outtextxy(x2, y2, b);
	moveto(x2, y2);
}
void option()
{
	char c;
	gname();
	setcolor(6);
	setfillstyle(1, 7);
	bar(240, 130, 250 + textwidth("NEW GAME") + 10, 170);
	outtextxy(250, 150, "NEW GAME");
	setcolor(15);
	outtextxy(250, 200, "LOAD GAME");
	outtextxy(250, 250, "TOPSCORES");
	outtextxy(250, 300, "ABOUT ME");
	outtextxy(250, 350, "HELP");
	moveto(250, 150);
	c = getch();
	while (c != ENTER)
	{
		if (c == 0)
			c = getch();
		switch (c)
		{
		case UP:
			if (gety() != 150)
			{
				if (gety() == 200)

					graph(250, 200, 250, 150, "LOAD GAME", "NEW GAME");

				else if (gety() == 250)

					graph(250, 250, 250, 200, "TOPSCORES", "LOAD GAME");

				else if (gety() == 300)
					graph(250, 300, 250, 250, "ABOUT ME", "TOPSCORES");

				else
					graph(250, 350, 250, 300, "HELP", "ABOUT ME");
			}
			break;

		case DOWN:
			if (gety() != 350)
			{
				if (gety() == 150)

					graph(250, 150, 250, 200, "NEW GAME", "LOAD GAME");

				else if (gety() == 200)
					graph(250, 200, 250, 250, "LOAD GAME", "TOPSCORES");

				else if (gety() == 250)

					graph(250, 250, 250, 300, "TOPSCORES", "ABOUT ME");

				else

					graph(250, 300, 250, 350, "ABOUT ME", "HELP");
			}
		}
		c = getch();
	}
	if (gety() == 250)
		hi_score();
	else if (gety() == 200)
		load();

	else if (gety() == 300)
		personal();

	else if (gety() == 350)
		help();
}
void gname()
{
	settextstyle(4, 1, 0);
	setcolor(14);
	outtextxy(50, 160, "PARANOID");
	outtextxy(500, 160, "PARANOID");
	settextstyle(4, 0, 0);
	outtextxy(170, 20, "PARANOID");
	outtextxy(170, 400, "PARANOID");
	settextstyle(0, 0, 0);
}
/*****************************MAIN******************************************/

void restart()
{

	m = 0;
	deletebat();
	// music(2);
	delay(100);
	array[0] = 227;
	array[1] = 454;
	array[2] = 273;
	array[3] = 454;
	array[4] = 274;
	array[5] = 455;
	array[6] = 274;
	array[7] = 456;
	array[8] = 273;
	array[9] = 457;
	array[10] = 227;
	array[11] = 457;
	array[12] = 226;
	array[13] = 456;
	array[14] = 226;
	array[15] = 455;
	array[16] = 227;
	array[17] = 454;
	x = 254;
	y = 446;
	k = 1;
	l = 1;
	direction = 0;
	drawbat();
	drawball();
	while (getch() != ENTER)
		;
}
void drawbat()
{
	int i;
	setcolor(15);
	setfillstyle(1, 15);
	for (i = 0; i <= 18; i += 2)
		array[i] = array[i] + m * 16;

	fillpoly(9, array);
}
void deletebat()
{
	setcolor(0);
	setfillstyle(1, 0);
	if (m == right)
		bar(array[14], array[15] - 1, array[14] + 16, array[15] + 3);
	else if (m == left)
		bar(array[4], array[5] - 1, array[4] - 16, array[5] + 3);
	else
		drawpoly(9, array);
	fillpoly(9, array);
}
void deleteball()
{
	setcolor(0);
	circle(x, y, R);
	setfillstyle(1, 0);
	floodfill(x, y, 0);
}
void move()
{
	int k;
	k = check();
	switch (k)
	{
	case FAILURE:
		drawball();
		deleteball();
		ball--;
		ballcalculation();
		if (ball)
			restart();
		break;

	case WALL:
		drawball();
		ddirection();
		// music(1);
		// sound(400);
		// nosound();
		break;

	case BAT:
		drawball();
		checkbat();
		// music(1);
		// sound(300);
		// nosound();
		break;

	case VALID:
		drawball();
		break;

	case BRICK:
		deletebrick();
		// music(5);
		if (!find)
			drawball();
		break;
	case BRICK_WALL:
		deletebrick();
		if (!find)
			drawball();
		direction = (direction + 2) % 4;
		break;

	case BAT_WALL:
	case TWOWALL:
		// music(1);
		drawball();
		direction = (direction + 2) % 4;
		break;
	}
}

void drawball()
{
	setcolor(15);
	setfillstyle(1, 15);
	circle(x, y, R);
	floodfill(x, y, 15);
}
void user_control()
{
	char c;
	c = getch();
	switch (c)
	{
	case 0:
		c = getch();
		switch (c)
		{
		case LEFT:
			if (array[12] > 40)
			{
				m = left;
				deletebat();
				drawbat();
				delay(0);
			}

			break;
		case RIGHT:
			if (array[4] < 460)
			{
				m = right;
				deletebat();
				drawbat();
				delay(0);
			}

			break;

		case PAUSE:
			drawball();
			while (!kbhit())
			{
			}
		}
		break;
	case ESC:
		q = 1;
		break;
	}
}
/********************external variable*************************************/
int cs = 0;

void checkupath(int a, int b)
{
	int i = 0;
	while (getpixel(a, b - i))
		i++;
	i--;
	if (i < 0)
		return;
	deletefubrick(a, b - i);
	cs++;
}
void deletebrick()
{
	int a = direction;
	checkupath(x, y + 5);
	checkupath(x, y - 5);
	checkupath(x + 5, y);
	checkupath(x - 5, y);
	checkupath(x + 5, y + 5);
	checkupath(x + 5, y - 5);
	checkupath(x - 5, y - 5);
	checkupath(x - 5, y + 5);
	if (cs > 1)
		direction = (a + 2) % 4;
	cs = 0;
}
int check()
{
	if (getpixel(x, y + 7) || getpixel(x, y - 7) || getpixel(x + 7, y) || getpixel(x - 7, y) || getpixel(x + 7, y + 7) || getpixel(x + 7, y - 7) || getpixel(x - 7, y - 7) || getpixel(x - 7, y + 7))
	{
		x = x + dx[direction];
		y = y + dy[direction];
	}
	else
	{
		x = x + dx[direction] * k;
		y = y + dy[direction] * l;
	}
	if (kbhit())
		user_control();
	if (y > 449)
		return FAILURE;
	else if ((x == 38 && y == 31) || (x == 462 && y == 31))
		return TWOWALL;
	else if ((x == 38 && (y >= 449 && x >= array[14] && x <= array[4])) || (x == 462 && (y >= 449 && x >= array[14] && x <= array[4])))
		return BAT_WALL;
	else if (((x == 38) && (getpixel(x + 5, y) || getpixel(x, y - 5) || getpixel(x, y + 5))) || ((x == 462) && (getpixel(x - 5, y) || getpixel(x, y + 5) || getpixel(x, y - 5)))) //||getpixel(x-5,y-5)||getpixel(x-5,y+5))!=)
		return BRICK_WALL;
	else if (x == 38 || x == 462 || y == 31)
		return WALL;
	else if (y >= 449 && x >= array[14] - 5 && x <= array[4] + 5)
		return BAT;
	else if (!getpixel(x, y + 5) && !getpixel(x, y - 5) && !getpixel(x + 5, y) && !getpixel(x - 5, y) && !getpixel(x + 5, y + 5) && !getpixel(x + 5, y - 5) && !getpixel(x - 5, y - 5) && !getpixel(x - 5, y + 5))
		return VALID;
	else
		return BRICK;
}
void ddirection()
{
	if (direction == 0)
	{
		if (!getpixel(x + 5, y + 5))
			direction = 3;
		else if (!getpixel(x - 5, y - 5))
			direction = 1;
		else
			direction = 2;
	}
	else if (direction == 1)
	{
		if (!getpixel(x - 5, y + 5))
			direction = 2;
		else if (!getpixel(x + 5, y - 5))
			direction = 0;

		else
			direction = 3;
	}
	else if (direction == 2)
	{
		if (!getpixel(x - 5, y - 5))
			direction = 1;
		else if (!getpixel(x + 5, y + 5))
			direction = 3;
		else
			direction = 0;
	}

	else //direction=3
	{
		if (!getpixel(x - 5, y + 5))
			direction = 2;
		else if (!getpixel(x + 5, y - 5))
			direction = 0;
		else
			direction = 1;
	}
}
void deletefubrick(int a, int b)
{
	int i = 0, ch, c = getpixel(a, b);
	while (getpixel(a - i, b) == c)
		i++;
	i--;
	ddirection();
	setfillstyle(1, 0);
	bar(a - i, b, a - i + 33, b + VD - 2);
	score += 10;
	scorecalculation();
	se.a[(b - 30) / VD][(a - i - 37) / HD] = 0;
}
char *lineeditor(int x, int y, char *str, char *a)
{
	int limitX = x + 150, i = 0;
	int Llimit = limitX, Rlimit = limitX + 100;
	char ch, temp[2];
	setcolor(9);
	settextstyle(0, 0, 1);
	outtextxy(x, y, str);
	setcolor(14);
	line(limitX, y + 10, limitX + 10, y + 10);
	ch = getch();
	while (!isalpha(ch))
		ch = getch();
	while (1)
	{
		//ch=getch();
		if (ch == 0)
			getch();
		switch (ch)
		{
		case '\r':
			a[i] = 0;
			return a;
		case 8:
			limitX -= 10;
			if (limitX < Llimit)
			{
				limitX += 10;
				break;
			}
			setfillstyle(1, 0);
			bar(limitX, y - 1, limitX + 10, y + 12);
			setcolor(0);
			line(limitX + 10, y + 10, limitX + 20, y + 10);
			setcolor(14);
			line(limitX, y + 10, limitX + 10, y + 10);
			i--;
			a[i] = 0;
			break;
		default:
			if (limitX > Rlimit)
				break;
			//if(!validity(ch))
			//	break;
			temp[0] = ch;
			temp[1] = 0;
			setcolor(9);
			settextstyle(0, 0, 1);
			outtextxy(limitX, y, temp);
			setcolor(0);
			line(limitX, y + 10, limitX + 10, y + 10);
			setcolor(14);
			line(limitX + 10, y + 10, limitX + 20, y + 10);
			limitX += 10;
			a[i++] = ch;
			a[i] = 0;
		}
		ch = getch();
		//while(!isprint(ch))ch=getch();
	}
}
int main()
{
	int gd = VGA, gm = VGAHI, d;
	char c;
	initgraph(&gd, &gm, "..\\bgi");
	option();
	cleardevice();
	levelmenu();
	graphmenu();
	scorecalculation();
	ballcalculation();
	drawbat();
	drawball();
	while (!q) /*main loop which controls the game*/
	{

		delay(8);
		deleteball();
		move();
	}
	// music(4);
	delay(50);

	if (ball == 0)
		r_ank();
	else if (!find)
	{
		deleteball();
		fsave();
	}
	gameover();
	getch();
	return 0;
}