/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:34:58 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/09 18:21:47 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdarg.h>

#ifndef DISPLAY_H
# define DISPLAY_H

class Display {

public:
	Display( void );
	~Display( void );

	void	warning(void);
	bool	big_enough(void);
	bool	invalid_input(void);
	void	whisper(std::string message);
	int		get_option(std::string	options[], int counter);
};

#endif
