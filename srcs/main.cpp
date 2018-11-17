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

static void plot_points (const Eigen::Matrix<double,
						 Eigen::Dynamic, Eigen::Dynamic> *X,
						 const Eigen::Matrix<double, Eigen::Dynamic, 1> *Y,
						 const unsigned char freedom)
{
  Gnuplot gp;
  vector<boost::tuple<double, double>> v(X->rows());
  Eigen::Matrix<double, 1, Eigen::Dynamic> m = (X->transpose() * (*X)).inverse() * X->transpose() * (*Y);
  size_t i;
  unsigned char j;

  cout << m << endl;
  for(i = 0; i < (size_t)X->rows(); i++)
	v[i] = boost::make_tuple((*X)(i, 1), (*Y)(i, 0));
  gp << "plot " << m(0, 0);
  for (j = 1; j < freedom; j++)
	{
	  gp << " + "<< m(0, j) << " * x**" << to_string(j);
	}
  gp << endl;
  gp << "replot '-' with points title 'pts_A'\n";
  gp.send1d(v);
}

int	main(int argc, char **argv)
{
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> X;
  Eigen::Matrix<double, Eigen::Dynamic, 1> Y;
  unsigned char freedom;

  if (argc < 3)
	{
	  cout << "Invalid number of arguments\n";
	  exit (1);
	}
  freedom = (unsigned char)stoi(argv[1]);
  for (int i = 2; i < argc; i++)
	{
	  data_reader(argv[i], &X, &Y, freedom);
	}
  plot_points(&X, &Y, freedom);
  // gp << "plot 1 + x + x ** 2 + x ** 3 + x ** 4 + x ** 5\n";
  return (0);
}
