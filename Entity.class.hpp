/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconti <mconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 08:36:34 by mconti            #+#    #+#             */
/*   Updated: 2019/05/25 08:36:36 by mconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ENTITY_CLASS_H

# define ENTITY_CLASS_H

# include <string>
# include <iostream>


class AEntity
{
	public:
		AEntity( void );
		AEntity( std::string type, int x, int y );
		AEntity( AEntity const & src );
		virtual ~AEntity( void );

		AEntity const &		operator=( AEntity const & rhs );

		virtual void	onPlayerHit( void ) = 0;
		virtual void	onEnemyHit( void ) = 0;

		virtual bool	onEvent( void );
		virtual bool	onMove( void );

		void			move( int x, int y );

		void			setX( int x );
		int				getX( void );

		void			setY( int y );
		int				getY( void );

		void			setActionFrequency( int frequency );
		void			addToActionFrequency( int frequency );

		void			setMoveFrequency( int frequency );
		void			addToMoveFrequency( int frequency );

	private:
		//	Positions
		int			_x;
		int 		_y;

		//	Entity class
		std::string	_type;

		/*	on How many turn waiting to launch onEvent/onMove, every onEvent/onMove need to be like :
		**		if (!AEntity::onEvent())
		**			{ ... } 
		**		return ;
		*/
		int			_action_frequency;		// if < 1 would be to do each turn
		int			_turn_before_action;	// initiayze at _action_frequency

		int			_move_frequency;		// if < 1 would be to do each turn
		int			_turn_before_move;		// initiayze at _action_frequency


};








#endif