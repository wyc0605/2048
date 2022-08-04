#include <bits/stdc++.h>
#include <termio.h>
using namespace std;
int mp[10][10],np[10][10];
int scanKeyboard()
{
    int in;
    struct termios new_settings;
    struct termios stored_settings;
    tcgetattr(0,&stored_settings);
    new_settings=stored_settings;
    new_settings.c_lflag&=(~ICANON);
    new_settings.c_cc[VTIME]=0;
    tcgetattr(0,&stored_settings);
    new_settings.c_cc[VMIN]=1;
    tcsetattr(0,TCSANOW,&new_settings);
    in=getchar();
    tcsetattr(0,TCSANOW,&stored_settings);
    return in;
}
int suiji(int minn,int maxn)
{
	random_device seed;
	ranlux48 engine(seed());
	uniform_int_distribution<> distrib(minn, maxn);
    return(distrib(engine));
}
void p()
{
    system("clear");
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            cout<<setw(6)<<mp[i][j];
        }
        cout<<endl<<endl;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            if(mp[i][j]==2048)
            {
                cout<<"你赢了！"<<endl;
                exit(0);
            }
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            if(!mp[i][j])
            {
                return;
            }
        }
    }
    cout<<"游戏结束！"<<endl;
    exit(0);
}
void w()
{
    int x=suiji(1,4);
    int y=suiji(1,4);
    while(mp[x][y])
    {
        x=suiji(1,4);
        y=suiji(1,4);
    }
    mp[x][y]=2;
}
void up()
{
    for(int i=2;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            if(mp[i-1][j]==0||mp[i-1][j]==mp[i][j])
            {
                mp[i-1][j]+=mp[i][j];
                mp[i][j]=0;
            }
        }
    }
}
void down()
{
    for(int i=3;i>=1;i--)
    {
        for(int j=1;j<=4;j++)
        {
            if(mp[i+1][j]==0||mp[i+1][j]==mp[i][j])
            {
                mp[i+1][j]+=mp[i][j];
                mp[i][j]=0;
            }
        }
    }
}
void right()
{
    for(int i=1;i<=4;i++)
    {
        for(int j=3;j>=1;j--)
        {
            if(mp[i][j+1]==0||mp[i][j+1]==mp[i][j])
            {
                mp[i][j+1]+=mp[i][j];
                mp[i][j]=0;
            }
        }
    }
}
void left()
{
    for(int i=1;i<=4;i++)
    {
        for(int j=2;j<=4;j++)
        {
            if(mp[i][j-1]==0||mp[i][j-1]==mp[i][j])
            {
                mp[i][j-1]+=mp[i][j];
                mp[i][j]=0;
            }
        }
    }
}
int main()
{
    mp[suiji(1,4)][suiji(1,4)]=2;
    w();
    while(true)
    {
        p();
        bool flag=false;
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
            {
                np[i][j]=mp[i][j];
            }
        }
        int a=scanKeyboard();
        if(a!=27)
        {
            continue;
        }
        int b=scanKeyboard();
        if(b!=91)
        {
            continue;
        }
        int c=scanKeyboard();
        if(c==65)
        {
            up();
        }
        else if(c==66)
        {
            down();
        }
        else if(c==67)
        {
            right();
        }
        else if(c==68)
        {
            left();
        }
        else
        {
            continue;
        }
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
            {
                if(mp[i][j]!=np[i][j])
                {
                    flag=true;
                }
            }
        }
        if(flag)
        {
            w();
        }
    }
    return 0;
}
