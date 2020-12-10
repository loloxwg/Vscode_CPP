// 25 30 6 22 0 0 71 0 0 10 0 0 26 2 4 36 0 0 0 5 0 0 33 0 40 55 0 0 44 0 0
////错误代码：Time limit exceeded
/*BiTree CreatBiTree(BiTree r,int m)
{
    BiTree p,q,w;
        p = (BiTree)malloc(sizeof(BiTNode));
        p->rchild = NULL;
         p->lchild = NULL;
        p->data = m;
        q = r;
        while(q)   
        {
            if(m>q->data)
            {  w = q;
                q = q->rchild;
            }
            if(m<q->data)   //1：系统不运行：这个地方没加else，我以为只要在while里循环就行了，当q为空，直接跳出，
          {  w = q;        //巨巨找出错误，如果上一个if执行了，q变为空，么下一个ifm无法与q->data比较,所以错误
          q = q->lchild;  //2：只判断了大于小于，没判读等于，如果为等于号，那么一直在while里循环，所以造成time limit
 
            }
        }
        if(m>w->data)
            w->rchild = p;
        else
            w->lchild = p;
        return r;
 
 
    }
/*
Time limit  出现的原因：
很多时候我们看到Time Limit Exceeded马上会想到一定是算法太慢，不符合要求，其实往往还可能遇到一种情况是没有判断输入结束，不然
系统一直在那等你的输出结果，发现你一直不输出，或者程序一直不退出，所以给Time Limit Exceeded。
*/