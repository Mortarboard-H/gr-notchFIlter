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
  // Nothing to declare in this block.

public:
  iirNotch_impl(double sampRate, double targetFreq, double depth);
  ~iirNotch_impl();

  // Where all the action really happens
  int work(int noutput_items, gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
};

} // namespace notchFilter
} // namespace gr

#endif /* INCLUDED_NOTCHFILTER_IIRNOTCH_IMPL_H */
