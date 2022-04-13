/* -*- c++ -*- */
/*
 * Copyright 2022 mortarboard-H.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "adaptiveNotch_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace notchFilter {

#pragma message("set the following appropriately and remove this warning")
using input_type = float;
#pragma message("set the following appropriately and remove this warning")
using output_type = float;
adaptiveNotch::sptr adaptiveNotch::make(double sampRate, double targetFreq)
{
    return gnuradio::make_block_sptr<adaptiveNotch_impl>(sampRate, targetFreq);
}


/*
 * The private constructor
 */
adaptiveNotch_impl::adaptiveNotch_impl(double sampRate, double targetFreq)
    : gr::sync_block("adaptiveNotch",
                     gr::io_signature::make(
                         1 /* min inputs */, 1 /* max inputs */, sizeof(input_type)),
                     gr::io_signature::make(
                         1 /* min outputs */, 1 /*max outputs */, sizeof(output_type)))
{
    this->sampRate=sampRate;
    this->targetFreq=targetFreq;
    this->curPhase=0;
    this->radPerSample=2*M_PI*targetFreq/sampRate;
}

/*
 * Our virtual destructor.
 */
adaptiveNotch_impl::~adaptiveNotch_impl() {}

void adaptiveNotch_impl::update_sample_rate(double rate)
{
    this->sampRate=rate;
}

void adaptiveNotch_impl::set_target_freq(double rate)
{
    this->targetFreq=rate;
    this->radPerSample=2*M_PI*targetFreq/this->sampRate;
}


int adaptiveNotch_impl::work(int noutput_items,
                             gr_vector_const_void_star& input_items,
                             gr_vector_void_star& output_items)
{
    auto in = static_cast<const input_type*>(input_items[0]);
    auto out = static_cast<output_type*>(output_items[0]);

#pragma message("Implement the signal processing in your block and remove this warning")
    // Do <+signal processing+>
    float w0=0.1,w1=0.1;
    double updateRate=0.01;
    for(int index=0;index<noutput_items;index++)
    {
        float in0=cos(curPhase);
        float in1=sin(curPhase);
        
        float outLMS=w0*in0+w1*in0;
        out[index]=in[index];
        out[index]-=outLMS;
        //out[index]=in0;
        auto error=out[index];
        w0+=(updateRate*error*in0);
        w1+=(updateRate*error*in1);
        curPhase+=radPerSample;
    }
    // Tell runtime system how many output items we produced.
    return noutput_items;
}

} /* namespace notchFilter */
} /* namespace gr */
