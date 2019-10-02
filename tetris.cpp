#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
int fail=0;
void do_T1(int** tetris,int*peakincol,int ref_point)
{
    if(peakincol[ref_point]<peakincol[ref_point+1]&&peakincol[ref_point]<peakincol[ref_point+2])
    {
        if(peakincol[ref_point]>=0)
        {   tetris[peakincol[ref_point]][ref_point]=1;
            tetris[peakincol[ref_point]][ref_point+1]=1;
            tetris[peakincol[ref_point]][ref_point+2]=1;
        }
        else fail=1;
        tetris[peakincol[ref_point]+1][ref_point+1]=1;
        if(fail==1)return;
        peakincol[ref_point]-=1;
        peakincol[ref_point+1]=peakincol[ref_point];
        peakincol[ref_point+2]=peakincol[ref_point];

    }
    else if(peakincol[ref_point+1]<=peakincol[ref_point]&&peakincol[ref_point+1]<=peakincol[ref_point+2])
    {
        if(peakincol[ref_point+1]-1>=0)
        {   tetris[peakincol[ref_point+1]-1][ref_point]=1;
            tetris[peakincol[ref_point+1]-1][ref_point+1]=1;
            tetris[peakincol[ref_point+1]-1][ref_point+2]=1;
        }
        else fail=1;
        tetris[peakincol[ref_point+1]][ref_point+1]=1;
        if(fail==1)return;
        peakincol[ref_point+1]-=2;
        peakincol[ref_point]=peakincol[ref_point+1];
        peakincol[ref_point+2]=peakincol[ref_point+1];
    }
    else if(peakincol[ref_point+2]<peakincol[ref_point+1]&&peakincol[ref_point+2]<peakincol[ref_point])
    {
        if(peakincol[ref_point+2]>=0)
        {   tetris[peakincol[ref_point+2]][ref_point+2]=1;
            tetris[peakincol[ref_point+2]][ref_point+1]=1;
            tetris[peakincol[ref_point+2]][ref_point]=1;
        }
        else fail=1;
        tetris[peakincol[ref_point+2]+1][ref_point+1]=1;
        if(fail==1)return;
        peakincol[ref_point+2]-=1;
        peakincol[ref_point+1]=peakincol[ref_point+2];
        peakincol[ref_point]=peakincol[ref_point+2];
    }
}

int main()
{
    int m,n;
    int reference_point;
    ifstream fin("test.txt");
    fin>>m>>n;
    ofstream fout("final.txt");
    int tetris[m][n];
    int *arr[m];
    int peakincol[n];//每一行最高可以放的位置
    for(int i=0;i<n;i++)
    {
        peakincol[i]=m-1;
    }
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
    while(command[0]!='E'&&fail!=1)
    {
        fin>>reference_point;
        //to do
        if(command[0]=='T'&&command[1]=='1')
        {
            do_T1(arr,peakincol,reference_point-1);
        }
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
