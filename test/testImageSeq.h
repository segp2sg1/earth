//  Copyright (C) 2001-2003 Matthew Landauer. All Rights Reserved.
//  
//  This program is free software; you can redistribute it and/or modify it
//  under the terms of version 2 of the GNU General Public License as
//  published by the Free Software Foundation.
//
//  This program is distributed in the hope that it would be useful, but
//  WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  Further, any
//  license provided herein, whether implied or otherwise, is limited to
//  this program in accordance with the express provisions of the GNU
//  General Public License.  Patent licenses, if any, provided herein do not
//  apply to combinations of this program with other product or programs, or
//  any other product whatsoever.  This program is distributed without any
//  warranty that the program is delivered free of the rightful claim of any
//  third person by way of infringement or the like.  See the GNU General
//  Public License for more details.
//
//  You should have received a copy of the GNU General Public License along
//  with this program; if not, write the Free Software Foundation, Inc., 59
//  Temple Place - Suite 330, Boston MA 02111-1307, USA.
//
// $Id$

#ifndef _testimageseq_h_
#define _testimageseq_h_

#include <cppunit/extensions/HelperMacros.h>

#include "ImageSeq.h"
#include "Path.h"

using namespace Sp;

class testImageSeq : public CppUnit::TestFixture
{
public:
	CPPUNIT_TEST_SUITE(testImageSeq);
	CPPUNIT_TEST(test);
	CPPUNIT_TEST_SUITE_END();
	
	void test();

private:
	void checkSequence(const ImageSeq &seq, std::string name, std::string frames,
		int width, int height, std::string format);
	void copyFile(const Path &path1, const Path &path2);
	void makeDirectory(const Path &path);
};

#endif
