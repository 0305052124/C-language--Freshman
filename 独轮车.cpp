#include<stdio.h>

struct cnode {
	int row;  //结点所在的行坐标
	int col;  //列坐标
	int color;   //颜色
	int direction; //方向
	int num;     //从起点到本结点的最小步数
};

struct cnode s;//start记录起始点信息
struct cnode t;//tail记录目标点信息
struct cnode open[200];//创建struct cnode类型的表
int head, tail, openlen = 200;//open表数据
int direct[4][2] = { {0,-1},{1,0},{0,1},{-1,0} };//向左，下，右，上四个方向转时，行列的增加值
int a[20][20];//记录迷宫状态
int n = 20;//n为迷宫边长
int b[20][20][5][4] ;//表示迷宫状态（0：未访问，1：已访问）


int search();//用广度搜索返回目标结点的最小步数
void readdate();//读入数据
void init();//初始化
struct cnode moveahead(struct cnode u);//返回u向前走一格得到的结点
int used(struct cnode v);//判断该结点是否是到达过的结点
void addtoopen(struct cnode v);//加入open表操作
int islegal(struct cnode v);//判断该结点是否是合法的结点（未越界且是空格）
int isaim(struct cnode v);//判断该结点是否是目标结点
struct cnode takeoutofopen();//从open表中取出一个结点，并将该节点在open表中删除
struct cnode turntoleft (struct cnode u);
struct cnode turntoright (struct cnode u);



int main()
{
	readdate();
	init();
	printf("独轮车最少需要%d个单位时间到达目标结点。\n", search());
	return 0;
}
int search()//用广度搜索返回目标结点的最小步数
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
		v = turntoleft(u);//u向左转，得到新结点v
		if (!used(v))
		{
			addtoopen(v);
		}
		v = turntoright(u);//u向右转，得到新结点v
		if (!used(v))
		{
			addtoopen(v);
		}
	}
}
void readdate()//读入数据
{
	char str[400];
	printf("请输入20*20的迷宫状态：（.表示空格，X表示有障碍物）\n");
	for (int i = 0; i < n; i++)
	{
		gets(str);
		for (int j = 0; j < n; j++)
		{
			if (str[j] == '.')  a[i][j] = 0;
			else a[i][j] = 1;
		}
	}
	printf("请输入起始结点信息（行、列、颜色、方向）\n");
	scanf("%d%d%d%d", &s.row, &s.col, &s.color, &s.direction);
	printf("请输入目标结点信息（行、列、颜色）\n");
	scanf("%d%d%d", &t.row, &t.col, &t.color);
}

void addtoopen(struct cnode v)
{
	open[tail++] = v;//把v放入open[tail],tail++
	tail = tail % openlen;//超出表的部分，更新原来的数据
	b[v.row][v.col][v.color][v.direction] = 1;//更新b数组 在v位置上的状态 为已到过
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
	addtoopen(s);//把起始点放入open表
}
struct cnode takeoutofopen()//从open表中取出一个结点，并将该节点在open表中删除
{
	struct cnode u;
	u = open[head++];
	head = head % openlen;
	return u;
}
struct cnode moveahead(struct cnode u)//返回u向前走一格得到的结点
{
	struct cnode v;
	v.row = u.row + direct[u.direction][0];//上下
	v.col = u.col + direct[u.direction][1];//左右
	v.color = (u.color + 1) % 5;//变一次颜色
	v.direction = u.direction;//方向不变
	v.num = u.num + 1;//步数+1，走了一步
	return v;
}
int isaim(struct cnode v)//判断该结点是否是目标结点
{
	if (v.row == t.row && v.col == t.col && v.color == t.color)
		return 1;
	else return 0;
}
int islegal(struct cnode v)//判断该结点是否是合法的结点（未越界且是空格）
{
	if (v.row < 0 || v.row >= n || v.col < 0 || v.col >= n)//越界了
		return 0;
	if (a[v.row][v.col] == 0)//结点未越界且是空格
		return 1;
	return 0;
}
int used(struct cnode v)//判断该结点是否是到达过的结点
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
















