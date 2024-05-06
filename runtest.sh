#/bin/sh

frama-c -wp -wp-timeout 10 -wp-rte -wp-timeout 10 -main trig safety-mechanism.c -report -then -mdr-gen md -mdr-out report.md

