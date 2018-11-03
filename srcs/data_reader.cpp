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

vector<boost::tuple<double, double>>	data_reader(string str)
{
  ifstream file;
  vector<boost::tuple<double, double>>	points;
  double x, y;

  file.open(str, fstream::in);
  if (!file.is_open())
    exit(1);
  while (!file.eof())
    {
	  file >> x >> y;
	  points.push_back(boost::make_tuple(y, x));
    }
  return (points);
}
