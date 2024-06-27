#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/lxk/Desktop/hw8/build
  make -f /Users/lxk/Desktop/hw8/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/lxk/Desktop/hw8/build
  make -f /Users/lxk/Desktop/hw8/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/lxk/Desktop/hw8/build
  make -f /Users/lxk/Desktop/hw8/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/lxk/Desktop/hw8/build
  make -f /Users/lxk/Desktop/hw8/build/CMakeScripts/ReRunCMake.make
fi

