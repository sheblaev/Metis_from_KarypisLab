/**
 * @file partition.h
 * @brief Partitioning function prototypes
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2014, Regents of the University of Minnesota
 * @version 1
 * @date 2014-09-17
 */




#ifndef MTMETIS_PARTITION_H
#define MTMETIS_PARTITION_H




#include "base.h"
#include "ctrl.h"
#include "graph.h"




/******************************************************************************
* SERIAL FUNCTION PROTOTYPES **************************************************
******************************************************************************/


#define partition_vertexseparator __mtmetis_partition_vertexseparator
/**
 * @brief Find a small vertex separator. Partitions 0 and 1 are the two halves,
 * and partition 2 is the separator.
 *
 * @param ctrl The control structure specifying runtime parameters.
 * @param graph The graph to find the separator in.
 * @param where The partition ID of each vertex (output).
 */
void partition_vertexseparator(
    ctrl_t * ctrl, 
    graph_t * graph, 
    pid_t ** where);


#define partition_print_info __mtmetis_print_info
/**
 * @brief Print information about a partition.
 *
 * @param ctrl The control structure.
 * @param graph The graph structure.
 * @param where The where vector.
 */
void partition_print_info(
    ctrl_t const * ctrl,
    graph_t const * graph,
    pid_t const * const * where);




/******************************************************************************
* PARALLEL FUNCTION PROTOTYPES ************************************************
******************************************************************************/


#define par_partition_kway __mtmetis_par_partition_kway
/**
 * @brief Entry level function for multithreaded kway partitioning. Should be
 * called by all threads in a  parallel region.
 *
 * @param ctrl The control structure.
 * @param graph The graph to partition.
 * @param where The allocated where vector.
 */
void par_partition_kway(
    ctrl_t * ctrl, 
    graph_t * graph, 
    pid_t ** where);


#define par_partition_rb __mtmetis_par_partition_rb
/**
 * @brief Entry level function for multithreaded kway partitioning. Should be
 * called by all threads in a parallel region.
 *
 * @param ctrl The control structure.
 * @param graph The graph to partition.
 * @param where The allocated where vector.
 */
void par_partition_rb(
    ctrl_t * ctrl, 
    graph_t * graph, 
    pid_t ** where);


#define par_partition_edgeseparator __mtmetis_par_partition_edgeseparator
/**
 * @brief Create a edge separator where partitions 0 and 1 are the two halves
 * and 2 is the separator.
 *
 * @param ctrl The control structure to use.
 * @param graph The graph to partition.
 * @param where The partition ids.
 */
void par_partition_edgeseparator(
    ctrl_t * ctrl,
    graph_t * graph,
    pid_t ** where);


#define par_partition_vertexseparator __mtmetis_par_partition_vertexseparator
/**
 * @brief Create a vertex separator where partitions 0 and 1 are the two halves
 * and 2 is the separator.
 *
 * @param ctrl The control structure to use.
 * @param graph The graph to partition.
 * @param where The partition ids.
 */
void par_partition_vertexseparator(
    ctrl_t * ctrl,
    graph_t * graph,
    pid_t ** where);


#define par_partition_pre __mtmetis_par_partition_pre
/**
 * @brief Pre-partition a graph, for redistribution among threads. 
 *
 * @param ctrl The ctrl structure with appropriate runtime parameters.
 * @param graph The graph to pre-partition.
 */
void par_partition_pre(
    ctrl_t * ctrl,
    graph_t * graph);

  


#endif
