/*
 * Copyright 2022 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(adaptiveNotch.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(e014ead3192dae1a16f0e4606375d164)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <notchFilter/adaptiveNotch.h>
// pydoc.h is automatically generated in the build directory
#include <adaptiveNotch_pydoc.h>

void bind_adaptiveNotch(py::module& m)
{

    using adaptiveNotch    = ::gr::notchFilter::adaptiveNotch;


    py::class_<adaptiveNotch, gr::sync_block, gr::block, gr::basic_block,
        std::shared_ptr<adaptiveNotch>>(m, "adaptiveNotch", D(adaptiveNotch))

        .def(py::init(&adaptiveNotch::make),
           py::arg("sampRate"),
           py::arg("targetFreq"),
           D(adaptiveNotch,make)
        )
        




        
        .def("update_sample_rate",&adaptiveNotch::update_sample_rate,       
            py::arg("rate"),
            D(adaptiveNotch,update_sample_rate)
        )


        
        .def("set_target_freq",&adaptiveNotch::set_target_freq,       
            py::arg("rate"),
            D(adaptiveNotch,set_target_freq)
        )

        ;




}







