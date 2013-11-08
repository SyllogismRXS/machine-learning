#include <iostream>

#include "Plot.h"

using std::cout;
using std::endl;

namespace mL
{

     Plot::Plot()
     {
     }
     
     void Plot::wait_for_key ()
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

     std::vector<double> Plot::interval_stl(double t0, double step, double tend)
     {
          std::vector<double> v;
          for(int i = t0; i < step; i++) {
               v.push_back(i);
          }
          return v;
     }

     Eigen::MatrixXd Plot::interval(double t0, double step, double tend)
     {
          int num_elements = (tend-t0)/step+1;
          Eigen::MatrixXd m(num_elements,1);

          double value = t0;
          for (int i = 0; i < num_elements; i++) {
               m(i,0) = value;
               value += step;               
          }
          return m;
     }

     
}
