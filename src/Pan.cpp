/////////////////////////////////////////////////////////////////////
// Implementation of the Pan class
// Copyright (C) 2016-7 V Lazzarini
//
// This software is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 3.0 of the License, or (at your option) any later version.
//
/////////////////////////////////////////////////////////////////////
#include "Pan.h"

const double*
AuLib::Pan::process(const double* sig){
  double lg,rg;
  lg = cos(m_pos*pi/2.);
  rg = sin(m_pos*pi/2.);
  for(int i = 0, j = 0; i < m_vsize; i++, j+=2){
    m_output[j] = lg*sig[i];
    m_output[j+1] = rg*sig[i];
  }
}
