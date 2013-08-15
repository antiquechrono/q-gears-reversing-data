/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-11 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include "QGearsHRCFile.h"

#include <OgreBone.h>
#include <OgreSkeletonManager.h>

namespace QGears
{
    //---------------------------------------------------------------------
    const String HRCFile::ROOT_BONE_NAME( "root" );

    //---------------------------------------------------------------------
    HRCFile::HRCFile()
    {
    }

    //---------------------------------------------------------------------
    HRCFile::~HRCFile()
    {
    }

    //---------------------------------------------------------------------
    void
    HRCFile::setName( const String &name )
    {
        m_name = name;
    }

    //---------------------------------------------------------------------
    Ogre::SkeletonPtr
    HRCFile::createSkeleton( const String &name, const String &group ) const
    {
        Ogre::SkeletonPtr skeleton( Ogre::SkeletonManager::getSingleton().create( name, group ) );
        skeleton->createBone( ROOT_BONE_NAME );

        for( BoneList::const_iterator it_bone( m_bones.begin() )
            ;it_bone != m_bones.end()
            ;++it_bone )
        {
            Ogre::Bone* child( skeleton->createBone( it_bone->name ) );
            Ogre::Bone* parent( skeleton->getBone( it_bone->parent ) );
            child->setPosition( 0, it_bone->length, 0 );
            parent->addChild( child );
        }
        return skeleton;
    }

    //---------------------------------------------------------------------
}
