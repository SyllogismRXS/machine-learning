#include <iostream>

#include <ml/plot/gnuplot_i.hpp>

#include <Eigen/Dense>
//using Eigen::MatrixXd;

using std::cout;
using std::endl;

#define SLEEP_LGTH 2  // sleep time in seconds
#define NPOINTS    50 // length of array

void wait_for_key ()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__)  // every keypress registered, also arrow keys
     cout << endl << "Press any key to continue..." << endl;

     FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
     _getch();
#elif defined(unix) || defined(__unix) || defined(__unix__) || defined(__APPLE__)
     cout << endl << "Press ENTER to continue..." << endl;

     std::cin.clear();
     std::cin.ignore(std::cin.rdbuf()->in_avail());
     std::cin.get();
#endif
     return;
}

int main(int argc, char *argv[])
{
     std::cout << "Hello Plot!" << std::endl;     
     try {
          Gnuplot g1("lines");

          std::vector<double> t, x, y;

          for(int i = 0; i < 100; i++) {
               t.push_back(i);
               x.push_back(i*i);
               y.push_back(i*2*i);
          }
          //g1.unset_grid();
          g1.plot_xyz(x,y,t,"user-defined points 3d");                           
          g1.set_xautoscale().replot();
  

          Gnuplot g2("lines");
          t.clear(); x.clear(); y.clear();

          for(int i = 0; i < 100; i++) {
               t.push_back(i);
               x.push_back(i*i);
               y.push_back(i*2*i);
          }
          g2.set_grid();
          g2.plot_xyz(x,y,t,"user-defined points 3d");                           
          g2.set_xautoscale().replot();  

          wait_for_key();       
     }
     catch (GnuplotException ge) {
          cout << ge.what() << endl;
     }

     return 0;
}
