#!/bin/bash
##===================================
## P7 Load Leveler Submission Script
##===================================
##
## Don't change these parameters unless you really know what you are doing
##
#@ environment = MP_INFOLEVEL=0; MP_USE_BULK_XFER=yes; MP_BULK_MIN_MSG_SIZE=64K; \
##                MP_EAGER_LIMIT=64K; MP_DEBUG_ENABLE_AFFINITY=no
##
##===================================
## Avoid core dumps
# @ core_limit   = 0
##===================================
## Job specific
##===================================
#
# @ job_name = testPC_HG_with3
# @ job_type = parallel
# @ class = verylong
# @ output = $(jobid).out
# @ error = $(jobid).err
# @ wall_clock_limit = 48:00:00
# @ node = 1
# @ tasks_per_node = 128
# @ queue
#
#===================================

module load gcc openmpi
#for dim in 1 2 3 5 10 20 30 40 50 60 70 80 90 100 150 200 
for dim in 100
do
for ord in 2
do
    ./testPC.x -n $dim -o $ord -p 1 
done
done
