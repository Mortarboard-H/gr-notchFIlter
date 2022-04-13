/* -*- c++ -*- */
/*
 * Copyright 2022 mortarboard-H.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_NOTCHFILTER_ADAPTIVENOTCH_H
#define INCLUDED_NOTCHFILTER_ADAPTIVENOTCH_H

#include <gnuradio/sync_block.h>
#include <notchFilter/api.h>

namespace gr {
namespace notchFilter {

/*!
 * \brief <+description of block+>
 * \ingroup notchFilter
 *
 */
class NOTCHFILTER_API adaptiveNotch : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<adaptiveNotch> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of notchFilter::adaptiveNotch.
     *
     * To avoid accidental use of raw pointers, notchFilter::adaptiveNotch's
     * constructor is in a private implementation
     * class. notchFilter::adaptiveNotch::make is the public interface for
     * creating new instances.
     */
    static sptr make(double sampRate, double targetFreq);
    /*!
     * \brief update sample rate
    */
    virtual void update_sample_rate(double rate)=0;

    /*!
     * \brief update target frequency
    */
    virtual void set_target_freq(double rate)=0;
};

} // namespace notchFilter
} // namespace gr

#endif /* INCLUDED_NOTCHFILTER_ADAPTIVENOTCH_H */
