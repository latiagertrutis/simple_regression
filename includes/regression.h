/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regression.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 11:48:28 by mrodrigu          #+#    #+#             */
//   Updated: 2018/10/30 17:26:46 by mrodrigu         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#ifndef REG_H
# define REG_H

#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include "../gnuplot-iostream/gnuplot-iostream.h"
using namespace std;

#define POINT_BUFF 50

vector<boost::tuple<double, double>>	data_reader(string str);

#endif
