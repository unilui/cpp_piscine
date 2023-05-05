/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:34:58 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/04 22:15:37 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>

#ifndef DISPLAY_H
# define DISPLAY_H

class Display {

public:
	Display( void );
	~Display( void );

	void	warning(void);
};

#endif
