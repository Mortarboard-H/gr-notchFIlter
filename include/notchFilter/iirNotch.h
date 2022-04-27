/* -*- c++ -*- */
/*
 * Copyright 2022 mortarboard-H.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_NOTCHFILTER_IIRNOTCH_H
#define INCLUDED_NOTCHFILTER_IIRNOTCH_H

#include <gnuradio/sync_block.h>
#include <notchFilter/api.h>

namespace gr {
namespace notchFilter {

/*!
 * \brief <+description of block+>
 * \ingroup notchFilter
 *
 */
class NOTCHFILTER_API iirNotch : virtual public gr::sync_block {
public:
  typedef std::shared_ptr<iirNotch> sptr;

  /*!
   * \brief Return a shared_ptr to a new instance of notchFilter::iirNotch.
   *
   * To avoid accidental use of raw pointers, notchFilter::iirNotch's
   * constructor is in a private implementation
   * class. notchFilter::iirNotch::make is the public interface for
   * creating new instances.
   */
  static sptr make(double sampRate, double targetFreq, double width);

  /*!
   * \brief call back function to update centre frequency
   */
  virtual void set_wc(double wc)=0;

  /*!
   * \brief call back function to update band frequency
   */
  virtual void set_wb(double wb)=0;
};

} // namespace notchFilter
} // namespace gr

#endif /* INCLUDED_NOTCHFILTER_IIRNOTCH_H */
