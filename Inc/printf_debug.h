/**
 * @file printf_debug.h
 * @author Donghyun Ko
 * @brief Print debug messages
 * @version 1.0
 * @date 2023
 * 
 * @copyright MIT License
 * 
 */
#ifndef __PRINTF_DEBUG_H__
#define __PRINTF_DEBUG_H__

/**
 * @brief Debug message macro (verbose level: 1).
 * In order to activate DEBUG_V macro, set the DEBUG_LEVEL equal to or greater than 1.
 * 
 */
#define DEBUG_V(...)
/**
 * @brief Debug message macro (verbose level: 2).
 * In order to activate DEBUG_VV macro, set the DEBUG_LEVEL equal to or greater than 2.
 * 
 */
#define DEBUG_VV(...)
/**
 * @brief Debug message macro (verbose level: 3).
 * In order to activate DEBUG_VVV macro, set the DEBUG_LEVEL equal to or greater than 3.
 * 
 */
#define DEBUG_VVV(...)

#if DEBUG_LEVEL >= 1
    #undef DEBUG_V
    #define DEBUG_V(...) printf(__VA_ARGS__)
#endif

#if DEBUG_LEVEL >= 2
    #undef DEBUG_VV
    #define DEBUG_VV(...) printf(__VA_ARGS__)
#endif

#if DEBUG_LEVEL >= 3
    #undef DEBUG_VVV
    #define DEBUG_VVV(...) printf(__VA_ARGS__)
#endif

#endif /* __PRINTF_DEBUG_H__ */