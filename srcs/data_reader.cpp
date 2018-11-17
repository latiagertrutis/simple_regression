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

void data_reader(const string str,
				 Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> *X,
				 Eigen::Matrix<double, Eigen::Dynamic, 1> *Y,
				 const unsigned char freedom)
{
  ifstream file;
  double x, y;
  size_t i;
  unsigned char j;

  X->resize(Eigen::NoChange, freedom);
  file.open(str, fstream::in);
  if (!file.is_open())
    exit(1);
  i = 0;
  while (!file.eof())
    {
	  X->conservativeResize(i + 1, Eigen::NoChange);
	  Y->conservativeResize(i + 1, Eigen::NoChange);
	  file >> y >> x;
	  for(j = 0; j < freedom; j++)
		(*X)(i, j) = pow(x, j);
	  Y->row(i) << y;
	  i++;
    }
}
