/**
 * @file initpart.h
 * @brief Parallel initial partitioning function prototypes.
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2014, Regents of the University of Minnesota
 * @version 1
 * @date 2014-09-17
 */





#ifndef MTMETIS_INITPART_H
#define MTMETIS_INITPART_H




#include "base.h"
#include "graph.h"
#include "ctrl.h"




/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


#define par_initpart_cut __mtmetis_par_initpart_cut
/**
 * @brief Create a cut partitioning of a coarsened graph.
 *
 * @param ctrl The control structure with runtime parameters.
 * @param graph The coarse graph to partition.
 *
 * @return The edgecut of the new partitioning.  
 */
wgt_t par_initpart_cut(
    ctrl_t * ctrl,
    graph_t * graph);


#define par_initpart_vsep __mtmetis_par_initpart_vsep
/**
 * @brief Create a small vertex separator of a coarsened graph.
 *
 * @param ctrl The control structure to use.
 * @param graph The graph to partition.
 *
 * @return The size of the vertex separator.
 */
wgt_t par_initpart_vsep(
    ctrl_t * ctrl,
    graph_t * graph);




#endif