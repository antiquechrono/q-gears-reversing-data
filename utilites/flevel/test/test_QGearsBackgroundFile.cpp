/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-07-31 Tobias Peters <tobias.peters@kreativeffekt.at>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/

#include <cstddef>

#include "QGearsBackgroundFile.h"

#define BOOST_TEST_MODULE QGearsBackgroundFile
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( header_size )
{
    BOOST_CHECK_EQUAL( 0x34, sizeof( QGears::BackgroundFile::SpriteData ) );
    BOOST_CHECK_EQUAL( 0x03, sizeof( QGears::BackgroundFile::Color_BGR) );

    QGears::BackgroundFile::SpriteData* sd( NULL );
    BOOST_CHECK_EQUAL( sizeof( *sd ), sizeof( QGears::BackgroundFile::SpriteData ) );
}

BOOST_AUTO_TEST_CASE( sprite_data_offset )
{
    BOOST_CHECK_EQUAL( 0x02, offsetof( QGears::BackgroundFile::SpriteData, dst_x ) );
    BOOST_CHECK_EQUAL( 0x04, offsetof( QGears::BackgroundFile::SpriteData, dst_y ) );
    BOOST_CHECK_EQUAL( 0x0A, offsetof( QGears::BackgroundFile::SpriteData, src_x ) );
    BOOST_CHECK_EQUAL( 0x0C, offsetof( QGears::BackgroundFile::SpriteData, src_y ) );
    BOOST_CHECK_EQUAL( 0x16, offsetof( QGears::BackgroundFile::SpriteData, palette_page ) );
    //BOOST_CHECK_EQUAL( 0x18, offsetof( QGears::BackgroundFile::SpriteData, flags ) );
    BOOST_CHECK_EQUAL( 0x20, offsetof( QGears::BackgroundFile::SpriteData, data_page ) );
    //BOOST_CHECK_EQUAL( 0x22, offsetof( QGears::BackgroundFile::SpriteData, sfx ) );
    //BOOST_CHECK_EQUAL( 0x2A, offsetof( QGears::BackgroundFile::SpriteData, off_x ) );
    //BOOST_CHECK_EQUAL( 0x2E, offsetof( QGears::BackgroundFile::SpriteData, off_y ) );
}