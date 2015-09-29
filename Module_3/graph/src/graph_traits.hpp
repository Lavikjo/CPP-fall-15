#ifndef ELEC_CPP_GRAPH_TRAITS_HH
#define ELEC_CPP_GRAPH_TRAITS_HH

/* Traits for a Graph
 * The vertext type (V) is not actually used by these traits
 * Contains the boolean information if the Graph is (un)directed or
 *  (un)weighted */

template <typename V, bool D = true, bool W = true>
struct graph_traits
{ 
    static const bool directed = D;
    static const bool weighted = W;
};

#endif
