#ifndef PLOT_H_
#define PLOT_H_
/// ----------------------------------------------------------------------------
/// @file Plot.h
/// @author Kevin DeMarco <kevin.demarco@gmail.com>
///
/// Time-stamp: <2013-11-08 00:10:09 syllogismrxs>
///
/// @version 1.0
/// Created: 07 Nov 2013
///
/// ----------------------------------------------------------------------------
/// @section LICENSE
/// 
/// The MIT License (MIT)  
/// Copyright (c) 2012 Kevin DeMarco
///
/// Permission is hereby granted, free of charge, to any person obtaining a 
/// copy of this software and associated documentation files (the "Software"), 
/// to deal in the Software without restriction, including without limitation 
/// the rights to use, copy, modify, merge, publish, distribute, sublicense, 
/// and/or sell copies of the Software, and to permit persons to whom the 
/// Software is furnished to do so, subject to the following conditions:
/// 
/// The above copyright notice and this permission notice shall be included in 
/// all copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
/// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
/// DEALINGS IN THE SOFTWARE.
/// ----------------------------------------------------------------------------
/// @section DESCRIPTION
/// 
/// The Plot class ...
/// 
/// ----------------------------------------------------------------------------

#include <vector>
#include <Eigen/Dense>

namespace mL{

class Plot {
private:
          
protected:
public:
     Plot();
     static void wait_for_key();

     static std::vector<double> interval_stl(double t0, double step, double tend);
     static Eigen::MatrixXd interval(double t0, double step, double tend);
     


};

}

#endif
