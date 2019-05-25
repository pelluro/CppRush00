

Square::Square( void )
{

}
Square::Square( Square const & src )
{

}

Square::~Square( void )
{

}

Square const &		Square::operator=( Square const & rhs )
{
	if (this != &rhs)
	{
		return *this;
	}
}

AEntity *		Square::getEntity( void )
{
	return this->_entity;
}