#include "Simple_window.h"
#include "Graph.h"
#include "Window.h"
#include "Point.h"
struct Lines_window : Graph_lib::Window {
    Lines_window(Point xy, int w, int h, const string& title);

private:
    Button start_;
    Text game_title;
    Text names;
    Text team_num;
    Text section_num;

    Image c;
    Image b;
    Image i;
    Image con;
    Image page;
	
    Button Continue_;
    Button BACK_;
	
    Button beg_;
    Button inter_;
    Button ad_;
    Button ex_;
	
	Vector<int> x;
	Vector<int> y;
	Vector_ref<Button> buttons; // vector of buttons
	
	static void cb_start(Address, Address);
    void start();
     
    static void cb_goback(Address,Address); 	 
    void goback();
    
	static void cb_difficulty(Address,Address);
    void difficulty();
	
	void g(int btn); // game algorithm function
	
	static void cb_exit(Address,Address);
	void exit();
	
	static void cb_beg(Address,Address);
	void beg();
	
	static void cb_inter(Address,Address);
	void inter();
	
	static void cb_ad(Address,Address);
	void ad();
	
	static void cb_ex(Address,Address);
	void ex();
};