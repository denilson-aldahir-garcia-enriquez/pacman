#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    std::string reset_position;
    int frame = 0;

    while (true)
    {
        auto can = Canvas(200,200);
    //can.DrawPointCircle(10,10,10);
    can.DrawBlockLine(10+frame, 40, 50+frame, 10); //vela
    can.DrawBlockLine(90+frame, 40, 50+frame, 10); //vela

    can.DrawBlockLine(5+frame, 40, 95+frame, 40); //cuerpo1
    can.DrawBlockLine(5+frame,40,15+frame,55); //cuerpo
    can.DrawBlockLine(95+frame,40,85+frame,55); //cuerpo
    can.DrawBlockLine(15+frame, 55, 85+frame, 55); //cuerpo

    can.DrawBlockLine (50+frame,10,50+frame,40);
    can.DrawBlockLine(15+frame,55,50+frame,40);
    can.DrawBlockLine(85+frame,55,50+frame,40);
    
    can.DrawPointCircleFilled(100+frame,20-frame,10);

        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        Element personaje = spinner(21, frame);
        Element lienzo = bgcolor(Color::DarkBlue, canvas(&can));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.3s);
        frame++;
    }

    return 0;
}