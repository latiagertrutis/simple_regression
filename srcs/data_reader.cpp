// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   data_reader.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/30 17:16:21 by mrodrigu          #+#    #+#             //
//   Updated: 2018/10/30 20:27:09 by mrodrigu         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "regression.h"

void data_reader(const string str, Eigen::Matrix<double, Eigen::Dynamic, 2> *X,
				 Eigen::Matrix<double, Eigen::Dynamic, 1> *Y)
{
  ifstream file;
  double x, y;
  size_t i;

  file.open(str, fstream::in);
  if (!file.is_open())
    exit(1);
  i = 0;
  while (!file.eof())
    {
	  X->conservativeResize(i + 1, Eigen::NoChange);
	  Y->conservativeResize(i + 1, Eigen::NoChange);
	  file >> y >> x;
	  X->row(i) << 1, x;
	  Y->row(i) << y;
	  i++;
    }
}
