#include"my.h"

void start();
void menu();
void createfood(fd* food);
void drawfood();
void drawsnake();
void draw();
void keyboard();
void gameover();

int main()
{
	//��ʼ��Ϸ
	
	start();

	system("pause");
	return 0;
}

//��ʼ����ͼƬ
void start()
{

	//��ͼ�󲢶�ȡͼƬ
	{
		initgraph(800, 600);

		loadimage(&headw, _T("E://SnakeImage//headw.png"), 20, 20);
		loadimage(&heada, _T("E://SnakeImage//heada.png"), 20, 20);
		loadimage(&heads, _T("E://SnakeImage//heads.png"), 20, 20);
		loadimage(&headd, _T("E://SnakeImage//headd.png"), 20, 20);
		loadimage(&snake, _T("E://SnakeImage//snake.png"), 20, 20);
		loadimage(&food0, _T("E://SnakeImage//food0.png"), 20, 20);
		loadimage(&food1, _T("E://SnakeImage//food1.png"), 20, 20);
		loadimage(&food2, _T("E://SnakeImage//food2.png"), 20, 20);
		loadimage(&food3, _T("E://SnakeImage//food3.png"), 20, 20);
		loadimage(&map, _T("E://SnakeImage//map.png"), 800, 600);

	}

	//�����߳�ʼ��
	{
		head = (sn*)malloc(sizeof(sn));
		head->pre = NULL;
		head->position_x = 7;
		head->position_y = 7;
		head->next = (sn*)malloc(sizeof(sn));
		p = head->next;
		p->position_x = 7;
		p->position_y = 7;
		p->pre = head;
		p->next = (sn*)malloc(sizeof(sn));
		tail = p->next;
		tail->position_x = 7;
		tail->position_y = 7;
		tail->pre = p;
		tail->next = NULL;
		p = NULL;
		//��ʼ����Ϊ3
	}

	//��������Ӽ�ʳ���ʼ��
	{
	srand((unsigned)time(NULL));
	createfood(fd1);
	createfood(fd2);
	createfood(fd3);
	createfood(fd4);
	fd1->type = 0;
	fd3->type = 0;
	}

	//���뿪ʼͼƬ
	loadimage(NULL, _T("E://SnakeImage//load0.jpg"), 800, 600);
	Sleep(700);
	loadimage(NULL, _T("E://SnakeImage//load1.jpg"), 800, 600);
	Sleep(1700);
	loadimage(NULL, _T("E://SnakeImage//load2.png"), 800, 600);
	Sleep(1700);
	
	menu();
}

//��ʼѡ��˵�
void menu()
{
	IMAGE menu0;
	loadimage(&menu0, _T("E://SnakeImage//menu0.png"));
	putimage(0, 0, &menu0);
	for (;;)
	{

	}
}

void createfood(fd*food)
{
	food->position_x = rand() % (MAP_WIDTH + 1);
	food->position_y = rand() % (MAP_LENGTH + 1);
	food->type = rand() % (4);
	//���ʳ���ڲ���������
	int flag = 0;
	p = head;
	while (p && flag==0)
	{
		if (food->position_x == p->position_x && food->position_y == p->position_y)
		{
			flag = 1;
			break;
		}
		p = p->next;
	}
	p = NULL;
	if (flag == 1)
		createfood(food);
	//���ʳ��᲻���غ�
	//�Ͳ������
}

//��ͼ
void drawfood()
{
	switch (fd1->type)
	{
	case 0:putimage((fd1->position_x * 10), (fd1->position_y) * 10, &food0); break;
	case 1:putimage((fd1->position_x * 10), (fd1->position_y) * 10, &food1); break;
	case 2:putimage((fd1->position_x * 10), (fd1->position_y) * 10, &food2); break;
	case 3:putimage((fd1->position_x * 10), (fd1->position_y) * 10, &food3); break;
	}
	switch (fd2->type)
	{
	case 0:putimage((fd2->position_x * 10), (fd2->position_y) * 10, &food0); break;
	case 1:putimage((fd2->position_x * 10), (fd2->position_y) * 10, &food1); break;
	case 2:putimage((fd2->position_x * 10), (fd2->position_y) * 10, &food2); break;
	case 3:putimage((fd2->position_x * 10), (fd2->position_y) * 10, &food3); break;
	}
	switch (fd3->type)
	{
	case 0:putimage((fd3->position_x * 10), (fd3->position_y) * 10, &food0); break;
	case 1:putimage((fd3->position_x * 10), (fd3->position_y) * 10, &food1); break;
	case 2:putimage((fd3->position_x * 10), (fd3->position_y) * 10, &food2); break;
	case 3:putimage((fd3->position_x * 10), (fd3->position_y) * 10, &food3); break;
	}
	switch (fd4->type)
	{
	case 0:putimage((fd4->position_x * 10), (fd4->position_y) * 10, &food0); break;
	case 1:putimage((fd4->position_x * 10), (fd4->position_y) * 10, &food1); break;
	case 2:putimage((fd4->position_x * 10), (fd4->position_y) * 10, &food2); break;
	case 3:putimage((fd4->position_x * 10), (fd4->position_y) * 10, &food3); break;
	}
}
void drawsnake()
{
	switch (go_position)
	{
	case 'w':putimage((head->position_x) * 10, (head->position_y) * 10, &headw); break;
	case 'a':putimage((head->position_x) * 10, (head->position_y) * 10, &heada); break;
	case 's':putimage((head->position_x) * 10, (head->position_y) * 10, &heads); break;
	case 'd':putimage((head->position_x) * 10, (head->position_y) * 10, &headd); break;
	}
	p = head->next;
	while (p)
	{
		putimage((p->position_x) * 10, (p->position_y) * 10, &snake);
		p = p->next;
	}
	p = NULL;
}
void draw()
{
	putimage(0, 0, &map);
	drawfood();
	drawsnake();
	Sleep(speed);
}

//��ͣ
void pause()
{

}

//���̶�ȡ
void keyboard()
{

}

//�����ͷ�Ӵ���ʲô
void check()
{
	//�Ե�ʳ�� ���ض���ʳ��
	if(head->position_x == fd1->position_x && head->position_y == fd1->position_y)
		switch (fd1->type)
		{
		case 0:join(); score = score + 5; 
			createfood(fd1);break;//������
		case 1:dele(); dele(); 
			createfood(fd1); break;//����
		case 2:dele(); score = score - 5; speed = speed - 10; 
			if (speed == 0)
			{
				speed = 10; score = score - 10;
			} createfood(fd1); break;//����
		case 3:createfood(fd1); break;//δ��
		}
	else
		if (head->position_x == fd2->position_x && head->position_y == fd2->position_y)
			switch (fd2->type)
				{					
				case 0:join(); score = score + 5; createfood(fd2); break;
				case 1:dele(); dele(); 
					createfood(fd2); break;
				case 2:dele(); score = score - 5; speed = speed - 10;
					if (speed == 0)
					{
						speed = 10; score = score - 10;
					}createfood(fd2); break;
				case 3:break;//δ��
				}
		else
			if (head->position_x == fd3->position_x && head->position_y == fd3->position_y)
				switch (fd3->type)
				{
				case 0:join(); score = score + 5; 
					createfood(fd3); break;
				case 1:dele(); dele(); 
					createfood(fd3); break;
				case 2:dele(); score = score - 5; speed = speed - 10;
					if (speed == 0)
					{
						speed = 10; score = score - 10;
					}createfood(fd3); break;
				case 3:createfood(fd3); break;//δ��
				}
			else
				if (head->position_x == fd4->position_x && head->position_y == fd4->position_y)
					switch (fd4->type)
					{
					case 0:join(); score = score + 5;
						createfood(fd4); break;
					case 1:dele(); dele(); 
						createfood(fd4); break;
					case 2:dele(); score = score - 5; speed = speed - 10;
						if (speed == 0)
						{
							speed = 10; score = score - 10;
						} createfood(fd4); break;
					case 3:createfood(fd4); break;//δ��
					}
	if (head == tail)
		gameover();
	
	//ײǽ
	if (head->position_x < 0 || head->position_x > 40 || head->position_y < 0 || head->position_y > 30)
		gameover();
	
	//�Ե��Լ�
	p = head->next;
	while (p)
	{
		if (head->position_x == p->position_x && head->position_y == p->position_y)
		{
			gameover();
			break;
			p = NULL;
		}
		p = p->next;
	}
}

//����������
void run()
{
	switch (go_position)
	{
	case'w':case'W':head->position_y--; break;
	case'a':case'A':head->position_x--; break;
	case's':case'S':head->position_y++; break;
	case'd':case'D':head->position_x++; break;
	}
	p = head->next;
	while (p)
	{
		p->position_x = p->pre->position_x;
		p->position_y = p->pre->position_y;
	}
	p = NULL;
	draw();
}


//��Ϸ����
void gameover()
{
	//�ռ��ͷ�
	p = head->next;
	while (p)
	{
		free(p->pre);
		p = p->next;
	}
	free(tail);

	//���

}