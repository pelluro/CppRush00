/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconti <mconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 08:36:34 by mconti            #+#    #+#             */
/*   Updated: 2019/05/25 08:36:36 by mconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AENTITY_CLASS_H

# define AENTITY_CLASS_H

# include <string>
# include <iostream>


class AEntity
{
	public:
		AEntity( void );
		AEntity( std::string name, std::string type, int x, int y );
		AEntity( std::string name, std::string type );
		AEntity( std::string type );
		AEntity( AEntity const & src );
		virtual ~AEntity( void );

		AEntity const &		operator=( AEntity const & rhs );

		virtual void	onEntityHit ( const AEntity &s ) = 0;

		void			move( int x, int y );

		void			setX( int x );
		int				getX( void );

		void			setY( int y );
		int				getY( void );

		std::string		getName(void);
		void			setName( std::string name);

	protected:
		//	Positions
		int			_x;
		int 		_y;

		//Entity name
		std::string	_name;
		

		//	Entity class
		std::string	_type;



};








#endif
