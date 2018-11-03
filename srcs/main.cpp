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

int	main(void)
{
  Gnuplot gp;
  string path = "resources/data1.dat";
  vector<boost::tuple<double, double>> points = data_reader(path);
  vector<boost::tuple<double, double>>::iterator it;

  for(it = points.begin(); it < points.end(); it++)
	cout << it->get<0>()<<" \t" << it->get<1>() << endl;
  gp << "plot '-' with points title 'pts_A'\n";
  gp.send1d(points);
}
