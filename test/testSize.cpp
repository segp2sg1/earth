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

#include <cppunit/extensions/HelperMacros.h>

class testSize : public CppUnit::TestFixture
{
public:
	CPPUNIT_TEST_SUITE(testSize);
	CPPUNIT_TEST(test);
	CPPUNIT_TEST_SUITE_END();
	
	void test();
};

CPPUNIT_TEST_SUITE_REGISTRATION(testSize);

#include "Size.h"

using namespace Sp;

void testSize::test() {
	Size s = Size::Bytes(4097);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(s.getBytes(), 4097.0, 0.1);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(s.getKBytes(), 4.0, 0.1);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(s.getMBytes(), 0.0, 0.1);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(s.getGBytes(), 0.0, 0.1);

	s = Size::GBytes(10);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(s.getGBytes(), 10.0, 0.1);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(s.getMBytes(), 10240.0, 0.1);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(s.getKBytes(), 10485760.0, 0.1);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(s.getBytes(), 1.073741e10, 10e5);
	
	s = Size::Bytes(0);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(s.getBytes(), 0.0, 0.1);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(s.getKBytes(), 0.0, 0.1);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(s.getMBytes(), 0.0, 0.1);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(s.getGBytes(), 0.0, 0.1);
}
