#include "std_lib_facilities_5.h"
#include "Simple_window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"

#include "GUI.h"

using namespace Graph_lib;
struct Main_window : Graph_lib::Window
{
	Main_window(Point xy, int w, int h, const string& title);
	
	Graph_lib::Button button1;
	Graph_lib::Button button2;
	Graph_lib::Button button3;
	Graph_lib::Button button4;
	Graph_lib::Button button5;
	Graph_lib::Button button6;
	Graph_lib::Button button7;
	Graph_lib::Button button8;
	Graph_lib::Button button9;
	Graph_lib::Button button10;
	Graph_lib::Button button11;
	Graph_lib::Button button12;
	Graph_lib::Button button13;
	Graph_lib::Button button14;
	Graph_lib::Button button15;
	Graph_lib::Button button16;
	
	/*Graph_lib::Button chooselevel;
	
	Graph_lib::Button level1;
	Graph_lib::Button level2;
	Graph_lib::Button level3;
	Graph_lib::Button level4;*/

	void push();
	//void choose_level();
};

Main_window::Main_window(Point xy, int w, int h, const string& title):Window(xy,w,h,title),
	button1(Point(100,100),100,100,"1",[](Address, Address pw){reference_to<Main_window>(pw).push();}),
	button2(Point(200,100),100,100,"2",[](Address, Address pw){reference_to<Main_window>(pw).push();}),
	button3(Point(300,100),100,100,"3",[](Address, Address pw){reference_to<Main_window>(pw).push();}),
	button4(Point(400,100),100,100,"4",[](Address, Address pw){reference_to<Main_window>(pw).push();}),
	button5(Point(100,200),100,100,"5",[](Address, Address pw){reference_to<Main_window>(pw).push();}),
	button6(Point(200,200),100,100,"6",[](Address, Address pw){reference_to<Main_window>(pw).push();}),
	button7(Point(300,200),100,100,"7",[](Address, Address pw){reference_to<Main_window>(pw).push();}),
	button8(Point(400,200),100,100,"8",[](Address, Address pw){reference_to<Main_window>(pw).push();}),
	button9(Point(100,300),100,100,"9",[](Address, Address pw){reference_to<Main_window>(pw).push();}),
	button10(Point(200,300),100,100,"10",[](Address, Address pw){reference_to<Main_window>(pw).push();}),
	button11(Point(300,300),100,100,"11",[](Address, Address pw){reference_to<Main_window>(pw).push();}),
	button12(Point(400,300),100,100,"12",[](Address, Address pw){reference_to<Main_window>(pw).push();}),
	button13(Point(100,400),100,100,"13",[](Address, Address pw){reference_to<Main_window>(pw).push();}),
	button14(Point(200,400),100,100,"14",[](Address, Address pw){reference_to<Main_window>(pw).push();}),
	button15(Point(300,400),100,100,"15",[](Address, Address pw){reference_to<Main_window>(pw).push();}),
	button16(Point(400,400),100,100,"16",[](Address, Address pw){reference_to<Main_window>(pw).push();})
	/*
	chooselevel(Point(150,150),100,100,"level",[](Address, Address pw){reference_to<Main_window>(pw).choose_level();}),
	
	level1(Point(100,100),100,100,"1",[](Address, Address pw){reference_to<Main_window>(pw).push();}),
	level2(Point(200,100),100,100,"2",[](Address, Address pw){reference_to<Main_window>(pw).push();}),
	level3(Point(300,100),100,100,"3",[](Address, Address pw){reference_to<Main_window>(pw).push();}),
	level4(Point(400,100),100,100,"4",[](Address, Address pw){reference_to<Main_window>(pw).push();}) */
{
	attach(button1);
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
	
	/*attach(chooselevel);
	
	attach(level1);
	attach(level2);
	attach(level3);
	attach(level4); */
}

void Main_window::push()
{
	//detach(button1);
	redraw();
}

/*void Main_window::choose_level()
{
	redraw();
}*/

int main()
try {
	Main_window win(Point(100,100),600,600,"game");
	return gui_main();
}
catch(exception &e){
	cerr << "exception: " << e.what() << "\n";
	return 1;
}
catch(...) {
	cerr << "Some exception\n";
	return 2;
}