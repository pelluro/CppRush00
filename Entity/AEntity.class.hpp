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
# define PLUS_X_PLUS_Y 5
# define LESS_X_PLUS_Y 6
# define PLUS_X_LESS_Y 7
# define LESS_X_LESS_Y 8

class AEntity
{
	public:
		AEntity( void );
		AEntity( std::string name, char type );
		AEntity( std::string name, char type, int speed);
		AEntity( std::string name, char type, int speed, int direction );
		AEntity( char type );
		AEntity( AEntity const & src );
		virtual ~AEntity( void );

		AEntity const &		operator=( AEntity const & rhs );

<<<<<<< HEAD
=======
		//	if can move true else false
//		 virtual bool    onMove( void );

>>>>>>> origin/debug2
		//	Actions
		virtual void    hit( AEntity const & entity );
		virtual void	move( int dx, int dy );

//        virtual AEntity *     clone( void );

        virtual int 	getDealDamage( void ) const;

		//	Variables
		void			setX( int x );
		int				getX( void ) const;
		int				getOldX( void ) const;
		void			setY( int y );
		int				getY( void ) const;
		int				getOldY( void ) const;

		std::string		getName(void) const;
		void			setName( std::string name);

		char			getType(void) const;
		void			setType( char type);

		virtual bool    move( void );
		virtual void    forceMove( void );
		virtual bool	onMove( void );

		virtual bool	toDelete( void );

		virtual void	fire( void ) = 0;
		virtual bool	onAction( void ) = 0;

		void            setSpeed( int frequency );
		void            addSpeed( int frequency );
		int             getSpeed( void ) const;

		void            setDirection( int direction );
		int             getDirection( void ) const;


protected:
		//	Positions
		int			_x;
		int 		_y;
		int			_oldX;
		int 		_oldY;

		int			_speed;		// if <= 1 would be to do each turn
		int			_turn_before_move;		// initialize at _speed
		int 		_direction;

		//Entity name
		std::string	_name;


		//	Entity class
		char _type;
};








#endif
