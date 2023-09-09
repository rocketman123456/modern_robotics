#include "modern_robotics.h"

#include <iostream>

using namespace MR;
using namespace std;

int main()
{
    cout << "Hello world" << endl;

    Eigen::Vector3d vec(1, 0, 0);
    Eigen::Matrix3d so3 = VecToso3(vec);
    // cout << so3 << endl;

    double L1 = 0.5;
    double L2 = 0.5;
    Eigen::MatrixXd M = Eigen::MatrixXd(4, 4);
    M << 0, 0, 1, L1, 0, 1, 0, 0, -1, 0, 0, -L2, 0, 0, 0, 1;
    // cout << M << endl;
    Eigen::MatrixXd s_list = Eigen::MatrixXd(6, 3);
    s_list << 0, 0, 1, 0, 0, 0,
            0, -1, 0, 0, 0, -L1,
            1, 0, 0, 0, L2, 0;
    // cout << s_list << endl;
    Eigen::VectorXd theta = Eigen::VectorXd(3);
    theta << 0, 0, 0;
    // cout << theta << endl;

    Eigen::MatrixXd T = FKinSpace(M, s_list, theta);
    cout << T << endl;

    return 0;
}
