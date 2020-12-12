#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct ArcCell
{
    int adj;				//���ڽ�
}ArcCell;

typedef struct VertexType
{
    int number;				//�������
    char *city;				//��������
}VertexType;				//���嶥�������

typedef struct
{
    VertexType  vex[25];				//ͼ�еĶ��㣬��Ϊ����
    ArcCell		arcs[25][25];		//ͼ�еıߣ���Ϊ���м�ľ���
    int 		vexnum, arcnum;		//������������
}MGragh;							//����ͼ������

MGragh G;			//��ͼ����Ϊȫ�ֱ���
int P[25][25];		//�������㣨վ�㣩
long int D[25];		//����


//********************************************************************************

// Function 			:CreateUDN(int v, int a)
// Description			:��ͼ����
// Calls				:��
// Calls By				:��
// Table Accessed		����
// Table Updated		����
// Input				��intv��int a
// Output				����
// return				��void
//Others				����

//**********************************************************************************
void GreateUDN(int v, int a)		//��ͼ����
{
    int i ,j;
    G.vexnum = v;
    G.arcnum = a;
    for( i = 0; i < G.vexnum; ++i )
    {
        G.vex[i].number = i;
    }
    // �±������ó��е�����
    G.vex[0].city = "Сʲ��";
    G.vex[1].city = "���Ժ";
    G.vex[2].city = "���½�";
    G.vex[3].city = "����ƺ";
    G.vex[4].city = "������";

    G.vex[5].city = "�ϳ���";
    G.vex[6].city = "���Ǹ�";
    G.vex[7].city = "�ٽ���";
    G.vex[8].city = "�ƻ�԰";
    G.vex[9].city = "��Ϫ��";

    G.vex[10].city = "������";
    G.vex[11].city = "ţ����";
    G.vex[12].city = "��·��";
    G.vex[13].city = "���Ӱ�";
    G.vex[14].city = "��ͼ��";

    G.vex[15].city = "ͭԪ��";
    G.vex[16].city = "��ó";
    G.vex[17].city = "��ƺ";
    G.vex[18].city = "�Ĺ���";
    G.vex[19].city = "�幫��";

    G.vex[20].city = "���½�";
    G.vex[21].city = "������";
    G.vex[22].city = "����ӹ�";
    G.vex[23].city = "����԰";
    G.vex[24].city = "����ɽ";

    //��������еı߼ٶ�Ϊ20000�������ǳ��м䲻�ɵ��������
    for(i = 0; i < G.vexnum; ++i)
        for(j = 0; j < G.vexnum; ++j)
            G.arcs[i][j].adj = 20000;

    //�±��ǿ�ֱ�ӵ���ĳ��м���룬�����������м�ľ����ǻ���ģ�����Ҫ��ͼ�жԳƵı�ͬʱ��ֵ
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
// Description			:��������б�
// Calls				:��
// Calls By				:��
// Table Accessed		����
// Table Updated		����
// Input				����
// Output				����
// return				��void
//Others				����

//**********************************************************************************
void narrate()
{
    int i, k;
    printf("\n***********��ӭʹ�����Ž�ͨͼ���·���㷨��ģ����������ͨͼ��***********\n");
    printf("\n\t\t�߲��˶�Զ�����콻ͨ��Ŧ����\n\n");
    for(i = 0; i < 25; ++i)
    {
        printf( "(%2d)%-12s", i, G.vex[i].city );		//��������б�
        k = k + 1;									//k++
        if( k % 4 == 0 )
            printf("\n");
    }
}

//********************************************************************************

// Function 			:ShortestPath
// Description			:���·���㷨����
// Calls				:��
// Calls By				:��
// Table Accessed		����
// Table Updated		����
// Input				��int num
// Output				����
// return				��void
//Others				����

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
// Description			:�������
// Calls				:��
// Calls By				:��
// Table Accessed		����
// Table Updated		����
// Input				��int num
// Output				����
// return				��void
//Others				����

//**********************************************************************************
void output( int city1, int city2 )
{
    int a, b, c, d, q = 0;
    a = city2;
    if( a != city1 )
    {
        printf( "\n��%s������%s�������·���ǣ�",G.vex[city1].city, G.vex[city2].city );
        printf("����̾���%dվ��\n\t", D[a]);
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
        printf("\n\n��ѡ�����վ��0-24����\n");
        scanf("%d", &v0);
        printf("��ѡ���յ�վ��0-24����\n");
        scanf("%d", &v1);
        ShortestPath(v0);				//������������֮������·��
        output(v0, v1);					//������
        printf("\n\n");
    }
    return 0;
}