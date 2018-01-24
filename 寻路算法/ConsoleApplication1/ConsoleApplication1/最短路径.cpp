#include<iostream>
using namespace std;
typedef char VertexType;
typedef int	 EdgeType;
#define MAXVEX 100
#define INFINTY 65535
typedef int	Patharc[MAXVEX];
typedef int ShortPathTable[MAXVEX];

typedef struct  
{
	VertexType  vexs[MAXVEX];//顶点表
	EdgeType	arc[MAXVEX][MAXVEX];//邻接矩阵
	int numVertexes, numEdges;//当前的顶点数和边数
}MGraph;

void	ShortestPath_Dijkstra(MGraph G, int V0, Patharc *P, ShortPathTable *D)
{
	int v, w, k, min;
	int final[MAXVEX];

	for (v=0;v<G.numVertexes;v++)
	{
		final[v] = 0;
		(*D)[v] = G.arc[V0][v];
		(*P)[v] = 0;
	}
	(*D)[V0] = 0;
	final[V0] = 1;

	for (v=1;v<G.numVertexes;v++)
	{
		min = INFINTY;
		for (w=0;w<G.numVertexes;w++)
		{
			if (!final[w] && (*D)[w] < min)
			{
				k = w;
				min = (*D)[w];
			}
		}

		final[k] = 1;
		for (w=0;w<G.numVertexes;w++)
		{
			if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
			{
				(*D)[w] = min + G.arc[k][w];
				(*P)[w] = k;
			}
		}
	}
}

int  main()
{
	MGraph _g;
	_g.numVertexes = 9;
	_g.numEdges = 16;
	_g.vexs[0] = 'V0'; _g.vexs[1] = 'V1'; _g.vexs[2] = 'V2'; _g.vexs[3] = 'V3'; _g.vexs[4] = 'V4';
	_g.vexs[5] = 'V5'; _g.vexs[6] = 'V6'; _g.vexs[7] = 'V7'; _g.vexs[8] = 'V8';
	for (int i=0;i<9;i++)
	{
		for (int j = 0; j < 9; j++)
		{
			_g.arc[i][j] = INFINTY;
		}
	}
	_g.arc[0][0] = 0; _g.arc[0][1] = 1; _g.arc[0][2] = 5; _g.arc[1][0] = 1; _g.arc[1][1] = 0; _g.arc[1][2] = 3; _g.arc[1][3] = 7;
	_g.arc[1][4] = 5; _g.arc[2][0] = 5; _g.arc[2][1] = 3; _g.arc[2][2] = 0; _g.arc[2][4] = 1; _g.arc[2][5] = 7; _g.arc[3][1] = 5;
	_g.arc[3][3] = 0; _g.arc[3][4] = 2; _g.arc[3][6] = 2; _g.arc[4][1] = 5; _g.arc[4][2] = 1; _g.arc[4][3] = 2; _g.arc[4][4] = 0;
	_g.arc[4][5] = 3; _g.arc[4][6] = 6; _g.arc[4][7] = 9; _g.arc[5][2] = 7; _g.arc[5][4] = 3; _g.arc[5][5] = 0; _g.arc[5][7] = 5;
	_g.arc[6][3] = 3; _g.arc[6][4] = 6; _g.arc[6][6] = 0; _g.arc[6][7] = 2; _g.arc[6][8] = 7; _g.arc[7][4] = 9; _g.arc[7][5] = 5;
	_g.arc[7][6] = 2; _g.arc[7][7] = 0; _g.arc[7][8] = 4; _g.arc[8][6] = 7; _g.arc[8][7] = 4; _g.arc[8][8] = 0;

	Patharc _P;
	ShortPathTable _D;
	ShortestPath_Dijkstra(_g, 6, &_P, &_D);
	system("pause");
	return 0;
}