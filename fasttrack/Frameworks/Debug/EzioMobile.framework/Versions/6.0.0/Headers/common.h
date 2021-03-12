/** -----------------------------------------------------------------------------
 
    Copyright (c) 2013 - GEMALTO DEVELOPMENT - R&D
                        Z.I. ATHELIA III - VOIE ANTIOPE
                          13 705 LA CIOTAT - FRANCE
 
                Tel. 33 (0)4 42 36 63 71 / Fax. 33 (0)4 42 36 69 53
 
    ------------------------------------------------------------------------------
    GEMALTO MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF THE 
    SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
    WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR 
    NON-INFRINGEMENT. GEMALTO SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY 
    LICENSEE AS A RESULT OF USING, MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS 
    DERIVATIVES.
    
    THIS SOFTWARE IS NOT DESIGNED OR INTENDED FOR USE OR RESALE AS ON-LINE CONTROL
    EQUIPMENT IN HAZARDOUS ENVIRONMENTS REQUIRING FAIL-SAFE PERFORMANCE, SUCH AS 
    IN THE OPERATION OF NUCLEAR FACILITIES, AIRCRAFT NAVIGATION OR COMMUNICATION 
    SYSTEMS, AIR TRAFFIC CONTROL, DIRECT LIFE SUPPORT MACHINES, OR WEAPONS 
    SYSTEMS, IN WHICH THE FAILURE OF THE SOFTWARE COULD LEAD DIRECTLY TO DEATH, 
    PERSONAL INJURY, OR SEVERE PHYSICAL OR ENVIRONMENTAL DAMAGE ("HIGH RISK 
    ACTIVITIES"). GEMALTO SPECIFICALLY DISCLAIMS ANY EXPRESS OR IMPLIED WARRANTY 
    OF FITNESS FOR HIGH RISK ACTIVITIES.
    
    ------------------------------------------------------------------------------
*/

#ifndef COMMON_H
#define COMMON_H
#define FALSE 0
#ifndef TRUE
#define TRUE (!FALSE)
#endif

#ifdef DEBUG
// Use stdout for errors in order to keep error information relevant with unit
// test execution.
//
// It makes more sense to send this data to stderr, BUT it is a problem when
// running gtest because the test and its errors are not interleaved (gtest
// uses stdout) resulting in errors appearing at random points in gtest's
// output.  Use stdout until a better solution is found.
#define DEBUG_PRINTF(...) \
    fprintf(stdout, "%s:%d: ", __FILE__, __LINE__); \
    fprintf(stdout, __VA_ARGS__); \
    fprintf(stdout, "\n"); \
    fflush( stdout);
#else
#define DEBUG_PRINTF(...)
#endif /*DEBUG*/

#define BREAK_IF_TRUE(C) \
    if (C) { break; }
#define BREAK_IF_FALSE(C) \
    if (!(C)) { break; }
#define BREAK_IF_TRUE_MSG(C, ...) \
    if (C) { DEBUG_PRINTF(__VA_ARGS__); break; }

#define BREAK_IF_ERROR(S) BREAK_IF_TRUE((S) != EM_STATUS_SUCCESS)
#define BREAK_IF_ERROR_MSG(S, ...) \
    BREAK_IF_TRUE_MSG((S) != EM_STATUS_SUCCESS, __VA_ARGS__)

#define BREAK_IF_EQ(L, R) BREAK_IF_TRUE((L) == (R))
#define BREAK_IF_EQ_MSG(L, R, ...) BREAK_IF_TRUE_MSG((L) == (R), __VA_ARGS__)

#define BREAK_IF_NE(L, R) BREAK_IF_TRUE((L) != (R))
#define BREAK_IF_NE_MSG(L, R, ...) BREAK_IF_TRUE_MSG((L) != (R), __VA_ARGS__)

#define BREAK_IF_NULL(P) BREAK_IF_TRUE((P) == NULL)
#define BREAK_IF_NULL_MSG(P, ...) BREAK_IF_TRUE_MSG((P) == NULL, __VA_ARGS__)

#define BREAK_IF_NOT_NULL(P) BREAK_IF_TRUE((P))
#define BREAK_IF_NOT_NULL_MSG(P, ...) \
    BREAK_IF_TRUE_MSG((P) != NULL, __VA_ARGS__)

#define BREAK_IF_GT(L, R) BREAK_IF_TRUE((L) > (R))
#define BREAK_IF_GT_MSG(L, R, ...) BREAK_IF_TRUE_MSG((L) > (R), __VA_ARGS__)

#define BREAK_IF_GE(L, R) BREAK_IF_TRUE((L) >= (R))
#define BREAK_IF_GE_MSG(L, R, ...) BREAK_IF_TRUE_MSG((L) >= (R), __VA_ARGS__)

#define BREAK_IF_LT(L, R) BREAK_IF_TRUE((L) < (R))
#define BREAK_IF_LT_MSG(L, R, ...) BREAK_IF_TRUE_MSG((L) < (R), __VA_ARGS__)

#define BREAK_IF_LE(L, R) BREAK_IF_TRUE((L) <= (R))
#define BREAK_IF_LE_MSG(L, R, ...) BREAK_IF_TRUE_MSG((L) <= (R), __VA_ARGS__)


#define ARRAY_SIZE(A) ( sizeof(A) / sizeof(*(A)) )

#endif /*COMMON_H*/
