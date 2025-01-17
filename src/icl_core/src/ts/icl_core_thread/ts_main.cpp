// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// This file is part of FZIs ic_workspace.
//
// This program is free software licensed under the LGPL
// (GNU LESSER GENERAL PUBLIC LICENSE Version 3).
// You can find a copy of this license in LICENSE folder in the top
// directory of the source code.
//
// © Copyright 2016 FZI Forschungszentrum Informatik, Karlsruhe, Germany
//
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Klaus Uhl <uhl@fzi.de>
 * \date    2009-12-14
 *
 */
//----------------------------------------------------------------------
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <icl_core/os_lxrt.h>
#include <icl_core_logging/Logging.h>

struct tGlobalFixture
{
  tGlobalFixture()
  {
    icl_core::os::lxrtStartup();
    icl_core::logging::initialize();
  }

  ~tGlobalFixture()
  {
    icl_core::logging::shutdown();
    icl_core::os::lxrtShutdown();
  }
};

BOOST_GLOBAL_FIXTURE(tGlobalFixture);