#include<stdio.h>

struct cnode {
	int row;  //������ڵ�������
	int col;  //������
	int color;   //��ɫ
	int direction; //����
	int num;     //����㵽��������С����
};

struct cnode s;//start��¼��ʼ����Ϣ
struct cnode t;//tail��¼Ŀ�����Ϣ
struct cnode open[200];//����struct cnode���͵ı�
int head, tail, openlen = 200;//open������
int direct[4][2] = { {0,-1},{1,0},{0,1},{-1,0} };//�����£��ң����ĸ�����תʱ�����е�����ֵ
int a[20][20];//��¼�Թ�״̬
int n = 20;//nΪ�Թ��߳�
int b[20][20][5][4] ;//��ʾ�Թ�״̬��0��δ���ʣ�1���ѷ��ʣ�


int search();//�ù����������Ŀ�������С����
void readdate();//��������
void init();//��ʼ��
struct cnode moveahead(struct cnode u);//����u��ǰ��һ��õ��Ľ��
int used(struct cnode v);//�жϸý���Ƿ��ǵ�����Ľ��
void addtoopen(struct cnode v);//����open�����
int islegal(struct cnode v);//�жϸý���Ƿ��ǺϷ��Ľ�㣨δԽ�����ǿո�
int isaim(struct cnode v);//�жϸý���Ƿ���Ŀ����
struct cnode takeoutofopen();//��open����ȡ��һ����㣬�����ýڵ���open����ɾ��
struct cnode turntoleft (struct cnode u);
struct cnode turntoright (struct cnode u);



int main()
{
	readdate();
	init();
	printf("���ֳ�������Ҫ%d����λʱ�䵽��Ŀ���㡣\n", search());
	return 0;
}
int search()//�ù����������Ŀ�������С����
{
	struct cnode u,v;
	while (head != tail)
	{
		u = takeoutofopen();
		v = moveahead(u);
		
		if (islegal(v))
		{
			if (isaim(v)) return (v.num);
			if (!used(v)) addtoopen(v);
		}
		v = turntoleft(u);//u����ת���õ��½��v
		if (!used(v))
		{
			addtoopen(v);
		}
		v = turntoright(u);//u����ת���õ��½��v
		if (!used(v))
		{
			addtoopen(v);
		}
	}
}
void readdate()//��������
{
	char str[400];
	printf("������20*20���Թ�״̬����.��ʾ�ո�X��ʾ���ϰ��\n");
	for (int i = 0; i < n; i++)
	{
		gets(str);
		for (int j = 0; j < n; j++)
		{
			if (str[j] == '.')  a[i][j] = 0;
			else a[i][j] = 1;
		}
	}
	printf("��������ʼ�����Ϣ���С��С���ɫ������\n");
	scanf("%d%d%d%d", &s.row, &s.col, &s.color, &s.direction);
	printf("������Ŀ������Ϣ���С��С���ɫ��\n");
	scanf("%d%d%d", &t.row, &t.col, &t.color);
}

void addtoopen(struct cnode v)
{
	open[tail++] = v;//��v����open[tail],tail++
	tail = tail % openlen;//������Ĳ��֣�����ԭ��������
	b[v.row][v.col][v.color][v.direction] = 1;//����b���� ��vλ���ϵ�״̬ Ϊ�ѵ���
}
void init()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				for (int l = 0; l < 4; l++)
				{
					b[i][j][k][l] = 0;
				}
			}
		}
	}
	head = 0;
	tail = 0;
	addtoopen(s);//����ʼ�����open��
}
struct cnode takeoutofopen()//��open����ȡ��һ����㣬�����ýڵ���open����ɾ��
{
	struct cnode u;
	u = open[head++];
	head = head % openlen;
	return u;
}
struct cnode moveahead(struct cnode u)//����u��ǰ��һ��õ��Ľ��
{
	struct cnode v;
	v.row = u.row + direct[u.direction][0];//����
	v.col = u.col + direct[u.direction][1];//����
	v.color = (u.color + 1) % 5;//��һ����ɫ
	v.direction = u.direction;//���򲻱�
	v.num = u.num + 1;//����+1������һ��
	return v;
}
int isaim(struct cnode v)//�жϸý���Ƿ���Ŀ����
{
	if (v.row == t.row && v.col == t.col && v.color == t.color)
		return 1;
	else return 0;
}
int islegal(struct cnode v)//�жϸý���Ƿ��ǺϷ��Ľ�㣨δԽ�����ǿո�
{
	if (v.row < 0 || v.row >= n || v.col < 0 || v.col >= n)//Խ����
		return 0;
	if (a[v.row][v.col] == 0)//���δԽ�����ǿո�
		return 1;
	return 0;
}
int used(struct cnode v)//�жϸý���Ƿ��ǵ�����Ľ��
{
	if (b[v.row][v.col][v.color][v.direction] == 0)
		return 0;
	else return 1;
}
struct cnode turntoleft(struct cnode u)
{
	struct cnode v = u;
	v.direction = (v.direction + 1) % 4;
	v.num = v.num + 1;
	return v;
}
struct cnode turntoright(struct cnode u) 
{
	struct cnode v = u;
	v.direction = (v.direction + 3) % 4;
	v.num = v.num + 1;
	return v;
}
















