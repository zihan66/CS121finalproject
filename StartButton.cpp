#include "StartButton.h"
Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    : Window{ xy, w, h, title }
    , Continue_(Point(315, 530), 70, 30, "Continue", cb_difficulty)
    , BACK_(Point(225, 530), 70, 30, "Startpage", cb_goback)
    , beg_(Point(100, 250), 100, 80, "page", cb_beg)
    , inter_(Point(200, 250), 100, 80, "squire", cb_inter)
    , ad_(Point(300, 250), 100, 80, "knight", cb_ad)
    , ex_(Point(400, 250), 100, 80, "king", cb_ex)
    , start_{ Point{ 250, 275 }, 100, 50, "Start", cb_start }
    , i{ Point{ 0, 0 }, "instruction.jpg" }
    , c{ Point{ 0, 0 }, "background2.jpg" }
    , game_title{ Point{ 250, 250 }, "Sliding Puzzle" }
    , b{ Point{ 250, 275 }, "button.jpg" }
    , page{ Point{ 225, 530 }, "startpage.jpg" }
    , con{ Point(315, 530), "continue.jpg" }
    , names{ Point{ 27, 350 }, "Names: Maria Theresia Tyas, Allison Wendell, Mackenzie Wieberg, Zihan Wei" }
    , team_num{ Point{ 275, 375 }, "Team 53" }
    , section_num{ Point{ 225, 400 }, "CSCE 121 Section 520" }
    , x{ 100, 200, 300, 400, 100, 200, 300, 400, 100, 200, 300, 400, 100, 200, 300, 400 }
    , y{ 100, 100, 100, 100, 200, 200, 200, 200, 300, 300, 300, 300, 400, 400, 400, 400 } // x, y are vectors for 16 buttons
    , step{ 0 }
    , username{ Point(250, 400), 80, 20, "Names: " }
    , score{ Point(100, 15), 400, 60, "Top score: " }
    , putton_pushed1{ false }
{
    attach(c);
    attach(start_);
    attach(game_title);
    attach(b);
    attach(names);
    attach(team_num);
    attach(section_num);
}

void Lines_window::Input()
{
    string names = username.get_string();
    ofstream ost(names);
    ost << names;
}
// main menu
void Lines_window::cb_start(Address, Address pw)
{
    reference_to<Lines_window>(pw).start();
}
void Lines_window::start()
{
    detach(c);
    detach(b);
    detach(start_);
    detach(game_title);
    detach(names);
    detach(team_num);
    detach(section_num);
    attach(i);
    attach(BACK_);
    attach(Continue_);
    attach(page);
    attach(con);
}

// go back to main menu
void Lines_window::cb_goback(Address, Address pw)
{
    reference_to<Lines_window>(pw).goback();
}
void Lines_window::goback()
{
    for (int i = 0; i < children(); ++i) {
        child(i)->hide();
    } // children() will return how many buttons you have attached on the window. child() tells a paticular one button

    attach(c);
    attach(start_);
    attach(game_title);
    attach(b);
    attach(names);
    attach(team_num);
    attach(section_num);
}

void Lines_window::cb_beg(Address, Address pw)
{
    reference_to<Lines_window>(pw).beg();
}
void Lines_window::beg()
{
    for (int i = 0; i < children(); ++i) {
        child(i)->hide();
    }
    buttons.push_back(new Button{ Point{ x[10], y[10] }, 100, 100, "", [](Address, Address pw) { reference_to<Lines_window>(pw).g(0); } });
    buttons.push_back(new Button{ Point{ x[1], y[1] }, 100, 100, "2", [](Address, Address pw) { reference_to<Lines_window>(pw).g(1); } });
    buttons.push_back(new Button{ Point{ x[2], y[2] }, 100, 100, "3", [](Address, Address pw) { reference_to<Lines_window>(pw).g(2); } });
    buttons.push_back(new Button{ Point{ x[3], y[3] }, 100, 100, "4", [](Address, Address pw) { reference_to<Lines_window>(pw).g(3); } });
    buttons.push_back(new Button{ Point{ x[4], y[4] }, 100, 100, "5", [](Address, Address pw) { reference_to<Lines_window>(pw).g(4); } });
    buttons.push_back(new Button{ Point{ x[5], y[5] }, 100, 100, "6", [](Address, Address pw) { reference_to<Lines_window>(pw).g(5); } });
    buttons.push_back(new Button{ Point{ x[6], y[6] }, 100, 100, "12", [](Address, Address pw) { reference_to<Lines_window>(pw).g(6); } });
    buttons.push_back(new Button{ Point{ x[7], y[7] }, 100, 100, "7", [](Address, Address pw) { reference_to<Lines_window>(pw).g(7); } });
    buttons.push_back(new Button{ Point{ x[8], y[8] }, 100, 100, "9", [](Address, Address pw) { reference_to<Lines_window>(pw).g(8); } });
    buttons.push_back(new Button{ Point{ x[9], y[9] }, 100, 100, "10", [](Address, Address pw) { reference_to<Lines_window>(pw).g(9); } });
    buttons.push_back(new Button{ Point{ x[0], y[0] }, 100, 100, "1", [](Address, Address pw) { reference_to<Lines_window>(pw).g(10); } });
    buttons.push_back(new Button{ Point{ x[11], y[11] }, 100, 100, "15", [](Address, Address pw) { reference_to<Lines_window>(pw).g(11); } });
    buttons.push_back(new Button{ Point{ x[12], y[12] }, 100, 100, "13", [](Address, Address pw) { reference_to<Lines_window>(pw).g(12); } });
    buttons.push_back(new Button{ Point{ x[13], y[13] }, 100, 100, "14", [](Address, Address pw) { reference_to<Lines_window>(pw).g(13); } });
    buttons.push_back(new Button{ Point{ x[14], y[14] }, 100, 100, "8", [](Address, Address pw) { reference_to<Lines_window>(pw).g(14); } });
    buttons.push_back(new Button{ Point{ x[15], y[15] }, 100, 100, "11", [](Address, Address pw) { reference_to<Lines_window>(pw).g(15); } });

    for (int i = buttons.size() - 16; i < buttons.size(); ++i) {
        attach(buttons[i]);
    }
    attach(BACK_);
    attach(score);
	cerr << "*** Called beg()" << endl;
    redraw();
}
void Lines_window::cb_inter(Address, Address pw)
{
    reference_to<Lines_window>(pw).inter();
}
void Lines_window::inter()
{
    /*detach(beg_);
    detach(inter_);
    detach(ad_);
    detach(ex_);*/
    for (int i = 0; i < children(); ++i) {
        child(i)->hide();
    }
    buttons.push_back(new Button{ Point{ x[0], y[0] }, 100, 100, "", [](Address, Address pw) { reference_to<Lines_window>(pw).g(0); } });
    buttons.push_back(new Button{ Point{ x[1], y[1] }, 100, 100, "6", [](Address, Address pw) { reference_to<Lines_window>(pw).g(1); } });
    buttons.push_back(new Button{ Point{ x[2], y[2] }, 100, 100, "3", [](Address, Address pw) { reference_to<Lines_window>(pw).g(2); } });
    buttons.push_back(new Button{ Point{ x[3], y[3] }, 100, 100, "6", [](Address, Address pw) { reference_to<Lines_window>(pw).g(3); } });
    buttons.push_back(new Button{ Point{ x[4], y[4] }, 100, 100, "9", [](Address, Address pw) { reference_to<Lines_window>(pw).g(4); } });
    buttons.push_back(new Button{ Point{ x[5], y[5] }, 100, 100, "5", [](Address, Address pw) { reference_to<Lines_window>(pw).g(5); } });
    buttons.push_back(new Button{ Point{ x[6], y[6] }, 100, 100, "6", [](Address, Address pw) { reference_to<Lines_window>(pw).g(6); } });
    buttons.push_back(new Button{ Point{ x[7], y[7] }, 100, 100, "09", [](Address, Address pw) { reference_to<Lines_window>(pw).g(7); } });
    buttons.push_back(new Button{ Point{ x[8], y[8] }, 100, 100, "8", [](Address, Address pw) { reference_to<Lines_window>(pw).g(8); } });
    buttons.push_back(new Button{ Point{ x[9], y[9] }, 100, 100, "9", [](Address, Address pw) { reference_to<Lines_window>(pw).g(9); } });
    buttons.push_back(new Button{ Point{ x[10], y[10] }, 100, 100, "0", [](Address, Address pw) { reference_to<Lines_window>(pw).g(10); } });
    buttons.push_back(new Button{ Point{ x[11], y[11] }, 100, 100, "11", [](Address, Address pw) { reference_to<Lines_window>(pw).g(11); } });
    buttons.push_back(new Button{ Point{ x[12], y[12] }, 100, 100, "12", [](Address, Address pw) { reference_to<Lines_window>(pw).g(12); } });
    buttons.push_back(new Button{ Point{ x[13], y[13] }, 100, 100, "13", [](Address, Address pw) { reference_to<Lines_window>(pw).g(13); } });
    buttons.push_back(new Button{ Point{ x[14], y[14] }, 100, 100, "14", [](Address, Address pw) { reference_to<Lines_window>(pw).g(14); } });
    buttons.push_back(new Button{ Point{ x[15], y[15] }, 100, 100, "15", [](Address, Address pw) { reference_to<Lines_window>(pw).g(15); } });

    for (int i = buttons.size() - 16; i < buttons.size(); ++i) {
        attach(buttons[i]);
    }
    attach(BACK_);
	cerr << "*** Called inter()" << endl;
    redraw();
}

void Lines_window::cb_ad(Address, Address pw)
{
    reference_to<Lines_window>(pw).ad();
}
void Lines_window::ad()
{
    for (int i = 0; i < children(); ++i) {
        child(i)->hide();
    }
    buttons.push_back(new Button{ Point{ x[9], y[9] }, 100, 100, "", [](Address, Address pw) { reference_to<Lines_window>(pw).g(0); } });
    buttons.push_back(new Button{ Point{ x[1], y[1] }, 100, 100, "a", [](Address, Address pw) { reference_to<Lines_window>(pw).g(1); } });
    buttons.push_back(new Button{ Point{ x[2], y[2] }, 100, 100, "b", [](Address, Address pw) { reference_to<Lines_window>(pw).g(2); } });
    buttons.push_back(new Button{ Point{ x[3], y[3] }, 100, 100, "3", [](Address, Address pw) { reference_to<Lines_window>(pw).g(3); } });
    buttons.push_back(new Button{ Point{ x[4], y[4] }, 100, 100, "4", [](Address, Address pw) { reference_to<Lines_window>(pw).g(4); } });
    buttons.push_back(new Button{ Point{ x[5], y[5] }, 100, 100, "5", [](Address, Address pw) { reference_to<Lines_window>(pw).g(5); } });
    buttons.push_back(new Button{ Point{ x[6], y[6] }, 100, 100, "6", [](Address, Address pw) { reference_to<Lines_window>(pw).g(6); } });
    buttons.push_back(new Button{ Point{ x[7], y[7] }, 100, 100, "7", [](Address, Address pw) { reference_to<Lines_window>(pw).g(7); } });
    buttons.push_back(new Button{ Point{ x[8], y[8] }, 100, 100, "8", [](Address, Address pw) { reference_to<Lines_window>(pw).g(8); } });
    buttons.push_back(new Button{ Point{ x[0], y[0] }, 100, 100, "9", [](Address, Address pw) { reference_to<Lines_window>(pw).g(9); } });
    buttons.push_back(new Button{ Point{ x[10], y[10] }, 100, 100, "", [](Address, Address pw) { reference_to<Lines_window>(pw).g(10); } });
    buttons.push_back(new Button{ Point{ x[11], y[11] }, 100, 100, "11", [](Address, Address pw) { reference_to<Lines_window>(pw).g(11); } });
    buttons.push_back(new Button{ Point{ x[12], y[12] }, 100, 100, "12", [](Address, Address pw) { reference_to<Lines_window>(pw).g(12); } });
    buttons.push_back(new Button{ Point{ x[13], y[13] }, 100, 100, "13", [](Address, Address pw) { reference_to<Lines_window>(pw).g(13); } });
    buttons.push_back(new Button{ Point{ x[14], y[14] }, 100, 100, "14", [](Address, Address pw) { reference_to<Lines_window>(pw).g(14); } });
    buttons.push_back(new Button{ Point{ x[15], y[15] }, 100, 100, "15", [](Address, Address pw) { reference_to<Lines_window>(pw).g(15); } });

     for (int i = buttons.size() - 16; i < buttons.size(); ++i) {
        attach(buttons[i]);
    }
    attach(BACK_);
	cerr << "*** Called ad()" << endl;
    redraw();
}

void Lines_window::cb_ex(Address, Address pw)
{
    reference_to<Lines_window>(pw).ex();
}
void Lines_window::ex()
{
    for (int i = 0; i < children(); ++i) {
        child(i)->hide();
    }
    buttons.push_back(new Button{ Point{ x[9], y[9] }, 100, 100, "", [](Address, Address pw) { reference_to<Lines_window>(pw).g(0); } });
    buttons.push_back(new Button{ Point{ x[1], y[1] }, 100, 100, "1", [](Address, Address pw) { reference_to<Lines_window>(pw).g(1); } });
    buttons.push_back(new Button{ Point{ x[2], y[2] }, 100, 100, "2", [](Address, Address pw) { reference_to<Lines_window>(pw).g(2); } });
    buttons.push_back(new Button{ Point{ x[3], y[3] }, 100, 100, "3", [](Address, Address pw) { reference_to<Lines_window>(pw).g(3); } });
    buttons.push_back(new Button{ Point{ x[4], y[4] }, 100, 100, "4", [](Address, Address pw) { reference_to<Lines_window>(pw).g(4); } });
    buttons.push_back(new Button{ Point{ x[5], y[5] }, 100, 100, "5", [](Address, Address pw) { reference_to<Lines_window>(pw).g(5); } });
    buttons.push_back(new Button{ Point{ x[6], y[6] }, 100, 100, "6", [](Address, Address pw) { reference_to<Lines_window>(pw).g(6); } });
    buttons.push_back(new Button{ Point{ x[7], y[7] }, 100, 100, "7", [](Address, Address pw) { reference_to<Lines_window>(pw).g(7); } });
    buttons.push_back(new Button{ Point{ x[8], y[8] }, 100, 100, "8", [](Address, Address pw) { reference_to<Lines_window>(pw).g(8); } });
    buttons.push_back(new Button{ Point{ x[0], y[0] }, 100, 100, "9", [](Address, Address pw) { reference_to<Lines_window>(pw).g(9); } });
    buttons.push_back(new Button{ Point{ x[10], y[10] }, 100, 100, "10", [](Address, Address pw) { reference_to<Lines_window>(pw).g(10); } });
    buttons.push_back(new Button{ Point{ x[11], y[11] }, 100, 100, "11", [](Address, Address pw) { reference_to<Lines_window>(pw).g(11); } });
    buttons.push_back(new Button{ Point{ x[12], y[12] }, 100, 100, "12", [](Address, Address pw) { reference_to<Lines_window>(pw).g(12); } });
    buttons.push_back(new Button{ Point{ x[13], y[13] }, 100, 100, "13", [](Address, Address pw) { reference_to<Lines_window>(pw).g(13); } });
    buttons.push_back(new Button{ Point{ x[14], y[14] }, 100, 100, "14", [](Address, Address pw) { reference_to<Lines_window>(pw).g(14); } });
    buttons.push_back(new Button{ Point{ x[15], y[15] }, 100, 100, "15", [](Address, Address pw) { reference_to<Lines_window>(pw).g(15); } });
    
    for (int i = buttons.size() - 16; i < buttons.size(); ++i) {
        attach(buttons[i]);
    }
    attach(BACK_);
	cerr << "*** Called ex()" << endl;
    redraw();
}

void Lines_window::cb_difficulty(Address, Address pw)
{
    reference_to<Lines_window>(pw).difficulty();
}
void Lines_window::difficulty()
{
    detach(Continue_);
    detach(con);
    detach(i);
    attach(beg_);
    attach(inter_);
    attach(ad_);
    attach(ex_);
    attach(username);
}

void Lines_window::g(int btn)
{
    if (btn == 0)

        redraw();

    else {

        // when user click one button, program will check if the button is around blank one. If so, they will exchange position.
        if (abs(buttons[buttons.size()-16+btn].loc.x - buttons[buttons.size()-16].loc.x) == 100 && abs(buttons[buttons.size()-16+btn].loc.y - buttons[buttons.size()-16].loc.y) == 0) {
            int tempx = buttons[buttons.size()-16+btn].loc.x;
            buttons[buttons.size()-16+btn].move(buttons[buttons.size()-16].loc.x - buttons[buttons.size()-16+btn].loc.x, 0);
            buttons[buttons.size()-16].move(tempx - buttons[buttons.size()-16].loc.x, 0);
            step++;
        }

        else if (abs(buttons[buttons.size()-16+btn].loc.y - buttons[buttons.size()-16].loc.y) == 100 && abs(buttons[buttons.size()-16+btn].loc.x - buttons[buttons.size()-16].loc.x) == 0) {
            int tempy = buttons[buttons.size()-16+btn].loc.y;
            buttons[buttons.size()-16+btn].move(0, buttons[buttons.size()-16].loc.y - buttons[buttons.size()-16+btn].loc.y);
            buttons[buttons.size()-16].move(0, tempy - buttons[buttons.size()-16].loc.y);
            step++;
        }
    }
    redraw();
}

int main() try {
	cerr << "Program Started" << endl;
    Lines_window win{ Point{ 100, 100 }, 600, 600, "Sliding Button" };
	cerr << "Program Started" << endl;

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
