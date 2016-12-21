/////////////////////////////////////////////////////////////////////
// Fir class: 
// Copyright (C) 2016-7 V Lazzarini
//
// This software is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 3.0 of the License, or (at your option) any later version.
//
/////////////////////////////////////////////////////////////////////
#ifndef _FIR_H_
#define _FIR_H_
#include "Delay.h"
#include "FuncTable.h"

namespace AuLib {

  /** Fir description
  */
  class Fir : public Delay {

  protected:
    const double *m_ir;
    uint32_t m_irsize;

  public:
    /** Fir constructor \n\n
        ir - impulse respnse
	vframes - vector size \n
        sr - sampling rate
    */  
  Fir(const FuncTable& ir, uint32_t vframes = def_vframes, double sr = def_sr) :
    m_ir(ir.table()), m_irsize(ir.tsize()),
      Delay(ir.tsize()*sr,0.,vframes,sr) { };

    /** process a signal sig 
     */
    virtual const double* process(const double* sig);

    /** process a signal in obj
     */
    virtual const Fir& process(const AudioBase& obj) {
      if(obj.vframes() == m_vframes &&
	 obj.nchnls() == m_nchnls) {
	process(obj.vector());
      } else m_error = AULIB_ERROR;
      return *this;
    }

  };

  /*! \class Fir Fir.h AuLib/Fir.h
   */
}
#endif
