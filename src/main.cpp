#include <iostream>
#include "errorR.h"
#include <Eigen/Dense>
#include <vector>

using namespace std;
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> RowMajMat;

int main()
{
    Eigen::Matrix<double, 3, 3> R, RDes;
    Eigen::Matrix<double, 3, 1> out;
    RDes = Eigen::MatrixXd::Identity(3,3);
    // R = Eigen::MatrixXd::Identity(3,3);
    
    R << 0.7115,  0.4325, -0.5538,
         0.6388, -0.7264,  0.2535,
        -0.2927, -0.5341, -0.7931;

    double R_[9], RDes_[9], out_[3];

    RowMajMat::Map(R_, R.rows(), R.cols()) = R;
    RowMajMat::Map(RDes_, RDes.rows(), RDes.cols()) = RDes;
    RowMajMat::Map(out_, out.rows(), out.cols()) = out;

    errorR(R_, RDes_, out_);

    cout << out_[0] << " " << out_[1] << " " << out_[2] << endl;

}