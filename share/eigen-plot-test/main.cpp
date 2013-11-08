#include <iostream>

#include <ml/plot/gnuplot_i.hpp>
#include <ml/plot/Plot.h>

#include <Eigen/Dense>

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
     std::cout << "Hello Plot!" << std::endl;     

     //Eigen::MatrixXd m(2,2);
     //m(0,0) = 3;
     //m(1,0) = 2.5;
     //m(0,1) = -1;
     //m(1,1) = m(1,0) + m(0,1);
     //std::cout << m << std::endl;

     try {
          //Eigen::MatrixXi m = Eigen::MatrixXi::Random(2,2);
          //cout << m << endl;
          
          Gnuplot g1("lines");
          
          std::vector<double> t, x, y;

          //t = mL::Plot::interval_2(0,.1,10);
          Eigen::MatrixXd m = mL::Plot::interval(0,0.9,4);
          
          
          
          //
          //for(int i = 0; i < 100; i++) {
          //     t.push_back(i);
          //     x.push_back(i*i);
          //     y.push_back(i*2*i);
          //}
          //g1.unset_grid();
          //g1.plot_xyz(x,y,t,"user-defined points 3d");                           
          //g1.set_xautoscale().replot();
          
          //mL::Plot::wait_for_key();
     }
     catch (GnuplotException ge) {
          cout << ge.what() << endl;
     }

     return 0;
}
