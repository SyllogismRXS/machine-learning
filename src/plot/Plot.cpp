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
}
