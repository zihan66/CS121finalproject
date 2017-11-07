#include "std_lib_facilities_5.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Window.h"
#include "Point.h"

struct Lines_window : Graph_lib::Window {
  Lines_window(Point xy, int w, int h, const string& title);

  public:

  private:
    Button start;
    Text game_title;
    Text names;
    Text team_num;
    Text section_num;
    bool button_pushed;
    static void cb_on1(Address, Address); // callback for next_button
    void on1(); // action to be done when next_button is pressed
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
              :Window{xy,w,h,title},
              start{Point{250,275}, 100, 50, "Start", cb_on1},
              game_title{Point{250,250},"Sliding Buttons"},
              names{Point{27,350}, "Names: Maria Theresia Tyas, Allison Wendell, Mackenzie Wieberg, Zihan Wei"},
              team_num{Point{275,375},"Team 53"},
              section_num{Point{225,400},"CSCE 121 Section 520"},
              button_pushed{false}
              {
                attach(start);
                attach(game_title);
                attach(names);
                attach(team_num);
                attach(section_num);
              }
void Lines_window::cb_on1(Address, Address pw)
//call Simple_window::next() for the window located at pw
{
    reference_to<Lines_window>(pw).on1();
}

void Lines_window::on1(){

  //Function definition
  if(!button_pushed)
  {
    detach(start);
    detach(game_title);
    detach(names);
    detach(team_num);
    detach(section_num);
  }
}

int main()
try {
  Lines_window win1{Point{100,100},600,600,"Sliding Button"};
  //win1.wait_for_button();
  return gui_main();
}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}
