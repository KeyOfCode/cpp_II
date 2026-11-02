/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:31:57 by darismen          #+#    #+#             */
/*   Updated: 2025/03/18 12:25:28 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <sstream>

#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

typedef struct s_data
{
    int id;
    int value;
} Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &);
	public:
		~Serializer();
		Serializer &operator= (Serializer const &rhs);
		
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif