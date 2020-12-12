#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct ArcCell
{
    int adj;				//相邻接
}ArcCell;

typedef struct VertexType
{
    int number;				//城市序号
    char *city;				//城市名称
}VertexType;				//定义顶点的类型

typedef struct
{
    VertexType  vex[25];				//图中的顶点，即为城市
    ArcCell		arcs[25][25];		//图中的边，即为城市间的距离
    int 		vexnum, arcnum;		//顶点数，边数
}MGragh;							//定义图的类型

MGragh G;			//把图定义为全局变量
int P[25][25];		//声明顶点（站点）
long int D[25];		//距离


//********************************************************************************

// Function 			:CreateUDN(int v, int a)
// Description			:造图函数
// Calls				:无
// Calls By				:无
// Table Accessed		：无
// Table Updated		：无
// Input				：intv，int a
// Output				：无
// return				：void
//Others				：无

//**********************************************************************************
void GreateUDN(int v, int a)		//造图函数
{
    int i ,j;
    G.vexnum = v;
    G.arcnum = a;
    for( i = 0; i < G.vexnum; ++i )
    {
        G.vex[i].number = i;
    }
    // 下边是设置城市的名称
    G.vex[0].city = "小什字";
    G.vex[1].city = "大剧院";
    G.vex[2].city = "上新街";
    G.vex[3].city = "刘家坪";
    G.vex[4].city = "长生桥";

    G.vex[5].city = "较场口";
    G.vex[6].city = "七星岗";
    G.vex[7].city = "临江门";
    G.vex[8].city = "黄花园";
    G.vex[9].city = "大溪沟";

    G.vex[10].city = "曾家岩";
    G.vex[11].city = "牛角沱";
    G.vex[12].city = "两路口";
    G.vex[13].city = "李子坝";
    G.vex[14].city = "佛图关";

    G.vex[15].city = "铜元局";
    G.vex[16].city = "工贸";
    G.vex[17].city = "南坪";
    G.vex[18].city = "四公里";
    G.vex[19].city = "五公里";

    G.vex[20].city = "华新街";
    G.vex[21].city = "观音桥";
    G.vex[22].city = "红旗河沟";
    G.vex[23].city = "花卉园";
    G.vex[24].city = "大龙山";

    //这里把所有的边假定为20000，含义是城市间不可到到达距离
    for(i = 0; i < G.vexnum; ++i)
        for(j = 0; j < G.vexnum; ++j)
            G.arcs[i][j].adj = 20000;

    //下边是可直接到达的城市间距离，由于两个城市间的距离是互相的，所以要对图中对称的边同时赋值
    G.arcs[0][2].adj = G.arcs[2][0].adj = 1;
    G.arcs[2][3].adj = G.arcs[3][2].adj = 1;
    G.arcs[3][4].adj = G.arcs[4][3].adj = 1;
    G.arcs[6][12].adj = G.arcs[12][6].adj = 1;

    G.arcs[0][5].adj = G.arcs[5][0].adj = 1;
    G.arcs[5][6].adj = G.arcs[6][5].adj = 1;
    G.arcs[5][7].adj = G.arcs[7][5].adj = 1;
    G.arcs[7][8].adj = G.arcs[8][7].adj = 1;
    G.arcs[8][9].adj = G.arcs[9][8].adj = 1;

    G.arcs[10][9].adj = G.arcs[9][10].adj = 1;
    G.arcs[10][11].adj = G.arcs[11][10].adj = 1;
    G.arcs[12][11].adj = G.arcs[11][12].adj = 1;
    G.arcs[13][11].adj = G.arcs[11][13].adj = 1;
    G.arcs[13][14].adj = G.arcs[14][13].adj = 1;

    G.arcs[12][15].adj = G.arcs[15][12].adj = 1;
    G.arcs[15][16].adj = G.arcs[16][15].adj = 1;
    G.arcs[16][17].adj = G.arcs[17][16].adj = 1;
    G.arcs[17][18].adj = G.arcs[18][17].adj = 1;
    G.arcs[18][19].adj = G.arcs[19][18].adj = 1;



    G.arcs[20][11].adj = G.arcs[11][20].adj = 1;
    G.arcs[20][21].adj = G.arcs[21][20].adj = 1;
    G.arcs[22][21].adj = G.arcs[21][22].adj = 1;
    G.arcs[23][22].adj = G.arcs[22][23].adj = 1;
    G.arcs[24][23].adj = G.arcs[23][24].adj = 1;



}


//********************************************************************************

// Function 			:narrate
// Description			:输出城市列表
// Calls				:无
// Calls By				:无
// Table Accessed		：无
// Table Updated		：无
// Input				：无
// Output				：无
// return				：void
//Others				：无

//**********************************************************************************
void narrate()
{
    int i, k;
    printf("\n***********欢迎使用最优交通图最短路径算法（模拟重庆轨道交通图）***********\n");
    printf("\n\t\t走不了多远的重庆交通枢纽中心\n\n");
    for(i = 0; i < 25; ++i)
    {
        printf( "(%2d)%-12s", i, G.vex[i].city );		//输出城市列表
        k = k + 1;									//k++
        if( k % 4 == 0 )
            printf("\n");
    }
}

//********************************************************************************

// Function 			:ShortestPath
// Description			:最短路径算法函数
// Calls				:无
// Calls By				:无
// Table Accessed		：无
// Table Updated		：无
// Input				：int num
// Output				：无
// return				：void
//Others				：无

//**********************************************************************************
void ShortestPath(int num)
{
    int v, w, i, t;
    int final[25];
    int min;
    for( v = 0; v < 25; ++v )
    {
        final[v] = 0;
        D[v] = G.arcs[num][v].adj;
        for(w = 0; w < 25; ++w)
        {
            P[v][w] = 0;
        }
        if(D[v] < 20000)
        {
            P[v][num] = 1;
            P[v][v] = 1;
        }
    }
    D[num] = 0;
    final[num] = 1;
    for( i = 0; i < 25; ++i )
    {
        min = 20000;
        for( w = 0; w < 25; ++w )
            if( !final[w] )
                if( D[w] < min )
                {
                    v=w;
                    min=D[w];
                }

        final[v] = 1;
        for( w = 0; w < 25; ++w)
            if( !final[w] && ( ( min+G.arcs[v][w].adj ) < D[w] ) )
            {
                D[w] = min + G.arcs[v][w].adj;
                for( t = 0; t < 25; ++t)
                    P[w][t] = P[v][t];
                P[w][w] = 1;
            }
    }
}

//********************************************************************************

// Function 			:ShortestPath
// Description			:输出函数
// Calls				:无
// Calls By				:无
// Table Accessed		：无
// Table Updated		：无
// Input				：int num
// Output				：无
// return				：void
//Others				：无

//**********************************************************************************
void output( int city1, int city2 )
{
    int a, b, c, d, q = 0;
    a = city2;
    if( a != city1 )
    {
        printf( "\n【%s】到【%s】的最短路径是：",G.vex[city1].city, G.vex[city2].city );
        printf("【最短经过%d站】\n\t", D[a]);
        printf("%s", G.vex[city1].city);
        d = city1;
        for(c = 0; c < 25; ++c)
        {
            gate:
            P[a][city1] = 0;
            for( b = 0; b < 25; b++)
            {
                if(G.arcs[d][b].adj < 20000 && P[a][b])
                {
                    printf("-->%s",G.vex[b].city);
                    q = q + 1;
                    P[a][b] = 0;
                    d = b;
                    if(a%8 == 8)
                        printf("\n");
                    goto gate;
                }
            }
        }
    }
}

int main()
{
    while(1)
    {
        int v0, v1;
        GreateUDN(25,23);
        narrate();
        printf("\n\n请选择起点站（0-24）：\n");
        scanf("%d", &v0);
        printf("请选择终点站（0-24）：\n");
        scanf("%d", &v1);
        ShortestPath(v0);				//计算两个城市之间的最短路径
        output(v0, v1);					//输出结果
        printf("\n\n");
    }
    return 0;
}