/* -*- c++ -*- */
/*
 * Copyright 2022 mortarboard-H.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_NOTCHFILTER_ADAPTIVENOTCH_IMPL_H
#define INCLUDED_NOTCHFILTER_ADAPTIVENOTCH_IMPL_H

#include <notchFilter/adaptiveNotch.h>

namespace gr {
namespace notchFilter {

class adaptiveNotch_impl : public adaptiveNotch
{
private:
    double sampRate;
    double targetFreq;
    double curPhase;
    double radPerSample;

public:
    adaptiveNotch_impl(double sampRate, double targetFreq);
    ~adaptiveNotch_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
    void update_sample_rate(double rate) override;
    void set_target_freq(double rate) override;
};

} // namespace notchFilter
} // namespace gr

#endif /* INCLUDED_NOTCHFILTER_ADAPTIVENOTCH_IMPL_H */
