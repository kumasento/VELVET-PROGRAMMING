#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
struct DD
{
    int x,y; 
}dData[1003];
bool operator<(const DD& lhs, const DD& rhs)
{
        if( lhs.x == rhs.x)
            return lhs.y < rhs.y;
        else return lhs.x < rhs.x;
}
set<DD>ss;
__inline DD lCircle(DD* dd)//逆时针旋转 
{
    DD d;
    d.x = 0 - dd->y;
    d.y = dd->x;
    return d;
}
__inline DD rCircle(DD* dd)//顺时针旋转 
{
    DD d;
    d.x = dd->y;
    d.y = 0 - dd->x;
    return d;
}
void print(int x,int y)
{
    printf("%d %d\n",x,y);
}
__inline bool opV(DD& d)//判断向量是不是向上或向左 
{ 
    if(d.x > 0)
        return true;
    else if(d.x == 0)
        return d.y>0;
    else return false;
}
void findSqr(int n)//找正方形 
{
    DD d,d2,d3,td;
    int cont=0;
    int ti,tj;
    for(int i = 0;i < n;i++)
    {
        for(int j = i + 1;j < n;j++)
        {
            d.x = dData[j].x - dData[i].x;
            d.y = dData[j].y - dData[i].y;
            ti = i;
            tj = j;
            if(!opV(d))
            {
                d.x = dData[i].x - dData[j].x;
                d.y = dData[i].y - dData[j].y;
                ti = j;
                tj = i;
            }
            if(!opV(d))
                continue;
            td = d;

                d2=lCircle(&d);
                d2.x = d2.x + dData[ti].x;
                d2.y = d2.y + dData[ti].y;

                d.x = -td.x;
                d.y = -td.y;
            
                d3 = rCircle(&d);
                d3.x = d3.x + dData[tj].x;
                d3.y = d3.y + dData[tj].y;

                if(ss.find(d2) != ss.end() && ss.find(d3) != ss.end())//上三角 
                {
                    cont++;
                }
            

        }
    }
    cout<<cont/2<<endl;
    return ;
}
int main()
{
    int n;
    int x,y;
    DD tmp;
    while(scanf("%d",&n)!=EOF)
    {
        if(n == 0)
            break;
        ss.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&dData[i].x,&dData[i].y);
            ss.insert(dData[i]);
        }
        findSqr(n);
    }
    return 0;
}