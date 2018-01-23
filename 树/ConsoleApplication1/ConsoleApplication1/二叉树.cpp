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

int  main()
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

	cout << "前置遍历" << endl;
	PreOrderTraverse(&tA);
	cout << "中荀遍历" << endl;
	InOrderTraverse(&tA);
	cout << "后序遍历" << endl;
	PostOrderTraverse(&tA);
	system("pause");
	return 0;
}