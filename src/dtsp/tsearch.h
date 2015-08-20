/**
 * File: tsearch.h
 *
 * This code is part of Data Transfer Security Protocol (DTSP) library.
 *
 * ANSI C code for Tree search generalised from Knuth Algorithm T (6.2.2).
 * It is literally a copy of POSIX (not ANSI) search.h "t*" methods.
 * Many search.h implementations are missing "tdestroy" implementation.
 *
 * @author NetBSD Community Team (christos, lukem, kleink)
 * @author Alexander Lokhman <alex.lokhman@gmail.com>
 *
 * Created on August 2015
 */

#ifndef TSEARCH_H
#define	TSEARCH_H

#include <assert.h>
#include <stdlib.h>

#define TSEARCH_POSIX  1
#define TSEARCH_DARWIN 0

#if (TSEARCH_POSIX || TSEARCH_DARWIN)
# include <search.h>
#endif

#ifdef	__cplusplus
extern "C" {
#endif

#if !TSEARCH_POSIX
#if !TSEARCH_DARWIN
    typedef enum {
        preorder,
        postorder,
        endorder,
        leaf,
    } VISIT;

    /**
     * Search for an entry matching the given KEY in the tree pointed to by
     * *ROOTP and insert a new element if not found.
     *
     * @param key       Tree key
     * @param rootp     Tree root
     * @param compar    Comparison function
     *
     * @return new or existing entry
     */
    void *tsearch(const void *key, void **rootp, int (*compar)(const void *, const void *));

    /**
     * Search for an entry matching the given KEY in the tree pointed to by
     * *ROOTP. If no matching entry is available return NULL.
     *
     * @param key       Tree key
     * @param rootp     Tree root
     * @param compar    Comparison function
     *
     * @return NULL or existing entry
     */
    void *tfind(const void *key, const void **rootp, int (*compar)(const void *, const void *));

    /**
     * Remove the element matching KEY from the tree pointed to by *ROOTP.
     *
     * @param key       Tree key
     * @param rootp     Tree root
     * @param compar    Comparison function
     *
     * @return pointer to the parent of the item deleted or NULL
     */
    void *tdelete(const void *key, void **rootp, int (*compar)(const void *, const void *));

    /**
     * Walk through the whole tree and call the ACTION callback for every node
     * or leaf.
     *
     * @param root      Tree root
     * @param action    Action function
     *
     * @return void
     */
    void twalk(const void *root, void (*action)(const void *nodep, const VISIT which, const int depth));
#endif  /* TSEARCH_DARWIN */

    /**
     * Destroy the whole tree, call FREEFCT for each node or leaf.
     *
     * @param root      Tree root
     * @param free_node Memory free function
     *
     * @return void
     */
    void tdestroy(void *root, void (*free_node)(void *nodep));
#endif  /* TSEARCH_POSIX */

#ifdef	__cplusplus
}
#endif

#endif	/* TSEARCH_H */
