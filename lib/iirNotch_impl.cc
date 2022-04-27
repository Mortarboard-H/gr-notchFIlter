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
iirNotch_impl::iirNotch_impl(double sampRate, double targetFreq, double width)
    : gr::sync_block(
          "iirNotch",
          gr::io_signature::make(1 /* min inputs */, 1 /* max inputs */,
                                 sizeof(input_type)),
          gr::io_signature::make(1 /* min outputs */, 1 /*max outputs */,
                                 sizeof(output_type))) 
{
    wc=targetFreq*2*M_PI;
    wb=width*2*M_PI;
    sampleRate=sampRate;
    double alpha=-wb/2;
    double beta=sqrt(4*wc*wc-wb*wb)/2;
    double r=exp(alpha/sampRate);
    a0=(1.0- 2 * r * cos(beta /sampRate) + r*r)/(2 - 2 * cos(wc / sampRate));
    a1=-2*a0*cosf(wc/sampRate);
    a2=a0;
    b1=2*r*cos(beta/sampRate);
    b2=-r*r;
    
}

/*
 * Our virtual destructor.
 */
iirNotch_impl::~iirNotch_impl() {}

/*
 * Set targetfreq.
 */
void iirNotch_impl::set_wc(double targetFreq)
{
  wc=targetFreq*2*M_PI;
  double alpha=-wb/2;
  double beta=sqrt(4*wc*wc-wb*wb)/2;
  double r=exp(alpha/sampleRate);
  a0=(1.0- 2 * r * cos(beta /sampleRate) + r*r)/(2 - 2 * cos(wc / sampleRate));
  a1=-2*a0*cosf(wc/sampleRate);
  a2=a0;
  b1=2*r*cos(beta/sampleRate);
  b2=-r*r;
}

/*
 * Set bandwidth.
 */
void iirNotch_impl::set_wb(double bandwidth)
{
  wb=bandwidth*2*M_PI;
  double alpha=-wb/2;
  double beta=sqrt(4*wc*wc-wb*wb)/2;
  double r=exp(alpha/sampleRate);
  a0=(1.0- 2 * r * cos(beta /sampleRate) + r*r)/(2 - 2 * cos(wc / sampleRate));
  a1=-2*a0*cos(wc/sampleRate);
  a2=a0;
  b1=2*r*cos(beta/sampleRate);
  b2=-r*r;
}


int iirNotch_impl::work(int noutput_items,
                        gr_vector_const_void_star &input_items,
                        gr_vector_void_star &output_items) {
  auto in = static_cast<const input_type *>(input_items[0]);
  auto out = static_cast<output_type *>(output_items[0]);

#pragma message(                                                               \
    "Implement the signal processing in your block and remove this warning")
  // Do <+signal processing+>
  float inprepre=0,inpre=0,outprepre=0,outpre=0;
  for(int i=0;i<noutput_items;i++)
  {
    out[i]=a0*in[i]+a1*inpre+a2*inprepre+b1*outpre+b2*outprepre;
    inprepre=inpre;
    inpre=in[i];
    outprepre=outpre;
    outpre=out[i];
    //out[i]=a0;
  }
  // Tell runtime system how many output items we produced.
  return noutput_items;
}

} /* namespace notchFilter */
} /* namespace gr */
