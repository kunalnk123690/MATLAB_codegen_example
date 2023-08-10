#include <iostream>
#include "errorR.h"
#include "errorR_blas.h"
#include <Eigen/Dense>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> RowMajMat;

int main()
{
    Eigen::Matrix<double, 3, 3> R, RDes;
    Eigen::Matrix<double, 3, 1> out;
    Eigen::Matrix<double, 3, 1> outBlas;
    RDes = Eigen::MatrixXd::Identity(3,3);
    // R = Eigen::MatrixXd::Identity(3,3);
    
    R << 0.7115,  0.4325, -0.5538,
         0.6388, -0.7264,  0.2535,
        -0.2927, -0.5341, -0.7931;

    double R_[9], RDes_[9], out_[3], outBlas_[3];

    RowMajMat::Map(R_, R.rows(), R.cols()) = R;
    RowMajMat::Map(RDes_, RDes.rows(), RDes.cols()) = RDes;
    RowMajMat::Map(out_, out.rows(), out.cols()) = out;
    RowMajMat::Map(outBlas_, outBlas.rows(), outBlas.cols()) = outBlas;

    auto start1 = high_resolution_clock::now();
    for(int i = 0; i < 1000; i++)
    {
        errorR(R_, RDes_, out_);
    }
    auto stop1 = high_resolution_clock::now();
    cout << "Time taken without blas (ns): " << duration_cast<nanoseconds>(stop1 - start1).count()/1000 << "\n";

    auto start2 = high_resolution_clock::now();
    for(int i = 0; i < 1000; i++)
    {
        errorR_blas(R_, RDes_, outBlas_);
    }
    auto stop2 = high_resolution_clock::now();
    cout << "Time taken with blas (ns): " << duration_cast<nanoseconds>(stop2 - start2).count()/1000 << "\n"; 

    cout << "error: " << out_[0] << " " << out_[1] << " " << out_[2] << "\n";
    cout << "error Blas: " << outBlas_[0] << " " << outBlas_[1] << " " << outBlas_[2] << "\n";

}
