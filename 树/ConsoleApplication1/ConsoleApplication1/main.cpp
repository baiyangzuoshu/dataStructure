#include<iostream>
using namespace std;

int  main()
{
	cout<<"hellowrold"<<endl;
	
	system("pause");
	return 0;
}
#if 0
树的基本概念
(1)特点：非线性结构，一个直接前驱，但可能有多个直接后继（1:n）
(2)根：根结点（没有前驱）；叶子：终端结点（没有后继）
(3)广义表 表示树 A(B(E(K,L),F),C(G),D(H(M),I,J))
树的存储问题
	顺序和链式存储
	转化为二叉树的原因。
二叉树的定义
	是n(n>=0)个结点的有限集合，由一个根结点以及两棵会不相交的、分别称为左子树和右子树的二叉树组成
二叉树的性质
（1）在二叉树的第i层上至多有2的(i-1)次幂个结点
（2）深度为k的二叉树至多有2的k次幂减1个结点
（3）对于任何一棵二叉树，若2度的结点树有n2个，则叶子树n0必定为n2+1
（4）对完全二叉树，若从上至下、从左至右编号，则编号为i的结点，其左孩子编号必为2i，其右孩子编号必为2i+1；
其双亲的编号必为i/2(i=1时为根除外)
完全二叉树
	第k-1层和满二叉树一样；最后一层的叶子靠左。
#endif