/*
BFS
*/ 
#include<cstdio>  
#include<cstring>  
#include<queue>  
#include<algorithm>  
using namespace std;  
const int maxn=100;  
bool vst[maxn][maxn]; // ���ʱ��  
int dir[4][2]={0,1,0,-1,1,0,-1,0}; // ��������  
  
struct State // BFS �����е�״̬���ݽṹ  
{  
    int x,y; // ����λ��  
    int Step_Counter; // ��������ͳ����  
};  
  
State a[maxn];  
  
boolCheckState(State s) // Լ����������  
{  
    if(!vst[s.x][s.y] && ...) // ��������         
        return 1;  
    else // Լ��������ͻ  
    return 0;  
}  
  
void bfs(State st)  
{  
    queue <State> q; // BFS ����  
    State now,next; // ����2 ��״̬����ǰ����һ��  
    st.Step_Counter=0; // ����������  
    q.push(st); // ���     
    vst[st.x][st.y]=1; // ���ʱ��  
    while(!q.empty())  
    {  
        now=q.front(); // ȡ����Ԫ�ؽ�����չ  
        if(now==G) // ����Ŀ��̬����ʱΪStep_Counter ����Сֵ�������˳�����  
        {  
            ...... // ����ش���  
            return;  
        }  
    for(int i=0;i<4;i++)  
    {  
        next.x=now.x+dir[i][0]; // ���չ�������   ��һ��״̬  
        next.y=now.y+dir[i][1];  
        next.Step_Counter=now.Step_Counter+1; // ��������1  
        if(CheckState(next)) // ���״̬����Լ�����������  
        {  
            q.push(next);  
            vst[next.x][next.y]=1; //���ʱ��  
        }  
    }  
    q.pop(); // ����Ԫ�س���  
    }  
 return;  
}  
  
int main()  
{  
......  
 return 0;  
}  
