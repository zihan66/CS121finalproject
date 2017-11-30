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
    , win{ Point{ 175, 250 }, 225, 100, "Win!!!", cb_win }
    , Hint{ Point{ 300, 530 }, 80, 40, "Hint", cb_hint }
    , i{ Point{ 0, 0 }, "instruction.jpg" }
    , c{ Point{ 0, 0 }, "background2.jpg" }
    , page{ Point{ 225, 530 }, "startpage.jpg" }
    , con{ Point(315, 530), "continue.jpg" }
    , d{}
    , orig_moves{ 0 }
    , step{ 0 }
    , username{ Point(250, 400), 80, 20, "Names: " }
    , score{ Point(100, 15), 400, 60, "Top score: " }
    , moves{ Point(400, 550), "Moves left: " }
	, incorrecttiles{ Point(100, 550), "Incorrect tiles: " }
	, final_score{0}
    , top_scores1{0,0,0,0,0}
    , all_scores1{}
    , username_list1{}
    , top_players1{"","","","","","","","","","","",""}
    , top_scores2{0,0,0,0,0}
    , all_scores2{}
    , username_list2{}
    , top_players2{"","","","","","","","","","","",""}
    , top_scores3{0,0,0,0,0}
    , all_scores3{}
    , username_list3{}
    , top_players3{"","","","","","","","","","","",""}
    , top_scores4{0,0,0,0,0}
    , all_scores4{}
    , username_list4{}
    , top_players4{"","","","","","","","","","","",""}
    , player{}
	, Quit( Point{ 510, 530 }, 50, 30, "quit", cb_Quit)
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

// main menu
void Lines_window::cb_start(Address, Address pw)
{
    reference_to<Lines_window>(pw).start();
}
void Lines_window::cb_win(Address, Address pw)
{
    reference_to<Lines_window>(pw).redraw();
}

void Lines_window::cb_hint(Address, Address pw)
{
    reference_to<Lines_window>(pw).hint();
}

// calculates distances for hint button
void Lines_window::hintdistances(int a, int b, int c, int x, int e, int f, int g, int h, int i, int j) {
	a = d.at(b);
    g = abs(a / 4 - (c+1) / 4) + abs (a % 4 - (c+1) % 4);
    a = d.at(x);
    h = abs(a / 4 - (c+1) / 4) + abs (a % 4 - (c+1) % 4);
    a = d.at(e);
    i = abs(a / 4 - (c+1) / 4) + abs (a % 4 - (c+1) % 4);
    a = d.at(f);
    j = abs(a / 4 - (c+1) / 4) + abs (a % 4 - (c+1) % 4);
}

// displays a hint for the user
void Lines_window::hint()
{
    int i, h, a, e, j = 0; // index of buttons
    while (d.at(j) != 0) { ++j; }
    i = (j / 4 - 1) * 4 + j % 4;
    h = j + 1;
    a = (j / 4 + 1) * 4 + j % 4;
    e = j - 1;
    if (i < 0) i = a;
    if ( j % 4 == 3) h = e;
    if (a > 15) a = i;
    if ( j % 4 == 0) e = h;
    int dist_of_above, dist_of_right, dist_of_left, dist_of_below, num = 0;
	hintdistances(num,i,j,h,a,e,dist_of_above, dist_of_right, dist_of_left, dist_of_below);
    int mydis[] = { dist_of_above, dist_of_right, dist_of_below, dist_of_left };
    int min = *std::min_element(mydis, mydis + 4);
    if (min == dist_of_above) buttons[i].label = "hint";
    else if (min == dist_of_right) buttons[h].label = "hint";
    else if (min == dist_of_left) buttons[a].label = "hint";
    else buttons[e].label = "hint";
    redraw();
}

// displays the start screen
void Lines_window::start()
{
    detach(c);
    detach(start_);
    attach(i);
    attach(BACK_);
    attach(Continue_);
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
	detach(incorrecttiles);
    attach(c);
    attach(start_);
}

// sets the tiles to red/green based on initial position
void Lines_window::initial_tilecolors(int a){
	if (d.color_tiles(a) == true) {
		buttons[a].pw->color(Color::green);
		redraw();
	}
	else {
		buttons[a].pw->color(Color::red);
		redraw();
	}
}

// attaches the beginner level game screen
void Lines_window::beg_attach() {
	attach(Quit);
	attach(BACK_);
    attach(Hint);
	attach(page);
    attach(score);
	incorrecttiles.set_label("Incorrect tiles: " + to_string(d.incorrect_tiles())); 
    moves.set_label("Moves left: " + to_string(step));
    attach(moves);
	attach(incorrecttiles);
	initial_scores1();
}

void Lines_window::cb_beg(Address, Address pw)
{
    reference_to<Lines_window>(pw).beg();
}

// beginner level game play
void Lines_window::beg()
{   player = username.get_string();
 	int randnum = ceil(rand() % 4);
	if (randnum == 0) d = GameData({1, 2, 3, 4, 5, 6, 12, 7, 9, 10, 0, 15, 13, 14, 8, 11});
	else if (randnum == 1) d = GameData({ 2, 3, 4, 8, 1, 6, 7, 0, 5, 10, 11, 12, 9, 13, 14, 15 });
	else if(randnum == 2) d = GameData({ 2, 3, 4, 8, 1, 5, 7, 0, 9, 6, 10, 11, 13, 14, 15, 12 });
	else d = GameData({ 0, 1, 2, 4, 6, 7, 3, 8, 5, 9, 10, 12, 13, 14, 11, 15 });
	orig_moves = 10;
    step = 10;
    for (int i = 0; i < children(); ++i) child(i)->hide();
    for (int i = 0; i < 16; ++i) {
        attach(buttons[i]);
		initial_tilecolors(i); }
    for (int i = 0; i < d.size(); ++i) {
        buttons[i].label = std::to_string(d.at(i));
		buttons[i].pw->labelcolor(Color::white);
    
		if (buttons[i].label == "0") buttons[i].pw->color(Color::blue); }
    buttons[d.findindex()].label = " ";
    beg_attach();
    redraw();
}

// attaches the intermediate level game screen
void Lines_window::inter_attach() {
	attach(Quit);
	attach(BACK_);
    attach(Hint);
	attach(page);
    attach(score);
	incorrecttiles.set_label("Incorrect tiles: " + to_string(d.incorrect_tiles())); 
    moves.set_label("Moves left: " + to_string(step));
    attach(moves);
	attach(incorrecttiles);
	initial_scores2();
}

void Lines_window::cb_inter(Address, Address pw)
{
    reference_to<Lines_window>(pw).inter();
}

// intermediate level game play
void Lines_window::inter()
{
    orig_moves = 20;
    step = 20;
	player = username.get_string();
	int randnum = ceil(rand() % 4);
	if (randnum == 0) d = GameData({ 1, 6, 3, 4, 5, 0, 2, 11, 9, 10, 14, 7, 13, 15, 12, 8 });
	else if (randnum == 1) d = GameData({ 2, 7, 4, 6, 1, 3, 10, 0, 5, 11, 12, 8, 9, 13, 14, 15 });
	else if(randnum == 2) d = GameData({ 5, 7, 1, 2, 9, 4, 11, 3, 13, 6, 0, 8, 14, 10, 15, 12 });
	else d = GameData({ 2, 3, 4, 7, 1, 11, 5, 6, 10, 12, 0, 8, 9, 13, 14, 15 }); 
    for (int i = 0; i < children(); ++i) { child(i)->hide(); }
    for (int i = 0; i < 16; ++i) {
        attach(buttons[i]);
		initial_tilecolors(i); }

    for (int i = 0; i < d.size(); ++i) {
        buttons[i].label = std::to_string(d.at(i));
		buttons[i].pw->labelcolor(Color::white);
    
		if (buttons[i].label == "0") buttons[i].pw->color(Color::blue); }
    buttons[d.findindex()].label = " "; // replace 0 with blank
	inter_attach();
    redraw();
}

// attaches the advanced level game screen
void Lines_window::ad_attach() {
    attach(Quit);
	attach(BACK_);
    attach(Hint);
	attach(page);
    attach(score);
	incorrecttiles.set_label("Incorrect tiles: " + to_string(d.incorrect_tiles())); 
    moves.set_label("Moves left: " + to_string(step));
    attach(moves);
	attach(incorrecttiles);
	initial_scores3();
}

void Lines_window::cb_ad(Address, Address pw)
{
    reference_to<Lines_window>(pw).ad();
}

// advanced level game play
void Lines_window::ad()
{
    orig_moves = 40;
    step = 40;
    player = username.get_string();
	int randnum = ceil(rand() % 4);
	if (randnum == 0) d = GameData({ 6, 5, 11, 4, 10, 13, 2, 1, 9, 15, 7, 3, 14, 12, 8, 0 });
	else if (randnum == 1) d = GameData({ 9, 12, 5, 7, 13, 1, 3, 4, 6, 14, 11, 2, 10, 0, 8, 15 });
	else if(randnum == 2) d = GameData({ 6, 13, 11, 2, 7, 10, 8, 3, 4, 14, 15, 9, 12, 0, 1, 5 });
	else d = GameData({ 11, 1, 6, 8, 2, 15, 10, 13, 12, 4, 7, 3, 5, 14, 9, 0 });
    for (int i = 0; i < children(); ++i) { child(i)->hide(); }
    for (int i = 0; i < 16; ++i) {
        attach(buttons[i]);
		initial_tilecolors(i); }
    for (int i = 0; i < d.size(); ++i) {
        buttons[i].label = std::to_string(d.at(i));
		buttons[i].pw->labelcolor(Color::white);
    
		if (buttons[i].label == "0") buttons[i].pw->color(Color::blue); }
    buttons[d.findindex()].label = " ";
	ad_attach();
    redraw();
}

// attaches the expert level game screen
void Lines_window::ex_attach() {
	attach(Quit);
	attach(BACK_);
    attach(Hint);
	attach(page);
    attach(score);
	incorrecttiles.set_label("Incorrect tiles: " + to_string(d.incorrect_tiles())); 
    moves.set_label("Moves left: " + to_string(step));
    attach(moves);
	attach(incorrecttiles);
	initial_scores4();
}

void Lines_window::cb_ex(Address, Address pw)
{
    reference_to<Lines_window>(pw).ex();
}

// expert level game play
void Lines_window::ex()
{
    orig_moves = 80;
    step = 80;
    player = username.get_string();
    int randnum = ceil(rand() % 4);
	if (randnum == 0) d = GameData({ 0, 12, 11, 13, 15, 14, 10, 9, 3, 7, 6, 2, 4, 8, 5, 1 });
	else if (randnum == 1) d = GameData({ 0, 15, 9, 13, 11, 12, 10, 14, 3, 7, 6, 2, 4, 8, 5, 1 });
	else if(randnum == 2) d = GameData({ 0, 12, 14, 13, 15, 11, 9, 10, 3, 7, 6, 2, 4, 8, 5, 1 });
	else d = GameData({ 0, 12, 9, 13, 15, 11, 10, 14, 7, 8, 5, 6, 4, 3, 2, 1 });
    for (int i = 0; i < children(); ++i) { child(i)->hide(); }
    for (int i = 0; i < 16; ++i) {
        attach(buttons[i]);
		initial_tilecolors(i); }
    for (int i = 0; i < d.size(); ++i) {
        buttons[i].label = std::to_string(d.at(i));
		buttons[i].pw->labelcolor(Color::white);
    
		if (buttons[i].label == "0")
			buttons[i].pw->color(Color::blue); }
    buttons[d.findindex()].label = " ";
    ex_attach();
    redraw();
}

void Lines_window::cb_difficulty(Address, Address pw)
{
    reference_to<Lines_window>(pw).difficulty();
}

// attaches the choose difficulty screen
void Lines_window::difficulty()
{
    detach(Continue_);
    detach(con);
    detach(i);
    attach(beg_);
    attach(inter_);
    attach(ad_);
    attach(ex_);
	attach(page);
    attach(username);
}

// input the scores for beginner level
void Lines_window::input_scores1(int finalscore)
{
    ofstream ost("scores1.txt");
    username_list1.push_back(player);
    all_scores1.push_back(finalscore);
    if(!ost)
        error("can't open input file","scores1.txt");

    else {
        vector<int> index{};
        for(int x = 0; x < all_scores1.size(); ++x)
            index.push_back(x);

        for(int i = 1; i < all_scores1.size(); ++i) {
            int k = i-1;
            int temp_index = index[i];
            int temp = all_scores1[i];
            while(k >= 0 && (all_scores1[k] <= temp)) {
                all_scores1[k + 1] = all_scores1[k];
                index[k + 1] = index[k];
                k = k-1;
            }
            all_scores1[k + 1] = temp;
            index[k + 1] = temp_index;
        }
        for(int x = 0; x < username_list1.size(); ++x) {
            int i = index[x];
            top_players1[x] = username_list1[i];
        }
        for(int x = 0; x < all_scores1.size(); ++x) {
            ost << top_players1[x] << " " << to_string(all_scores1[x]) << " ";
        } 
    }  
    redraw();  
}

// initial scores for beginner level
void Lines_window::initial_scores1()
{
score.put("");
    string output = "";
    ifstream ist;
    string name_file;

    int score_file = 0;
    string top_five = "";

    ist.open("scores1.txt");
    
    if(username_list1.size()==0) {
        fstream ofs;
        ofs.open("scores1.txt", ios::out | ios::trunc);
        ofs.close(); }
    else {
        if(ist.is_open()) {
            int index = 0;
            int i = 0;
            for(int x = 0; x < 5; ++x) {
                if(ist >> name_file >> score_file) {
                    if((i++) > 0) output += ", ";
                    output += name_file + ": " + to_string(score_file);
                    ++i; }}}}
    if(output != "") output += ", ";
    output += player + ": --";
    score.put(output);
    redraw();
}

// output the scores for beginner level
void Lines_window::output_scores1()
{
    string output = "";
    ifstream ist;
    string name_file;

    int score_file = 0;
    string top_five = "";

    ist.open("scores1.txt");
    
    if(ist.is_open()) {
        int index = 0;
        int i = 0;
        for(int x = 0; x < 5; ++x) {
            if(ist >> name_file >> score_file) {
                if((i++) > 0)
                    output += ", ";
                output += name_file + ": " + to_string(score_file);
                ++i;
            }
        }
    }
    score.put(output);
    redraw();
}

// input the scores for intermediate level
void Lines_window::input_scores2(int finalscore)
{
    ofstream ost("scores2.txt");
    username_list2.push_back(player);
    all_scores2.push_back(finalscore);
    if(!ost)
        error("can't open input file","scores2.txt");

    else {
        vector<int> index{};
        for(int x = 0; x < all_scores2.size(); ++x)
            index.push_back(x);

        for(int i = 1; i < all_scores2.size(); ++i) {
            int k = i-1;
            int temp_index = index[i];
            int temp = all_scores2[i];
            while(k >= 0 && (all_scores2[k] <= temp)) {
                all_scores2[k + 1] = all_scores2[k];
                index[k + 1] = index[k];
                k = k-1;
            }
            all_scores2[k + 1] = temp;
            index[k + 1] = temp_index;
        }
        for(int x = 0; x < username_list2.size(); ++x) {
            int i = index[x];
            top_players2[x] = username_list2[i];
        }
        for(int x = 0; x < all_scores2.size(); ++x) {
            ost << top_players2[x] << " " << to_string(all_scores2[x]) << " ";
        }
    }  
    redraw();    
}

// initial scores for intermediate level
void Lines_window::initial_scores2()
{
score.put("");
    string output = "";
    ifstream ist;
    string name_file;

    int score_file = 0;
    string top_five = "";

    ist.open("scores2.txt");
    
    if(username_list2.size()==0) {
        fstream ofs;
        ofs.open("scores2.txt", ios::out | ios::trunc);
        ofs.close(); }
    else {
        if(ist.is_open()) {
            int index = 0;
            int i = 0;
            for(int x = 0; x < 5; ++x) {
                if(ist >> name_file >> score_file) {
                    if((i++) > 0) output += ", ";
                    output += name_file + ": " + to_string(score_file);
                    ++i; }}}}
    if(output != "") output += ", ";
    output += player + ": --";
    score.put(output);
    redraw();
}

// output scores for intermediate level
void Lines_window::output_scores2()
{
   string output = "";
    ifstream ist;
    string name_file;

    int score_file = 0;
    string top_five = "";

    ist.open("scores2.txt");
    
    if(ist.is_open()) {
        int index = 0;
        int i = 0;
        for(int x = 0; x < 5; ++x) {
            if(ist >> name_file >> score_file) {
                if((i++) > 0)
                    output += ", ";
                output += name_file + ": " + to_string(score_file);
                ++i;
            }
        }
    }
    score.put(output);
    redraw();

}

// input scores for advanced level
void Lines_window::input_scores3(int finalscore)
{
    ofstream ost("scores3.txt");
    username_list3.push_back(player);
    all_scores3.push_back(finalscore);
    if(!ost) error("can't open input file","scores3.txt");

    else {
        vector<int> index{};
        for(int x = 0; x < all_scores3.size(); ++x) index.push_back(x);

        for(int i = 1; i < all_scores3.size(); ++i) {
            int k = i-1;
            int temp_index = index[i];
            int temp = all_scores3[i];
            while(k >= 0 && (all_scores3[k] <= temp)) {
                all_scores3[k + 1] = all_scores3[k];
                index[k + 1] = index[k];
                k = k-1; }
            all_scores3[k + 1] = temp;
            index[k + 1] = temp_index; }
        for(int x = 0; x < username_list3.size(); ++x) {
            int i = index[x];
            top_players3[x] = username_list3[i]; }
        for(int x = 0; x < all_scores3.size(); ++x) ost << top_players3[x] << " " << to_string(all_scores3[x]) << " "; }  
    redraw(); 
}

// intial scores for advanced level
void Lines_window::initial_scores3()
{
	score.put("");
    string output = "";
    ifstream ist;
    string name_file;

    int score_file = 0;
    string top_five = "";

    ist.open("scores3.txt");
    
    if(username_list3.size()==0) {
        fstream ofs;
        ofs.open("scores3.txt", ios::out | ios::trunc);
        ofs.close(); }
    else {
        if(ist.is_open()) {
            int index = 0;
            int i = 0;
            for(int x = 0; x < 5; ++x) {
                if(ist >> name_file >> score_file) {
                    if((i++) > 0) output += ", ";
                    output += name_file + ": " + to_string(score_file);
                    ++i; }}}}
    if(output != "") output += ", ";
    output += player + ": --";
    score.put(output);
    redraw();
}

// output scores for advanced level
void Lines_window::output_scores3()
{
   string output = "";
    ifstream ist;
    string name_file;

    int score_file = 0;
    string top_five = "";

    ist.open("scores3.txt");
    
    if(ist.is_open()) {
        int index = 0;
        int i = 0;
        for(int x = 0; x < 5; ++x) {
            if(ist >> name_file >> score_file) {
                if((i++) > 0)
                    output += ", ";
                output += name_file + ": " + to_string(score_file);
                ++i;
            }
        }
    }
    score.put(output);
    redraw();
}

// input scores for expert level
void Lines_window::input_scores4(int finalscore)
{
    ofstream ost("scores4.txt");
    username_list4.push_back(player);
    all_scores4.push_back(finalscore);
    if(!ost) error("can't open input file","scores4.txt");

    else {
        vector<int> index{};
        for(int x = 0; x < all_scores4.size(); ++x) index.push_back(x);

        for(int i = 1; i < all_scores4.size(); ++i) {
            int k = i-1;
            int temp_index = index[i];
            int temp = all_scores4[i];
            while(k >= 0 && (all_scores4[k] <= temp)) {
                all_scores4[k + 1] = all_scores4[k];
                index[k + 1] = index[k];
                k = k-1; }
            all_scores4[k + 1] = temp;
            index[k + 1] = temp_index; }
        for(int x = 0; x < username_list4.size(); ++x) {
            int i = index[x];
            top_players4[x] = username_list4[i]; }
        for(int x = 0; x < all_scores4.size(); ++x) ost << top_players4[x] << " " << to_string(all_scores4[x]) << " "; }  
    redraw(); 
}

// initial scores for expert level
void Lines_window::initial_scores4()
{
    score.put("");
    string output = "";
    ifstream ist;
    string name_file;

    int score_file = 0;
    string top_five = "";

    ist.open("scores4.txt");
    
    if(username_list4.size()==0) {
        fstream ofs;
        ofs.open("scores4.txt", ios::out | ios::trunc);
        ofs.close(); }
    else {
        if(ist.is_open()) {
            int index = 0;
            int i = 0;
            for(int x = 0; x < 5; ++x) {
                if(ist >> name_file >> score_file) {
                    if((i++) > 0) output += ", ";
                    output += name_file + ": " + to_string(score_file);
                    ++i; }}}}
    if(output != "") output += ", ";
    output += player + ": --";
    score.put(output);
    redraw();
}

// output scores for expert level
void Lines_window::output_scores4()
{
    string output = "";
    ifstream ist;
    string name_file;

    int score_file = 0;
    string top_five = "";

    ist.open("scores4.txt");
    
    if(ist.is_open()) {
        int index = 0;
        int i = 0;
        for(auto x = 0; x < 5; ++x) {
            if(ist >> name_file >> score_file) {
                if((i++) > 0)
                    output += ", ";
                output += name_file + ": " + to_string(score_file);
                ++i;
            }
        }
    }
    score.put(output);
    redraw();
}

// sets tile colors to red/green based on correct/incorrect position
void Lines_window::tilecolors(int a, int b) {
	buttons[a].pw->color(Color::blue);
				
	if(d.color_tiles(b) == true) {
		buttons[b].pw->color(Color::green);
				redraw();
			}
	else {
		buttons[b].pw->color(Color::red);
		redraw();
	}
}

// checks if tile has been moved
void Lines_window::movecheck(int a, int b) {
	int temp = d.at(a);
	d.at(a) = d.at(b);
	d.at(b) = temp;
	
	tilecolors(a, b);
	
	step = step - 1;
	moves.set_label("Moves left: " + to_string(step));
	incorrecttiles.set_label("Incorrect tiles: " + to_string(d.incorrect_tiles())); 
	attach(moves);
	attach(incorrecttiles);
}

// calculate scores for beginner level
void Lines_window::calculatescore1() {
	final_score = orig_moves*(16-d.incorrect_tiles());
	input_scores1(final_score);
	output_scores1();
	if (d.incorrect_tiles() == 0) {
		win.label = "You've won, " + player + "!\n Final Score: " + to_string(final_score) + "\nNumber of incorrect tiles: 0";
		attach(win);
	}
	else {
		win.label = "You've lost, " + player +"!\n Final Score: " + to_string(final_score) + "\nNumber of incorrect tiles: " + to_string(d.incorrect_tiles());
		attach(win);
	}
}

// calculate scores for intermediate level
void Lines_window::calculatescore2() {
	final_score = orig_moves*(16-d.incorrect_tiles());
	input_scores2(final_score);
	output_scores2();
	if (d.incorrect_tiles() == 0) {
		win.label = "You've won, " + player +"!\n Final Score: " + to_string(final_score) + "\nNumber of incorrect tiles: 0";
		attach(win);
	}
	else {
		win.label = "You've lost, " + player +"!\n Final Score: " + to_string(final_score) + "\nNumber of incorrect tiles: " + to_string(d.incorrect_tiles());
		attach(win);
	}
}

// calculate scores for advanced level
void Lines_window::calculatescore3() {
	final_score = orig_moves*(16-d.incorrect_tiles());
	input_scores3(final_score);
	output_scores3();
	if (d.incorrect_tiles() == 0) {
		win.label = "You've won, " + player + "!\n Final Score: " + to_string(final_score) + "\nNumber of incorrect tiles: 0";
		attach(win);
	}
	else {
		win.label = "You've lost, " + player + "!\n Final Score: " + to_string(final_score) + "\nNumber of incorrect tiles: " + to_string(d.incorrect_tiles());
		attach(win);
	}
}

// calculate scores for expert level
void Lines_window::calculatescore4() {
	final_score = orig_moves*(16-d.incorrect_tiles());
	input_scores4(final_score);
	output_scores4();
	if (d.incorrect_tiles() == 0) {
		win.label = "You've won, " + player + "!\n Final Score: " + to_string(final_score) + "\nNumber of incorrect tiles: 0";
		attach(win);
	}
	else {
		win.label = "You've lost, " + player + "!\n Final Score: " + to_string(final_score) + "\nNumber of incorrect tiles: " + to_string(d.incorrect_tiles());
		attach(win);
	}
}

// move function for buttons
void Lines_window::g(int btn)
{ 
    if(orig_moves == 10) initial_scores1();
    else if (orig_moves == 20) initial_scores2();
    else if (orig_moves == 40) initial_scores3();
    else if (orig_moves == 80) initial_scores4();
	
    vector<int> correct{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0 };
    int incorrect_tiles = 0;
    
    if (d.at(btn) == 0) redraw();
     else {
            // when user click one button, program will check if the button is around blank one. If so, they will exchange position.
            int j = 0;
            while (d.at(j) != 0) { ++j; }
            if (abs(btn % 4 - j % 4) == 1 && abs(btn / 4 - j / 4) == 0) movecheck(btn, j);
            else if ((abs(btn / 4 - j / 4) == 1) && (abs(btn % 4 - j % 4) == 0)) movecheck(btn, j);
                
            if (step == 0) {
				if (orig_moves == 10) calculatescore1();
				else if (orig_moves == 20) calculatescore2();
				else if (orig_moves == 40) calculatescore3();
				else if (orig_moves == 80) calculatescore4();
				
                for (int x = 0; x < buttons.size(); ++x) detach(buttons[x]);
                detach(Hint);
            }

            for (int i = 0; i < d.size(); ++i) buttons[i].label = std::to_string(d.at(i));
            buttons[d.findindex()].label = " ";
			redraw();
        }
    redraw();
}

void Lines_window::cb_Quit(Address, Address pw)
{
    reference_to<Lines_window>(pw).quit1();
}
// quit button
void Lines_window::quit1(){
        hide();
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
