#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
int fail=0;
int m,n;



void release(int** tetris)
{
    int del=1;
    for(int i=m-1;i>=0;i--)
    {
        del=1;
        for(int j=0;j<n;j++)
        {
            if(tetris[i][j]==0)
            {
                del=0;
                break;
            }
        }
        if(del==1)
        {
            for(int k=i;k>=1;k--)
            {
                for(int j=0;j<n;j++)
                {
                    tetris[k][j]=tetris[k-1][j];
                }
            }
            for(int j=0;j<n;j++)
            {
                tetris[0][j]=0;
            }
        }
    }
}


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
        if(peakincol[ref_point]+1>=0)tetris[peakincol[ref_point]+1][ref_point+1]=1;
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
        if(peakincol[ref_point+1]>=0)tetris[peakincol[ref_point+1]][ref_point+1]=1;
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
        if(peakincol[ref_point+2]+1>=0)tetris[peakincol[ref_point+2]+1][ref_point+1]=1;
        if(fail==1)return;
        peakincol[ref_point+2]-=1;
        peakincol[ref_point+1]=peakincol[ref_point+2];
        peakincol[ref_point]=peakincol[ref_point+2];
    }
}


void do_T2(int** tetris,int*peakincol,int ref_point)
{
    if(peakincol[ref_point]<peakincol[ref_point+1])
    {
        if(peakincol[ref_point]>=0)
        {
            tetris[peakincol[ref_point]][ref_point]=1;
            tetris[peakincol[ref_point]][ref_point+1]=1;
        }
        else fail=1;
        if(peakincol[ref_point]-1>=0)
        tetris[peakincol[ref_point]-1][ref_point+1]=1;
        else fail=1;
        if(peakincol[ref_point]+1>=0)
        tetris[peakincol[ref_point]+1][ref_point+1]=1;
        else fail=1;
        if(fail==1)return;
        peakincol[ref_point]-=1;
        peakincol[ref_point+1]=peakincol[ref_point]-1;
    }
    else if(peakincol[ref_point+1]<=peakincol[ref_point])
    {
        if(peakincol[ref_point+1]>=0)
        tetris[peakincol[ref_point+1]][ref_point+1]=1;
        else fail=1;
        if(peakincol[ref_point+1]-1>=0)
        {
            tetris[peakincol[ref_point+1]-1][ref_point+1]=1;
            tetris[peakincol[ref_point+1]-1][ref_point]=1;
        }
        else fail=1;
        if(peakincol[ref_point+1]-2>=0)
        tetris[peakincol[ref_point+1]-2][ref_point+1]=1;
        else fail=1;
        if(fail==1)return;
        peakincol[ref_point]=peakincol[ref_point+1]-2;
        peakincol[ref_point+1]-=3;
    }
}



int main()
{
    int reference_point;
    ifstream fin("test.txt");
    fin>>m>>n;
    ofstream fout("final.txt");
    int tetris[m][n];
    int *arr[m];
    int peakincol[n];//�C�@��̰��i�H�񪺦�m
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
            release(arr);
        }
        else if(command[0]=='T'&&command[1]=='2')
        {
            do_T2(arr,peakincol,reference_point-1);
            release(arr);
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
