#!/bin/sh
set -x
aclocal && autoconf && autoreconf --install
