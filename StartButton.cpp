#include "Simple_window.h"
#include "Graph.h"
#include "Window.h"
#include "Point.h"
#include <FL/Fl_Button.H>
struct Lines_window : Graph_lib::Window {
    Lines_window(Point xy, int w, int h, const string& title);

private:
    Button start;
    Text game_title;
    Text names;
    Text team_num;
    Text section_num;
    Image c;
	Image b;
	Image i;
    Button BACK;
    Button button2;
    Button button3;
    Button button4;
    Button button5;
    Button button6;
    Button button7;
    Button button8;
    Button button9;
    Button button10;
    Button button11;
    Button button12;
    Button button13;
    Button button14;
    Button button15;
    Button button16;
    bool button_pushed;
    void on1(); // action to be done when next_button is pressed
    void push();
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    : Window{ xy, w, h, title }
    , BACK(Point(275, 530), 70, 30, "Startpage", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , button2(Point(200, 100), 100, 100, "2", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , button3(Point(300, 100), 100, 100, "3", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , button4(Point(400, 100), 100, 100, "4", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , button5(Point(100, 200), 100, 100, "5", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , button6(Point(200, 200), 100, 100, "6", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , button7(Point(300, 200), 100, 100, "7", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , button8(Point(400, 200), 100, 100, "8", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , button9(Point(100, 300), 100, 100, "9", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , button10(Point(200, 300), 100, 100, "10", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , button11(Point(300, 300), 100, 100, "11", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , button12(Point(400, 300), 100, 100, "12", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , button13(Point(100, 400), 100, 100, "13", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , button14(Point(200, 400), 100, 100, "14", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , button15(Point(300, 400), 100, 100, "15", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , button16(Point(400, 400), 100, 100, "16", [](Address, Address pw) { reference_to<Lines_window>(pw).push(); })
    , start{ Point{ 250, 275 }, 100, 50, "Start",
        [](Address, Address pw) { reference_to<Lines_window>(pw).on1(); } }
	,  i{ Point{ 0, 0 }, "instruction.jpg" }
    , c{ Point{ 0, 0 }, "background2.jpg" }
    , game_title{ Point{ 250, 250 }, "Sliding Puzzle" }
	, b{Point{ 250, 275 },"button.jpg"}
    , names{ Point{ 27, 350 }, "Names: Maria Theresia Tyas, Allison Wendell, Mackenzie Wieberg, Zihan Wei" }
    , team_num{ Point{ 275, 375 }, "Team 53" }
    , section_num{ Point{ 225, 400 }, "CSCE 121 Section 520" }
    , button_pushed{ false }
{  
    attach(c);
	attach(b);
	attach(start);
    attach(game_title);
    attach(names);
    attach(team_num);
    attach(section_num);
}
void Lines_window::push()
{
    //detach(button1);
    redraw();
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
		/*
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
        attach(button16);*/
    }
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
