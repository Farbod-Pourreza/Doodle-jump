#include "rsdl.hpp"
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>
#define TRUE 1
#define FALSE 0
using namespace std;
class doodle{
public:
void set_parameters();
void draw(Window* window);
void set_filename (string x) { filename = x;};
void move_up_and_down(Window *window , int &move_right , int &move_left);
void moveleft(){x+=-5;};
void moveright(){x+=5;};
private:
int x;
int y;
int dy;
int dx;
int score;
string filename;
};
class object{
    public:
      object(int  , int );
      virtual void draw(Window* window)=0;
    protected:
    int x;
    int y;
    string filename;
    string type;
};
class platform : public object{
    public:
    platform(int , int);
    void draw(Window* window);
    private:
};
class mplatform : public object{
    public:
    mpplatform(int , int);
    void draw(Window* window);
    private:
};
class bplatform : public object{
    public:
    platform(int , int);
    void draw(Window* window);
    private:
};
class spring : public object{
    public:
    platform(int , int);
    void draw(Window* window);
    private:
};
class enemy : public object{
    public:
    platform(int , int);
    void draw(Window* window);
    private:
};

object :: object(int x_input , int y_input)
{
    x=x_input;
    y=500 -y_input;
}
platform :: platform(int x_input , int y_input) : object(x_input , y_input)
{
    x=x_input;
    y=500 -y_input;
}
mplatform :: mplatform(int x_input , int y_input) : object(x_input , y_input)
{
    x=x_input;
    y=500 -y_input;
}
bplatform :: bplatform(int x_input , int y_input) : object(x_input , y_input)
{
    x=x_input;
    y=500 -y_input;
}
spring :: spring(int x_input , int y_input) : object(x_input , y_input)
{
    x=x_input;
    y=500 -y_input;
}
enemy :: enemy(int x_input , int y_input) : object(x_input , y_input)
{
    x=x_input;
    y=500 -y_input;
}




void platform :: draw(Window* window)
{
    window->draw_img("platform.jpg",Rectangle(x,y,60,18));
} 
void bplatform :: draw(Window* window)
{
    window->draw_img("platform.jpg",Rectangle(x,y,60,18));
} 
void doodle :: set_parameters()
{
x=210;
y=220;
dy=0;
dx=13;
filename ="right.png";
}

void doodle::draw(Window* window)
{
window->draw_img(filename,Rectangle(x,y,62,60));
}

void doodle:: move_up_and_down(Window* window , int &move_right , int &move_left)
{
    if(move_right==TRUE)
    {
        x+=dx;
        filename="right.png";
    }
    if(move_left == TRUE)
    {
        x-=dx;
        filename="left.png";
    }
    if(x<0)
        x=500;
    if(x>500)
        x=0;
     dy += -2;
     y = y+ dy;
     if(y<250)
     dy = 29;
 
}


void update(Window* window, doodle &doodle , int &move_right , int &move_left);
void draw(Window* window,doodle  &doodle , vector<object*> objects);
void read_from_file(vector<object*> &objects);



int main()
{

    doodle doodle;
    doodle.set_parameters();
    vector<object*> objects;
    read_from_file(objects);
    int move_right=0 , move_left=0;
Window *window = new Window(500,500,"RSDL demo");
while(TRUE)
 {
    update(window,doodle,move_right,move_left);
    
    draw(window,doodle,objects);
    delay(40);
 }
}



void update(Window* window , doodle& doodle , int &move_right , int &move_left)
{
 char pressed_key;
 while(window->has_pending_event()) {
   Event e = window->poll_for_event();
   switch(e.get_type()) {
       case Event::EventType::QUIT:
       exit(0);
       case Event::EventType::KEY_PRESS:
       {
         pressed_key = e.get_pressed_key();
         if(pressed_key == 'd')
           move_right=TRUE;
         if(pressed_key == 'a')
           move_left=TRUE;
           break; 
       }
       case Event::EventType::KEY_RELEASE:
       {
           move_right=0;
           move_left =0;
       }
   } 
}
 doodle.move_up_and_down(window , move_right , move_left);
}

void draw(Window* window,doodle& doodle , vector<object*> objects)
{
 window->clear();
 window->draw_img("background.png");
 doodle.draw(window);
 for(int i = 0 ; i<objects.size() ; i++)
 {
     objects[i]->draw(window);
 }
 window->update_screen();
 
 
}
void read_from_file(vector<object*> &objects)
{
    int x_input , y_input , numberof_ent;
    string input;
    fstream file;
    file.open("map.txt");
    file >> numberof_ent;
    for(int i=0 ; i<numberof_ent ; i++)
    {
    file >> x_input >> y_input >> input;
    cout << x_input;
    if(input == "platform")
     {
        platform *plat=new platform(x_input , y_input);
        objects.push_back(plat);
     }
     if(input == "mplatform")
     {
        platform *mplat=new mplatform(x_input , y_input);
        objects.push_back(mplat);
     }
     if(input == "bplatform")
     {
        platform *bplat=new bplatform(x_input , y_input);
        objects.push_back(bplat);
     }
     if(input == "spring")
     {
        platform *spring=new spring(x_input , y_input);
        objects.push_back(spring);
     }
     if(input == "enemy")
     {
        platform *enemy=new enemy(x_input , y_input);
        objects.push_back(enemy);
     } 
    }
}