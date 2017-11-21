#include "Simple_window.h"
#include "Graph.h"
#include "Window.h"
#include "Point.h"
#include <iostream>
#include <fstream>
struct Lines_window : Graph_lib::Window {
    Lines_window(Point xy, int w, int h, const string& title);

private:
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
    Button Hint;
    Button Quit;
	
    Text moves;
    Text final_score;
    
    In_box username;
    //In_box date;
    Out_box score;
    int step;
    int orig_moves;
	Vector<int> data;
    Vector_ref<Button> buttons; // vector of buttons
    
    static void cb_quit(Address, Address);
    void quit();
	
    static void cb_start(Address, Address);
    void start();
	
	static void cb_win(Address,Address);

    static void cb_goback(Address, Address);
    void goback();

    static void cb_difficulty(Address, Address);
    void difficulty();
    
	static void cb_hint(Address, Address);
	void hint();
	
    void g(int btn); // game algorithm function

    static void cb_beg(Address, Address);
    void beg();

    static void cb_inter(Address, Address);
    void inter();

    static void cb_ad(Address, Address);
    void ad();

    static void cb_ex(Address, Address);
    void ex();

    void Input();
};