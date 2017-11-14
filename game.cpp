#include "StartButton.h"
Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    : Window{ xy, w, h, title }
    , Continue(Point(315, 530), 70, 30, "Continue", [](Address, Address pw) { reference_to<Lines_window>(pw).difficulty(); })
    , BACK(Point(225, 530), 70, 30, "Startpage", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , beg(Point(100, 250), 100, 80, "page", [](Address, Address pw) { reference_to<Lines_window>(pw).game(); })
    , inter(Point(200, 250), 100, 80, "squire", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , ad(Point(300, 250), 100, 80, "knight", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , ex(Point(400, 250), 100, 80, "king", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
	, button1(Point(100,100), 100, 100, "", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , button2(Point(200, 100), 100, 100, "2", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , button3(Point(300, 100), 100, 100, "3", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , button4(Point(400, 100), 100, 100, "4", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , start{ Point{ 250, 275 }, 100, 50, "Start", [](Address, Address pw) { reference_to<Lines_window>(pw).on1(); } }
    , i{ Point{ 0, 0 }, "instruction.jpg" }
    , c{ Point{ 0, 0 }, "background2.jpg" }
    , game_title{ Point{ 250, 250 }, "Sliding Puzzle" }
    , b{ Point{ 250, 275 }, "button.jpg" }
    , page{ Point{ 225, 530 }, "startpage.jpg" }
    , con{ Point(315, 530), "continue.jpg" }
    , names{ Point{ 27, 350 }, "Names: Maria Theresia Tyas, Allison Wendell, Mackenzie Wieberg, Zihan Wei" }
    , team_num{ Point{ 275, 375 }, "Team 53" }
    , section_num{ Point{ 225, 400 }, "CSCE 121 Section 520" }
    , button_pushed{ false }
{
    attach(c);
    attach(start);
    attach(game_title);
    attach(b);
    attach(names);
    attach(team_num);
    attach(section_num);
}
void Lines_window::push()
{

    redraw();
}
void Lines_window::g()
{
	if (button2.loc.x-100==100) {
		button2.loc.x=100;
		button1.loc.x=200;
	}
}
void Lines_window::difficulty()
{
    detach(Continue);
    detach(con);
    detach(i);
    attach(beg);
    attach(inter);
    attach(ad);
    attach(ex);
}
void Lines_window::on1()
{

    //Function definition
    if (!button_pushed) {
        detach(c);
        detach(b);
        detach(start);
        detach(game_title);
        detach(names);
        detach(team_num);
        detach(section_num);
        attach(i);
        attach(BACK);
        attach(Continue);
        attach(page);
        attach(con);
    }
}
void Lines_window::goback()
{
}
void Lines_window::game()
{   detach(beg);
    detach(inter);
    detach(ad);
    detach(ex);
    attach(button2);
    attach(button3);
    attach(button4);
    attach(button5);
    attach(button6);
    attach(button7);
    attach(button8);
    attach(button9);
    attach(button10);
    attach(button11);
    attach(button12);
    attach(button13);
    attach(button14);
    attach(button15);
    attach(button16);
}
int main() try {
    Lines_window win{ Point{ 100, 100 }, 600, 600, "Sliding Button" };
    return gui_main();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Some exception\n";
    return 2;
}
