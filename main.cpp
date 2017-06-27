//
//  main.cpp
//  二叉树 哈夫曼树
//
//  Created by 董依萌 on 2017/6/27.
//  Copyright © 2017年 董依萌. All rights reserved.
//

/*---------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct BiTNode
{
    ElemType data;/*数据域*/
    struct BiTNode *lchild,*rchild; /*左、右孩子域*/
}BiTNode,*BiTree;/*定义二叉链表结点及结点指针类型*/
/*---------------------------------------------------------------------------------------------------*/
/*按先序建立二叉树的二叉链表。函数的返回值指向根结点*/
bool  CreateBiTree(BiTree &T)
{   char ch ;
    ch=getchar();
    if (ch=='#')
    {    T=NULL;  }
    else
    {  T=(BiTNode *)malloc(sizeof(BiTNode)) ;
        T->data=ch ;
        CreateBiTree(T->lchild) ;
        CreateBiTree(T->rchild) ;
    }
    return true;
}
/*---------------------------------------------------------------------------------------------------*/
/*二叉树中序遍历的非递归算法，T为指向根结点*/
void inorder(BiTree T)
{
    BiTree p,stack[20];
    int top=0;
    p=T;
    do{
        while(p){
            stack[top++]=p;
            p=p->lchild;
        }
        if(top!=-1){
            p=stack[--top];
            printf("%c",p->data);
            p=p->rchild;
        }
    }while(top!=0||p!=NULL);
    
    
    
}
/*---------------------------------------------------------------------------------------------------*/
/*二叉树先序遍历的递归算法，T为指向根结点*/
void  preorder(BiTree T)
{
    if(T){
        printf("%c",T->data);
        preorder(T->lchild);
        preorder(T->rchild);
    }
    
    
}
/*---------------------------------------------------------------------------------------------------*/
/*求以T为根的二叉树的叶子结点个数，T指向根结点，返回值为叶子结点个数*/
int countleaf(BiTree T)
{
    static int n=0;
    if(T){
        countleaf(T->lchild);
        countleaf(T->rchild);
        if(T->lchild==NULL&&T->rchild==NULL)
            n++;
    }
    
    return n;
}
/*---------------------------------------------------------------------------------------------------*/
int main()
{ BiTree T;
    int n;
    CreateBiTree(T);
    /*构建二叉树的二叉链表，输入字符序列为ABC##DE#G##F###，#表示空字符*/
    /*按先序遍历二叉树*/
    preorder(T);
    
    /*按中序遍历二叉树*/
    inorder(T);
    
    /*输出叶子个数*/
    n = countleaf(T);
    printf("%d\n",n);
    
    
}












