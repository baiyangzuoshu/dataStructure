#include<iostream>
using namespace std;
typedef	string TElemType;
typedef struct BiTNode
{
	TElemType data;
	struct  BiTNode	*lchild, *rchild;
}BiTNode,*BiTree;

void	PreOrderTraverse(BiTree T)
{
	if (nullptr == T)
		return;

	cout << T->data.c_str();
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

void	InOrderTraverse(BiTree T)
{
	if (nullptr == T)
		return;

	InOrderTraverse(T->lchild);
	cout << T->data.c_str();
	InOrderTraverse(T->rchild);
}

void	PostOrderTraverse(BiTree T)
{
	if (nullptr == T)
		return;

	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	cout << T->data.c_str();
}

void	printSpace(int _index)
{
	for (int i = 0; i < _index; i++)
	{
		cout << " ";
	}
}

void	printTree(BiTree T,string& _result)
{
	if (nullptr == T)
	{
		_result.append("▽");
		return;
	}
	
	_result.append(T->data);
	
	printTree(T->lchild,_result);
	
	printTree(T->rchild,_result);
	
}

int  main888()
{
	BiTNode tA, tB, tC, tD, tE, tF, tG, tH, tI;
	tA.data = "A"; tA.lchild = &tB; tA.rchild = &tC;
	tB.data = "B"; tB.lchild = &tD; tB.rchild = nullptr;
	tC.data = "C"; tC.lchild = &tE; tC.rchild = &tF;
	tD.data = "D"; tD.lchild = &tG; tD.rchild = &tH;
	tE.data = "E"; tE.lchild = nullptr; tE.rchild = &tI;
	tF.data = "F"; tF.lchild = nullptr; tF.rchild = nullptr;
	tG.data = "G"; tG.lchild = nullptr; tG.rchild = nullptr;
	tH.data = "H"; tH.lchild = nullptr; tH.rchild = nullptr;
	tI.data = "I"; tI.lchild = nullptr; tI.rchild = nullptr;

	string _result("");
	printTree(&tA, _result);
	cout << endl;
	cout << "result:" << _result.c_str() << endl;
	cout << "前置遍历:";
	PreOrderTraverse(&tA);
	cout << endl;
	cout << "中荀遍历:";
	InOrderTraverse(&tA);
	cout << endl;
	cout << "后序遍历:";
	PostOrderTraverse(&tA);
	cout << endl;
	system("pause");
	return 0;
}