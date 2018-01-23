#include<iostream>
using namespace std;
#define MAX_TREE_SIZE 100
typedef	int TElemType;
typedef struct PTNode
{
	TElemType	data;
	int			parent;

}PTNode;

typedef struct  
{
	PTNode  nodes[MAX_TREE_SIZE];
	int		r, n;
}PTree;
//Ë«Ç×±íÊ¾·¨
int  main02()
{

	PTree	_tree;
	PTNode tA, tB, tC, tD, tE, tF, tG, tH, tI, tJ;
	tA.data = 1; tA.parent = -1; _tree.nodes[0] = tA; _tree.r = 0; _tree.n = 1;
	tB.data = 2; tB.parent = 0; _tree.nodes[1] = tB; _tree.n++;
	tC.data = 3; tC.parent = 0; _tree.nodes[2] = tC; _tree.n++;
	tD.data = 4; tD.parent = 1; _tree.nodes[3] = tD; _tree.n++;
	tE.data = 5; tE.parent = 2; _tree.nodes[4] = tE; _tree.n++;
	tF.data = 6; tF.parent = 2; _tree.nodes[5] = tF; _tree.n++;
	tG.data = 7; tG.parent = 3; _tree.nodes[6] = tG; _tree.n++;
	tH.data = 8; tH.parent = 3; _tree.nodes[7] = tH; _tree.n++;
	tI.data = 9; tI.parent = 3; _tree.nodes[8] = tI; _tree.n++;
	tJ.data = 10; tJ.parent = 4; _tree.nodes[9] = tJ; _tree.n++;

	for (int i = 0; i < _tree.n; i++)
	{
		cout <<"data:"<<_tree.nodes[i].data <<",parent:"<<_tree.nodes[i].parent<< endl;
	}
	cout<<"hellowrold"<<endl;
	
	system("pause");
	return 0;
}