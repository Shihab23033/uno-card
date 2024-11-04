#include<bits/stdc++.h>
#include <windows.h>
//colors
#define color_red "\x1b[31m"
#define color_green "\x1b[32m"
#define color_yellow "\x1b[33m"
#define color_blue "\x1b[34m"
#define color_reset "\x1b[0m"
using namespace std;

vector<string> cards= {"R0","R1","R2","R3","R4","R5","R6","R7","R8","R9","G0"
,"G1","G2","G3","G4","G5","G6","G7","G8","G9","B0","B1","B2","B3","B4","B5","B6"
,"B7","B8","B9","Y0","Y1","Y2","Y3","Y4","Y5","Y6","Y7","Y8","Y9","R0","R1","R2"
,"R3","R4","R5","R6","R7","R8","R9","G0","G1","G2","G3","G4","G5","G6","G7","G8"
,"G9","B0","B1","B2","B3","B4","B5","B6","B7","B8","B9","Y0","Y1","Y2","Y3","Y4"
,"Y5","Y6","Y7","Y8","Y9","R2+","Rrev","Rstp","G2+","Grev","Gstp","B2+","Brev"
,"Bstp","Y2+","Yrev","Ystp","R2+","Rrev","Rstp","G2+","Grev","Gstp","B2+","Brev"
,"Bstp","Y2+","Yrev","Ystp","S4+","S4+","S4+","S4+","S4+","Scol","Scol","Scol","Scol","Scol" };
int turn=0,panishment=0;

struct player
{
    int player_id;
    vector<string> card;
};
struct player person[4];

//functions
void color_print(string str)
{
    char clr= str[0];
    char text[4];
    int i;
    for(i=1; str[i]!=0; i++)
        text[i-1]=str[i];
    text[i-1]=0;
    switch(clr)
    {
    case 'Y':
        printf(color_yellow" |%s|",text);
        break;
    case 'R':
        printf(color_red" |%s|",text);
        break;
    case 'B':
        printf(color_blue" |%s|",text);
        break;
    case 'G':
        printf(color_green" |%s|",text);
        break;
    case 'S':
        printf(color_reset" |%s|",text);
        break;
    }
    printf(color_reset);
}

void turn_decesion(int x)
{
    if(x)
        turn++;
    else turn--;
    if(turn==4)
        turn=0;
    else if(turn==-1)
        turn=3;
}
void shaffle(int item)
{
    string first_half[item/2],last_half[item/2];
    int i;
    for(i=0; i<item/2; i++)
    {
        first_half[i]=cards[i];
        last_half[i]=cards[i+item/2];
    }
    i=0;
    for(int j=0; i<item; j++)
    {
        cards[i++]=last_half[j];
        cards[i++]=first_half[j];
    }

}
void display( queue<string> q)
{
    queue<string> qu=q;
    while(! qu.empty())
    {
        color_print(qu.front());
        qu.pop();
    }
    cout<<endl;
}
int bot_decesion(int x,char key,string txt)
{
    int i,flag=0;
    if(panishment==1)
        goto colr;
    if(txt=="2+")
    {
        for (i=0; i<person[x].card.size(); i++)
        {
            string str;
            str=person[x].card[i];
            str.erase(str.begin());
            if(str=="2+"||str=="4+")
            {
                flag =1;
                break;
            }
        }
        if(flag) return i;
        else return -1;
    }
    else if(txt=="4+")
    {
        for (i=0; i<person[x].card.size(); i++)
        {
            string str;
            str=person[x].card[i];
            str.erase(str.begin());
            if(str=="4+")
            {
                flag =1;
                break;
            }
        }
        if(flag) return i;
        else return -1;
    }
    else if(txt=="col")
    {
        for (i=0; i<person[x].card.size(); i++)
        {
            if(person[x].card[i][0]==key)
            {
                flag=1;
                break;
            }
        }
        if(flag) return i;
    }
    else
    {
colr:
        for (i=0; i<person[x].card.size(); i++)
        {
            if(person[x].card[i][0]==key)
            {
                flag=1;
                break;
            }
        }
        if(flag) return i;
        for (i=0; i<person[x].card.size(); i++)
        {
            int j;
            string str="hhhh";
            str=person[x].card[i];
            str.erase(str.begin());
            if(txt==str)
            {
                flag =1;
                break;
            }

        }
        if(flag) return i;
        for (i=0; i<person[x].card.size(); i++)
        {
            if(person[x].card[i][0]=='S')
            {
                flag =1;
                break;
            }
        }
        if(flag) return i;
    }
    if(flag==0)
        return -1;
}
char ccount(int x)
{
    int r=0,g=0,b=0,y=0,i;
    for(i=0; i<person[x].card.size(); i++)
    {
        if(person[x].card[i][0]=='R')
            r++;
        else if(person[x].card[i][0]=='G')
            g++;
        else if(person[x].card[i][0]=='B')
            b++;
        else if(person[x].card[i][0]=='Y')
            y++;
    }
    int mx=max(r,g);
    mx=max(mx,b);
    mx=max(mx,y);
    if(r==mx)
        return 'R';
    else if(g==mx)
        return 'G';
    else if(b==mx)
        return 'B';
    else if(y==mx)
        return 'Y';
}
void color_card(char x)
{

    switch(x)
    {
    case 'Y':
        printf(color_yellow"Yellow"color_reset);
        break;
    case 'R':
        printf(color_red"Red"color_reset);
        break;
    case 'B':
        printf(color_blue"Blue"color_reset);
        break;
    case 'G':
        printf(color_green"Green"color_reset);
        break;
    case 'S':
        printf(color_reset"White");
        break;
    }
}
int main()
{
//card shaffle
    srand(time(0));
    int i,shaffle_count=1+rand()%3,card_count=cards.size();
    while(shaffle_count--)
        shaffle(card_count);

//creating dek
    stack<string> dek;
    for(i=cards.size()-1; i>=0; i--)
        dek.push(cards[i]);
    cards.clear();

//card distribution
    for(i=0; i<7; i++)
    {
        for(int j=0; j<4; j++)
        {
            person[j].card.push_back(dek.top());
            dek.pop();
        }
    }


//first card pick
    queue<string> view;
    int power_card=1;
    while(power_card==1)
    {
        string temp=dek.top();
        //cout<<temp;
        if(temp.size()==2)
            power_card=0;
        if(power_card==0)
            view.push(temp);
        cards.push_back(temp);
        dek.pop();
    }

//logic

    bool play=true;
    int clockwise=1;
    string temp = view.back(),text;
    char key = temp[0];
    text=temp;
    text.erase(text.begin());
    int c=1,plus_count=0;
    string apperance;

//game start
    while(play)
    {
        system("cls");
        cout<<"Recent cards:";
        display(view);

//some checking variables and flags
        apperance=view.back();
        if(text=="2+")
            plus_count+=2;
        else if(text=="4+")
            plus_count+=4;
        else
            plus_count=0;
        int i,key_flag=0,dek_flag=1;//key 0 means normal,1 means color chosen. //dek_flag 1 means didn't took card from deck, 0 means took.

//check before picking card
        if(text=="stp"&& c<2)
        {
            printf("\nPlayer %d blocked\n",turn+1);
            Sleep(300);
            //  system("pause");
            turn_decesion(clockwise);
        }
        else if(text=="rev"&&c<2)
        {
            if(clockwise==1)
                clockwise=0;
            else
                clockwise=1;
            cout<<"\nGame reversed\n";
            turn_decesion(clockwise);
            turn_decesion(clockwise);
        }
        else if((text=="col"||text=="4+")&&turn!=3)
        {

            key=ccount(turn);
            cout<<"player Choose color= ";
            color_card(key);
            cout<<endl;
            key_flag=1;
        }

//directions for playing
        cout<<"\nplayer "<<turn+1<<"'s turn\n";
        if((text=="2+"||text=="4+")&&panishment==0)
            cout<<"[Choose text: "<<text<<"]\n"<<endl;
        else if((text=="2+"||text=="4+")&&panishment==1)
        {
            cout<<"[Choose color= ";
            color_card(key);
            cout<<" or text = "<<text<<" ]\n";
        }
        else if(text=="col")
        {
            cout<<"[Choose color= ";
            color_card(key);
            cout<<"]\n";
        }
        else
        {
            cout<<"[Choose color= ";
            color_card(key);
            cout<<" or text = "<<text<<" ]\n";
        }
        int index;
check:
        if(turn!=3)
        {
            index=bot_decesion(turn,key,text);
        }

//my input
        else
        {
again:
            cout<<"\nDisplaying your cards:\n";
            for(int j=0; j<person[turn].card.size(); j++)
            {
                color_print(person[turn].card[j]);
                cout<<"("<<j<<") ";
            }
            cout<<"\n\nChoose a card index (enter -1 if no playable card or 'e' to exit):";

            string input;
            cin >> input;

            // Check if the player wants to exit the game
            if(input == "e")
            {
                cout << "\nPlayer has chosen to exit the game. Exiting...\n";
                play = false; // Terminates the game loop
                break; // Breaks out of the while loop
            }

            // Convert input to integer if not 'e'
            index = stoi(input);

            //input error
            if(index != -1)
            {
                if(index >= person[turn].card.size())
                    goto again;
                string verify = person[turn].card[index], text_check;
                char key_check = verify[0];
                verify.erase(verify.begin());
                if(key != key_check && text != verify)
                {
                    cout<<"\n***wrong input***\n";
                    goto again;
                }
            }
            if(person[turn].card[index] == "S4+" || person[turn].card[index] == "Scol")
            {
                char col;
                cout << "\nchoose a color(R/G/B/Y):";
                cin >> key;
                key_flag = 1;
            }
        }
        int ind_cpy=index;
        string str;
        if(index==-1)
        {
            if(dek_flag==0)
            {
                turn_decesion(clockwise);
                panishment=0;
            }
            if(text[1]!='+'&&dek_flag)
            {
                str=dek.top();
                person[turn].card.push_back(str);
                dek.pop();
                dek_flag=0;
                printf("\nPlayer %d took a card from deck\n",turn+1);
                goto check;
                Sleep(300);
            }
            else if(text[1]=='+'&&panishment==0)
            {
                int penalty=plus_count;
                while(penalty--)
                {
                    str=dek.top();
                    person[turn].card.push_back(str);
                    dek.pop();
                }
                panishment=1;
                printf("\nPlayer %d took %d cards from deck\n",turn+1,plus_count);
                Sleep(300);
                turn_decesion(clockwise);
            }
        }
        else
        {
            str=person[turn].card[index];
            printf("\nPlayer %d choose card: ",turn+1);
            color_print(str);
            cout<<endl;
            Sleep(300);
            view.push(str);
            auto it=person[turn].card.begin();
            while(index--)
                it++;
            person[turn].card.erase(it);
            turn_decesion(clockwise);
        }
        str=view.back();
        if(key_flag==0)
            key=str[0];

        text=str;
        text.erase(text.begin());
//game check
       // system("pause");
        if(apperance==view.back())
            c++;
        else c=1;
        {
//dek refill
            if(view.size()>4)
            {
                str=view.front();
                cards.push_back(str);
                view.pop();
            }
            if(dek.size()<10)
            {
                shaffle(cards.size());
                for(i=cards.size()-1; i>=0; i--)
                    dek.push(cards[i]);
                cards.clear();
            }
        }
//game terminator
        for(i=0; i<4; i++)
            if(person[i].card.size()==0)
            {
                play=false;
                int n=10;
                while(n--)
                    cout<< "\nGAME OVER!\nPLAYEER: "<<i+1<<" WIN\n";
                system("pause");
                break;
            }
        Sleep(1000);
    }

    return 0;
}
