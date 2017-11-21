#include "StartButton.h"
Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    : Window{ xy, w, h, title }
    , Continue_(Point(315, 530), 70, 30, "Continue", cb_difficulty)
    , BACK_(Point(170, 530), 70, 30, "Startpage", cb_goback)
    , beg_(Point(100, 250), 100, 80, "page", cb_beg)
    , inter_(Point(200, 250), 100, 80, "squire", cb_inter)
    , ad_(Point(300, 250), 100, 80, "knight", cb_ad)
    , ex_(Point(400, 250), 100, 80, "king", cb_ex)
    , start_{ Point{ 250, 275 }, 100, 50, "Start", cb_start }
    , win{ Point{ 200, 250 }, 150, 100, "Win!!!", cb_win }
    , Hint{ Point{ 250, 530 }, 70, 30, "Hint", cb_hint }
    , i{ Point{ 0, 0 }, "instruction.jpg" }
    , c{ Point{ 0, 0 }, "background2.jpg" }
    , page{ Point{ 170, 530 }, "startpage.jpg" }
    , con{ Point(315, 530), "continue.jpg" }
    , data{ 1, 2, 3, 4, 5, 6, 12, 7, 9, 10, 0, 15, 13, 14, 8, 11 }
    , orig_moves{ 0 }
    , step{ 0 }
    , username{ Point(250, 400), 80, 20, "Names: " }
    , score{ Point(100, 15), 400, 60, "Top score: " }
    , moves{ Point(400, 550), "Moves left: " }
    , final_score{ Point(200, 200), "Final Score: " }
	, Quit(Point{ 330, 530 }, 70, 30, "Quit", cb_quit)
{
    buttons.push_back(new Button{ Point{ 100, 100 }, 100, 100, "1", [](Address, Address pw) { reference_to<Lines_window>(pw).g(0); } });
    buttons.push_back(new Button{ Point{ 200, 100 }, 100, 100, "2", [](Address, Address pw) { reference_to<Lines_window>(pw).g(1); } });
    buttons.push_back(new Button{ Point{ 300, 100 }, 100, 100, "3", [](Address, Address pw) { reference_to<Lines_window>(pw).g(2); } });
    buttons.push_back(new Button{ Point{ 400, 100 }, 100, 100, "4", [](Address, Address pw) { reference_to<Lines_window>(pw).g(3); } });
    buttons.push_back(new Button{ Point{ 100, 200 }, 100, 100, "5", [](Address, Address pw) { reference_to<Lines_window>(pw).g(4); } });
    buttons.push_back(new Button{ Point{ 200, 200 }, 100, 100, "6", [](Address, Address pw) { reference_to<Lines_window>(pw).g(5); } });
    buttons.push_back(new Button{ Point{ 300, 200 }, 100, 100, "7", [](Address, Address pw) { reference_to<Lines_window>(pw).g(6); } });
    buttons.push_back(new Button{ Point{ 400, 200 }, 100, 100, "8", [](Address, Address pw) { reference_to<Lines_window>(pw).g(7); } });
    buttons.push_back(new Button{ Point{ 100, 300 }, 100, 100, "9", [](Address, Address pw) { reference_to<Lines_window>(pw).g(8); } });
    buttons.push_back(new Button{ Point{ 200, 300 }, 100, 100, "10", [](Address, Address pw) { reference_to<Lines_window>(pw).g(9); } });
    buttons.push_back(new Button{ Point{ 300, 300 }, 100, 100, "11", [](Address, Address pw) { reference_to<Lines_window>(pw).g(10); } });
    buttons.push_back(new Button{ Point{ 400, 300 }, 100, 100, "12", [](Address, Address pw) { reference_to<Lines_window>(pw).g(11); } });
    buttons.push_back(new Button{ Point{ 100, 400 }, 100, 100, "13", [](Address, Address pw) { reference_to<Lines_window>(pw).g(12); } });
    buttons.push_back(new Button{ Point{ 200, 400 }, 100, 100, "14", [](Address, Address pw) { reference_to<Lines_window>(pw).g(13); } });
    buttons.push_back(new Button{ Point{ 300, 400 }, 100, 100, "15", [](Address, Address pw) { reference_to<Lines_window>(pw).g(14); } });
    buttons.push_back(new Button{ Point{ 400, 400 }, 100, 100, "16", [](Address, Address pw) { reference_to<Lines_window>(pw).g(15); } });
    attach(c);
    attach(start_);
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
void Lines_window::cb_win(Address, Address pw)
{
    reference_to<Lines_window>(pw).redraw();
}


void Lines_window::cb_quit(Address, Address pw)
{
    reference_to<Lines_window>(pw).quit();
}
void Lines_window::quit()
{
	exit(0);
}


void Lines_window::cb_hint(Address, Address pw)
{
    reference_to<Lines_window>(pw).hint();
}
void Lines_window::hint()
{
    int i = 0; // index of above button
    int h = 0; // index of right button
    int a = 0; // index of below button
    int e = 0; // index of left  button
    int j = 0; // index of empty button
    while (data[j] != 0) {
        ++j;
    }
    i = (j / 4 - 1) * 4 + j % 4;
    h = j + 1;
    a = (j / 4 + 1) * 4 + j % 4;
    e = j - 1;
    if (i < 0)
        i = a;
	    //cout<<i;
    if ( j % 4 == 3)
		//cout<<h<<endl;
        h = e;
    if (a > 15)
        a = i;
    if ( j % 4 == 0)
        e = h;
    int dist_of_above = 0;
    int dist_of_right = 0;
    int dist_of_left = 0;
    int dist_of_below = 0;
    int num = 0;
    num = data[i];
    dist_of_above = (abs((num-1) / 4 - j / 4) + abs ((num-1)% 4 - (j % 4))-abs((num-1)/4-i/4)-abs((num-1)%4-i%4));
    num = data[h];
	
    dist_of_right = (abs((num-1)/ 4 - j / 4) + abs ((num-1) % 4 - (j % 4))-abs((num-1)/4-h/4)-abs((num-1)%4-h%4));
    num = data[a];
    dist_of_below = (abs((num-1) / 4 - j/ 4) + abs ((num-1)% 4 - (j % 4))-abs((num-1)/4-a/4)-abs((num-1)%4-a%4));
    num = data[e];
    dist_of_left = (abs((num-1) / 4 - j / 4) + abs ((num-1) % 4 - (j % 4))-abs((num-1)/4-e/4)-abs((num-1)%4-e%4));
    int mydis[] = { dist_of_above, dist_of_right, dist_of_below, dist_of_left };
    int min = *std::min_element(mydis, mydis + 4);
    if (min == dist_of_above)
        buttons[i].label = "hint";
    else if (min == dist_of_right)
        buttons[h].label = "hint";
    else if (min == dist_of_left)
        buttons[a].label = "hint";
    else
        buttons[e].label = "hint";
    redraw();
}

void Lines_window::start()
{
    detach(c);
    detach(start_);
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
    detach(moves);
    detach(final_score);
    attach(c);
    attach(start_);
}

void Lines_window::cb_beg(Address, Address pw)
{
    reference_to<Lines_window>(pw).beg();
}
void Lines_window::beg()
{
    vector<int> data0{ 1, 2, 3, 4, 5, 6, 12, 7, 9, 10, 0, 15, 13, 14, 8, 11 };
    orig_moves = 10;
    step = 10;
    int j = 0;
    while (data0[j] != 0) {
        ++j;
    }
    for (int i = 0; i < 16; ++i)
        data[i] = data0[i];
    for (int i = 0; i < children(); ++i) {
        child(i)->hide();
    }
    for (int i = 0; i < 16; ++i)
        attach(buttons[i]);
    for (int i = 0; i < data.size(); ++i) {
        buttons[i].label = std::to_string(data[i]);
    }
    buttons[j].label = " ";
    attach(BACK_);
    attach(Hint);
	attach(Quit);
    attach(score);
   
    redraw();
}

void Lines_window::cb_inter(Address, Address pw)
{
    reference_to<Lines_window>(pw).inter();
}
void Lines_window::inter()
{
    orig_moves = 20;
    step = 20;
    vector<int> data1{ 1, 6, 3, 4, 5, 0, 2, 11, 9, 10, 14, 7, 13, 15, 12, 8 };
    int j = 0;
    while (data1[j] != 0) {
        ++j;
    }
    // find the index of 0
    for (int i = 0; i < 16; ++i)
        data[i] = data1[i];
    for (int i = 0; i < children(); ++i) {
        child(i)->hide();
    }
    for (int i = 0; i < 16; ++i)
        attach(buttons[i]);
    for (int i = 0; i < data.size(); ++i) {
        buttons[i].label = std::to_string(data[i]);
    }
    buttons[j].label = " "; // replace 0 with blank
    attach(BACK_);
	attach(Hint);
	attach(Quit);
    redraw();
}

void Lines_window::cb_ad(Address, Address pw)
{
    reference_to<Lines_window>(pw).ad();
}
void Lines_window::ad()
{
    orig_moves = 40;
    step = 40;
    vector<int> data2{ 6, 5, 11, 4, 10, 13, 2, 1, 9, 15, 7, 3, 14, 12, 8, 0 };
    int j = 0;
    while (data2[j] != 0) {
        ++j;
    }
    for (int i = 0; i < 16; ++i)
        data[i] = data2[i];
    for (int i = 0; i < children(); ++i) {
        child(i)->hide();
    }
    for (int i = 0; i < 16; ++i)
        attach(buttons[i]);
    for (int i = 0; i < data.size(); ++i) {
        buttons[i].label = std::to_string(data[i]);
    }
    buttons[j].label = " ";
    attach(BACK_);
	attach(Hint);
	attach(Quit);
    redraw();
}

void Lines_window::cb_ex(Address, Address pw)
{
    reference_to<Lines_window>(pw).ex();
}
void Lines_window::ex()
{
    orig_moves = 80;
    step = 80;
    vector<int> data3{ 0, 12, 11, 13, 15, 14, 10, 9, 3, 7, 6, 2, 4, 8, 5, 1 };
    int j = 0;
    while (data3[j] != 0) {
        ++j;
    }
    for (int i = 0; i < 16; ++i)
        data[i] = data3[i];
    for (int i = 0; i < children(); ++i) {
        child(i)->hide();
    }
    for (int i = 0; i < 16; ++i)
        attach(buttons[i]);
    for (int i = 0; i < data.size(); ++i) {
        buttons[i].label = std::to_string(data[i]);
    }
    buttons[j].label = " ";
    attach(BACK_);
	attach(Hint);
	attach(Quit);
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
	attach(Quit);
}

void Lines_window::g(int btn)
{
    vector<int> correct{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0 };
    int incorrect_tiles = 0;
    if (step == 1) {
        --step;
        moves.set_label("Moves left: " + to_string(step));
        attach(moves);
        for (int i = 0; i < data.size(); ++i) {

            if (data[i] != correct[i])
                incorrect_tiles++;
        }
        if (incorrect_tiles == 0) {
            win.label = "You've won!\n Final Score: " + to_string(orig_moves * (16 - incorrect_tiles));
            attach(win);
        }
        else {
            win.label = "You've lost!\n Final Score: " + to_string(orig_moves * (16 - incorrect_tiles));
            attach(win);
        }
        for (int x = 0; x < buttons.size(); ++x) {
            detach(buttons[x]);
        }
    }

    else {
        if (data[btn] == 0)

            redraw();

        else {

            // when user click one button, program will check if the button is around blank one. If so, they will exchange position.
            int j = 0;

            while (data[j] != 0) {
                ++j;
            }
            if (abs(btn % 4 - j % 4) == 1 && abs(btn / 4 - j / 4) == 0) {
                int temp = data[btn];
                data[btn] = data[j];
                data[j] = temp;
                step = step - 1;
                moves.set_label("Moves left: " + to_string(step));
                attach(moves);
                for (int i = 0; i < data.size(); ++i)
                    ;
                //cout << data[i];
            }

            else if ((abs(btn / 4 - j / 4) == 1) && (abs(btn % 4 - j % 4) == 0)) {
                int temp = data[btn];
                data[btn] = data[j];
                data[j] = temp;
                step = step - 1;
                moves.set_label("Moves left: " + to_string(step));
                attach(moves);
                for (int i = 0; i < data.size(); ++i)
                    ;
                //cout << data[i];
            }
            for (int i = 0; i < data.size(); ++i) {
                buttons[i].label = std::to_string(data[i]);
            }
            int h = 0;
            while (data[h] != 0) {
                ++h;
            }
            buttons[h].label = " ";

            redraw();
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
