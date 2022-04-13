/* -*- c++ -*- */
/*
 * Copyright 2022 mortarboard-H.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "iirNotch_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace notchFilter {

#pragma message("set the following appropriately and remove this warning")
using input_type = float;
#pragma message("set the following appropriately and remove this warning")
using output_type = float;
iirNotch::sptr iirNotch::make(double sampRate, double targetFreq,
                              double depth) {
  return gnuradio::make_block_sptr<iirNotch_impl>(sampRate, targetFreq, depth);
}

/*
 * The private constructor
 */
iirNotch_impl::iirNotch_impl(double sampRate, double targetFreq, double depth)
    : gr::sync_block(
          "iirNotch",
          gr::io_signature::make(1 /* min inputs */, 1 /* max inputs */,
                                 sizeof(input_type)),
          gr::io_signature::make(1 /* min outputs */, 1 /*max outputs */,
                                 sizeof(output_type))) {}

/*
 * Our virtual destructor.
 */
iirNotch_impl::~iirNotch_impl() {}

int iirNotch_impl::work(int noutput_items,
                        gr_vector_const_void_star &input_items,
                        gr_vector_void_star &output_items) {
  auto in = static_cast<const input_type *>(input_items[0]);
  auto out = static_cast<output_type *>(output_items[0]);

#pragma message(                                                               \
    "Implement the signal processing in your block and remove this warning")
  // Do <+signal processing+>

  // Tell runtime system how many output items we produced.
  return noutput_items;
}

} /* namespace notchFilter */
} /* namespace gr */
