#include "Simple_window.h"
#include "Graph.h"
#include "Window.h"
#include "Point.h"
#include <iostream>
#include <fstream>
#include "game_data.h"
struct Lines_window : Graph_lib::Window {
    Lines_window(Point xy, int w, int h, const string& title);

private:
	// declare buttons, images, text, etc
    Button start_;

    Image c;
    Image i;
    Image con;
    Image page;

    Button Continue_;
    Button BACK_;

    Button beg_;
    Button inter_;
    Button ad_;
    Button ex_;
	Button win;
	Button Quit;
    Button Hint;
    
    Text moves;
	Text incorrecttiles;
    
    In_box username;
    Out_box score;
    int step;
    int orig_moves;
    int final_score;

	GameData d;
    Vector_ref<Button> buttons; // vector of buttons
    Vector_ref<Text> nums;

	// scores vectors
    vector<int> top_scores1;
    vector<string> username_list1; 
    vector<int> all_scores1;
    vector<string> top_players1;

    vector<int> top_scores2;
    vector<string> username_list2; 
    vector<int> all_scores2;
    vector<string> top_players2;

    vector<int> top_scores3;
    vector<string> username_list3; 
    vector<int> all_scores3;
    vector<string> top_players3;

    vector<int> top_scores4;
    vector<string> username_list4; 
    vector<int> all_scores4;
    vector<string> top_players4;

    string player;
    
	//callback functions
    static void cb_start(Address, Address);
    void start();
	
	static void cb_win(Address,Address);

    static void cb_goback(Address, Address);
    void goback();

    static void cb_difficulty(Address, Address);
    void difficulty();
    
	// hint button
	static void cb_hint(Address, Address);
	void hint();
	
	void hintdistances(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
	
	// game algorithm function
    void g(int btn);
	void movecheck(int a, int b);

    static void cb_exit(Address, Address);
    void exit();

    static void cb_beg(Address, Address);
    void beg();

    static void cb_inter(Address, Address);
    void inter();

    static void cb_ad(Address, Address);
    void ad();

    static void cb_ex(Address, Address);
    void ex();
	
	static void cb_Quit(Address,Address);
	void quit1();

	// scores functions
    void input_scores1(int a);
    void print_score();
    void output_scores1();
	void initial_scores1();
	
	void input_scores2(int a);
    void output_scores2();
	void initial_scores2();
	
	void input_scores3(int a);
    void output_scores3();
	void initial_scores3();
	
	void input_scores4(int a);
    void output_scores4();
	void initial_scores4();
	
	void calculatescore1();
	void calculatescore2();
	void calculatescore3();
	void calculatescore4();
	
	// attach functions
	void beg_attach();
	void inter_attach();
	void ad_attach();
	void ex_attach();
	
	// tile color functions
	void initial_tilecolors(int a);
	void tilecolors(int a, int b);
	
	
};