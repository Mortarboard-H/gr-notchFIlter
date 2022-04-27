/* -*- c++ -*- */
/*
 * Copyright 2022 mortarboard-H.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_NOTCHFILTER_IIRNOTCH_IMPL_H
#define INCLUDED_NOTCHFILTER_IIRNOTCH_IMPL_H

#include <notchFilter/iirNotch.h>

namespace gr {
namespace notchFilter {

class iirNotch_impl : public iirNotch {
private:
  //coefficient of input sample
  double a0,a1,a2;
  //coefficient of delayed output sample
  double b1,b2;
  double wc;
  double wb;
  double sampleRate;

public:
  iirNotch_impl(double sampRate, double targetFreq, double width);
  ~iirNotch_impl();

  // Where all the action really happens
  int work(int noutput_items, gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
  
  void set_wc(double wc) override;
  void set_wb(double wb) override;
};

} // namespace notchFilter
} // namespace gr

#endif /* INCLUDED_NOTCHFILTER_IIRNOTCH_IMPL_H */
