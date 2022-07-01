/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dynarr.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/30 19:30:46 by lsinke        #+#    #+#                 */
/*   Updated: 2022/06/30 19:30:46 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNARR_H
# define DYNARR_H

# define GROW_SIZE 64

# include <stdbool.h>
# include <stddef.h>

/**
 * A dynamic (growable) array, usable for all types
 * 
 * arr is the internal array
 * data_size is the size of the data type (sizeof <type>)
 * arr_size is the size (in objects!) of the internal array
 * arr_idx is the next unused index of the internal array
 */
typedef struct s_dynarr {
	void			*arr;
	const size_t	data_size;
	size_t			arr_size;
	size_t			arr_idx;
}	t_dynarr;

/**
 * Create a new (growable) dynamic array
 * 
 * @param[out] ptr A pointer where the new dynamic array will be created
 * @param[in] init_size The initial size (in objects!) of the internal array
 * @param[in] data_size The size of the data type this array will be used for
 * 
 * @return true if everything went as planned, false if an error occured
 */
bool	dynarr_create(t_dynarr *ptr, size_t init_size, const size_t data_size);

/**
 * Frees all resources used in this array (the internal array)
 * 
 * @param[in/out] arr the dynarr to delete
 */
void	dynarr_delete(t_dynarr *arr);

/**
 * "Finalize" this array. Shrinks the internal array to the minimal size
 * necessary for everything to fit
 * 
 * @param arr[in/out] the buffer to finalize
 * 
 * @return true if everything went as planned, false if an error occured
 * 
 * This function will not modify (and not free) the array if an error occurs
 */
bool	dynarr_finalize(t_dynarr *arr);

/**
 * Append some objects to the end of this array. Growing the internal array
 * if necessary
 * 
 * @param arr[in/out] the dynarr to append to
 * @param objs[in] the objects to append to the arary
 * @param count[in] the amount of objects to be added
 * 
 * @return true if everything went as planned, false if an error occured
 */
bool	dynarr_add(t_dynarr *arr, void *objs, size_t count);

/**
 * Get an object from a certain index in the array.
 * 
 * @param arr[in/out] the dynarr to get the object from
 * @param index[in] the index of the object in the array
 *
 * @return The object at the given index, or NULL if index is out of bounds
 */
void	*dynarr_get(t_dynarr *arr, size_t index);

/**
 * Store an object at a certain index in the array. Growing the array to that
 * size if necessary.
 * 
 * @param arr[in/out] the dynarr to store the object in 
 * @param index[in] the index where the object will be stored in the array
 * @param obj[in] the object to store
 * 
 * @return true if everything went as planned, false if an error occured 
 */
bool	dynarr_set(t_dynarr *arr, size_t index, void *obj);

/**
 * Grow (or shrink) the internal array
 * 
 * @param arr[in/out] the dynarr to grow
 * @param new_size[in] the new size (in objects!) to grow the array to.
 * 
 * @return true if everything went as planned, false if an error occured
 */
bool	dynarr_grow(t_dynarr *arr, size_t new_size);

/**
 * Perform a function on every object in this dynarr
 *
 * @param arr[in/out] the dynarr to iterate over 
 * @param f[in] the function to call with every object
 * @param param[in] an extra parameter for the function to be called
 */
void	dynarr_foreach(t_dynarr *arr, void (*f)(void *, void *), void *param);

#endif //DYNARR_H