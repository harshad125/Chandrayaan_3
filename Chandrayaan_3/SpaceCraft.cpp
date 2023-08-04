#include <bits/stdc++.h>
using namespace std;

//it's define coordinate of the spacecraft in spacearea
struct coordinate
{
    int x, y, z;
};

/*here ,i have created spacecraft control class for managing spacecraft movement.spacecraft receive command and according to command, it will perform operation. */
class spacecraftcontrol
{
private:
    coordinate spacecraft;
    char facedirection;
    int flag;

public:
   //constructor for initializing facedirection and initial coordinate of the spacecraft
    spacecraftcontrol()
    {
        facedirection = 'N';
        spacecraft.x = 0;
        spacecraft.y = 0;
        spacecraft.z = 0;
        flag = 0;
    }
    //it will  provide  current spacecraft coordinate
    coordinate getcoordinate()
    {
        return spacecraft;
    }
    //it will set spacecraft coordinate
    void setcoordinate(coordinate &c)
    {
        spacecraft.x = c.x;
        spacecraft.y = c.y;
        spacecraft.z = c.z;
    }
    //it will provide current facedirection of the spacecraft
    char getdirection()
    {
        return facedirection;
    }
    //it will set facedirection of the spacecraft
    void setdirection(char &s)
    {
        facedirection = s;
    }
    //it will print the current result of the spacecraft
    void print()
    {
        cout <<"X: "<< spacecraft.x << " | " << "Y: "<<spacecraft.y << "| " <<"Z: "<< spacecraft.z << "| " <<"FACE_DIRECTION: "<< facedirection << "\n";
    }
    void spacecraftmovement(vector<char> &steps);
    void performactionnorth(char step);
    void performactionsouth(char step);
    void performactioneast(char step);
    void performactionwest(char step);
    void performactionupward(char step);
    void performactiondownward(char step);
};

/*it will check command ,whenever it is given by user ,it is correct or not */
bool iscorrect(char ch)
{
    if (ch == 'F' || ch == 'B' || ch == 'L' || ch == 'R' || ch == 'U' || ch == 'D')
    {
        return true;
    }
    return false;
}

/*it is main function for handling movement of spacecraft.according to input command and facedirection it will perform operation*/
void spacecraftcontrol::spacecraftmovement(vector<char> &steps)
{
    int stepslength = steps.size();
    for (int i = 0; i < stepslength; i++)
    {
        switch (facedirection)
        {
        case 'N':
            performactionnorth(steps[i]);
            break;
        case 'S':
            performactionsouth(steps[i]);
            break;
        case 'E':
            performactioneast(steps[i]);
            break;
        case 'W':
            performactionwest(steps[i]);
            break;
        case 'U':
            performactionupward(steps[i]);
            break;
        case 'D':
            performactiondownward(steps[i]);
            break;

        default:
            break;
        }
        if (!flag)
        {
            print();
        }else{
            break;
        }
    }
}

/*when direction of the spacecraft is north that time according to input command it will perform operation and change its location like if input is forward then it will move one step ahead*/
void spacecraftcontrol::performactionnorth(char step)
{
    if (iscorrect(step))
    {
        switch (step)
        {
        case 'F':
            spacecraft.y += 1;
            break;
        case 'B':
            spacecraft.y -= 1;
            break;
        case 'L':
            facedirection = 'W';
            break;
        case 'R':
            facedirection = 'E';
            break;
        case 'U':
            facedirection = 'U';
            break;
        case 'D':
            facedirection = 'D';
            break;
        default:
            break;
        }
    }
    else
    {
        flag = 1;
        cout << "invalid input ,please try to give correct input i.e:- F,B,L,R,U,D"
             << "\n";
        return;
    }
}


/*when direction of the spacecraft is south that time according to input command it will perform operation and change its location like if input is forward then it will move one step ahead*/
void spacecraftcontrol::performactionsouth(char step)
{
    if (iscorrect(step))
    {
        switch (step)
        {
        case 'F':
            spacecraft.y -= 1;
            break;
        case 'B':
            spacecraft.y += 1;
            break;
        case 'L':
            facedirection = 'E';
            break;
        case 'R':
            facedirection = 'W';
            break;
        case 'U':
            facedirection = 'U';
            break;
        case 'D':
            facedirection = 'D';
            break;
        default:
            break;
        }
    }
    else
    {
        flag = 1;
        cout << "invalid input ,please try to give correct input i.e:- F,B,L,R,U,D"
             << "\n";
        return;
    }
}


/*when direction of the spacecraft is east that time according to input command it will perform operation and change its location like if input is forward then it will move one step ahead*/
void spacecraftcontrol::performactioneast(char step)
{
    if (iscorrect(step))
    {
        switch (step)
        {
        case 'F':
            spacecraft.x += 1;
            break;
        case 'B':
            spacecraft.x -= 1;
            break;
        case 'L':
            facedirection = 'N';
            break;
        case 'R':
            facedirection = 'S';
            break;
        case 'U':
            facedirection = 'U';
            break;
        case 'D':
            facedirection = 'D';
            break;
        default:
            break;
        }
    }
    else
    {
        flag = 1;
        cout << "invalid input ,please try to give correct input i.e:- F,B,L,R,U,D"
             << "\n";
        return;
    }
}

/*when direction of the spacecraft is west that time according to input command it will perform operation and change its location like if input is forward then it will move one step ahead*/
void spacecraftcontrol::performactionwest(char step)
{
    if (iscorrect(step))
    {
        switch (step)
        {
        case 'F':
            spacecraft.x -= 1;
            break;
        case 'B':
            spacecraft.x += 1;
            break;
        case 'L':
            facedirection = 'S';
            break;
        case 'R':
            facedirection = 'N';
            break;
        case 'U':
            facedirection = 'U';
            break;
        case 'D':
            facedirection = 'D';
            break;
        default:
            break;
        }
    }
    else
    {
        flag = 1;
        cout << "invalid input ,please try to give correct input i.e:- F,B,L,R,U,D"
             << "\n";
        return;
    }
}

/*when direction of the spacecraft is upward that time according to input command it will perform operation and change its location like if input is forward then it will move one step ahead*/
void spacecraftcontrol::performactionupward(char step)
{
    if (iscorrect(step))
    {
        switch (step)
        {
        case 'F':
            spacecraft.z += 1;
            break;
        case 'B':
            spacecraft.z -= 1;
            break;
        case 'L':
            facedirection = 'W';
            break;
        case 'R':
            facedirection = 'E';
            break;
        case 'U':
            facedirection = 'S';
            break;
        case 'D':
            facedirection = 'N';
            break;
        default:

            break;
        }
    }
    else
    {
        flag = 1;
        cout << "invalid input ,please try to give correct input i.e:- F,B,L,R,U,D"
             << "\n";
        return;
    }
}

/*when direction of the spacecraft is downward that time according to input command it will perform operation and change its location like if input is forward then it will move one step ahead*/
void spacecraftcontrol::performactiondownward(char step)
{
    if (iscorrect(step))
    {
        switch (step)
        {
        case 'F':
            spacecraft.z -= 1;
            break;
        case 'B':
            spacecraft.z += 1;
            break;
        case 'L':
            facedirection = 'E';
            break;
        case 'R':
            facedirection = 'W';
            break;
        case 'U':
            facedirection = 'N';
            break;
        case 'D':
            facedirection = 'S';
            break;
        default:
            break;
        }
    }else{
        flag = 1;
        cout << "invalid input ,please try to give correct input i.e:- F,B,L,R,U,D"
             << "\n";
        return;
    }
}

int main()
{
    spacecraftcontrol s1;
    vector<char> steps = {'F', 'R', 'U', 'B', 'L'};
    s1.spacecraftmovement(steps);

    // cout << s1.getdirection() << "\n";
}