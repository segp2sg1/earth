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

class testDateTime : public CppUnit::TestFixture
{
public:
	CPPUNIT_TEST_SUITE(testDateTime);
	CPPUNIT_TEST(test);
	CPPUNIT_TEST_SUITE_END();
	
	void test();
};

CPPUNIT_TEST_SUITE_REGISTRATION(testDateTime);

#include "DateTime.h"

using namespace Sp;

void testDateTime::test()
{
	// Commented this test out because unit time zero (the epoch) is defined as a specific
	// time in GMT. However, when you get the local time it will be different in different
	// time zones and so the test will fail or work depending on which timezone you're in.
	DateTime t1 = DateTime::unixDateTime(0);
	//checkEqual("test 1", t1.timeAndDateString(), "Wed Dec 31 16:00:00 1969");
	//checkEqual("test 2", t1.year(), 1969);
	//checkEqual("test 3", t1.hour(), 16);
	//checkEqual("test 4", t1.minute(), 0);
	//checkEqual("test 5", t1.second(), 0);
	//checkEqual("test 6", t1.dayOfWeek(), 3);
	//checkEqual("test 7", t1.dayOfMonth(), 31);
	//checkEqual("test 8", t1.month(), 12);
	//checkEqual("test 9", t1.monthStringShort(), "Dec");
	//checkEqual("test 10", t1.monthString(), "December");
	//checkEqual("test 11", t1.dayOfWeekStringShort(), "Wed");
	//checkEqual("test 12", t1.dayOfWeekString(), "Wednesday");
	//checkEqual("test 13", t1.timeString(), "16:00:00");
	DateTime t2 = DateTime::unixDateTime(100);
	DateTime t0;
	CPPUNIT_ASSERT(t0 == t1);
	CPPUNIT_ASSERT(t0 <  t2);
	CPPUNIT_ASSERT(!(t2 <  t0));
	CPPUNIT_ASSERT(!(t0 == t2));
	CPPUNIT_ASSERT(t1 <  t2);
	CPPUNIT_ASSERT(!(t2 <  t1));
	CPPUNIT_ASSERT(!(t1 == t2));
}
