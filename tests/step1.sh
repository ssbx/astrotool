#!/bin/sh

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

${DIR}/../_build/code/step1_printFitsTable ${DIR}/../support/material/input/A1.catalog.fits
