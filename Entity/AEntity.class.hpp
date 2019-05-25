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

# define PLUS_X 0
# define LESS_X 1
# define PLUS_Y 2
# define LESS_Y 3


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

		//	if can move true else false
		virtual bool    onMove( void );

		//	Actions
		virtual void    hit( AEntity const & entity ) = 0;
		virtual void    move( void );
		void			move( int x, int y );

        virtual AEntity *     clone( void ) = 0;

		//	Variables
    	void            setSpeed( int frequency );
	    void            addSpeed( int frequency );

		void			setX( int x );
		int				getX( void ) const;

		void			setY( int y );
		int				getY( void ) const;

		std::string		getName(void) const;
		void			setName( std::string name);

		std::string		getType(void) const;
		void			setType( std::string type);

	protected:
		//	Positions
		int			_x;
		int 		_y;

		//Entity name
		std::string	_name;
		

		//	Entity class
		std::string	_type;

	    int			_speed;		// if <= 1 would be to do each turn
		int			_turn_before_move;		// initiayze at _speed
		int 		_direction;


};








#endif
