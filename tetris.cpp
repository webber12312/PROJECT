#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int fail=0;
typedef struct
{
    int x;
    int y;
}Place;
class block{
    public:
    block(int type,int refer,int put)
    {
        if(type==1)
        {
            place[0].x=put;
            place[0].y=refer;
            place[1].x=put;
            place[1].y=refer+1;
            place[2].x=put;
            place[2].y=refer+2;
            place[3].x=put+1;
            place[3].y=refer+1;
        }
        else if(type==2)
        {
            place[0].x=put;
            place[0].y=refer;
            place[1].x=put;
            place[1].y=refer+1;
            place[2].x=put-1;
            place[2].y=refer+1;
            place[3].x=put+1;
            place[3].y=refer+1;
        }
        else if(type==3)
        {
            place[0].x=put;
            place[0].y=refer;
            place[1].x=put;
            place[1].y=refer+1;
            place[2].x=put;
            place[2].y=refer+2;
            place[3].x=put-1;
            place[3].y=refer+1;
        }
        else if(type==4)
        {
            place[0].x=put;
            place[0].y=refer;
            place[1].x=put-1;
            place[1].y=refer;
            place[2].x=put-2;
            place[2].y=refer;
            place[3].x=put-1;
            place[3].y=refer+1;
        }
        else if(type==5)
        {
            place[0].x=put;
            place[0].y=refer;
            place[1].x=put-1;
            place[1].y=refer;
            place[2].x=put-2;
            place[2].y=refer;
            place[3].x=put;
            place[3].y=refer+1;
        }
        else if(type==6)
        {
            place[0].x=put;
            place[0].y=refer;
            place[1].x=put-1;
            place[1].y=refer;
            place[2].x=put-1;
            place[2].y=refer+1;
            place[3].x=put-1;
            place[3].y=refer+2;
        }
        else if(type==7)
        {
            place[0].x=put;
            place[0].y=refer;
            place[1].x=put;
            place[1].y=refer+1;
            place[2].x=put+1;
            place[2].y=refer+1;
            place[3].x=put+2;
            place[3].y=refer+1;
        }
        else if(type==8)
        {
            place[0].x=put;
            place[0].y=refer;
            place[1].x=put;
            place[1].y=refer+1;
            place[2].x=put;
            place[2].y=refer+2;
            place[3].x=put-1;
            place[3].y=refer+2;
        }
        else if(type==9)
        {
            place[0].x=put;
            place[0].y=refer;
            place[1].x=put;
            place[1].y=refer+1;
            place[2].x=put-1;
            place[2].y=refer+1;
            place[3].x=put-2;
            place[3].y=refer+1;
        }
        else if(type==10)
        {
            place[0].x=put;
            place[0].y=refer;
            place[1].x=put-1;
            place[1].y=refer;
            place[2].x=put;
            place[2].y=refer+1;
            place[3].x=put;
            place[3].y=refer+2;
        }
        else if(type==11)
        {
            place[0].x=put;
            place[0].y=refer;
            place[1].x=put-1;
            place[1].y=refer;
            place[2].x=put-2;
            place[2].y=refer;
            place[3].x=put-2;
            place[3].y=refer+1;
        }
        else if(type==12)
        {
            place[0].x=put;
            place[0].y=refer;
            place[1].x=put;
            place[1].y=refer+1;
            place[2].x=put;
            place[2].y=refer+2;
            place[3].x=put+1;
            place[3].y=refer+2;
        }
        else if(type==13)
        {
            place[0].x=put;
            place[0].y=refer;
            place[1].x=put;
            place[1].y=refer+1;
            place[2].x=put-1;
            place[2].y=refer+1;
            place[3].x=put-1;
            place[3].y=refer+2;
        }
        else if(type==14)
        {
            place[0].x=put;
            place[0].y=refer;
            place[1].x=put-1;
            place[1].y=refer;
            place[2].x=put;
            place[2].y=refer+1;
            place[3].x=put+1;
            place[3].y=refer+1;
        }
        else if(type==15)
        {
            place[0].x=put;
            place[0].y=refer;
            place[1].x=put;
            place[1].y=refer+1;
            place[2].x=put+1;
            place[2].y=refer+1;
            place[3].x=put+1;
            place[3].y=refer+2;
        }
        else if(type==16)
        {
            place[0].x=put;
            place[0].y=refer;
            place[1].x=put-1;
            place[1].y=refer;
            place[2].x=put-1;
            place[2].y=refer+1;
            place[3].x=put-2;
            place[3].y=refer+1;
        }
        else if(type==17)
        {
            place[0].x=put;
            place[0].y=refer;
            place[1].x=put-1;
            place[1].y=refer;
            place[2].x=put-2;
            place[2].y=refer;
            place[3].x=put-3;
            place[3].y=refer;
        }
        else if(type==18)
        {
            place[0].x=put;
            place[0].y=refer;
            place[1].x=put;
            place[1].y=refer+1;
            place[2].x=put;
            place[2].y=refer+2;
            place[3].x=put;
            place[3].y=refer+3;
        }
        else if(type==19)
        {
            place[0].x=put;
            place[0].y=refer;
            place[1].x=put-1;
            place[1].y=refer;
            place[2].x=put;
            place[2].y=refer+1;
            place[3].x=put-1;
            place[3].y=refer+1;
        }
    }
    int getplace_x(int i)
    {
        return place[i].x;
    }
    int getplace_y(int i)
    {
        return place[i].y;
    }
    private:
    Place place[4];
};

void setmap(int**tetris,block b)
{
    for(int i=0;i<4;i++)
    {
        if(b.getplace_x(i)>=0)
        {
            tetris[b.getplace_x(i)][b.getplace_y(i)]=1;
        }
        else fail=1;
    }
}

void clearmap(int**tetris)
{
    int del=1;
    for(int i=m-1;i>=0;i--)
    {
        for(j=0;j<n;j++)
        {
            if(tetris[i][j]==0)
            {
                del=0;
                break;
            }
        }
        if(del==1)
        {
            for(int k=i;k>=0;k--)
            {
                for(int j=0;j<n;j++)
                {
                    tetris[k][j]=tetris[k-1][j];
                }
            }
            i++;
        }
        del=1;
    }
}

int main()
{
    int m,n,type,put;
    int ref_pt;
    ifstream fin("test.txt");
    ofstream fout("final.txt");
    fin>>m>>n;
    int tetris[m][n];
    int* arr[m];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            tetris[i][j]=0;
        }
    }
    for(int i=0;i<m;i++)
    {
        arr[i]=tetris[i];
    }
    char command[4];
    fin>>command;
    while(command[0]!='E')
    {
        fin>>ref_pt;
        ref_pt--;
        if(command[0]=='T'&&command[1]=='1')
        {
            type=1;
            for(int i=0;i<m;i++)
            {
                if(tetris[i][ref_pt+1]==1)
                {put=i-2;
                 break;
                }
                else if(tetris[i][ref_pt]==1)
                {put=i-1;
                 break;
                }
                else if(tetris[i][ref_pt+2]==1)
                {put=i-1;
                 break;
                }
                else put=m-2;
            }
        }
        else if(command[0]=='T'&&command[1]=='2')
        {
            type=2;
            for(int i=0;i<m;i++)
            {
                if(tetris[i][ref_pt+1]==1)
                {put=i-2;
                 break;
                }
                else if(tetris[i][ref_pt]==1)
                {put=i-1;
                 break;
                }
                else put=m-2;
            }
        }
        else if(command[0]=='T'&&command[1]=='3')
        {
            type=3;
            for(int i=0;i<m;i++)
            {
                if(tetris[i][ref_pt+1]==1)
                {put=i-1;
                 break;
                }
                else if(tetris[i][ref_pt]==1)
                {put=i-1;
                 break;
                }
                else if(tetris[i][ref_pt+2]==1)
                {put=i-1;
                 break;
                }
                else put=m-1;
            }
        }
        else if(command[0]=='T'&&command[1]=='4')
        {
            type=4;
            for(int i=0;i<m;i++)
            {
                if(tetris[i][ref_pt+1]==1)
                {put=i;
                 break;
                }
                else if(tetris[i][ref_pt]==1)
                {put=i-1;
                 break;
                }
                else put=m-1;
            }
        }
        else if(command[0]=='L'&&command[1]=='1')
        {
            type=5;
            for(int i=0;i<m;i++)
            {
                if(tetris[i][ref_pt+1]==1)
                {put=i-1;
                 break;
                }
                else if(tetris[i][ref_pt]==1)
                {put=i-1;
                 break;
                }
                else put=m-1;
            }
        }
        else if(command[0]=='L'&&command[1]=='2')
        {
            type=6;
            for(int i=0;i<m;i++)
            {
                if(tetris[i][ref_pt+1]==1)
                {put=i;
                 break;
                }
                else if(tetris[i][ref_pt]==1)
                {put=i-1;
                 break;
                }
                else if(tetris[i][ref_pt+2]==1)
                {put=i;
                 break;
                }
                else put=m-1;
            }
        }
        else if(command[0]=='L'&&command[1]=='3')
        {
            type=7;
            for(int i=0;i<m;i++)
            {
                if(tetris[i][ref_pt+1]==1)
                {put=i-3;
                 break;
                }
                else if(tetris[i][ref_pt]==1)
                {put=i-1;
                 break;
                }
                else put=m-3;
            }
        }
        else if(command[0]=='L'&&command[1]=='4')
        {
            type=8;
            for(int i=0;i<m;i++)
            {
                if(tetris[i][ref_pt+1]==1)
                {put=i-1;
                 break;
                }
                else if(tetris[i][ref_pt]==1)
                {put=i-1;
                 break;
                }
                else if(tetris[i][ref_pt+2]==1)
                {put=i-1;
                 break;
                }
                else put=m-1;
            }
        }
        else if(command[0]=='J'&&command[1]=='1')
        {
            type=9;
            for(int i=0;i<m;i++)
            {
                if(tetris[i][ref_pt+1]==1)
                {put=i-1;
                 break;
                }
                else if(tetris[i][ref_pt]==1)
                {put=i-1;
                 break;
                }
                else put=m-1;
            }
        }
        else if(command[0]=='J'&&command[1]=='2')
        {
            type=10;
            for(int i=0;i<m;i++)
            {
                if(tetris[i][ref_pt+1]==1)
                {put=i-1;
                 break;
                }
                else if(tetris[i][ref_pt]==1)
                {put=i-1;
                 break;
                }
                else if(tetris[i][ref_pt+2]==1)
                {put=i-1;
                 break;
                }
                else put=m-1;
            }
        }
        else if(command[0]=='J'&&command[1]=='3')
        {
            type=11;
            for(int i=0;i<m;i++)
            {
                if(tetris[i][ref_pt+1]==1)
                {put=i+1;
                 break;
                }
                else if(tetris[i][ref_pt]==1)
                {put=i-1;
                 break;
                }
                else put=m-1;
            }
        }
        else if(command[0]=='J'&&command[1]=='4')
        {
            type=12;
            for(int i=0;i<m;i++)
            {
                if(tetris[i][ref_pt+1]==1)
                {put=i-1;
                 break;
                }
                else if(tetris[i][ref_pt]==1)
                {put=i-1;
                 break;
                }
                else if(tetris[i][ref_pt+2]==1)
                {put=i-2;
                 break;
                }
                else put=m-2;
            }
        }
        else if(command[0]=='S'&&command[1]=='1')
        {
            type=13;
            for(int i=0;i<m;i++)
            {
                if(tetris[i][ref_pt+1]==1)
                {put=i-1;
                 break;
                }
                else if(tetris[i][ref_pt]==1)
                {put=i-1;
                 break;
                }
                else if(tetris[i][ref_pt+2]==1)
                {put=i;
                 break;
                }
                else put=m-1;
            }
        }
        else if(command[0]=='S'&&command[1]=='2')
        {
            type=14;
            for(int i=0;i<m;i++)
            {
                if(tetris[i][ref_pt+1]==1)
                {put=i-2;
                 break;
                }
                else if(tetris[i][ref_pt]==1)
                {put=i-1;
                 break;
                }
                else put=m-2;
            }
        }
        else if(command[0]=='Z'&&command[1]=='1')
        {
            type=15;
            for(int i=0;i<m;i++)
            {
                if(tetris[i][ref_pt+1]==1)
                {put=i-2;
                 break;
                }
                else if(tetris[i][ref_pt]==1)
                {put=i-1;
                 break;
                }
                else if(tetris[i][ref_pt+2]==1)
                {put=i-2;
                 break;
                }
                else put=m-2;
            }
        }
        else if(command[0]=='Z'&&command[1]=='2')
        {
            type=16;
            for(int i=0;i<m;i++)
            {
                if(tetris[i][ref_pt+1]==1)
                {put=i;
                 break;
                }
                else if(tetris[i][ref_pt]==1)
                {put=i-1;
                 break;
                }
                else put=m-1;
            }
        }
        else if(command[0]=='I'&&command[1]=='1')
        {
            type=17;
            for(int i=0;i<m;i++)
            {
                if(tetris[i][ref_pt]==1)
                {put=i-1;
                 break;
                }
                else put=m-1;
            }
        }
        else if(command[0]=='I'&&command[1]=='2')
        {
            type=18;
            for(int i=0;i<m;i++)
            {
                if(tetris[i][ref_pt]==1)
                {put=i-1;
                 break;
                }
                if(tetris[i][ref_pt+1]==1)
                {put=i-1;
                 break;
                }
                if(tetris[i][ref_pt+2]==1)
                {put=i-1;
                 break;
                }
                if(tetris[i][ref_pt+3]==1)
                {put=i-1;
                 break;
                }
                else put=m-1;
            }
        }
        else if(command[0]=='O')
        {
            type=19;
            for(int i=0;i<m;i++)
            {
                if(tetris[i][ref_pt]==1)
                {put=i-1;
                 break;
                }
                if(tetris[i][ref_pt+1]==1)
                {put=i-1;
                 break;
                }
                else put=m-1;
            }
        }
        block b(type,ref_pt,put);
        setmap(arr,b);
        if(fail==1)break;
        memset(command,0,sizeof(command));
        fin>>command;
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            fout<<tetris[i][j];
        }
        fout<<endl;
    }
}
