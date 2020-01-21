/**
 * base class for different autonomous agents interacting within a habitat
 *
 * by Blakely L McConnell  2015->~∞
 */

#include "generative/dftrFauna.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "cinder/rand.h"
#include "cinder/gl/gl.h"

namespace drifter
{
namespace generative
{
    Fauna::Fauna( const ci::vec2 & position, float radius )
            : _currentAge( 0.0f ), _position( position ), _radius( radius )
    {
        boost::uuids::uuid bId;
        _id = boost::uuids::to_string( bId );
        std::cout << "fauna with id: " << _id << " has been initialized at " << _position.x << ": " << _position.y << std::endl;
        _reach = _radius;
        _maxAge = ci::randFloat( 60.0f, 500.0f );
        _color = ci::Colorf( ci::randFloat( 0.0f, 1.0f ),
                ci::randFloat( 0.0f, 1.0f ),
                ci::randFloat( 0.0f, 1.0f ));
    }

    void Fauna::Draw() const
    {
        using namespace ci::gl;

        drawSolidCircle( _position, _radius );
    }
} //generative
} //drifter