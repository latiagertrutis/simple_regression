// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/30 11:47:06 by mrodrigu          #+#    #+#             //
//   Updated: 2018/10/30 20:27:09 by mrodrigu         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "regression.h"

static void plot_points (const Eigen::Matrix<double, Eigen::Dynamic, 2> *X,
						 const Eigen::Matrix<double, Eigen::Dynamic, 1> *Y)
{
  Gnuplot gp;
  vector<boost::tuple<double, double>> v(X->rows());
  size_t i;

  for(i = 0; i < (size_t)X->rows(); i++)
	v[i] = boost::make_tuple((*X)(i, 1), (*Y)(i, 0));
  gp << "plot -0.262323 + 1.00212 * x \n";
  gp << "replot '-' with points title 'pts_A'\n";
  gp.send1d(v);
}

int	main(void)
{
  string path = "resources/data1.dat";
  Eigen::Matrix<double, Eigen::Dynamic, 2> X;
  Eigen::Matrix<double, Eigen::Dynamic, 1> Y;

  data_reader(path, &X, &Y);
  plot_points(&X, &Y);
  cout << (X.transpose() * X).inverse() * X.transpose() * Y << endl;
  // gp << "plot 1 + x + x ** 2 + x ** 3 + x ** 4 + x ** 5\n";
  return (0);
}
