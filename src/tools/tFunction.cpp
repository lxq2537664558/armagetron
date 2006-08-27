
#include "tFunction.h"

// *******************************************************************************
// *
// *	tFunction
// *
// *******************************************************************************
//!
//!
// *******************************************************************************

tFunction::tFunction( void )
        : offset_(0), slope_(0)
{
}

// *******************************************************************************
// *
// *	~tFunction
// *
// *******************************************************************************
//!
//!
// *******************************************************************************

tFunction::~tFunction( void )
{
}

// *******************************************************************************
// *
// *	Evaluate
// *
// *******************************************************************************
//!
//!		@param	argument
//!		@return
//!
// *******************************************************************************

REAL tFunction::Evaluate( REAL argument ) const
{
    return offset_ + slope_ * argument;
}
